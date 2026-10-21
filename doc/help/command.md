<!-- Generated from lib/help/command.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-99"></a>List of Commands

Angband commands are entered as an "underlying command" (a single key)
plus a variety of optional or required arguments.  You may choose how the
"keyboard keys" are mapped to the "underlying commands" by choosing one of
two standard "keysets", the "original" keyset or the "roguelike" keyset.

The original keyset is very similar to the "underlying" command set,
with a few additions (such as the ability to use the numeric "directions" to
"walk" or the "5" key to "stay still").  The roguelike keyset provides similar
additions, and also allows the use of the h/j/k/l/y/u/b/n keys to "walk" (or,
in combination with the shift or control keys, to run or tunnel), which thus
requires a variety of key mappings to allow access to the underlying commands
used for walking/running/tunneling.  In particular, the "roguelike" keyset
includes many more "capital" and "control" keys, as shown below.

Note that any keys that are not required for access to the underlying
command set may be used by the user as "command macro" triggers (see below).
You may always specify any "underlying command" directly by pressing backslash
("\\") plus the "underlying command" key.  This is normally only used in "macro"
definitions.  $`\color{#00A5A5}{\textsf{You may often enter "control-keys" as a caret ("^") plus the key}}`$
(so "^" + "p" often yields "^P").

Some commands allow an optional "repeat count", which allows you to tell
the game that you wish to do the command multiple times, unless you press a
key or are otherwise disturbed.  To enter a "repeat count", type '0', followed
by the numerical count, followed by the command.  You must type "space" before
entering certain commands.  Skipping the numerical count yields a count of 99.
An option allows certain commands (open, tunnel, etc) to auto-repeat.

Some commands will prompt for extra information, such as a direction, an
inventory or equipment item, a spell, a textual inscription, the symbol of a
monster race, a sub-command, a verification, an amount of time, a quantity,
a file name, or various other things.  Normally you can hit return to choose
the "default" response, or escape to cancel the command entirely.

Some commands will prompt for a spell or an inventory item.  Pressing
space (or '\*') will give you a list of choices.  Pressing "-" (minus) selects
the item on the floor.  Pressing a lowercase letter selects the given item.
Pressing a capital letter selects the given item after verification.  Pressing
a numeric digit '#' selects the first item (if any) whose inscription contains
"@#" or "@x#", where "x" is the current "underlying command".  You may only
specify items which are "legal" for the command.  Whenever an item inscription
contains "!\*" or "!x" (with "x" as above) you must verify its selection.

In ToME, there are items which occasionally teleport you away, asking
for permission first. The recurring "Teleport (y/n)?" can be annoying, and
this behavior can be eliminated by inscribing the object which causes the
teleportation with "." (or any inscription containing the character ".").
With this inscription, the object will no longer teleport you around nor
keep asking you. If you want to restore the teleport ability to the object,
just remove the "." from its inscription. Note that cursed items which
teleport you are unaffected by the inscription.

Some commands will prompt for a direction.  You may enter a "compass"
direction using any of the "direction keys" shown below.  Sometimes, you may
specify that you wish to use the current "target", by pressing "t" or "5", or
that you wish to select a new target, by pressing "\*" (see "Target" below).

### <a id="tag-95"></a>Original Keyset Directions Roguelike Keyset Directions

```text
7  8  9                           y  k  u
4     6                           h     l
1  2  3                           b  j  n
```

Each of the standard keysets provides some short-cuts over the "underlying
commands".  For example, both keysets allow you to "walk" by simply pressing
an "original" direction key (or a "roguelike" direction key if you are using
the roguelike keyset), instead of using the "walk" command plus a direction.
$`\color{#00A5A5}{\textsf{The roguelike keyset allows you to "run" or "tunnel" by simply holding the}}`$
$`\color{#00A5A5}{\textsf{shift or control modifier key down while pressing a "roguelike" direction key,}}`$
$`\color{#00A5A5}{\textsf{instead of using the "run" or "tunnel" command plus a direction.}}`$  Both keysets
allow the use of the "5" key to "stand still", which is most convenient when
using the original keyset.

Note that on many systems, it is possible to define "macros" (or "command
macros") to various keys, or key combinations, so that it is often possible to
make macros which, for example, allow the use of the shift or control modifier
keys, plus a numeric keypad key, to specify the "run" or "tunnel" command, with
the given direction, regardless of any keymap definitions, by using the fact
that you can always, for example, use "\\" + "." + "6", to specify "run east".

## <a id="tag-100"></a>Original Keyset Command Summary (4.2.x)

|   |   |
| --- | --- |
| [a  Aim a wand](#tag-1) | [A  Activate an artifact](#tag-2) |
| [b  Browse a book](#tag-3) | [B  Bash a door](#tag-4) |
| [c  Close a door](#tag-5) | [C  Character description](#tag-6) |
| [d  Drop an item](#tag-7) | D  (unused) |
| [e  Equipment list](#tag-9) | [E  Eat some food](#tag-10) |
| [f  Fire (shoot) an item](#tag-11) | [F  Fuel your lantern/torch](#tag-12) |
| [g  Stay still (flip pickup)](#tag-13) | [G  Gain new skills](#tag-14) |
| [h  Hack up a corpse](#tag-15) | [H  Drink from a fountain](#tag-16) |
| [i  Inventory list](#tag-17) | [I  Inspect (closely examine) an item](#tag-18) |
| [j  Jam a door](#tag-19) | J  (unused) |
| [k  Destroy an item](#tag-20) | [K  Cure meat](#tag-21) |
| [l  Look around](#tag-22) | [L  Look around dungeon by sector](#tag-23) |
| [m  Cast a spell / use mental power](#tag-24) | [M  Full dungeon map](#tag-25) |
| [n  Repeat last command](#tag-85) | [N  Abilities Screen](#tag-91) |
| [o  Open a door or chest](#tag-26) | [O  Sacrifice at an altar](#tag-27) |
| [p  Pray to your god (if any)](#tag-28) | [P  Pet commands](#tag-29) |
| [q  Quaff a potion](#tag-30) | [Q  Quit (commit suicide)](#tag-31) |
| [r  Read a scroll](#tag-32) | [R  Rest for a period](#tag-33) |
| [s  Search for traps/doors](#tag-34) | [S  Toggle search mode](#tag-35) |
| [t  Take off equipment](#tag-36) | [T  Dig a tunnel](#tag-37) |
| [u  Use a staff](#tag-38) | [U  Use bonus power (if any)](#tag-39) |
| [v  Throw an item](#tag-40) | [V  Version Info](#tag-41) |
| [w  Wear/wield equipment](#tag-42) | W  (unused) |
| [x  Engrave the floor](#tag-43) | X  (unused) |
| [y  Give item to monster](#tag-44) | [Y  Chat with a monster](#tag-96) |
| [z  Zap a rod](#tag-45) | [Z  Steal](#tag-46) |
| [!  Interact with system](#tag-47) | [^A  (special - debug command)](debug.md) |
| [@  Interact with macros](#tag-49) | ^B  (unused) |
| [#  Begin extended command](#tag-89) | ^C  (special - break) |
| [<span>$</span>  Record macros](#tag-97) | ^D  (unused) |
| [%  Interact with visuals](#tag-51) | [^E  Toggle choice window](#tag-52) |
| ^  (special - control key) | [^F  Repeat level feeling](#tag-53) |
| [&  Interact with colors](#tag-54) | ^G  (unused) |
| [\*  Target monster or location](#tag-55) | ^H  (unused) |
| (  (unused) | ^I  (special - tab) |
| )  (unused) | ^J  (special - linefeed) |
| [{  Inscribe an object](#tag-58) | ^K  (unused) |
| [}  Uninscribe an object](#tag-59) | ^L  (unused) |
| \[  (unused) | ^M  (special - return) |
| \]  (unused) | ^N  (unused) |
| [-  Walk (flip pickup)](#tag-60) | ^O  (unused) |
| [\_  Re-Enter store](#tag-61) | [^P  Show previous messages](#tag-62) |
| [+  Alter grid](#tag-63) | [^Q  Quit to next midi song](#tag-64) |
| [=  Set options](#tag-65) | [^R  Redraw the screen](#tag-66) |
| [;  Walk (with pickup)](#tag-67) | [^S  Save and don't quit](#tag-68) |
| [:  Take notes](#tag-69) | [^T  Time of the day](#tag-70) |
| '  (unused) | ^U  (unused) |
| ["  Enter a user pref command](#tag-71) | ^V  (unused) |
| [,  Stay still (with pickup)](#tag-72) | ^W  (special - wizard mode) |
| [\<  Go up staircase](#tag-74) | [^X  Save and quit](#tag-75) |
| [.  Run](#tag-76) | ^Y  (unused) |
| [>  Go down staircase](#tag-77) | ^Z  (unused) |
| &nbsp;&nbsp;[(special - bypass keymap)](#tag-79) |  |
| [\`  (special - escape)](#tag-81) | [\~  Display current knowledge](#tag-82) |
| [/  Identify symbol](#tag-83) | [?  Help](#tag-84) |
|  | [^\]  Take an html screenshot](#tag-98) |

## <a id="tag-101"></a>Roguelike Keyset Command Summary (4.2.x)

|   |   |
| --- | --- |
| [a  Zap a rod (Activate)](#tag-45) | [A  Activate an artifact](#tag-2) |
| [b  (walk - south west)](#tag-95) | [B  (run - south west)](#tag-95) |
| [c  Close a door](#tag-5) | [C  Character description](#tag-6) |
| [d  Drop an item](#tag-7) | D  (unused) |
| [e  Equipment list](#tag-9) | [E  Eat some food](#tag-10) |
| [f  Bash a door (force)](#tag-4) | [F  Fuel your lantern/torch](#tag-12) |
| [g  Stay still (flip pickup)](#tag-13) | [G  Gain new skills](#tag-14) |
| [h  (walk - west)](#tag-95) | [H  (run - west)](#tag-95) |
| [i  Inventory list](#tag-17) | [I  Observe an item](#tag-18) |
| [j  (walk - south)](#tag-95) | [J  (run - south)](#tag-95) |
| [k  (walk - north)](#tag-95) | [K  (run - north)](#tag-95) |
| [l  (walk - east)](#tag-95) | [L  (run - east)](#tag-95) |
| [m  Spell casting / mental power](#tag-24) | [M  Full dungeon map](#tag-25) |
| [n  (walk - south east)](#tag-95) | [N  (run - south east)](#tag-95) |
| [o  Open a door or chest](#tag-26) | [O  Use bonus power (if any)](#tag-39) |
| [p  Pray to your god (if any)](#tag-28) | [P  Browse a book](#tag-3) |
| [q  Quaff a potion](#tag-30) | [Q  Quit (commit suicide)](#tag-31) |
| [r  Read a scroll](#tag-32) | [R  Rest for a period](#tag-33) |
| [s  Search for traps/doors](#tag-34) | [S  Record macros](#tag-97) |
| [t  Fire an item](#tag-11) | [T  Take off equipment](#tag-36) |
| [u  (walk - north east)](#tag-95) | [U  (run - north east)](#tag-95) |
| [v  Throw an item](#tag-40) | [V  Drink from a fountain](#tag-16) |
| [w  Wear/wield equipment](#tag-42) | [W  Locate player on map (Where)](#tag-23) |
| [x  Look around](#tag-22) | [X  Pet commands](#tag-29) |
| [y  (walk - north west)](#tag-95) | [Y  (run - north west)](#tag-95) |
| [z  Aim a wand (Zap)](#tag-1) | [Z  Use a staff (Zap)](#tag-38) |
| [!  Interact with system](#tag-47) | ^A  (special - debug command) |
| [@  Interact with macros](#tag-49) | [^B  (tunnel - south west)](#tag-95) |
| [#  Toggle search mode](#tag-35) | ^C  (special - break) |
| [<span>$</span>  Hack up a corpse](#tag-15) | [^D  Destroy item](#tag-20) |
| [%  Interact with visuals](#tag-51) | [^E  Toggle choice window](#tag-52) |
| ^  (special - control key) | [^F  Repeat level feeling](#tag-53) |
| [&  Interact with colors](#tag-54) | [^G  Sacrifice at an altar](#tag-27) |
| [\*  Target monster or location](#tag-55) | [^H  (tunnel - west)](#tag-95) |
| [(  Chat](#tag-96) | ^I  (special - tab) |
| [)  Begin extended command](#tag-89) | [^J  (tunnel - south)](#tag-95) |
| [{  Inscribe an object](#tag-58) | [^K  (tunnel - north)](#tag-95) |
| [}  Uninscribe an object](#tag-59) | [^L  (tunnel - east)](#tag-95) |
| \[  [Steal](#tag-46) | [^M  (tunnel - south)](#tag-95) |
| \]  [Engrave the floor](#tag-43) | [^N  (tunnel - south east)](#tag-95) |
| [-  Walk (flip pickup)](#tag-60) | [^O  Cure meat](#tag-21) |
| [\_  Enter store](#tag-61) | [^P  Show previous messages](#tag-62) |
| [+  Alter grid](#tag-63) | [^Q  Quit to next midi song](#tag-64) |
| [=  Set options](#tag-65) | [^R  Redraw the screen](#tag-66) |
| [;  Walk (with pickup)](#tag-67) | [^S  Save and don't quit](#tag-68) |
| [:  Take notes](#tag-69) | [^T  Dig a Tunnel](#tag-37) |
| ['  Give object to monster](#tag-44) | [^U  (tunnel - north east)](#tag-95) |
| ["  Enter a user pref command](#tag-71) | ^V  (unused) |
| [,  Run](#tag-76) | ^W  (special - wizard mode) |
| [\<  Go up staircase](#tag-74) | [^X  Save and quit](#tag-75) |
| [.  Stay still (with pickup)](#tag-72) | [^Y  (tunnel - north west)](#tag-95) |
| [>  Go down staircase](#tag-77) | ^Z  (unused) |
| &nbsp;&nbsp;[(special - bypass keymap)](#tag-79) |  |
| [\`  (special - escape)](#tag-81) | [\~  Display current knowledge](#tag-82) |
| [/  Identify symbol](#tag-83) | [?  Help](#tag-84) |

## <a id="tag-102"></a>Special Keys

Certain special keys may be intercepted by the operating system or
the host machine, causing unexpected results.  In general, these special keys
are control keys, and often, you can disable their special effects.

If you are playing on a UNIX or similar system, then Ctrl-C will
interrupt ToME.  The second and third interrupt will induce a warning
bell, and the fourth will induce both a warning bell and a special message,
since the fifth will quit the game, after killing your character.  Also,
Ctrl-Z will suspend the game, and return you to the original command shell,
until you resume the game with the "fg" command.  There is now a compilation
option to force the game to prevent the "double ctrl-z escape death trick".
The Ctrl-\\ and Ctrl-D and Ctrl-S keys should not be intercepted.

It is often possible to specify "control-keys" without actually
pressing the control key, by typing a caret ("^") followed by the key.\
This is useful for specifying control-key commands which might be caught
by the operating system as explained above.

<a id="tag-79"></a>Pressing $`\color{#00AD00}{\textsf{backslash ("\\")}}`$ before a command will bypass all keymaps,
and the next keypress will be interpreted as an "underlying command" key,
unless it is a caret ("^"), in which case the keypress after that will be
turned into a control-key and interpreted as a command in the underlying
ToME keyset.  The backslash key is useful for creating macro actions
which are not affected by any keymap definitions that may be in force, for
example, the sequence "\\" + "." + "6" will always mean "run east", even if
the "." key has been mapped to a different underlying command.

The "0" and "^" and "\\" keys all have special meaning when entered
at the command prompt, and there is no "useful" way to specify any of them
as an "underlying command", which is okay, since they would have no effect.

<a id="tag-81"></a>For many input requests or queries, the $`\color{#00AD00}{\textsf{special character ESCAPE}}`$
will abort the command.  The "\[y/n\]" prompts may be answered with "y" or
"n", or escape.  The "-more-" message prompts may be cleared (after reading
the displayed message) by pressing ESCAPE, SPACE, RETURN, LINEFEED, or by
any keypress, if the "quick_messages" option is turned on.

## <a id="tag-103"></a><a id="tag-104"></a>Command Counts

Some commands can be executed a fixed number of times by preceding
them with a count.  Counted commands will execute until the count expires,
until you type any character, or until something significant happens, such
as being attacked.  Thus, a counted command doesn't work to attack another
creature.  While the command is being repeated, the number of times left
to be repeated will flash by on the line at the bottom of the screen.

$`\color{#00A5A5}{\textsf{To give a count to a command, type 0, the repeat count, and then}}`$
$`\color{#00A5A5}{\textsf{the command.}}`$ If you want to give a movement command and you are using the
original command set (where the movement commands are digits), press space
after the count and you will be prompted for the command.

Counted commands are very useful for searching or tunneling, as
they automatically terminate on success, or if you are attacked.  You may
also terminate any counted command (or resting or running), by typing any
character.  This character is ignored, but it is safest to use a SPACE or
ESCAPE which are always ignored as commands in case you type the command
just after the count expires.

You can tell ToME to automatically use a repeat count of 99
with commands you normally want to repeat (open, tunnel, bash, alter,
etc) by setting the "always_repeat" option.

## Selection of Objects

Many commands will also prompt for a particular object to be used.
For example, the command to read a scroll will ask you which of the
scrolls that you are carrying that you wish to read.  In such cases, the
selection is made by typing a letter of the alphabet.  The prompt will
indicate the possible letters, and will also allow you to type the key
"\*", which causes all of the available options to be described.  The list
of choices will also be shown in the Choice window, if you are using a
windows environment and windows are turned on.  Often you will be able to
press "/" to select an object from your equipment instead of your
inventory.  Pressing space once will have the same effect as "\*", and
the second time will cancel the command and run the "i" or "e" command.

$`\color{#00A5A5}{\textsf{The particular object may be selected by an upper case or a lower}}`$
$`\color{#00A5A5}{\textsf{case letter.  If lower case is used, the selection takes place}}`$
$`\color{#00A5A5}{\textsf{immediately.  If upper case is used, then the particular option is}}`$
$`\color{#00A5A5}{\textsf{described, and you are given the option of confirming or retracting that}}`$
$`\color{#00A5A5}{\textsf{choice.}}`$  Upper case selection is thus safer, but requires an extra key
stroke.  Also see the "!\*" and "!x" inscriptions, below.

For many commands, $`\color{#00A5A5}{\textsf{you can also use "-" to select an object on the}}`$
$`\color{#00A5A5}{\textsf{floor where you are standing.}}`$  This lets you read scrolls or quaff
potions, for example, off the dungeon floor without picking them up.

<a id="tag-90"></a>If you enter a number between 0 and 9, the first item engraved
with "@#" where "#" is the number you entered will be selected.  For example,
if you have a shovel engraved with "@0" and you type "w" (for wield) and
then 0, you will wield the shovel.  This is very useful for macros (see
below), since you can use this to select an object regardless of its
location in your pack. Multiple numbers can be engraved on the same object; for
example, if a sword is engraved with @1@0, then either "w1" or "w0" will
wield it.  Normally, you inscribe "@1@0" on your primary weapon, and
"@2@0" on your secondary weapon.  $`\color{#00A5A5}{\textsf{Note that an inscription containing}}`$
$`\color{#00A5A5}{\textsf{"@x#" will act like "@#" but only when the current "ToME command"}}`$
$`\color{#00A5A5}{\textsf{is "x".}}`$  Thus you can put "@z4" on a rod and "@u4" on a staff, and then
use both "z4" and "u4" as desired.

Note that any object containing "!x" in its inscription, where
"x" is the current "ToME command" (or containing "!\*" ever) will induce
"verification" whenever that object is "selected".  Thus, inscribing, say,
"!f!k!d" on an object will greatly reduce the odds of you "losing" it by
accident, and $`\color{#00A5A5}{\textsf{inscribing "!*" on an object}}`$ will allow you to be very paranoid
about the object.  Note that "selling" and "dropping" both use the "d" command.

## <a id="tag-105"></a>User Pref Files

ToME allows you to change various aspects of the game to suit
your tastes.  You may define keymaps (changing the way ToME maps your
keypresses to underlying commands), create macros (allowing you to map a
single keypress to a series of keypresses), modify the visuals (allowing
you to change the appearance of monsters, objects, or terrain features),
change the colors (allowing you to make a given color brighter, darker,
or even completely different), or set options (turning them off or on).

ToME stores your preferences in files called "user pref files",
which contain comments and "user pref commands", which are simple strings
describing one aspect of the system about which the user has a preference.
There are many ways to load a user pref file, and in fact, some of these
files are automatically loaded for you by the game.  All of the files are
kept in the "lib/user/" directory, though you may have to use one of the
command line arguments to redirect this directory, especially on multiuser
systems.  You may also enter single user pref commands directly, using the
special "Enter a user pref command" command, activated by "double quote".
You may have to use the "redraw" command (^R) after changing certain of
the aspects of the game, to allow ToME to adapt to your changes.

When the game starts up, after you have loaded an old character,
or created a new character, some user pref files are loaded automatically.
First, the "pref.prf" file is loaded.  This file contains some user pref
commands which will work on all platforms.  Then one of "font-xxx.prf"
(for normal usage) or "graf-xxx.prf" (for bitmap usage) is loaded.  These
files contain attr/char changes to allow the monsters, objects, and/or
terrain features to look "better" on your system.  Then the "pref-xxx.prf"
file is loaded.  This file contains pre-defined system specific stuff
(macros, color definitions, etc).  Then, the "user-xxx.prf" file is loaded.
This file contains user-defined system specific stuff.  The "user-xxx.prf"
file is used as the "default" user pref file in many places.  The "xxx" is
the "system suffix" for your system, taken from the "main-xxx.c" file which
was used to generate your executable.  Finally, the "Race.prf", "Class.prf",
and "Name.prf" files are loaded, where "Race", "Class", and "Name" are
replaced by the actual race, class, and name of the current character.

Several commands allow you to both load existing user pref files,
create new user pref files, append information to existing user pref files,
and/or interact with various of the user preferences in a more intuitive
way than the user pref commands allow.  The commands include "Interact with
macros" (@), "Interact with visuals" (%), and "Interact with colors" (&),
described below.

### <a id="tag-106"></a>User Pref Files (Macros)

The "Interact with macros" command allows you to define or remove
"macros", which are mappings from a single logical keypress to a sequence
of keypresses, allowing you to use special keys on the keyboard, such as
function keys or keypad keys, possibly in conjunction with modifier keys,
to "automate" repetitive multi-keypress commands that you use a lot.

Since macros represent keypress sequences, and not all keypresses
have a printable representation, macro triggers and actions must often be
"encoded" into a human readable form.  This is done using several types
of encoding, including "\\xHH" for character number HH in hexidecimal, "\\e"
for the "escape" code, "\\n" for the "newline" code, "\\r" for the "return"
code, "\\s" for the "space" code, "\\\\" for backslash, "\\^" for caret, and
"^X" for the code for any "control" key "ctrl-X".  Note that the "action"
of a macro will not be checked against other macro triggers (unless the
macro action contains a "control-backslash"), so you cannot make infinite
loops.  You may specify extremely long macros, but you are limited in
length by the underlying input mechanisms, which in general limit you
to about 1024 keys in both triggers and actions.

The special "\\" command (which must be encoded in macros as "\\\\")
is very useful in macros, since it bypasses all keymaps and allows the next
keystroke to be considered a command in the underlying ToME command set.\
For example, a macro which maps Shift-KP6 to "\\" + "." + "6" will induce
the "run east" behavior, regardless of what keyset the user has chosen, and
regardless of what keymaps have been defined.

Macros can be specified in user pref files as a pair of lines, one
of the form "A:\<str>", which defines the encoded macro action, and one of
the form "P:\<str>", which defines the encoded macro trigger.

A $`\color{#00A5A5}{\textsf{common example of a macro}}`$ to cast the first spell in your first spell
book at the nearest monster would be: \\e\\e\\em1a\*t where \\e is an escape (to make
sure you are not still within another command), m1 selects the spell book that
is inscribed ({) with @m1, a selects the first spell in that book, and \*t targets
the nearest monster.

More detailed information about specific macros can be found in
[macrofaq.txt](macrofaq.md), originally written by Jim Lyon (jplyon@attglobal.net),
modified for ToME with Jim's permission by Dawnmist
(angband@dawnmist.8m.com).

### <a id="tag-107"></a>User Pref Files (Keymaps)

The "Interact with macros" command also allows you to define
"keymaps", which are vaguely related to macros.  A keymap maps a single
keypress to a series of keypresses, which bypass both other keymaps and
any macros.  ToME uses keymaps to map the original and the roguelike
keysets to the underlying command set, and allows the user to modify or
add keymaps of their own.  Note that all keymap actions must be specified
using underlying commands, not keypresses from the original or roguelike
keysets.  The original keyset is almost identical to the underlying keyset,
except that "numbers" are mapped to ";" plus a direction, "5" is mapped to
",", and a few control-keys are mapped to various things.  See "command.txt"
for the full set of underlying commands.  Some uses for keymaps include the
ability to "disable" a command by mapping it to "\\x00",

Keymaps can be specified in user pref files as line of the form
"M:\<T> \<key> \<str>", where \<T> is the keyset (0/1 for original/roguelike),
\<key> is the encoded trigger key, and \<str> is the encoded keymap action.

### <a id="tag-108"></a>User Pref Files (Visuals)

You can use the "Interact with visuals" command to change various
visual information, currently including the choice of what attr/char values
are used to represent various monsters, objects, or terrain features.  Note
that in combination appropriate support in "main-xxx.c", and with the use of
the "use_graphics" flag, you may be able to specify that "graphic bitmaps"
should be used instead of normal "colored characters" for various things.

When interactively modifying the attr/char values for monsters,
objects, or terrain features, pressing "n" or "N" will change which entry
you are changing, pressing "a" or "A" will rotate through the available
attr values, and pressing "c" or "C" will rotate though the available char
values.  Note that attr/char values with the "high bit" set may induce the
display of special "graphic" pictures if the "use_graphics" flag is set,
and your system supports the "use_graphics" flag.

Note that this command can be abused in various ways, and if you
must do so, remember that you are only cheating yourself.

Keymaps can be specified in user pref files as line of the form
"R:\<N>:\<A>/\<C>" or "K:\<N>:\<A>/\<C>" or "F:\<N>:\<A>/\<C>" or "U:\<N>:\<A>/\<C>".

### <a id="tag-109"></a>User Pref Files (Colors)

The "Interact with colors" command allows you to change the actual
internal values used to display various colors.  This command may or may
not have any effect on your machine.  Advanced machines may allow you to
change the actual RGB values used to represent each of the 16 colors used
by ToME, and perhaps even allow you to define new colors which are not
currently used by ToME.

Colors can be specified in user pref files as line of the form
"V:\<N>:\<V>:\<R>:\<G>:\<B>".

### <a id="tag-110"></a>User Pref Files (Options)

The "Interact with options" command allows you to turn options
on or off.  You may turn options off or on using the user pref commands
of the form "X:\<option>" or "Y:\<option>" respectively.

## <a id="tag-111"></a>Command Descriptions

The following command descriptions are listed as the command name
plus the "underlying command" key.  This is followed by the command name
and "roguelike" keyset key, if different from the underlying command key.
Then comes a brief description of the command, including information about
alternative methods of specifying the command in each keyset, when needed.
Several commands (tunnel, bash, open) are repeated 99 times if the
"always_repeat" option is set and no repeat count is given.  Some commands
use the "repeat count" to automatically repeat the command several times,
while others use the "repeat count" as an "argument", for example, commands
which need a "quantity" will use the "repeat count" instead of asking for
a quantity, allowing the use of "0d" for "drop all".  Commands which ask
for a quantity will convert any "letters" into the maximal legal value.

## <a id="tag-112"></a>Inventory Commands

<a id="tag-17"></a>$`\color{#00AD00}{\textsf{Inventory list (i)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Displays a list of objects being carried but not equipped.  You
can carry up to 23 different items, not counting those in your
equipment.  Often, many identical objects can be "stacked" into
a "pile" which will count as a single item.  This is always
true of things like potions, scrolls, and food, but you may have
to set options to allow wands, staves, and other such objects to
stack.  Each object has a weight, and if you carry more objects
than your strength permits, you will begin to slow down.

<a id="tag-9"></a>$`\color{#00AD00}{\textsf{Equipment list (e)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to display a list of the objects currently being
used by your character.  The number and type of available slots for
equipment may vary. A human for example has 15 slots for equipment,
each corresponding to a different location on the body, and each of
which may contain only a single object at a time, and each of which
may only contain objects of the proper "type".\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You must be using an object to receive any of its special
powers.

<a id="tag-7"></a>$`\color{#00AD00}{\textsf{Drop an item (d)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command drops an item from your inventory or equipment onto the
dungeon floor.  If the place you are standing on already has objects
in it, ToME will attempt to drop the item onto an adjacent space.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A floor spot can hold more than one object, but there is still the
possibility that if the floor is too full and you attempt to drop
something, it may disappear and be destroyed.  If the selected pile
contains multiple items, you may specify a quantity.

<a id="tag-20"></a>$`\color{#00AD00}{\textsf{Destroy an item (k) or Destroy an item (^D)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This destroys an item in your inventory or on the dungeon floor.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If the selected pile contains multiple objects, you may specify
a quantity.  You must always verify this command.

<a id="tag-42"></a>$`\color{#00AD00}{\textsf{Wear/Wield equipment (w)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;To wear or wield an object in your inventory, use this command.
Since only one object can be in each slot at a time, if you wear
or wield an item into a slot which is already occupied, the old
item will be first be taken off, and may in fact be dropped if
there is no room for it in your inventory.

<a id="tag-36"></a>$`\color{#00AD00}{\textsf{Take off equipment (t) or Take off equipment (T)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to take off a piece of equipment and return it
to your inventory.  Occasionally, you will run into a cursed item
which cannot be removed.  These items normally penalise you in some
way and cannot be taken off until the curse is removed.  If there
is no room in your inventory for the item, your pack will overflow
and you will drop the item after taking it off.

## <a id="tag-113"></a>Movement Commands

<a id="tag-67"></a>$`\color{#00AD00}{\textsf{Walk (with pickup) (;)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Moves one step in the given direction.  The square you are moving
into must not be blocked by walls or doors.  You will pick up any
items in the destination grid if the "always_pickup" option is set,
or if the "query_pickup" option is set and you respond correctly.
This command can take a count and requires a direction.  You may
also use the "original" direction keys (both keysets) or the
"roguelike" direction keys (roguelike keyset) to walk in a
direction.

<a id="tag-60"></a>$`\color{#00AD00}{\textsf{Walk (flip pickup) (-)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This is just like normal move, except that the "Pick things up"
option is inverted.  In other words, if you normally pick up
anything you encounter (the default), you will not pick things up
when using this command.  If you normally do not pick things up,
you will when using this command.  This command can take a count
and requires a direction.

<a id="tag-76"></a>$`\color{#00AD00}{\textsf{Run (.) or Run (,)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command will move in the given direction, following any bends
in the corridor, until you either have to make a "choice" between
two directions or you are disturbed.  You can configure what will
disturb you by setting the disturbance options.  Run requires a
direction.  You may also use shift plus the "roguelike" direction
keys (roguelike keyset), or shift plus the "original" direction keys
on the keypad (both keysets, some machines) to run in a direction.

<a id="tag-74"></a>$`\color{#00AD00}{\textsf{Go up staircase (<)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Climbs up an up staircase you are standing on.  There is always at
least one staircase going up on every level (this doesn't mean it's
easy to find) except for the surface, where '\<' will bring up the
wilderness map.  Going up a staircase will take you to a new dungeon
level unless you are at the first level of the dungeon, in which case
you will return to the surface.  Note that whenever you leave a dungeon
level, you will never find it again, unless the level contains a dungeon
town.  This means that for all intents and purposes, any objects on that
level are destroyed. This includes unknown artifacts unless the "Create
characters in preserve mode" option was set when your character was
created, in which case the artifacts may show up again later.

<a id="tag-77"></a>$`\color{#00AD00}{\textsf{Go down staircase (>)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Descends a down staircase you are standing on.  There are always
at least two staircases going down on each level, except for the
last level of a dungeon, and some "quest" levels, which have none until
the quest monsters are killed.  Going down a staircase will take you
to a new dungeon level.  See "Go Up Staircase" for more info.

This command is also used to enter Void Jumpgates, and to zoom in from
the wilderness map.

## <a id="tag-114"></a>Resting Commands

<a id="tag-72"></a>$`\color{#00AD00}{\textsf{Stay still (with pickup) (,) or Stay still (with pickup) (.)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Stays in the same square for one move.  If you normally pick up
objects you encounter, you will pick up whatever you are standing
on.  This command can take a count.  You may also use the "5" key
(both keysets).

<a id="tag-13"></a>$`\color{#00AD00}{\textsf{Stay still (flip pickup) (g)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Stays in the same square for one move.  If you normally pick up
objects you encounter, you will not pick up whatever you are
standing on.  If you normally do not pick up objects, you will
pick up what you are standing on.  This command is normally only
used when the "always_pickup" option is false.  This command can
take a count.

<a id="tag-33"></a>$`\color{#00AD00}{\textsf{Rest (R)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Resting is better for you than repeatedly staying still, and can
be told to automatically stop after a certain amount of time, or
when various conditions are met.  In any case, you always wake up
when anything disturbing happens, or when you press any key.  To
rest, enter the Rest command, followed by the number of turns you
want to rest, or "\*" to rest until your hit points and mana are
restored, or "&" to rest until you are fully "healed".  This command
can take a count, which is used for the number of turns to rest.

<a id="tag-61"></a>$`\color{#00AD00}{\textsf{Enter store (_)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;When standing on the door of a store, this command allows the character
to enter the store again.

## <a id="tag-115"></a>Searching Commands

<a id="tag-34"></a>$`\color{#00AD00}{\textsf{Search (s)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command can be used to locate hidden traps and secret doors
in the spaces adjacent to the player.  More than a single turn of
searching will be required in most cases.  You should always
search a chest before trying to open it, since they are generally
trapped.  This command can take a count, which is useful if you
are fairly sure of finding something eventually, since the command
stops as soon as anything is found.  This command can take a count.

<a id="tag-35"></a>$`\color{#00AD00}{\textsf{Toggle search mode (S) or Toggle search mode (#)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command will take you into and out of search mode.  When
first pressed, the message "Searching" will appear at the bottom
of the screen.  You are now taking two turns for each command, one
for the command and one turn to search.  This means that you are
taking twice the time to move around the dungeon, and therefore
twice the food.  Search mode will automatically turn off if you
are disturbed.  You may also turn off search mode by entering the
Search Mode command again.

## <a id="tag-116"></a><a id="tag-117"></a>Alter Commands

<a id="tag-37"></a>$`\color{#00AD00}{\textsf{Tunnel (T) or Tunnel (^T)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tunnelling or mining is a very useful art.  There are many kinds of
rock, with varying hardness, including permanent rock (permanent),
granite (very hard), quartz veins (hard), magma veins (soft), and
rubble (very soft).  Quartz and Magma veins may be displayed in a
special way, and may sometimes contain treasure, in which case they
will be displayed in a different way.  Rubble sometimes covers an
object.  It is only possible to tunnel if you are wielding a digging
tool such as a shovel or a pick.  Tunnelling ability increases with
strength and tool weight.  This command can take a count, requires a
direction, and is affected by the "always_repeat" option.

<a id="tag-26"></a>$`\color{#00AD00}{\textsf{Open a door or chest (o)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;To open an object such as a door or chest, you must use this
command.  If the object is locked, you will attempt to pick the
lock based.  Some doors will be jammed shut and may have to be
forced open.  You may need several tries to open a door or chest.
Open can take a count, requires a direction, and is affected by
the "always_repeat" option.

<a id="tag-5"></a>$`\color{#00AD00}{\textsf{Close a door (c)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Non-intelligent and some other creatures cannot open doors, so
shutting doors can be quite valuable.  Broken doors cannot be closed.
Bashing a door open may break it. Close can take a count, requires a
direction, and is affected by the "always_repeat" option.

<a id="tag-19"></a>$`\color{#00AD00}{\textsf{Jam a door (j) or Spike a door (S)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Many monsters can simply open closed doors, and can eventually
get through a locked door.  You may therefore occasionally want
to jam a door shut with iron spikes.  Each spike used on the door
will make it harder to bash down the door, up to a certain limit.
Smaller monsters are less able to bash down doors.  In order to
use this command, you must be carrying iron spikes.  Jam or Spike
requires a direction.

<a id="tag-4"></a>$`\color{#00AD00}{\textsf{Bash a door (B) or Force a door (f)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command allows you to bash down jammed doors.  Your bashing
ability increases with strength.  Bashing open a door can (briefly)
throw you off balance.  Doors that are stuck, or which have been
jammed closed with spikes can only be opened by bashing, and all
closed doors can be bashed open if desired.  Bashing a door open
may permanently break it so that it can never be closed.  Bash or
Force can take a count, requires a direction, and is affected by
the "always_repeat" option.

<a id="tag-63"></a>$`\color{#00AD00}{\textsf{Alter (+)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This special command allows the use of a single keypress to select
any of the "obvious" commands above (attack, tunnel, bash, open,
close), and, by using macros or keymaps, to combine this keypress
with directions.  In general, this allows the use of the
"control" key plus the appropriate "direction" key (including the
roguelike direction keys in roguelike mode) as a kind of generic
"alter the terrain feature of an adjacent grid" command.  Alter
can take a count, requires a direction, and is affected by the
"always_repeat" option.

<a id="tag-43"></a>$`\color{#00AD00}{\textsf{Engrave the floor (x)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The dungeon is full of magics, and as such pools of it collect on
the floor in places. With the "inscribe" command, it is possible
to create some spell effects by inscribing words you have read from
various parchments detailing the languages used within the dungeon.
Then, if there is enough mana collected on that square, walking over
the inscription will trigger the spell. Some spells can be triggered
only by the player, some only by monsters, and some are triggered by
both.

<a id="tag-46"></a>$`\color{#00AD00}{\textsf{Steal (Z)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows the player to try to steal items from shops. Also allows
rogues to steal from monsters.

## <a id="tag-118"></a>Spell and Prayer Commands

<a id="tag-3"></a>$`\color{#00AD00}{\textsf{Browse a book (b) or Peruse a book (P)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Only characters with some knowledge in the magic schools, such as
mages, priests, rogues, and rangers, can read magic spellbooks.
Warriors normally cannot read any books.  When this command is used,
all of the spells or prayers contained in the selected book are
displayed, along with information such as their level, the amount of
mana or piety required to cast them, and whether or not you know the
spell or prayer.

<a id="tag-14"></a>$`\color{#00AD00}{\textsf{Gain new skills (G)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to access the skills menu and spend the skill points
you gain at each new character level to increase the range of things
your character is able to do.

<a id="tag-91"></a>$`\color{#00AD00}{\textsf{Gain new abilities (N)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to access the Abilities menu and spend the skill points
you gain at each new character level to increase the range of things
your character is able to do.

<a id="tag-24"></a>$`\color{#00AD00}{\textsf{Cast a spell / Pray a prayer (m) / Use a mental power}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;To cast a spell or prayer, you must have the skill level required in
that school of magic to be able access that spell, and a book that
contains that spell in your inventory (for most schools). Each spell
has a chance of failure which starts out fairly large but decreases
as you gain levels.  If you don't have enough mana to cast a spell,
you will be told you do not have enough mana to cast it. Since in most
cases you must read the spell from a book, you cannot be blind or
confused while casting, and there must be some light present.

Some classes (for example, Thaumaturgists) have the ability to use
some magic without actually needing spell books of any sort. These
classes are able to access their magical powers through the use of
the 'm' command.

<a id="tag-39"></a>$`\color{#00AD00}{\textsf{Use bonus power (if any) (U) or (O)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Some races and classes have special natural abilities. All of these
possible abilities are listed in an index under the U (or O) command.
These type of abilities can include the Vampire's bite, a DeathMold's
telekinesis, and a RohanKnight's light speed capabilities.

## <a id="tag-119"></a>Object Manipulation Commands

<a id="tag-10"></a>$`\color{#00AD00}{\textsf{Eat some food (E)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You must eat regularly to prevent starvation.  As you grow hungry,
a message will appear at the bottom of the screen saying "Hungry".
If you go hungry long enough, you will become weak, then start
fainting, and eventually, you may will die of starvation.  You
may use this command to eat food in your inventory.  Note that
you can sometimes find food in the dungeon, or you can butcher
corpses of killed creatures to obtain raw meat, but it is not
always wise to eat strange food.

<a id="tag-12"></a>$`\color{#00AD00}{\textsf{Fuel your lantern/torch (F)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If you are using a torch and have more torches in your pack,
or you are using a lantern and have flasks of oil in your pack,
then your can "refuel" them with this command.  Torches and Lanterns
are limited in their maximal fuel.  In general, two flasks will fully
fuel a lantern and two torches will fully fuel a torch.

<a id="tag-30"></a>$`\color{#00AD00}{\textsf{Quaff a potion (q)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to drink a potion.  Potions affect the player in
various ways, but the effects are not always immediately obvious.

<a id="tag-32"></a>$`\color{#00AD00}{\textsf{Read a scroll (r)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to read a scroll.  Scroll spells usually have an
area effect, except for a few cases where they act on other objects.
Reading a scroll causes the parchment to disintegrate as the scroll
takes effect.  Most scrolls which prompt for more information can
be aborted (by pressing escape), which will stop reading the scroll
before it disintegrates.

<a id="tag-58"></a>$`\color{#00AD00}{\textsf{Inscribe an object (\{)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command inscribes a string on an object.  The inscription is
displayed inside curly braces after the object description.  The
inscription is limited to the particular object (or pile) and is
not automatically transferred to all similar objects.  Under certain
circumstances, ToME will display "fake" inscriptions on certain
objects ("cursed", "broken", "tried", "empty", "NN% off") when
appropriate.  These "fake" inscriptions are "covered up" by real
inscriptions, but will re-appear if the real inscription is removed.
In addition, ToME will occasionally place a "real" inscription on
an object for you, normally as the result of your character getting
a "feeling" about the item.  All characters will get "feelings" about
weapons and armor after carrying them for a while.  Warriors get the
most detailed feelings, and get them quicker than any other class.
An item labeled as "{empty}" was found to be out of charges, and an
item labeled as "{tried}" is a "flavoured" item which the character
has used, but whose effects are unknown.  Certain inscriptions have
a meaning to the game, see "@#", "@x#", "!\*", and "!x", in the section
on [inventory object selection.](#tag-90)

<a id="tag-59"></a>$`\color{#00AD00}{\textsf{Uninscribe an object (\})}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command removes the inscription on an object.  This command will
have no effect on "fake" inscriptions added by the game itself.

<a id="tag-15"></a>$`\color{#00AD00}{\textsf{Hack up a corpse (h or \$)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Corpses can be cut up into smaller pieces of meat, allowing the user to
eat the meat, or cure it for later use.

<a id="tag-21"></a>$`\color{#00AD00}{\textsf{Cure meat (K)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Curing meat requires the use of a potion of salt water, and is used to
protect meat from hacked-up corpses from going bad.

<a id="tag-16"></a>$`\color{#00AD00}{\textsf{Drink from a fountain (H)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;All fountains in Arda are magical, and act like magical potions.  The
game will ask you whether you want to quaff from a fountain or to fill
empty bottles.  The only way to identify the type of fountain is to
fill your bottles from it and see what you get.

<a id="tag-44"></a>$`\color{#00AD00}{\textsf{Give item to monster (y)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command is used to give an item within your inventory to a monster
standing next to you. The monster may not accept the item you give it,
however.

<a id="tag-96"></a>$`\color{#00AD00}{\textsf{Chat (Y)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command allows you to chat with someone. Be warned that most
monsters won't chat

## Magical Object Commands

<a id="tag-2"></a>$`\color{#00AD00}{\textsf{Activate an artifact (A)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You have heard rumours of special weapons and armour deep in the
Pits, items that can let you breath fire like a dragon or light
rooms with just a thought.  Should you ever be lucky enough to
find such an item, this command will let you activate its special
ability.  Special abilities can only be used if you are wearing or
wielding the item.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Note that there are also a few common objects that can be activated,
e.g. music instruments, monster eggs and spell-storing mage staves,
and that some artifacts, so-called "junkarts", can't be wielded, but
must be activated from the backpack.

<a id="tag-1"></a>$`\color{#00AD00}{\textsf{Aim a wand (a) or Zap a wand (z)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Wands must be aimed in a direction to be used.  Wands are magical
devices, and therefore there is a chance you will not be able to
figure out how to use them if you aren't good with magical
devices.  They will fire a shot that affects the first object or
creature encountered or fire a beam that affects anything in a
given direction, depending on the wand.  An obstruction such as a
door or wall will generally stop the effects from traveling any
farther.  This command requires a direction and can use a target.

<a id="tag-38"></a>$`\color{#00AD00}{\textsf{Use a staff (u) or Zap a staff (Z)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command will use a staff.  A staff is normally very similar
to a scroll, in that they normally either have an area effect or
affect a specific object.  Staves are magical devices, and there
is a chance you will not be able to figure out how to use them.

<a id="tag-45"></a>$`\color{#00AD00}{\textsf{Zap a rod (z) or Activate a rod (a)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Rods are extremely powerful magical items, which cannot be burnt
or shattered, and which can have either staff-like or wand-like
effects, but unlike staves and wands, they don't have charges.
Instead, they draw on the ambient magical energy to recharge
themselves, and therefore can only be activated once every few
turns.  The recharging time varies depending on the type of rod.
This command may require a direction (depending on the type of
rod, and whether you are aware of its type) and can use a target.

## <a id="tag-120"></a>Throwing and Missile Weapons

<a id="tag-11"></a>$`\color{#00AD00}{\textsf{Fire an item (f) or Fire an item (t)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You may throw any object carried by your character.  Depending on
the weight, it may travel across the room or drop down beside you.
Only one object from a pile will be thrown at a time.  Note that
throwing an object will often cause it to break, so be careful!\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If you throw something at a creature, your chances of hitting it
are determined by your pluses to hit, your ability at throwing,
and the object's pluses to hit.  Once the creature is it, the
object may or may not do any damage to it.  You've heard rumors
that some objects found in the dungeon can do huge amounts of
damage when thrown, but you're not sure which objects those
are....  Note that flasks of oil will do a fairly large chunk
of damage to a monster on impact, supposedly representing fire
damage, but it works against fire elementals too...  If you are
wielding a missile launcher compatible with the object you are
throwing, then you automatically use the launcher to fire the
missile with much higher range, accuracy, and damage, then you
would get by just throwing the missile.  Fire or Throw requires
a direction.  Targeting mode (see the next command) can be invoked
with "\*" at the "Direction?" prompt.

<a id="tag-40"></a>$`\color{#00AD00}{\textsf{Throw an item (v)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You may throw any object carried by your character.  The lighter
the object, the farther you can throw it.  Only one object from a
stack may be thrown at a time.  Throwing an object may break it.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If you throw something at a monster, your chances of hitting it
are determined by your pluses to hit, your ability at throwing,
and the object's pluses to hit.  If the object hits the monster,
it may or may not do damage.  Some objects, such as weapons, or
flasks of oil, can do a substantial amount of damage.  This
command requires a direction, and can take a target.

<a id="tag-55"></a>$`\color{#00AD00}{\textsf{Targeting Mode (*)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This will allow you to aim your spells and such at a specific
monster or grid, so that you can point directly towards that
monster or grid (even if this is not a "compass" direction) when
you are asked for a direction.  You can set a target using this
command, or you can set a new target at the "Direction?" prompt when
appropriate.  At the targeting prompt, you have many options.  First
of all, targetting mode starts targetting nearby monsters which can
be reached by "projectable" spells and thrown objects.  In this mode,
you can press "t" (or "5" or ".") to select the current monster,
space to advance to the next monster, "-" to back up to the previous
monster, direction keys to advance to a monster more or less in that
direction, "r" to "recall" the current monster, "q" to exit targetting
mode, and "p" (or "o") to stop targetting monsters and enter the mode
for targetting a location on the floor or in a wall.  Note that if
there are no nearby monsters, you will automatically enter this mode.
Note that hitting "o" is just like "p", except that the location
cursor starts on the last examined monster instead of on the player.
In this mode, you use the "direction" keys to move around, and the
"q" key to quit, and the "t" (or "5" or ".") key to target the cursor
location.  Note that targetting a location is slightly "dangerous",
as the target is maintained even if you are far away.  To cancel an
old target, simply hit "\*" and then ESCAPE (or "q").  Note that when
you cast a spell or throw an object at the target location, the path
chosen is the "optimal" path towards that location, which may or may
not be the path you want.  Sometimes, by clever choice of a location
on the floor for your target, you may be able to convince a thrown
object or cast spell to squeeze through a hole or corridor that is
blocking direct access to a different grid.  Launching a ball spell
or breath weapon at a location in the middle of a group of monsters
can often improve the effects of that attack, since ball attacks are
not stopped by interposed monsters if the ball is launched at a target.
This command takes no time.

## <a id="tag-121"></a>Looking Commands

<a id="tag-25"></a>$`\color{#00AD00}{\textsf{Full screen map (M)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command will show a map of the entire dungeon, reduced by a
factor of nine, on the screen.  Only the major dungeon features
will be visible because of the scale, so even some important
objects may not show up on the map.  This is particularly useful
in locating where the stairs are relative to your current
position, or for identifying unexplored areas of the dungeon.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command takes no time.

<a id="tag-23"></a>$`\color{#00AD00}{\textsf{Locate player on map (L) or Where is the player (W)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command lets you scroll your map around, looking at all sectors
of the current dungeon level, until you press escape, at which point
the map will be re-centred on the player if necessary.  To scroll
the map around, simply press any of the "direction" keys.  The top
line will display the sector location, and the offset from your
current sector.  This command takes no time.

<a id="tag-22"></a>$`\color{#00AD00}{\textsf{Look around (l) or Examine things (x)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command is used to look around at nearby monsters (to determine
their type and health) and objects (to determine their type).  It is
also used to find out what objects (if any) are under monsters, and
if a monster is currently inside a wall.  This command takes no time.
When you are looking at something, you may hit space for more details,
or to advance to the next interesting monster or object, or minus ("-")
to go back to the previous monster or object, or a direction key to
advance to the nearest interesting monster or object (if any) in that
general direction, or "r" to recall information about the current
monster race, or "q" or escape to stop looking around.  You always
start out looking at the "nearest" interesting monster or object.

<a id="tag-18"></a>$`\color{#00AD00}{\textsf{Observe an item (I)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command lets you observe a previously \*identified\* item.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This will tell you things about the special powers of the object.
Currently, it only makes sense for artifacts and ego-items.

## <a id="tag-122"></a>Message Commands

<a id="tag-53"></a>$`\color{#00AD00}{\textsf{Repeat level feeling (^F)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Repeats the feeling about the dungeon level that you got when you
first entered the level.

<a id="tag-62"></a>$`\color{#00AD00}{\textsf{View previous messages (^P)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command shows you all the recent messages.  You can scroll
through them, or exit with ESCAPE.  This command takes no time.

<a id="tag-69"></a>$`\color{#00AD00}{\textsf{Take notes (:)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command allows you to take notes, which will then appear in your
note file. The note file can be displayed through the "Display Current
Knowledge" command (\~ or \|). This command takes no time.

## <a id="tag-123"></a>Game Status Commands

<a id="tag-6"></a>$`\color{#00AD00}{\textsf{Character Description (C)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Brings up a full description of your character, including your
skill levels, your current and potential stats, and various other
information.  From this screen, you can change your name or use
the file character description command to save your character
status to a file.  That command saves additional information,
including your background, your inventory, and the contents of
your house.

<a id="tag-82"></a>$`\color{#00AD00}{\textsf{Display Current Knowledge (~ or |)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The command opens a menu from which you can lookup information
collected so far. This includes known artifacts, unique monsters,
identified objects, killed creatures, recall depths, acquired
corruptions, current pets, current quests, current fates, known
traps, known dungeon towns and last but not least the note file.

Display known artifacts\
This selection lists all of the artifacts that you have encountered.
Any artifact that appears in this list, which you cannot seem to
find, has been lost forever.  The "preserve" mode will prevent
you from accidentally losing any artifacts, but will also prevent
you from ever getting a "special" level feeling.

Display known uniques\
Brings up a list of known unique monsters, plus their current
status.  Once killed, unique monsters never show up again, with a
few remarkable exceptions.

Display known objects\
This list all 'flavoured' objects (such as rings, scrolls, wands,
potions, etc.) which you have identified.

Display kill count\
This lists all killed creatures together with a total kill count.

Display recall depths\
This lists all recall depths of entered dungeons as well as marks
the current recall dungeon with an asterisk.

Display corruptions\
This lists all acquired corruptions with their beneficial and
detrimental effects.

Display current pets\
Display current quests\
Display current fates\
Display known traps\
Display known dungeon towns

Display notes\
Shows you your notes file, where all remarkable events are noted.
You can add notes yourself by using the "Take notes" command (:).

<a id="tag-70"></a>$`\color{#00AD00}{\textsf{Time of the day (^T)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command is used to give the current date and time within the game.
Extremely useful for characters such as Vampires to check whether
it is safe to leave the dungeon.

## <a id="tag-124"></a><a id="tag-125"></a>Saving and Exiting Commands

<a id="tag-75"></a>$`\color{#00AD00}{\textsf{Save and Quit (Ctrl-X)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;To save your game so that you can return to it later, use this
command.  Save files will also be generated (hopefully) if the
game crashes due to a system error.  After you die, you can use
your savefile to play again with the same options and such.

<a id="tag-68"></a>$`\color{#00AD00}{\textsf{Save (Ctrl-S)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command saves the game but doesn't exit ToME.  Use this
frequently if you are paranoid about having the computer crash
while you are playing.

<a id="tag-31"></a>$`\color{#00AD00}{\textsf{Quit (commit suicide) (Q)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Kills your character and exits ToME.  You will be prompted to
make sure you really want to do this, and then asked to verify
that choice.  Note that dead characters are dead forever.

## <a id="tag-126"></a><a id="tag-127"></a>User pref file commands

<a id="tag-65"></a>$`\color{#00AD00}{\textsf{Interact with options (=)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allow you to interact with options.  Note that using the "cheat"
options may mark your savefile as unsuitable for the high score
list.  You may change normal options using the "X" and "Y" user
pref commands.  You must use the "redraw" command (^R) after
changing certain options.

<a id="tag-49"></a>$`\color{#00AD00}{\textsf{Interact with macros (@)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allow you to interact with macros.  You may load or save macros
from user pref files, create macros of various types, or define
keymaps.  You must define a "current action", shown at the bottom
of the screen, before you attempt to use any of the "create macro"
commands, which use that "current action" as their action.  This
is a horrible interface, and will be fixed eventually.

<a id="tag-51"></a>$`\color{#00AD00}{\textsf{Interact with visuals (%)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allow you to interact with visuals.  You may load or save visuals
from user pref files, or modify the attr/char mappings for the
monsters, objects, and terrain features.  You must use the "redraw"
command (^R) to redraw the map after changing attr/char mappings.

<a id="tag-54"></a>$`\color{#00AD00}{\textsf{Interact with colors (&)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allow the user to interact with colors.  This command only
works on some systems.

<a id="tag-47"></a>$`\color{#00AD00}{\textsf{Interact with the system (!)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allow the user to interact with the underlying visual system.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command is currently unused.

<a id="tag-71"></a>$`\color{#00AD00}{\textsf{Enter a user pref command (")}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ToME stores your preferences in files called "user pref files",
which contain comments and "user pref commands", which are simple strings
describing one aspect of the system about which the user has a preference.
You may enter single user pref commands directly, using the special "Enter
a user pref command" command, activated by "double quote". You may have to
use the "redraw" command (^R) after changing certain of the aspects of the
game, to allow ToME to adapt to your changes.

## <a id="tag-128"></a>Help

<a id="tag-84"></a>$`\color{#00AD00}{\textsf{Help (?)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Brings up the ToME on-line help system.  Note that the help
files are just text files in a particular format, and that other
help files may be available on the Net.  In particular, there are
a variety of spoiler files which do not come with the standard
distribution.  Check the place you got ToME from or ask on the
newsgroup rec.games.roguelike.angband about them.

<a id="tag-83"></a>$`\color{#00AD00}{\textsf{Identify Symbol (/)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use this command to find out what a character stands for.  For
instance, by pressing "/.", you can find out that the "." symbol
stands for a floor spot.  When used with a symbol that represents
creatures, the this command will tell you only what class of
creature the symbol stands for, not give you specific information
about a creature you can see.  To get that, use the Look command.

There are three special symbols you can use with the Identify
Symbol command to access specific parts of your monster memory.
Typing Ctrl-A when asked for a symbol will recall details about
all monsters, typing Ctrl-U will recall details about all unique
monsters, and typing Ctrl-N will recall details about all
non-unique monsters.

If the character stands for a creature, you are asked if you want
to recall details.  If you answer yes, information about the
creatures you have encountered with that symbol is shown in the
Recall window if available, or on the screen if not.  You can also
answer "k" to see the list sorted by number of kills, or "p" to
see the list sorted by dungeon level the monster is normally found
on.  Pressing ESCAPE at any point will exit this command.

<a id="tag-41"></a>$`\color{#00AD00}{\textsf{Game Version (V)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command will tell you what version of ToME you are using.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For more information, see the "version.txt" help file.

## <a id="tag-129"></a>Extra Commands

<a id="tag-85"></a>$`\color{#00AD00}{\textsf{Repeat last command (n)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This will automatically repeat the last command you inputted.

<a id="tag-27"></a>$`\color{#00AD00}{\textsf{Sacrifice at an altar (O)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Altars are places dedicated to the worship of a particular God. To
start worshipping the God who owns the altar, you must first sacrifice
on their altar.

Be warned, not all Gods are equal in power, and once you have selected
a God to worship, it is almost impossible to change which God you worship.
When your God is happy with you, you will receive more benefits from them.
Your God's happiness will decrease over time, so you will need to accomplish
deeds that increase your standing.  Note that there is no requirement
for most classes to worship any God. (See [gods.txt](gods.md) for more information)

<a id="tag-28"></a>$`\color{#00AD00}{\textsf{Pray to your God (p)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If you worship a God, you have the option of praying. The effects of
praying differ considerably depending on the god, ranging from the
battle frenzy of paladins to the self-healing powers of druids.
However, Gods do not like being disturbed, with negative effects on
your piety. See [gods.txt](gods.md) for more information.

<a id="tag-29"></a>$`\color{#00AD00}{\textsf{Pet commands (P)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;From time to time, you may acquire a pet within the dungeon. Pets are able
(to a more or less limited extent) to follow some simple commands, like
follow me. These commands are all accessed through the menu under "Pet
Commands".

<a id="tag-52"></a>$`\color{#00AD00}{\textsf{Toggle Choice Window (^E)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Toggles the display in the choice window (if available) between
your inventory and your equipment.  This command only applies if
you are running ToME under a windowing environment and the
choice window is available.  This also redraws the choice window.

<a id="tag-66"></a>$`\color{#00AD00}{\textsf{Redraw Screen (^R)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command adapts to various changes in global options, and
redraws all of the windows.  This command should be used after
changing various global properties (options, attr/char mappings,
color definitions, etc).  When in doubt, use it.

<a id="tag-56"></a>$`\color{#00AD00}{\textsf{Load screen dump (left-paren)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command loads a "snap-shot" of the current screen from the file
"dump.txt", and displays it on the screen.

<a id="tag-57"></a>$`\color{#00AD00}{\textsf{Save screen dump (right-paren)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command dumps a "snap-shot" of the current screen to the file
"dump.txt", including encoded color information.

<a id="tag-64"></a>$`\color{#00AD00}{\textsf{Quit to next midi song (^Q)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In the DOS binary (and maybe Windows) of ToME, it is possible for
the game to play any midi song in the lib/xtra/music directory. This
command allows the player to force the game to finish the current song
and move on to another one (i.e. if you are tired of hearing the current
song, you can change it).

<a id="tag-97"></a>$`\color{#00AD00}{\textsf{Record macros (\$)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This is an easier way to create macros. Activate it, press the key
sequence for your macro, reactivate it and it will create the macro
for you. Note than when possible using the @ key at item selection
is a good idea since it removes the need to inscribe items.

<a id="tag-98"></a>$`\color{#00AD00}{\textsf{Take html screenshot (^])}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Creates an html screenshot of the current screen.

<a id="tag-89"></a>$`\color{#00AD00}{\textsf{Begin extended command (#)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Begins an extended command.  Type "help" or "?" at the prompt for a
list of these commands.

\--\
Original: Alexander Cutler and Andy Astrand\
Updated (2.7.6): Russ Allbery (rra@cs.stanford.edu)\
Updated (2.7.9): Ben Harrison (benh@phial.com)\
Updated PernAngband 5.x.x: Dawnmist (angband@dawnmist.8m.com)
Updated for ToME 2.1
