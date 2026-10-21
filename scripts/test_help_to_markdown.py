#!/usr/bin/env python3
"""Unit tests for help_to_markdown.py (standard library only).

Run with:  python3 -m unittest discover -s scripts -p 'test_*.py'
"""

import os
import random
import sys
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import help_to_markdown as h2m  # noqa: E402


def convert(text, name='page.txt', others=None):
    """Convert one page (given as str) and return (markdown, warnings)."""
    sources = {name: text.encode('latin-1')}
    for other, body in (others or {}).items():
        sources[other] = body.encode('latin-1')
    outputs, warnings = h2m.convert_set(sources, 'lib/help')
    return outputs[h2m.output_name(name)], warnings


def body(text, **kwargs):
    """Converted page without the generated-file header comment."""
    md, _ = convert(text, **kwargs)
    header, _, rest = md.partition('\n\n')
    assert header.startswith('<!--'), header
    return rest


def tex(colour, text):
    return '$`\\color{%s}{\\textsf{%s}}`$' % (colour, text)


class ReadLinesTest(unittest.TestCase):
    """my_fgets() semantics: line endings, tabs, unprintable characters."""

    def test_line_endings(self):
        self.assertEqual(h2m.read_lines(b'a\nb\r\nc\rd\n\re'),
                         ['a', 'b', 'c', 'd', 'e'])

    def test_no_final_newline(self):
        self.assertEqual(h2m.read_lines(b'a\nb'), ['a', 'b'])
        self.assertEqual(h2m.read_lines(b'a\n'), ['a'])

    def test_tabs_expand_to_eight_columns_of_the_raw_line(self):
        self.assertEqual(h2m.read_lines(b'ab\tc'), ['ab      c'])
        # Tab stops count the colour prefix too, as in the game.
        self.assertEqual(h2m.read_lines(b'#####Gab\tc'), ['#####Gab        c'])

    def test_control_characters_are_dropped(self):
        self.assertEqual(h2m.read_lines(b'a\x01b\x7fc'), ['abc'])

    def test_latin1_is_decoded(self):
        self.assertEqual(h2m.read_lines(b'Pietil\xe4'), ['Pietil\u00e4'])


class ParseLineTest(unittest.TestCase):

    def test_plain(self):
        line = h2m.parse_line('hello')
        self.assertEqual(line.kind, 'text')
        self.assertIsNone(line.colour)
        self.assertEqual(line.display, 'hello')

    def test_colour_prefix(self):
        line = h2m.parse_line('#####Rtitle')
        self.assertEqual(line.colour, 'R')
        self.assertEqual(line.display, 'title')

    def test_white_is_the_default_colour(self):
        self.assertIsNone(h2m.parse_line('#####wplain').colour)

    def test_empty_colour_lines_are_blank(self):
        self.assertEqual(h2m.parse_line('#####B').kind, 'blank')
        self.assertEqual(h2m.parse_line('#####').kind, 'blank')
        self.assertEqual(h2m.parse_line('    ').kind, 'blank')

    def test_link_colour_definition_is_dropped(self):
        self.assertIsNone(h2m.parse_line('|||||oy'))
        self.assertIsNone(h2m.parse_line('#####R|||||oy'))

    def test_tag(self):
        line = h2m.parse_line('~~~~~07|Options|Ingame')
        self.assertEqual((line.kind, line.tag), ('tag', 7))
        self.assertEqual(h2m.parse_line('~~~~~9 ').tag, 9)
        self.assertEqual(h2m.parse_line('~~~~~|x').tag, 0)

    def test_tag_with_extra_tilde_is_accepted(self):
        # lib/help/g_eru.txt has "~~~~~~03"; the game reads it as tag 0.
        line = h2m.parse_line('~~~~~~03|Eru|Prayers')
        self.assertEqual(line.tag, 3)

    def test_verbatim_line_keeps_characters_and_drops_colours(self):
        line = h2m.parse_line('&&&&&B/B-wxRy')
        self.assertEqual((line.kind, line.display), ('verbatim', '/-xy'))
        # A dangling colour character is ignored.
        self.assertEqual(h2m.parse_line('&&&&&BaB').display, 'a')

    def test_link(self):
        segs = h2m.parse_line('see *****skills.txt*34[Nature] now').segs
        self.assertEqual([s.kind for s in segs], ['text', 'link', 'text'])
        link = segs[1]
        self.assertEqual((link.target, link.tag, link.text),
                         ('skills.txt', 34, 'Nature'))

    def test_link_with_key_prefix(self):
        link = h2m.parse_line('*****/ageneral.txt*0[(a) About]').segs[0]
        self.assertEqual((link.target, link.tag, link.text),
                         ('general.txt', 0, '(a) About'))

    def test_link_label_escapes(self):
        line = h2m.parse_line(r'*****c.txt*98[^\]  Dump] and *****c.txt*79[\\ key]')
        self.assertEqual(line.display, '^]  Dump and \\ key')

    def test_colour_span(self):
        segs = h2m.parse_line(r'a [[[[[Bblue \] text] b').segs
        self.assertEqual([(s.text, s.colour) for s in segs],
                         [('a ', None), ('blue ] text', 'B'), (' b', None)])
        self.assertTrue(segs[1].span)

    def test_span_inherits_nothing_from_line_colour(self):
        segs = h2m.parse_line('#####Gx [[[[[Ry] z').segs
        self.assertEqual([(s.text, s.colour) for s in segs],
                         [('x ', 'G'), ('y', 'R'), (' z', 'G')])

    def test_html_removal(self):
        self.assertEqual(h2m.parse_line('{{{{{<p>}Attacking').display,
                         'Attacking')

    def test_unterminated_markup_does_not_crash(self):
        warnings = []
        line = h2m.parse_line('x *****nolabel', warnings.append)
        self.assertEqual(line.display, 'x *****nolabel')
        line = h2m.parse_line('*****a.txt*0[open label', warnings.append)
        self.assertEqual(line.display, 'open label')
        line = h2m.parse_line('[[[[[Gopen span', warnings.append)
        self.assertEqual(line.display, 'open span')
        self.assertEqual(len(warnings), 3)


class EdgeCaseTest(unittest.TestCase):

    def test_unknown_colours_are_ignored_with_a_warning(self):
        md, warnings = convert('#####Qodd line\nand [[[[[Qodd span]\n')
        self.assertTrue(md.endswith('odd line\\\nand odd span\n'), md)
        self.assertEqual(len(warnings), 2)

    def test_link_with_a_negative_number_goes_to_the_top(self):
        md, warnings = convert('*****page.txt*-5[x]\n')
        self.assertIn('[x](page.md)', md)
        self.assertTrue(any('line 5' in w for w in warnings))

    def test_link_without_text_is_invisible(self):
        md, warnings = convert('see *****other.txt*0[] here\n', others={'other.txt': 'x\n'})
        self.assertTrue(md.endswith('\nsee  here\n'), md)
        self.assertTrue(any('no text' in w for w in warnings))

    def test_empty_file(self):
        md, warnings = convert('')
        self.assertTrue(md.startswith('<!--') and md.endswith('-->\n'), md)
        self.assertEqual(warnings, [])

    def test_files_that_are_not_pages(self):
        outputs, warnings = h2m.convert_set({'a.txt': b'x\n', 'head.aux': b'<html>\n',
                                             'notes.doc': b'?\n'}, 'lib/help')
        self.assertEqual(sorted(outputs), ['README.md', 'a.md'])
        self.assertEqual(warnings, ['lib/help/notes.doc: not a help page; skipped'])


class InlineTest(unittest.TestCase):

    def test_markdown_characters_are_escaped(self):
        self.assertEqual(body('a*b*c [x] <y> `z` |p| ~q~ \\ _u_ snake_case\n'),
                         'a\\*b\\*c \\[x\\] \\<y> \\`z\\` \\|p\\| \\~q\\~ \\\\ '
                         '\\_u\\_ snake_case\n')

    def test_urls_get_explicit_boundaries(self):
        self.assertEqual(body('Home Page ("http://www.phial.com/")\nwas created.\n'),
                         'Home Page ("<http://www.phial.com/>")\\\nwas created.\n')
        self.assertEqual(body('Try http://wiki.t-o-m-e.net . We also\n'),
                         'Try <http://wiki.t-o-m-e.net> . We also\n')

    def test_dollar_cannot_start_maths(self):
        self.assertEqual(body('costs $5 or $6\n'),
                         'costs <span>$</span>5 or <span>$</span>6\n')

    def test_entity_like_text_is_escaped(self):
        self.assertEqual(body('AT&T &amp; co\n'), 'AT&T &amp;amp; co\n')

    def test_block_syntax_at_line_start_is_escaped(self):
        self.assertEqual(body('# a\n- b\n+ c\n> d\n1. e\n2) f\n'),
                         '\\# a\\\n\\- b\\\n\\+ c\\\n\\> d\\\n1\\. e\\\n2\\) f\n')

    def test_coloured_text_uses_latex(self):
        self.assertEqual(body('a [[[[[Bblue] b\n'),
                         'a ' + tex('#00A5A5', 'blue') + ' b\n')

    def test_latex_special_characters(self):
        self.assertEqual(body('[[[[[v{a} \\\\ $5 50% #1 ^_~&]\n'),
                         tex('#FF00FF', '\\{a\\} \\\\ \\$5 50% #1 ^_~&') + '\n')

    def test_coloured_whitespace_stays_outside_latex(self):
        self.assertEqual(body('x[[[[[o  pad  ]y\n'),
                         'x  ' + tex('#E87400', 'pad') + '  y\n')

    def test_default_colour_is_not_coloured(self):
        self.assertEqual(body('[[[[[wplain] text\n'), 'plain text\n')

    def test_backtick_cannot_be_put_in_latex(self):
        md, warnings = convert('[[[[[Ba`b]\n')
        self.assertIn('a\\`b', md)
        self.assertNotIn('\\color', md)
        self.assertTrue(warnings)

    def test_single_character_span_is_a_glyph_on_black(self):
        self.assertEqual(body('[[[[[y;] A glyph of warding\n'),
                         '$`\\color{#FFFF00}{\\colorbox{black}{;}}`$ '
                         'A glyph of warding\n')
        # Explicit white glyphs are shown, but white on black.
        self.assertIn('\\color{#FFFFFF}{\\colorbox{black}{#}}', body('[[[[[w#]\n'))

    def test_url_in_coloured_span_stays_a_link(self):
        self.assertEqual(body('try [[[[[ghttp://example.com/a.html]\n'),
                         'try <http://example.com/a.html>\n')

    def test_whole_coloured_line(self):
        self.assertEqual(body('#####UPrereq: Nature skill@20\n'),
                         tex('#C08040', 'Prereq: Nature skill@20') + '\n')

    def test_links_inside_coloured_line_are_plain_links(self):
        self.assertEqual(
            body('#####Bsee *****page.txt*0[here] now\n'),
            tex('#00A5A5', 'see') + ' [here](page.md) ' + tex('#00A5A5', 'now') + '\n')


class LinkTest(unittest.TestCase):

    OTHERS = {
        'other.txt': '~~~~~05|Other\nx\n',
        'menu.hlp': 'menu\n',
    }

    def test_link_to_page(self):
        self.assertEqual(body('*****other.txt*0[Other]\n', others=self.OTHERS),
                         '[Other](other.md)\n')

    def test_link_to_anchor_on_other_page(self):
        self.assertEqual(body('*****other.txt*05[Other]\n', others=self.OTHERS),
                         '[Other](other.md#tag-5)\n')

    def test_link_to_anchor_on_same_page(self):
        self.assertEqual(body('*****page.txt*3[down]\n~~~~~3\nthere\n'),
                         '[down](#tag-3)\n\n<a id="tag-3"></a>there\n')

    def test_link_to_menu_page(self):
        self.assertEqual(body('*****/zmenu.hlp*0[(z) Menu]\n', others=self.OTHERS),
                         '[(z) Menu](menu.hlp.md)\n')

    def test_missing_anchor_links_to_page_top(self):
        md, warnings = convert('*****other.txt*9[Other]\n', others=self.OTHERS)
        self.assertIn('[Other](other.md)', md)
        self.assertTrue(any('tag 9' in w for w in warnings))

    def test_missing_page_becomes_plain_text(self):
        md, warnings = convert('*****gone.txt*0[Gone] x\n')
        self.assertIn('Gone x', md)
        self.assertNotIn('](', md)
        self.assertTrue(any('gone.txt' in w for w in warnings))

    def test_link_label_whitespace_moves_outside(self):
        self.assertEqual(body('[*****page.txt*0[  Steal]\n'),
                         '\\[  [Steal](page.md)\n')


class AnchorTest(unittest.TestCase):

    def test_anchor_attaches_to_heading(self):
        self.assertEqual(body('~~~~~01|A\n~~~~~02|B\n#####R=== Title ===\ntext\n'),
                         '# <a id="tag-1"></a><a id="tag-2"></a>Title\n\ntext\n')

    def test_tag_line_separates_paragraphs(self):
        self.assertEqual(body('one\n~~~~~4\ntwo\n'),
                         'one\n\n<a id="tag-4"></a>two\n')

    def test_duplicate_tag_first_wins(self):
        md, warnings = convert('~~~~~4\none\n~~~~~4\ntwo\n')
        self.assertEqual(md.count('id="tag-4"'), 1)
        self.assertIn('<a id="tag-4"></a>one', md)
        self.assertTrue(warnings)

    def test_tag_zero_is_not_an_anchor(self):
        self.assertEqual(body('~~~~~|label\ntext\n'), 'text\n')

    def test_anchor_at_end_of_file(self):
        self.assertEqual(body('text\n~~~~~8\n'), 'text\n\n<a id="tag-8"></a>\n')

    def test_anchor_on_code_block_uses_pre(self):
        self.assertEqual(body('~~~~~2\n&&&&&wa\n&&&&&w<\n'),
                         '<pre><a id="tag-2"></a>a\n&lt;</pre>\n')


class HeadingTest(unittest.TestCase):

    def test_first_red_heading_is_the_title(self):
        self.assertEqual(body('#####R=== One ===\n\n#####R=== Two ===\n'),
                         '# One\n\n## Two\n')

    def test_red_heading_after_content_is_level_two(self):
        self.assertEqual(body('text\n\n#####R=== Two ===\n'),
                         'text\n\n## Two\n')

    def test_underlined_heading(self):
        self.assertEqual(body('#####RWelcome.\n#####R=========\n\nx\n'),
                         '# Welcome.\n\nx\n')

    def test_banner_heading(self):
        self.assertEqual(body('#####R  /------\\\n#####R <  Box  >\n#####R  \\------/\n'),
                         '# Box\n')

    def test_green_heading(self):
        self.assertEqual(body('#####GDescription\nSome text.\n'),
                         '### Description\n\nSome text.\n')

    def test_ruled_green_heading(self):
        self.assertEqual(body('#####G-------\n#####G1.1 About\n#####G-------\n'),
                         '### 1.1 About\n')

    def test_heading_whitespace_is_collapsed(self):
        self.assertEqual(body('#####GMaximise stats    [maximize]\n    desc\n'),
                         '### Maximise stats \\[maximize\\]\n\ndesc\n')

    def test_long_coloured_sentences_are_not_headings(self):
        text = ('#####RThis is a difficult modifier.  Your character will almost '
                'always die.\n#####Rcharacters.\n')
        self.assertEqual(
            body(text),
            tex('#FF0000', 'This is a difficult modifier.  Your character will '
                'almost always die.') + '\\\n' + tex('#FF0000', 'characters.') + '\n')

    def test_wrapped_title_is_one_heading(self):
        self.assertEqual(
            body('#####G----------\n'
                 '#####GQ: Why do I always start in a terribly difficult, very deep dungeon\n'
                 '#####G a town? Is the game really this hard?\n'
                 '\nA: You chose a Lost soul.\n'),
            '### Q: Why do I always start in a terribly difficult, very deep dungeon '
            'a town? Is the game really this hard?\n\nA: You chose a Lost soul.\n')
        self.assertEqual(
            body('#####GOK, well I can see the pseudo-id status is there, what is that? And\n'
                 '#####Gwhere does it say swords?\nWell actually...\n'),
            '### OK, well I can see the pseudo-id status is there, what is that? And '
            'where does it say swords?\n\nWell actually...\n')

    def test_coloured_line_under_a_title_rule_is_a_heading(self):
        self.assertEqual(body('#####R==========\n#####B      ToME Macro FAQ\n\ntext\n'),
                         '# ToME Macro FAQ\n\ntext\n')

    def test_subtitle_after_heading_is_coloured_text(self):
        self.assertEqual(body('#####R      Title\n#####R   Updated 2.3\n'),
                         '# Title\n\n' + tex('#FF0000', 'Updated 2.3') + '\n')

    def test_hash_in_heading_is_escaped(self):
        self.assertEqual(body('#####GIssue #\n'), '### Issue \\#\n')


class ParagraphTest(unittest.TestCase):

    def test_soft_wrapped_lines_are_joined(self):
        text = ('This line was wrapped by the author because the next word would not fit\n'
                'on the line, so it continues.\n')
        self.assertEqual(body(text), text)

    def test_short_lines_keep_their_breaks(self):
        self.assertEqual(body('Line one.\nLine two.\n'), 'Line one.\\\nLine two.\n')

    def test_sentence_per_line_is_kept_unless_the_line_was_full(self):
        text = ('Allows you to create shots, arrows and bolts from various materials.\n'
                'You can always make shots.\n')
        self.assertEqual(body(text), text.replace('materials.\n', 'materials.\\\n'))
        text = ('If a monster dies to your attack but you still have blows left\n'
                'you will not lose the full turn.\n')
        self.assertEqual(body(text), text)
        text = ('Your melee blows can insta-kill, but you only receive 1/3 of the experience.\n'
                'For that kill.\n')
        self.assertEqual(body(text), text)

    def test_lines_that_are_a_single_link_are_not_joined(self):
        text = ('    *****page.txt*0[Possession - Possessor powers and more and more]\n'
                '    *****page.txt*0[Prayer]\n')
        self.assertEqual(body(text),
                         '[Possession - Possessor powers and more and more](page.md)\\\n'
                         '[Prayer](page.md)\n')

    def test_width_is_measured_on_the_displayed_text(self):
        text = ('[[[[[GThe Soothsayer:] To discover what *****page.txt*0[fates ("a")] lie for you.\n'
                '[[[[[GThe Inn:] Wine, dine, rest and relax!\n')
        self.assertEqual(body(text),
                         tex('#00AD00', 'The Soothsayer:') + ' To discover what '
                         '[fates ("a")](page.md) lie for you.\\\n'
                         + tex('#00AD00', 'The Inn:') + ' Wine, dine, rest and relax!\n')

    def test_indent_of_a_first_line_alone_is_dropped(self):
        text = ('        Welcome to ToME, a popular descendant of Moria/Angband.\n'
                'ToME has many unique features.\n')
        self.assertEqual(body(text), 'Welcome to ToME, a popular descendant of '
                         'Moria/Angband.\\\nToME has many unique features.\n')

    def test_lines_with_links_are_joined_when_the_next_word_did_not_fit(self):
        text = ('As well as spending your skill points on *****page.txt*0[skills], you can '
                'also choose\nto spend them on abilities.\n')
        self.assertEqual(body(text),
                         'As well as spending your skill points on [skills](page.md), you can '
                         'also choose\nto spend them on abilities.\n')

    def test_list_items_keep_their_breaks(self):
        text = ('A long introductory line that would normally be joined to the following '
                'one\n- but this is a list item\n')
        self.assertEqual(body(text),
                         'A long introductory line that would normally be joined to the '
                         'following one\\\n\\- but this is a list item\n')

    def test_indentation_is_kept_with_nbsp(self):
        self.assertEqual(body('1. Item\n   detail\n'),
                         '1\\. Item\\\n&nbsp;&nbsp;&nbsp;detail\n')

    def test_first_line_indent_of_a_paragraph_is_dropped(self):
        text = ('        Certain special keys may be intercepted by the operating system or\n'
                'the host machine, causing unexpected results.\n')
        self.assertEqual(body(text), text.lstrip())

    def test_indented_wrapped_text_is_indented_once(self):
        text = ('[[[[[GInventory list (i)]\n'
                '        Displays a list of objects being carried but not equipped.  You\n'
                '        can carry up to 23 different items.\n')
        self.assertEqual(body(text),
                         tex('#00AD00', 'Inventory list (i)') + '\\\n'
                         + '&nbsp;' * 8 + 'Displays a list of objects being carried but not '
                         'equipped.  You\ncan carry up to 23 different items.\n')

    def test_no_trailing_space_before_a_hard_break(self):
        self.assertEqual(body('*****page.txt*0[Damage ]\nnext\n'),
                         '[Damage](page.md)\\\nnext\n')

    def test_common_indentation_is_removed(self):
        self.assertEqual(body('    a\n    b\n'), 'a\\\nb\n')

    def test_rule_line_becomes_thematic_break(self):
        self.assertEqual(body('above\n-------\nbelow\n'), 'above\n\n---\n\nbelow\n')

    def test_coloured_lines_are_not_joined(self):
        text = ('#####vYour Air and Conveyance skills must have reached a combined level\n'
                '#####vof 22.\n')
        self.assertEqual(body(text), tex('#FF00FF', 'Your Air and Conveyance skills must '
                                         'have reached a combined level') + '\\\n'
                         + tex('#FF00FF', 'of 22.') + '\n')


class TableTest(unittest.TestCase):

    def test_pipe_table_with_header(self):
        text = ('#####GKey    | Action\n'
                '----------------------\n'
                'Escape | Leave\n'
                'Space  | Advance\n'
                '----------------------\n')
        self.assertEqual(body(text),
                         '| Key | Action |\n| --- | --- |\n'
                         '| Escape | Leave |\n| Space | Advance |\n')

    def test_pipe_table_without_header(self):
        text = 'Space          | Advance\n2, down arrow  | Line\n'
        self.assertEqual(body(text),
                         '|   |   |\n| --- | --- |\n'
                         '| Space | Advance |\n| 2, down arrow | Line |\n')

    def test_aligned_table_with_coloured_header_and_indented_rows(self):
        row = '%-21s%-9s%s'
        text = '\n'.join(['#####B' + row % ('Skill', 'Start', 'Gain'),
                          row % ('Combat', '2.000', '[0.700]'),
                          row % ('  Weaponmastery', '1.000', '[0.700]'),
                          'Magic',
                          row % ('  Spell-power', '0.000', '[0.800]')]) + '\n'
        self.assertEqual(body(text),
                         '| Skill | Start | Gain |\n| --- | --- | --- |\n'
                         '| Combat | 2.000 | \\[0.700\\] |\n'
                         '| &nbsp;&nbsp;Weaponmastery | 1.000 | \\[0.700\\] |\n'
                         '| Magic |  |  |\n'
                         '| &nbsp;&nbsp;Spell-power | 0.000 | \\[0.800\\] |\n')

    def test_two_column_list_of_links(self):
        text = (' *****page.txt*1[a  Aim a wand]              *****page.txt*2[A  Activate]\n'
                ' D  (unused)                *****page.txt*3[^E  Toggle]\n'
                '~~~~~1\n~~~~~2\n~~~~~3\nx\n')
        self.assertEqual(body(text).split('\n\n')[0],
                         '|   |   |\n| --- | --- |\n'
                         '| [a  Aim a wand](#tag-1) | [A  Activate](#tag-2) |\n'
                         '| D  (unused) | [^E  Toggle](#tag-3) |')

    def test_columns_may_touch_where_most_rows_have_a_gap(self):
        # From skills.txt and dungeon.txt: one long entry fills its column.
        text = ('  *****page.txt*0[Air]                *****page.txt*0[Antimagic]\n'
                '  *****page.txt*0[Conveyance]         *****page.txt*0[Corpse]\n'
                '  *****page.txt*0[Corpse-preservation]*****page.txt*0[Critical-hits]\n'
                '  *****page.txt*0[Doors, Rooms, etc.] *****page.txt*0[Pets]\n'
                '  *****page.txt*0[Earth]              *****page.txt*0[Fire]\n'
                '  *****page.txt*0[Magic]              *****page.txt*0[Mana]\n')
        self.assertEqual(body(text),
                         '|   |   |\n| --- | --- |\n'
                         '| [Air](page.md) | [Antimagic](page.md) |\n'
                         '| [Conveyance](page.md) | [Corpse](page.md) |\n'
                         '| [Corpse-preservation](page.md) | [Critical-hits](page.md) |\n'
                         '| [Doors, Rooms, etc.](page.md) | [Pets](page.md) |\n'
                         '| [Earth](page.md) | [Fire](page.md) |\n'
                         '| [Magic](page.md) | [Mana](page.md) |\n')

    def test_numbers_may_be_one_space_apart(self):
        text = ('Beorning    +4   -2   +3   -5      12\n'
                'Death Mold  +10   0   +10 -15      15\n'
                'Dunadan     +1   +2   +3   +2      10\n')
        self.assertEqual(body(text),
                         '|   |   |   |   |   |   |\n| --- | --- | --- | --- | --- | --- |\n'
                         '| Beorning | +4 | -2 | +3 | -5 | 12 |\n'
                         '| Death Mold | +10 | 0 | +10 | -15 | 15 |\n'
                         '| Dunadan | +1 | +2 | +3 | +2 | 10 |\n')

    def test_header_words_one_space_apart_stay_together(self):
        row = '%-21s%-13s%s'
        text = '\n'.join(['#####B' + row % ('Skill', 'Start Mod', 'Skill Point Gains Mod'),
                          row % ('Combat', '1.500', '      [0.000]'),
                          row % ('Magic', '0.900', '      [0.100]')]) + '\n'
        self.assertEqual(body(text),
                         '| Skill | Start Mod | Skill Point Gains Mod |\n| --- | --- | --- |\n'
                         '| Combat | 1.500 | \\[0.000\\] |\n'
                         '| Magic | 0.900 | \\[0.100\\] |\n')

    def test_single_spaces_shared_by_all_rows_do_not_split_columns(self):
        text = '  A floor space      x   yes\n  A trap here        y   no\n'
        self.assertEqual(body(text),
                         '|   |   |   |\n| --- | --- | --- |\n'
                         '| A floor space | x | yes |\n| A trap here | y | no |\n')

    def test_orphan_rows_that_fit_the_columns_belong_to_the_table(self):
        text = ('   one       two\n'
                '   three     four\n'
                '             five\n'
                '   six\n'
                'Prose after the table.\n')
        self.assertEqual(body(text),
                         '|   |   |\n| --- | --- |\n'
                         '| one | two |\n| three | four |\n|  | five |\n| six |  |\n'
                         '\nProse after the table.\n')

    def test_unindented_orphan_row_aligned_with_two_columns(self):
        text = 'Alt    Alt\nCtrl   Control\nShift  Shift\nSee also the next part.\n'
        self.assertEqual(body(text),
                         '|   |   |\n| --- | --- |\n| Alt | Alt |\n| Ctrl | Control |\n'
                         '| Shift | Shift |\n\nSee also the next part.\n')

    def test_long_orphan_rows_of_links_belong_to_the_table(self):
        text = ('     *****page.txt*0[Races]                           *****page.txt*0[Gods]\n'
                '     *****page.txt*0[Stats]                           *****page.txt*0[Abilities]\n'
                '     *****page.txt*0[Combinations of Race and Class]  *****page.txt*0[Stat tables]\n')
        self.assertTrue(body(text).endswith(
            '| [Combinations of Race and Class](page.md) | [Stat tables](page.md) |\n'))

    def test_columns_that_never_share_a_row_are_merged(self):
        # birth.txt lines up its class list by raw text, not as displayed.
        def row(*cells):
            line = ''
            for column, name in cells:
                line += ' ' * (column - len(h2m.parse_line(line).display if line else ''))
                line += '*****page.txt*0[%s]' % name
            return line + '\n'
        text = (row((52, 'Mage'), (77, 'Rogue'))
                + row((5, 'Archer'), (31, 'Mimic'))
                + row((5, 'Assassin'), (31, 'Mindcrafter'), (56, 'Sorceror'))
                + row((5, 'Axemaster'), (31, 'Monk'), (56, 'Summoner')))
        self.assertEqual(body(text),
                         '|   |   |   |\n| --- | --- | --- |\n'
                         '|  | [Mage](page.md) | [Rogue](page.md) |\n'
                         '| [Archer](page.md) | [Mimic](page.md) |  |\n'
                         '| [Assassin](page.md) | [Mindcrafter](page.md) | [Sorceror](page.md) |\n'
                         '| [Axemaster](page.md) | [Monk](page.md) | [Summoner](page.md) |\n')

    def test_glyph_table_keeps_colours(self):
        text = ('  [[[[[y;]   A glyph of warding      4   Temple\n'
                '  .   A floor space           [[[[[U>]   A shaft down\n')
        md = body(text)
        self.assertTrue(md.startswith('|   |   |   |   |\n| --- | --- | --- | --- |\n'), md)
        self.assertIn('| $`\\color{#FFFF00}{\\colorbox{black}{;}}`$ | A glyph of warding | 4 | Temple |',
                      md)
        self.assertIn('| . | A floor space | $`\\color{#C08040}{\\colorbox{black}{>}}`$ '
                      '| A shaft down |', md)

    def test_pipe_characters_in_cells_are_escaped(self):
        text = '  ?   A rune             |   An edged weapon\n  !   A potion           /   A pole-arm\n'
        self.assertIn('| ? | A rune | \\| | An edged weapon |', body(text))

    def test_diagram_of_single_characters_is_a_code_block(self):
        text = '   7  8  9      y  k  u\n   4     6      h     l\n'
        self.assertEqual(body(text), '```text\n7  8  9      y  k  u\n4     6      h     l\n```\n')

    def test_layout_with_links_that_is_not_a_table_uses_pre(self):
        text = ' *****page.txt*0[x]   y   z\n  1   2   3   *****page.txt*0[<]\n'
        self.assertEqual(body(text),
                         '<pre><a href="page.md">x</a>   y   z\n'
                         ' 1   2   3   <a href="page.md">&lt;</a></pre>\n')


class VerbatimTest(unittest.TestCase):

    def test_screen_dump_becomes_code_block(self):
        self.assertEqual(body('Look:\n\n&&&&&B/B-B\\\n&&&&&B|wxB|\n\nafter\n'),
                         'Look:\n\n```text\n/-\\\n|x|\n```\n\nafter\n')

    def test_fence_is_longer_than_backtick_runs(self):
        self.assertEqual(body('&&&&&w`w`w`\n&&&&&wa\n'), '````text\n```\na\n````\n')


class MenuPageTest(unittest.TestCase):

    def test_menu_page(self):
        text = ('|||||oy\n'
                '~~~~~01|Help|Main Menu\n'
                '#####RWelcome to the Help System.\n'
                '#####R==========================\n'
                '\n'
                'Please choose one of the following:\n'
                '\n'
                '    *****/ageneral.txt*0[(a) About this help system]\n'
                '    *****/bnewbie.hlp*0[(b) Help for new players] Skills, magic + more\n'
                '\n'
                '#####GBasic keys:\n'
                'Space          | Advance 1 page\n'
                '2, down arrow  | Advance 1 line\n')
        others = {'general.txt': 'x\n', 'newbie.hlp': 'y\n'}
        md, warnings = convert(text, name='help.hlp', others=others)
        self.assertEqual(warnings, [])
        self.assertEqual(
            md,
            '<!-- Generated from lib/help/help.hlp by scripts/help_to_markdown.py; '
            'do not edit. -->\n'
            '\n'
            '# <a id="tag-1"></a>Welcome to the Help System.\n'
            '\n'
            'Please choose one of the following:\n'
            '\n'
            '[(a) About this help system](general.md)\\\n'
            '[(b) Help for new players](newbie.hlp.md) Skills, magic + more\n'
            '\n'
            '### Basic keys:\n'
            '\n'
            '|   |   |\n'
            '| --- | --- |\n'
            '| Space | Advance 1 page |\n'
            '| 2, down arrow | Advance 1 line |\n')


class SetTest(unittest.TestCase):

    SOURCES = {
        'a.txt': b'#####R=== Alpha ===\nSee *****b.txt*2[b].\n',
        'b.txt': b'~~~~~02\n#####R=== Beta ===\n',
        'menu.hlp': b'*****a.txt*0[a]\n',
        'head.aux': b'<html>\n',
    }

    def test_output_names(self):
        self.assertEqual(h2m.output_name('ability.txt'), 'ability.md')
        self.assertEqual(h2m.output_name('magic.hlp'), 'magic.hlp.md')

    def test_set_conversion_and_index(self):
        outputs, warnings = h2m.convert_set(self.SOURCES, 'lib/help')
        self.assertEqual(warnings, [])
        self.assertEqual(sorted(outputs), ['README.md', 'a.md', 'b.md', 'menu.hlp.md'])
        index = outputs['README.md']
        self.assertIn('[Alpha](a.md)', index)
        self.assertIn('[Beta](b.md)', index)
        self.assertIn('menu.hlp', index)
        self.assertNotIn('head.aux', index)

    def test_conversion_is_deterministic(self):
        first = h2m.convert_set(self.SOURCES, 'lib/help')
        items = list(self.SOURCES.items())
        random.Random(1).shuffle(items)
        second = h2m.convert_set(dict(items), 'lib/help')
        self.assertEqual(first, second)


class CheckerTest(unittest.TestCase):

    def setUp(self):
        self.outputs, _ = h2m.convert_set(SetTest.SOURCES, 'lib/help')
        self.tree = {'doc/help/' + name: text for name, text in self.outputs.items()}
        self.sources = {'lib/help': sorted(SetTest.SOURCES)}

    def check(self):
        return h2m.check_tree(self.tree, self.sources, {'lib/help': 'doc/help'},
                              exists=lambda path: path.split('/')[0] in ('lib', 'scripts'))

    def test_generated_output_passes(self):
        problems, stats = self.check()
        self.assertEqual(problems, [])
        self.assertGreater(stats['links'], 0)

    def test_missing_output_is_reported(self):
        del self.tree['doc/help/b.md']
        problems, _ = self.check()
        self.assertTrue(any('b.txt' in p for p in problems), problems)

    def test_unknown_source_file_is_reported(self):
        self.sources['lib/help'].append('new.doc')
        problems, _ = self.check()
        self.assertTrue(any('new.doc' in p for p in problems), problems)

    def test_broken_link_is_reported(self):
        self.tree['doc/help/a.md'] += '\n[x](nowhere.md)\n'
        problems, _ = self.check()
        self.assertTrue(any('nowhere.md' in p for p in problems), problems)

    def test_broken_anchor_is_reported(self):
        self.tree['doc/help/a.md'] += '\n[x](b.md#tag-99) <a href="#tag-98">y</a>\n'
        problems, _ = self.check()
        self.assertTrue(any('tag-99' in p for p in problems), problems)
        self.assertTrue(any('tag-98' in p for p in problems), problems)

    def test_markup_remnants_are_reported(self):
        for remnant in ('#####R', '\\*\\*\\*\\*\\*', '\\[\\[\\[\\[\\[', '{{{{{',
                        '\\|\\|\\|\\|\\|', '\\~\\~\\~\\~\\~', '&&&&&'):
            tree = dict(self.tree)
            tree['doc/help/a.md'] += '\ntext %s text\n' % remnant
            problems, _ = h2m.check_tree(tree, self.sources, {'lib/help': 'doc/help'},
                                         exists=lambda path: True)
            self.assertTrue(any('markup' in p for p in problems), remnant)

    def test_unbalanced_latex_is_reported(self):
        self.tree['doc/help/a.md'] += '\n$`\\color{red}{\\textsf{x}`$\n'
        problems, _ = self.check()
        self.assertTrue(any('LaTeX' in p for p in problems), problems)


class CommittedOutputTest(unittest.TestCase):
    """The committed doc/help must match the sources and pass the checker."""

    def test_committed_output_is_current_and_valid(self):
        root = h2m.repo_root()
        if not os.path.isdir(os.path.join(root, 'doc', 'help')):
            self.skipTest('doc/help has not been generated')
        stale = h2m.stale_outputs(root)
        self.assertEqual(stale, [], 'run scripts/help_to_markdown.py')
        problems, stats = h2m.check_repo(root)
        self.assertEqual(problems, [])
        self.assertGreater(stats['links'], 1000)


if __name__ == '__main__':
    unittest.main()
