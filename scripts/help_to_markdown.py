#!/usr/bin/env python3
"""Convert the in-game help to Markdown that can be read on GitHub.

The help that the game shows (the '?' command) is read from lib/help, and
from lib/mods/theme/help for the Theme module.  Those files are the source
of truth.  This script turns each set into GitHub-flavoured Markdown under
doc/help and doc/help/theme; never edit the generated files by hand.

    python3 scripts/help_to_markdown.py            # regenerate doc/help
    python3 scripts/help_to_markdown.py --check    # verify doc/help only
    python3 -m unittest discover -s scripts -p 'test_*.py'

The docs workflow (.github/workflows/docs.yml) fails when the committed
Markdown does not match what this script generates, so regenerate and
commit doc/help together with any change to the help files.  The script
owns every *.md file directly in doc/help and doc/help/theme: it rewrites
them and deletes those that no help file generates any more.

The markup is interpreted as show_file_aux() in src/files.cc does:

    #####X...          the whole line is drawn in colour X (dwsorgbuDWvyRGBU)
    |||||XY            link colours (not shown)
    ~~~~~NN|...        tag NN, a link target; the rest of the line is ignored
    &&&&&XcXc...       screen dump: pairs of colour and character
    *****F*NN[label]   link to tag NN of help file F (0: top of the file)
    *****/kF*NN[label] the same, with shortcut key k
    [[[[[Xtext]        text in colour X
    {{{{{...}          removed (meant for an old HTML export)
    \\c                in a [label] or [[[[[X...]: the character c itself

and is rendered as follows:

  - Red and green lines that read as titles become headings; the first red
    title of a page is its level 1 heading.
  - Tags become <a id="tag-NN"> anchors on the next block, and links point
    at them (GitHub prefixes such ids with "user-content-" and resolves
    "#tag-NN" fragments to them).
  - Other coloured text becomes LaTeX, $`\\color{...}{\\textsf{...}}`$, in a
    shade of the game colour that is readable on GitHub's light and dark
    themes.  White is the default colour and is left alone.  Single
    coloured characters (map symbols) are drawn in the game colour on black.
  - Column layouts become Markdown tables where the columns can be found,
    code blocks (or <pre> when they contain links) otherwise.  Screen dumps
    become code blocks.
  - Prose keeps the source line breaks, except that lines the author
    wrapped only because they were full are joined.
"""

import argparse
import collections
import html
import os
import posixpath
import re
import sys

SCRIPT = 'scripts/help_to_markdown.py'

# (title, source directory, output directory), relative to the repository.
HELP_SETS = (
    ('ToME help', 'lib/help', 'doc/help'),
    ('Theme module help', 'lib/mods/theme/help', 'doc/help/theme'),
)

PAGE_SUFFIXES = ('.txt', '.hlp')

# Files in the help directories that are not help pages: the HTML header and
# footer of an old HTML export.
NON_PAGES = frozenset(['head.aux', 'foot.aux'])

INDEX_NAME = 'README.md'

# The game palette (angband_color_table in src/variable.cc).  Used as is for
# single characters, which are drawn on black as in the game.
GAME_COLOURS = {
    'd': '#000000', 'w': '#FFFFFF', 's': '#808080', 'o': '#FF8000',
    'r': '#C00000', 'g': '#008040', 'b': '#0000FF', 'u': '#804000',
    'D': '#404040', 'W': '#C0C0C0', 'v': '#FF00FF', 'y': '#FFFF00',
    'R': '#FF0000', 'G': '#00FF00', 'B': '#00FFFF', 'U': '#C08040',
}

# Text colours on GitHub's background: each game colour with its lightness
# changed (if needed) so that it has a contrast of at least 3:1 against both
# the light (#ffffff) and the dark (#0d1117) theme.  'w' (white) is the
# default colour and is not coloured at all.
TEXT_COLOURS = {
    'd': '#606060', 's': '#808080', 'o': '#E87400',
    'r': '#C40000', 'g': '#008040', 'b': '#3E3EFF', 'u': '#974C00',
    'D': '#606060', 'W': '#949494', 'v': '#FF00FF', 'y': '#9A9A00',
    'R': '#FF0000', 'G': '#00AD00', 'B': '#00A5A5', 'U': '#C08040',
}

# Line colours that are used for titles, and the heading level they get.
HEADING_LEVELS = {'R': 2, 'G': 3}

# Prose keeps its line breaks, except where a line was evidently wrapped
# because the next word did not fit: when the line plus the next word is
# longer than WRAP_FULL, or longer than WRAP_SOFT and the line does not end
# a sentence before the next one starts.
WRAP_FULL = 76
WRAP_SOFT = 64

MARKERS = ('#####', '|||||', '~~~~~', '&&&&&', '*****', '[[[[[', '{{{{{')

GAP_RE = re.compile(r'\S {3,}\S')
SENTENCE_END_RE = re.compile(r'[.!?]["\')]?$')
SENTENCE_START_RE = re.compile(r'["\'(]?[A-Z0-9]')
LIST_RE = re.compile(r'(?:[-*+o]|\d+[.)]|[A-Za-z][.)]|\(\w{1,3}\))\s')
LEAD_DECORATION_RE = re.compile(r'\s*(?:[=~*#_-]{2,}|[=<])?\s*')
TRAIL_DECORATION_RE = re.compile(r'\s*(?:[=~*#_-]{2,}|[=>])?\s*$')
RULE_CHARS = frozenset('-=~_*+#<>/\\| ')
ENTITY_RE = re.compile(r'&(?:#[0-9]+|#[xX][0-9a-fA-F]+|[A-Za-z][A-Za-z0-9]*);')
URL_RE = re.compile(r'(?:https?|ftp)://[^\s<>`|]+$')
TEXT_URL_RE = re.compile(r'(?:https?|ftp)://[^\s<>"\'`|\\()\[\]{}]*[^\s<>"\'`|\\()\[\]{}.,;:!?]')
LINE_START_RE = re.compile(r'^(\d+)([.)])')
NUMBER_RE = re.compile(r'[-+]?\d')


# --------------------------------------------------------------------------
# Reading and parsing

def read_lines(data):
    """Split a help file into lines the way my_fgets() in src/util.cc does.

    Lines end at LF, CR, CRLF or LFCR; tabs expand to the next multiple of
    eight columns of the raw line; control characters are dropped.  Bytes
    are Latin-1 (the game itself drops non-ASCII bytes; we keep them).
    """
    lines = []
    buf = []
    i, n = 0, len(data)
    while i < n:
        c = data[i]
        i += 1
        if c in (0x0A, 0x0D):
            pair = 0x0D if c == 0x0A else 0x0A
            if i < n and data[i] == pair:
                i += 1
            lines.append(''.join(buf))
            buf = []
        elif c == 0x09:
            buf.extend(' ' * (8 - len(buf) % 8))
        elif 0x20 <= c < 0x7F or c >= 0xA0:
            buf.append(chr(c))
    if buf:
        lines.append(''.join(buf))
    return lines


Seg = collections.namedtuple('Seg', 'kind text colour span target tag')


def text_seg(text, colour=None, span=False):
    return Seg('text', text, colour, span, None, 0)


def link_seg(text, target, tag):
    return Seg('link', text, None, False, target, tag)


class Line(object):
    """One source line: 'text', 'blank', 'tag' or 'verbatim'."""

    def __init__(self, kind, colour=None, segs=(), tag=0, display=''):
        self.kind = kind
        self.colour = colour
        self.segs = list(segs)
        self.tag = tag
        self.display = display
        self.number = 0


def atoi(text):
    match = re.match(r'\s*([-+]?\d+)', text)
    return int(match.group(1)) if match else 0


def read_label(body, i, warn):
    """Read up to an unescaped ']' from body[i:]; return (text, next index)."""
    out = []
    n = len(body)
    while i < n and body[i] != ']':
        if body[i] == '\\' and i + 1 < n:
            i += 1
        out.append(body[i])
        i += 1
    if i >= n:
        warn('missing "]"; the text runs to the end of the line')
    return ''.join(out), i + 1


def parse_inline(body, colour, warn):
    segs = []
    plain = []

    def flush():
        if plain:
            segs.append(text_seg(''.join(plain), colour))
            del plain[:]

    i, n = 0, len(body)
    while i < n:
        if body.startswith('*****', i):
            j = i + 5
            if body.startswith('/', j):
                j += 2
            star = body.find('*', j)
            bracket = body.find('[', star + 1) if star >= 0 else -1
            if star < 0 or bracket < 0:
                warn('malformed link "%s"' % body[i:])
                plain.append(body[i:i + 5])
                i += 5
                continue
            label, i = read_label(body, bracket + 1, warn)
            if not label:
                warn('link to %s has no text, so it cannot be seen; dropped' % body[j:star])
                continue
            flush()
            segs.append(link_seg(label, body[j:star], atoi(body[star + 1:bracket])))
        elif body.startswith('[[[[[', i) and i + 5 < n:
            code = body[i + 5]
            if code not in GAME_COLOURS:
                warn('unknown colour "%s"' % code)
                code = None
            label, i = read_label(body, i + 6, warn)
            flush()
            segs.append(text_seg(label, code, span=True))
        elif body.startswith('{{{{{', i):
            close = body.find('}', i + 6)
            if close < 0:
                warn('missing "}"; the rest of the line is dropped')
                close = n
            i = close + 1
        else:
            plain.append(body[i])
            i += 1
    flush()
    return segs


def parse_line(text, warn=None):
    """Parse one line; returns a Line, or None for lines that are not shown."""
    warn = warn or (lambda message: None)
    colour = None
    body = text
    if text.startswith('#####'):
        colour = text[5:6]
        body = text[6:]
        if not colour:
            return Line('blank')
        if colour not in GAME_COLOURS:
            warn('unknown colour "%s"' % colour)
            colour = None
        elif colour == 'w':
            colour = None
    if body.startswith('|||||'):
        return None
    if body.startswith('~~~~~'):
        match = re.match(r'(~+)(\d*)', body)
        if len(match.group(1)) > 5 and match.group(2):
            # The game sees no number here (tag 0); take the evident intent.
            warn('tag "%s" has more than five "~"' % body)
        return Line('tag', tag=atoi(match.group(2)))
    if body.startswith('&&&&&'):
        return Line('verbatim', display=body[6::2].rstrip())
    segs = parse_inline(body, colour, warn)
    display = ''.join(seg.text for seg in segs)
    if not display.strip():
        return Line('blank')
    return Line('text', colour, segs, display=display)


def parse_page(lines, warn):
    """Parse lines into Line objects; warn(number, message)."""
    parsed = []
    for number, text in enumerate(lines, 1):
        line = parse_line(text, lambda message, number=number: warn(number, message))
        if line is not None:
            line.number = number
            parsed.append(line)
    return parsed


# --------------------------------------------------------------------------
# Line properties

def leading_spaces(text):
    return len(text) - len(text.lstrip(' '))


def is_rule(line):
    """A line drawn only with characters such as '-', '=' or '/'."""
    text = line.display.strip()
    return (len(text) >= 3 and all(seg.kind == 'text' for seg in line.segs)
            and all(c in RULE_CHARS for c in text))


def has_gap(line):
    return bool(GAP_RE.search(line.display.rstrip()))


def pipe_positions(line):
    """Display columns of the '|' characters of the plain text of a line."""
    positions = []
    pos = 0
    for seg in line.segs:
        if seg.kind == 'text' and not seg.span:
            positions.extend(pos + i for i, c in enumerate(seg.text) if c == '|')
        pos += len(seg.text)
    return positions


def is_pipe_row(line):
    return any(seg.kind == 'text' and not seg.span and ' | ' in seg.text
               for seg in line.segs)


def is_layout(line):
    return has_gap(line) or is_pipe_row(line)


def slice_segs(segs, start, end):
    """The part of segs between display columns start and end."""
    out = []
    pos = 0
    for seg in segs:
        lo, hi = max(pos, start), min(pos + len(seg.text), end)
        if lo < hi:
            out.append(seg._replace(text=seg.text[lo - pos:hi - pos]))
        pos += len(seg.text)
    return out


def strip_segs(segs):
    """Remove the whitespace around plain text at both ends of segs."""
    segs = list(segs)
    while segs and segs[0].kind == 'text' and not segs[0].text.strip():
        segs.pop(0)
    while segs and segs[-1].kind == 'text' and not segs[-1].text.strip():
        segs.pop()
    if segs and segs[0].kind == 'text':
        segs[0] = segs[0]._replace(text=segs[0].text.lstrip())
    if segs and segs[-1].kind == 'text':
        segs[-1] = segs[-1]._replace(text=segs[-1].text.rstrip())
    return segs


def display_of(segs):
    return ''.join(seg.text for seg in segs)


def split_space(text):
    core = text.strip()
    if not core:
        return text, '', ''
    start = text.index(core)
    return text[:start], core, text[start + len(core):]


def output_name(name):
    """Output file of a help file: x.txt -> x.md, x.hlp -> x.hlp.md."""
    if name.endswith('.txt'):
        return name[:-4] + '.md'
    return name + '.md'


# --------------------------------------------------------------------------
# Inline rendering

def escape_markdown(text, line_start=False, heading=False, urls=True):
    """Escape text for Markdown; URLs become <...> autolinks, so that GitHub
    does not take the punctuation after them as part of the link."""
    if urls and TEXT_URL_RE.search(text):
        parts = []
        pos = 0
        for match in TEXT_URL_RE.finditer(text):
            parts.append(escape_markdown(text[pos:match.start()], line_start and pos == 0,
                                         heading, False))
            parts.append('<%s>' % match.group())
            pos = match.end()
        parts.append(escape_markdown(text[pos:], False, heading, False))
        return ''.join(parts)
    out = []
    for i, c in enumerate(text):
        if c in '\\`*[]<|~':
            out.append('\\' + c)
        elif c == '_':
            inner = (0 < i < len(text) - 1 and text[i - 1].isalnum()
                     and text[i + 1].isalnum())
            out.append('_' if inner else '\\_')
        elif c == '$':
            # GitHub would read a pair of '$' as maths; a span prevents it.
            out.append('<span>$</span>')
        elif c == '&' and ENTITY_RE.match(text, i):
            out.append('&amp;')
        elif c == '#' and heading:
            out.append('\\#')
        else:
            out.append(c)
    result = ''.join(out)
    if line_start:
        if result[:1] in ('#', '>', '+', '-', '='):
            result = '\\' + result
        else:
            result = LINE_START_RE.sub(r'\1\\\2', result)
    return result


def escape_tex(text, in_table=False):
    """Escape text for a TeX text box inside $`...`$."""
    out = []
    for c in text:
        if c in '\\{}$':
            out.append('\\' + c)
        elif c == '|' and in_table:
            out.append('\\|')   # unescaped again by the GFM table parser
        else:
            out.append(c)
    return ''.join(out)


def tex_text(colour, text, in_table=False):
    return '$`\\color{%s}{\\textsf{%s}}`$' % (colour, escape_tex(text, in_table))


def tex_glyph(colour, char, in_table=False):
    return '$`\\color{%s}{\\colorbox{black}{%s}}`$' % (colour, escape_tex(char, in_table))


class LinkResolver(object):
    """Turns (page, target, tag) into a relative URL within one help set."""

    def __init__(self, tags):
        self.tags = tags    # page name -> set of tag numbers

    def url(self, page, target, tag, warn):
        if target not in self.tags:
            warn('link to missing page %s; shown as plain text' % target)
            return None
        if tag < 0:
            warn('link to line %d of %s; linking to the top of the page' % (-tag, target))
            tag = 0
        if tag and tag not in self.tags[target]:
            warn('link to %s tag %d: no such tag; linking to the top of the page'
                 % (target, tag))
            tag = 0
        fragment = '#tag-%d' % tag if tag else ''
        if target == page and fragment:
            return fragment
        return output_name(target) + fragment


def page_tags(lines, warn):
    """The tags of a page (the first one wins, as in the game)."""
    tags = set()
    for line in lines:
        if line.kind == 'tag' and line.tag > 0:
            if line.tag in tags:
                warn(line.number, 'duplicate tag %d; links go to the first one' % line.tag)
            tags.add(line.tag)
    return tags


# --------------------------------------------------------------------------
# Page conversion

class Page(object):

    def __init__(self, name, lines, links, warn):
        self.name = name
        self.lines = lines
        self.links = links
        self.warn = warn            # warn(line number, message)
        self.blocks = []
        self.anchors = []
        self.seen_tags = set()
        self.content_seen = False
        self.has_title = False
        self.title = None
        self.number = 0             # line being rendered, for warnings

    # ---- inline

    def line_warn(self, message):
        self.warn(self.number, message)

    def render_text(self, seg, line_start=False, in_table=False, heading=None):
        colour = seg.colour
        if heading is not None and not seg.span and colour == heading:
            colour = None           # the heading itself shows this colour
        lead, core, trail = split_space(seg.text)
        if seg.span and len(core) == 1 and lead == trail == '' and core != '`':
            return tex_glyph(GAME_COLOURS[colour or 'w'], core, in_table)
        if seg.span and URL_RE.match(core):
            return lead + '<' + core + '>' + trail
        hex_colour = TEXT_COLOURS.get(colour)
        if hex_colour and core and '`' in core:
            self.line_warn('cannot colour text containing "`": %s' % core)
            hex_colour = None
        if not hex_colour or not core:
            return escape_markdown(seg.text, line_start, heading is not None)
        return lead + tex_text(hex_colour, core, in_table) + trail

    def render_link(self, seg, line_start=False):
        url = self.links.url(self.name, seg.target, seg.tag, self.line_warn)
        lead, core, trail = split_space(seg.text)
        if url is None:
            return escape_markdown(seg.text, line_start)
        return '%s[%s](%s)%s' % (lead, escape_markdown(core, urls=False), url, trail)

    def render_inline(self, segs, line_start=False, in_table=False, heading=None):
        out = []
        for i, seg in enumerate(segs):
            start = line_start and i == 0
            if seg.kind == 'link':
                out.append(self.render_link(seg, start))
            else:
                out.append(self.render_text(seg, start, in_table, heading))
        return ''.join(out)

    def render_pre_line(self, segs):
        out = []
        for seg in segs:
            url = None
            if seg.kind == 'link':
                url = self.links.url(self.name, seg.target, seg.tag, self.line_warn)
            text = html.escape(seg.text, quote=False)
            out.append('<a href="%s">%s</a>' % (url, text) if url else text)
        return ''.join(out)

    # ---- blocks

    def take_anchors(self):
        anchors = ''.join('<a id="%s"></a>' % a for a in self.anchors)
        self.anchors = []
        return anchors

    def add_block(self, text):
        self.blocks.append(text)
        self.content_seen = True

    def add_tag(self, line):
        if line.tag > 0 and line.tag not in self.seen_tags:
            self.seen_tags.add(line.tag)
            self.anchors.append('tag-%d' % line.tag)

    def convert(self):
        run, screen = [], []
        for line in self.lines:
            if line.kind != 'verbatim' and screen:
                self.emit_screen(screen)
                screen = []
            if line.kind != 'text' and run:
                self.emit_run(run)
                run = []
            if line.kind == 'text':
                run.append(line)
            elif line.kind == 'verbatim':
                screen.append(line)
            elif line.kind == 'tag':
                self.add_tag(line)
        if screen:
            self.emit_screen(screen)
        if run:
            self.emit_run(run)
        if self.anchors:
            self.add_block(self.take_anchors())
        return self.blocks

    def emit_screen(self, lines):
        rows = [line.display for line in lines]
        while rows and not rows[-1]:
            rows.pop()
        self.number = lines[0].number
        self.emit_code(rows, [[text_seg(row)] for row in rows],
                       [line.number for line in lines])

    def emit_code(self, rows, segs_rows, numbers):
        if self.anchors or any(seg.kind == 'link' for segs in segs_rows for seg in segs):
            lines = []
            for number, segs in zip(numbers, segs_rows):
                self.number = number
                lines.append(self.render_pre_line(segs))
            self.add_block('<pre>%s%s</pre>' % (self.take_anchors(), '\n'.join(lines)))
            return
        longest = max([len(m) for row in rows for m in re.findall('`+', row)] or [0])
        fence = '`' * max(3, longest + 1)
        self.add_block('%stext\n%s\n%s' % (fence, '\n'.join(rows), fence))

    def emit_run(self, run):
        """Emit a run of consecutive text lines: headings and content."""
        content = []
        i = 0
        while i < len(run):
            level = HEADING_LEVELS.get(run[i].colour)
            if level:
                j = i
                while j < len(run) and run[j].colour == run[i].colour:
                    j += 1
                colour = run[i].colour
                heading = self.find_heading(run[i:j], run[j] if j < len(run) else None)
                if (heading is None and j + 1 == len(run) and run[j].colour
                        and all(is_rule(line) for line in run[i:j])):
                    # A title rule over a lone line in another colour.
                    heading = self.find_heading(run[j:], None)
                    if heading:
                        heading = (heading[0], j + 1 - i)
                        colour = run[j].colour
                        j += 1
                if heading:
                    segs, used = heading
                    self.emit_content(content)
                    content = []
                    self.emit_heading(level, segs, colour, run[i].number)
                    content.extend(run[i + used:j])
                else:
                    content.extend(run[i:j])
                i = j
            else:
                content.append(run[i])
                i += 1
        self.emit_content(content)

    def find_heading(self, group, after):
        """Return (segments, lines used) if a group of title-coloured lines
        starts with a title: text between rules or decorated like
        '=== Title ===', or a short text on its own.  A long title may
        continue on the next lines."""
        k = 0
        while k < len(group) and is_rule(group[k]):
            k += 1
        if k == len(group):
            return None
        heads = [group[k]]
        while (k + len(heads) < len(group) and not is_rule(group[k + len(heads)])
               and len(heads[-1].display.strip()) >= 60):
            heads.append(group[k + len(heads)])
        used = k + len(heads)
        while used < len(group) and is_rule(group[used]):
            used += 1
        segs = []
        decorated = k > 0 or used > k + len(heads)     # rules around the title
        for line in heads:
            display = line.display
            lead = LEAD_DECORATION_RE.match(display).end()
            trail = TRAIL_DECORATION_RE.search(display, lead).start()
            decorated = decorated or bool(display[:lead].strip() or display[trail:].strip())
            if segs:
                segs.append(text_seg(' '))
            segs.extend(slice_segs(line.segs, lead, max(lead, trail)))
        text = ' '.join(display_of(segs).split())
        if not text:
            return None
        follower = group[k + 1] if k + 1 < len(group) else after
        if has_gap(heads[0]) and follower is not None and (
                is_layout(follower) or (is_rule(follower) and follower.colour is None)):
            return None     # the header of a table
        if not decorated:
            if len(heads) == 1 and (len(text) > 60 or text.endswith(',')):
                return None
            if len(text) > 160 or re.search(r'[.!]\s+[A-Z]', text):
                return None     # coloured prose, not a title
        return segs, used

    def emit_heading(self, level, segs, colour, number):
        self.number = number
        if level == 2 and not self.content_seen and not self.has_title:
            level = 1
        self.has_title = self.has_title or level == 1
        segs = strip_segs([seg._replace(text=re.sub(r'\s+', ' ', seg.text))
                           if seg.kind == 'text' else seg for seg in segs])
        if self.title is None:
            self.title = display_of(segs)
        # Not add_block(): a heading does not end the page's title area.
        self.blocks.append('%s %s%s' % ('#' * level, self.take_anchors(),
                                        self.render_inline(segs, heading=colour)))

    def emit_content(self, lines):
        """Split non-heading lines into column layouts and prose."""
        if not lines:
            return
        n = len(lines)
        candidate = [is_layout(line) for line in lines]
        layout = list(candidate)
        # Short lines between layout lines are rows with empty cells.
        i = 0
        while i < n:
            j = i
            while j < n and not layout[j]:
                j += 1
            if 0 < i < j < n and j - i <= 2 and all(
                    is_rule(line) or len(line.display.strip()) <= 40 for line in lines[i:j]):
                layout[i:j] = [True] * (j - i)
            i = j + 1
        # Rules next to layout lines are its borders.
        for i in list(range(n)) + list(reversed(range(n))):
            if not layout[i] and is_rule(lines[i]) and (
                    (i > 0 and layout[i - 1]) or (i + 1 < n and layout[i + 1])):
                layout[i] = True
        runs = []
        i = 0
        while i < n:
            j = i
            while j < n and layout[j]:
                j += 1
            if sum(candidate[i:j]) >= 2 and table_columns(lines[i:j]):
                runs.append([i, j])
            i = j + 1
        # Lone entries next to a layout that fit its columns belong to it.
        for k, run in enumerate(runs):
            low = runs[k - 1][1] if k else 0
            high = runs[k + 1][0] if k + 1 < len(runs) else n
            while run[0] > low and fits_columns(lines[run[0] - 1], lines[run[0]:run[1]]):
                run[0] -= 1
            while run[1] < high and fits_columns(lines[run[1]], lines[run[0]:run[1]]):
                run[1] += 1
        pos = 0
        for start, end in runs:
            self.emit_prose(lines[pos:start])
            self.emit_layout(lines[start:end])
            pos = end
        self.emit_prose(lines[pos:])

    def emit_layout(self, lines):
        """Emit a column layout as a table, or as a code block."""
        self.number = lines[0].number
        rows = [line for line in lines if not is_rule(line)]
        columns = table_columns(rows)
        table = columns and self.make_table(lines, rows, list(columns))
        if table:
            self.add_block(table)
            return
        indent = min(leading_spaces(line.display) for line in lines)
        segs_rows = [slice_segs(line.segs, indent, len(line.display)) for line in lines]
        rows = [display_of(segs).rstrip() for segs in segs_rows]
        self.emit_code(rows, segs_rows, [line.number for line in lines])

    def make_table(self, lines, rows, columns):
        if len(rows) < 2:
            return None
        first = lines.index(rows[0])
        coloured_header = rows[0].colour is not None and any(
            row.colour != rows[0].colour for row in rows[1:])
        ruled_header = first + 1 < len(lines) and is_rule(lines[first + 1])
        header = rows[0] if coloured_header or ruled_header else None
        cells = [[strip_segs(slice_segs(row.segs, start, end)) for start, end in columns]
                 for row in rows]
        # Merge neighbouring columns that are never both filled (ragged layouts).
        i = 0
        while i + 1 < len(columns):
            if any(row[i] and row[i + 1] for row in cells):
                i += 1
                continue
            columns[i:i + 2] = [(columns[i][0], columns[i + 1][1])]
            for row in cells:
                row[i:i + 2] = [row[i] or row[i + 1]]
        texts = [display_of(cell) for row in cells for cell in row]
        if all(len(text) <= 1 for text in texts):
            return None     # a diagram, not a table
        indents = [leading_spaces(row.display[columns[0][0]:]) for row in rows
                   if row.display[columns[0][0]:columns[0][1]].strip()]
        base = min(indents) if indents else 0

        def render_row(row, row_cells, is_header):
            self.number = row.number
            out = []
            for i, cell in enumerate(row_cells):
                text = self.render_inline(cell, in_table=True,
                                          heading=row.colour if is_header else None).strip()
                if i == 0 and cell:
                    depth = leading_spaces(row.display[columns[0][0]:]) - base
                    text = '&nbsp;' * max(0, depth) + text
                out.append(text)
            return out

        if header is not None:
            head = render_row(header, cells[0], True)
            body = [render_row(row, row_cells, False)
                    for row, row_cells in zip(rows[1:], cells[1:])]
        else:
            head = [' '] * len(columns)
            body = [render_row(row, row_cells, False) for row, row_cells in zip(rows, cells)]
        head[0] = self.take_anchors() + head[0]
        out = ['| %s |' % ' | '.join(head), '| %s |' % ' | '.join(['---'] * len(columns))]
        out.extend('| %s |' % ' | '.join(row) for row in body)
        return '\n'.join(out)

    def emit_prose(self, lines):
        chunk = []
        for line in lines:
            if is_rule(line):
                self.emit_paragraph(chunk)
                chunk = []
                self.add_block('---')
            else:
                chunk.append(line)
        self.emit_paragraph(chunk)

    def emit_paragraph(self, lines):
        if not lines:
            return
        indent = min(leading_spaces(line.display) for line in lines)
        soft = [soft_break(prev, line, indent) for prev, line in zip(lines, lines[1:])]
        rendered = []
        for i, line in enumerate(lines):
            self.number = line.number
            depth = leading_spaces(line.display) - indent
            if i == 0 and len(lines) > 1 and (soft[0] or all(
                    leading_spaces(other.display) == indent for other in lines[1:])):
                depth = 0       # the indented first line of a paragraph
            elif i > 0 and soft[i - 1]:
                depth = 0       # a continued line
            segs = strip_segs(slice_segs(line.segs, indent, len(line.display)))
            rendered.append('&nbsp;' * depth
                            + self.render_inline(segs, line_start=depth == 0).rstrip())
        text = self.take_anchors() + rendered[0]
        for is_soft, line_text in zip(soft, rendered[1:]):
            text += ('\n' if is_soft else '\\\n') + line_text
        self.add_block(text)


def soft_break(prev, line, indent):
    """True if prev was wrapped only because the next word did not fit."""
    if prev.colour or line.colour or is_entry(prev) or is_entry(line):
        return False
    if leading_spaces(line.display) not in (indent, leading_spaces(prev.display)):
        return False
    if prev.display.rstrip().endswith(':'):
        return False
    stripped = line.display.strip()
    if LIST_RE.match(stripped):
        return False
    width = len(prev.display.rstrip()) + 1 + len(stripped.split()[0])
    if width > WRAP_FULL:
        return True
    return width > WRAP_SOFT and not (SENTENCE_END_RE.search(prev.display.rstrip())
                                      and SENTENCE_START_RE.match(stripped))


def is_entry(line):
    """A line that is just one link, like the entries of a menu."""
    segs = strip_segs(line.segs)
    return len(segs) == 1 and segs[0].kind == 'link'


def pipe_columns(rows):
    """Columns separated by '|' at the same position in every row."""
    positions = [pipe_positions(row) for row in rows]
    if not positions[0] or any(p != positions[0] for p in positions):
        return None
    width = max(len(row.display) for row in rows)
    edges = [-1] + positions[0] + [width]
    return [(edges[i] + 1, edges[i + 1]) for i in range(len(edges) - 1)]


Token = collections.namedtuple('Token', 'start end atomic text')


def row_tokens(row):
    """The words, links and coloured spans of a row, by display column."""
    tokens = []
    pos = 0
    for seg in row.segs:
        if seg.kind == 'link' or seg.span:
            if seg.text:
                tokens.append(Token(pos, pos + len(seg.text), True, seg.text))
        else:
            tokens.extend(Token(pos + m.start(), pos + m.end(), False, m.group())
                          for m in re.finditer(r'\S+', seg.text))
        pos += len(seg.text)
    return tokens


def gutter_columns(rows):
    """Find columns from the blank space between them.

    A column boundary never cuts a word, a link or coloured text.  It must be
    at least two characters wide, except in a minority of rows, and there
    only next to a link or coloured text, or before a number (entries that
    fill their column).
    """
    tokens = [row_tokens(row) for row in rows]
    every = [token for row in tokens for token in row]
    if not every:
        return None
    first = min(token.start for token in every)
    last = max(token.end for token in every)
    # cut[p]: no token runs across the line between columns p - 1 and p;
    # blank[p]: no token covers column p.
    cut = [True] * (last + 1)
    blank = [True] * (last + 1)
    for token in every:
        for p in range(token.start, token.end):
            blank[p] = False
            if p > token.start:
                cut[p] = False
    columns = []
    start = first
    p = first + 1
    while p < last:
        if not cut[p]:
            p += 1
            continue
        gap = p
        while p < last and blank[p] and cut[p + 1]:
            p += 1
        if p - gap >= 2 or narrow_gap_ok(tokens, gap, p):
            columns.append((start, gap))
            start = p
        p += 1
    columns.append((start, last))
    return columns if len(columns) >= 2 else None


def narrow_gap_ok(tokens, left, right):
    """May the narrow gap between columns left and right separate columns?"""
    tight = spaced = 0
    for row in tokens:
        before = [t for t in row if t.end <= left]
        after = [t for t in row if t.start >= right]
        if not before or not after:
            continue
        a = max(before, key=lambda t: t.end)
        b = min(after, key=lambda t: t.start)
        if b.start - a.end >= 2:
            spaced += 1
            continue
        tight += 1
        if not (a.atomic or b.atomic or NUMBER_RE.match(b.text)):
            return False
    return tight < spaced


def table_columns(rows):
    rows = [row for row in rows if not is_rule(row)]
    if len(rows) < 2:
        return None
    return pipe_columns(rows) or gutter_columns(rows)


def fits_columns(line, rows):
    """True if a short line (or one of links only) is a row of the layout:
    indented to one of its columns, or lined up with two of them."""
    if line.kind != 'text' or is_rule(line):
        return False
    links_only = all(seg.kind == 'link' or not seg.text.strip() for seg in line.segs)
    if len(line.display.strip()) > 40 and not links_only:
        return False
    columns = table_columns(rows)
    if not columns:
        return False
    starts = [start for start, _ in columns]
    aligned = len(set(starts) & set(token.start for token in row_tokens(line)))
    indent = leading_spaces(line.display)
    if aligned < (1 if indent and indent in starts else 2):
        return False
    widened = table_columns(list(rows) + [line])
    return bool(widened) and [s for s, _ in widened] == starts


# --------------------------------------------------------------------------
# Help sets

def convert_set(sources, src_dir, out_dir='doc/help', title='ToME help'):
    """Convert one help set.

    sources maps file names to their contents (bytes).  Returns
    (outputs, warnings): outputs maps output file names to Markdown text,
    warnings is a sorted list of messages.
    """
    found = []

    def warner(name):
        return lambda number, message: found.append((name, number, message))

    pages = sorted((name for name in sources if name.endswith(PAGE_SUFFIXES)),
                   key=lambda name: (name.lower(), name))
    for name in sorted(sources):
        if name not in pages and name not in NON_PAGES:
            found.append((name, 0, 'not a help page; skipped'))
    parsed = {}
    tags = {}
    for name in pages:
        parsed[name] = parse_page(read_lines(sources[name]), warner(name))
        tags[name] = page_tags(parsed[name], warner(name))
    links = LinkResolver(tags)
    outputs = {}
    titles = {}
    for name in pages:
        page = Page(name, parsed[name], links, warner(name))
        blocks = page.convert()
        header = ('<!-- Generated from %s/%s by %s; do not edit. -->'
                  % (src_dir, name, SCRIPT))
        outputs[output_name(name)] = '\n\n'.join([header] + blocks) + '\n'
        titles[name] = page.title or name
    if len(outputs) != len(pages) or INDEX_NAME in outputs:
        raise ValueError('output file names collide in %s' % src_dir)
    outputs[INDEX_NAME] = render_index(pages, titles, src_dir, out_dir, title)
    warnings = ['%s/%s:%d: %s' % (src_dir, name, number, message) if number
                else '%s/%s: %s' % (src_dir, name, message)
                for name, number, message in sorted(set(found))]
    return outputs, warnings


def render_index(pages, titles, src_dir, out_dir, title):
    up = posixpath.relpath('.', out_dir)
    start = []
    if 'help.hlp' in pages:
        start.append('the [main menu](%s)' % output_name('help.hlp'))
    if 'index.txt' in pages:
        start.append('the [alphabetical index](%s)' % output_name('index.txt'))
    lines = [
        '<!-- Generated by %s; do not edit. -->' % SCRIPT,
        '',
        '# %s' % title,
        '',
        'The help that the game shows when you press `?`, converted to Markdown.',
    ]
    if start:
        lines[-1] += ' Start with %s.' % ' or '.join(start)
    lines += [
        '',
        'These pages are generated from [%s](%s/%s) by [%s](%s/%s).'
        % (src_dir, up, src_dir, SCRIPT, up, SCRIPT),
        'To change them, edit the help files and run the script again.',
        '',
        '| Page | Help file |',
        '| --- | --- |',
    ]
    for name in pages:
        lines.append('| [%s](%s) | [%s](%s/%s/%s) |'
                     % (escape_markdown(titles[name]), output_name(name),
                        escape_markdown(name), up, src_dir, name))
    return '\n'.join(lines) + '\n'


def repo_root():
    return os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read_sources(root, src_dir):
    directory = os.path.join(root, src_dir)
    sources = {}
    for name in sorted(os.listdir(directory)):
        path = os.path.join(directory, name)
        if os.path.isfile(path):
            with open(path, 'rb') as f:
                sources[name] = f.read()
    return sources


def render_all(root):
    """Return ({path: text} for every output file, [warnings])."""
    files = {}
    warnings = []
    for title, src_dir, out_dir in HELP_SETS:
        outputs, set_warnings = convert_set(read_sources(root, src_dir), src_dir,
                                            out_dir, title)
        files.update((posixpath.join(out_dir, name), text)
                     for name, text in outputs.items())
        warnings.extend(set_warnings)
    return files, warnings


def existing_outputs(root):
    """{path: text} for the Markdown files now in the output directories."""
    files = {}
    for _, _, out_dir in HELP_SETS:
        directory = os.path.join(root, out_dir)
        if not os.path.isdir(directory):
            continue
        for name in sorted(os.listdir(directory)):
            path = os.path.join(directory, name)
            if name.endswith('.md') and os.path.isfile(path):
                with open(path, 'rb') as f:
                    files[posixpath.join(out_dir, name)] = f.read().decode('utf-8')
    return files


def stale_outputs(root):
    """Output files that are missing, different or no longer generated."""
    wanted, _ = render_all(root)
    present = existing_outputs(root)
    return sorted(path for path in set(wanted) | set(present)
                  if wanted.get(path) != present.get(path))


def write_outputs(root, files):
    for path in sorted(files):
        full = os.path.join(root, path)
        directory = os.path.dirname(full)
        if not os.path.isdir(directory):
            os.makedirs(directory)
        with open(full, 'wb') as f:
            f.write(files[path].encode('utf-8'))
    for path in existing_outputs(root):
        if path not in files:
            os.remove(os.path.join(root, path))


# --------------------------------------------------------------------------
# Checking the whole output

LINK_RE = re.compile(r'(?<!\\)\]\(([^()\s]*)\)|href="([^"]*)"')
ID_RE = re.compile(r'<a id="([^"]*)"></a>')
TEX_RE = re.compile(r'\$`(.*?)`\$')
FENCE_RE = re.compile(r'^(`{3,}).*?^\1$', re.M | re.S)


def tex_balanced(tex):
    depth = 0
    i = 0
    while i < len(tex):
        if tex[i] == '\\':
            i += 2
            continue
        if tex[i] == '{':
            depth += 1
        elif tex[i] == '}':
            depth -= 1
            if depth < 0:
                return False
        i += 1
    return depth == 0


def check_tree(tree, sources, set_dirs, exists):
    """Check generated Markdown.

    tree maps output paths to their text, sources maps each source directory
    to its file names, set_dirs maps source to output directories, and
    exists(path) tells whether a path outside tree exists.  Returns
    (problems, statistics).
    """
    problems = []
    stats = {'pages': 0, 'files': len(tree), 'links': 0, 'anchors': 0}
    for src_dir in sorted(sources):
        out_dir = set_dirs[src_dir]
        expected = {INDEX_NAME}
        for name in sorted(sources[src_dir]):
            if name.endswith(PAGE_SUFFIXES):
                expected.add(output_name(name))
                if posixpath.join(out_dir, output_name(name)) in tree:
                    stats['pages'] += 1
                else:
                    problems.append('%s/%s: no output file %s/%s'
                                    % (src_dir, name, out_dir, output_name(name)))
            elif name not in NON_PAGES:
                problems.append('%s/%s: not a help page (*.txt, *.hlp) and not in NON_PAGES'
                                % (src_dir, name))
        if posixpath.join(out_dir, INDEX_NAME) not in tree:
            problems.append('%s: no %s' % (out_dir, INDEX_NAME))
        for path in sorted(tree):
            directory, name = posixpath.split(path)
            if directory == out_dir and name not in expected:
                problems.append('%s: no help file generates this file' % path)

    ids = {}
    for path, text in tree.items():
        found = ID_RE.findall(text)
        ids[path] = set(found)
        stats['anchors'] += len(found)
        for anchor in sorted(set(a for a in found if found.count(a) > 1)):
            problems.append('%s: duplicate anchor %s' % (path, anchor))

    for path in sorted(tree):
        text = tree[path]
        prose = FENCE_RE.sub('', text)
        for match in LINK_RE.finditer(prose):
            target = match.group(1) if match.group(1) is not None else match.group(2)
            if re.match(r'[A-Za-z][A-Za-z0-9+.-]*:', target):
                continue        # external
            stats['links'] += 1
            page, _, fragment = target.partition('#')
            resolved = (posixpath.normpath(posixpath.join(posixpath.dirname(path), page))
                        if page else path)
            if resolved in tree:
                if fragment and fragment not in ids[resolved]:
                    problems.append('%s: link to missing anchor %s' % (path, target))
            elif not exists(resolved):
                problems.append('%s: link to missing file %s' % (path, target))
        unescaped = re.sub(r'\\(.)', r'\1', text)
        for marker in MARKERS:
            if marker in unescaped:
                problems.append('%s: help markup "%s" left in the output' % (path, marker))
        for number, line in enumerate(text.split('\n'), 1):
            spans = TEX_RE.findall(line)
            if line.count('$`') != len(spans) or not all(map(tex_balanced, spans)):
                problems.append('%s:%d: malformed LaTeX' % (path, number))
    return problems, stats


def check_repo(root):
    """Check the Markdown files on disk; returns (problems, statistics)."""
    tree = existing_outputs(root)
    sources = {}
    set_dirs = {}
    for _, src_dir, out_dir in HELP_SETS:
        directory = os.path.join(root, src_dir)
        sources[src_dir] = sorted(name for name in os.listdir(directory)
                                  if os.path.isfile(os.path.join(directory, name)))
        set_dirs[src_dir] = out_dir
    return check_tree(tree, sources, set_dirs,
                      lambda path: os.path.exists(os.path.join(root, path)))


# --------------------------------------------------------------------------

def main(argv=None):
    parser = argparse.ArgumentParser(
        description='Convert lib/help and lib/mods/theme/help to Markdown in doc/help.')
    parser.add_argument('--check', action='store_true',
                        help='check that doc/help is up to date and its links work; '
                             'write nothing')
    args = parser.parse_args(argv)
    root = repo_root()
    if args.check:
        stale = stale_outputs(root)
        problems, stats = check_repo(root)
        for path in stale:
            print('%s: out of date; run %s' % (path, SCRIPT))
        for problem in problems:
            print(problem)
        print('Checked %(files)d files (%(pages)d help pages), %(links)d links, '
              '%(anchors)d anchors.' % stats)
        return 1 if stale or problems else 0
    files, warnings = render_all(root)
    write_outputs(root, files)
    for warning in warnings:
        print('warning: %s' % warning, file=sys.stderr)
    print('Wrote %d files.' % len(files))
    return 0


if __name__ == '__main__':
    sys.exit(main())
