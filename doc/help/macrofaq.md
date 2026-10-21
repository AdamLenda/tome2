<!-- Generated from lib/help/macrofaq.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-43"></a><a id="tag-44"></a>ToME Macro FAQ

&nbsp;&nbsp;Original Angband Macro FAQ by Jim Lyon\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(jplyon@attglobal.net)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;09-Dec-2000\
Compiled from usenet postings to r.g.r.a\
&nbsp;&nbsp;&nbsp;and Angband source & documentation

$`\color{#00A5A5}{\textsf{Edited by Dawnmist (angband@dawnmist.8m.com)}}`$\
&nbsp;&nbsp;&nbsp;$`\color{#00A5A5}{\textsf{for PernAngband 5.x.x on 03-Aug-2001}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$`\color{#00A5A5}{\textsf{with permission from Jim Lyon}}`$

## <a id="tag-30"></a>1. Introduction

### 1.1 About this FAQ

This FAQ is mean to be a companion to the standard ToME help files
for using inscriptions, macros, and keymaps. The ToME help files
which also describe them are listed in the "References" section.

This documentation is for ToME, version 4.2.x.

---

$`\color{#00A5A5}{\textsf{SPOILER ALERT}}`$

---

This document gives some information on how the game does or doesn't
work that might be considered spoiling.\
(Most players advanced enough to use macros probably won't notice.)

### 1.2 Table of contents

&nbsp;[1. Introduction](#tag-30)\
&nbsp;[2. Quick start tutorial](#tag-5)\
&nbsp;[3. Overview](#tag-32)\
&nbsp;[4. Common macros and techniques](#tag-33)\
&nbsp;[5. Common questions](#tag-34)\
&nbsp;[6. Common problems](#tag-35)\
&nbsp;[7. Inscriptions added by the game](#tag-36)\
&nbsp;[8. Keys and commands](#tag-37)\
&nbsp;[9. Pref files](#tag-38)\
[10. Macro editing commands](#tag-39)\
[11. Advanced macro techniques](#tag-20)\
[12. Problems](#tag-41)\
[13. Miscellaneous](#tag-42)

### 1.3 Notation

$`\color{#00A5A5}{\textsf{Single Quotes (')}}`$\
These are generally used to delimit a single character to be typed in.\
These shouldn't by typed in themselves.

$`\color{#00A5A5}{\textsf{Double Quotes (")}}`$\
These are generally used to delimit a sequence of characters to be
typed in. These shouldn't by typed in themselves.

$`\color{#00A5A5}{\textsf{Parentheses ( )}}`$\
These are generally used for single-key Angband commands.

$`\color{#00A5A5}{\textsf{Braces \{ \}}}`$\
These are used to enclose inscriptions. These aren't typed in as part
of inscribing an item. They are added by the interface.

### Special Keys

The following abbreviations are used in this document. These keys may
be named differently or missing on some keyboards. Some keys may be
duplicated. These abbreviations shouldn't be typed in literally. For
example, when F1 is encountered in a string of keys to press it means
to press the F1 function key, not 'F','1', unless otherwise stated.
Additional special keys may be listed later.

|   |   |
| --- | --- |
| Alt | Alt |
| Ctrl | Control |
| Del | Delete |
| Esc | Escape |
| Enter | Enter / Return |
| F1 | Function key F1, ... |
| Shift | Shift |

### System abbreviations

Each system that ToME compiles on has a semi-standard 3-letter
abbreviation. These are commonly referred to in the source and docs
using "xxx" as a "wildcard" standing for any one of them. In this
document "\*\*\*" is used instead because there are actual generic files
not associated with any specific system that use "xxx". Sometimes this
refers to a feature instead of a specific system: "xxx" is used for a
generic / default file, and "new" is used for Adam Bolt's tiles.

## <a id="tag-5"></a>2. Quick Start Tutorial

This section is designed to get you quickly using the most common
keymaps and macros. Later sections explain the techniques used in more
detail. These examples may not be the "best" ones to use in real play.

### 2.0 Definitions

First, you should know some fundamental terms:

Actions are sequences of keypresses that the game can recognise. They
can't be recorded by the game, but must be input manually.

Macros and keymaps map a keypress to an action. They can be used to
customise the keyboard, reduce typing, and speed up game play. Macros
must be used when the trigger key doesn't have a system-independent
representation. Keymap actions can only contain underlying commands.\
$`\color{#00A5A5}{\textsf{Most customisation should be done with keymaps instead of macros when}}`$
$`\color{#00A5A5}{\textsf{there is a choice.}}`$

Inscriptions are "markings" which you can put on any game item. One
use is to label items in a way that doesn't depend on inventory
position. Another allows verifying the selection of an item. Under the
right conditions they can save your life.

### 2.1 Swap weapons

First inscribe your main weapon:\
(Press the following keys in sequence)

|   |   |
| --- | --- |
| 1) { | Inscribe an object |
| 2) \* | Show inventory list |
| 3) / | Switch to equipment list |
| 4) a | Main weapon slot |
| 5) @w0 | Wield when object 0 is chosen |
| 6) | (Hit Enter) |

Now inscribe the second weapon:

|   |   |
| --- | --- |
| 1) { | Inscribe an object |
| 2) \* | Show inventory list |
| 3) | (Choose letter of second weapon) |
| 4) @w0 | Wield when object 0 is chosen |
| 5) | (Hit Enter) |

Finally, ToME (unlike standard 'Vanilla' Angband) does\
not have an automatic trigger key to swap items, so it must be
created. Select a key that is not being used for any other commands
('X' in the normal keyset is free - see [command.txt](command.md)), and create
the following keymap:

|   |   |
| --- | --- |
| 1) @ | Interact with macros |
| 2) 8 | Create a keymap |
| 3) X | The trigger key for the keymap |
| 4) w0 | Wield object 0 |
| 5) | (Hit Enter) |
| 6) | (Hit Esc to exit the editor) |

Now to swap weapons, just press the trigger key 'X' which is bound to
the default keymap "w0". You may also press "w0" directly to swap.

### <a id="tag-45"></a><a id="tag-46"></a>2.2 Using the macro-recorder

You may find all the key-presses involved in ToME a long and time-consuming way
to play the game. There are ways to speed up repeated commands by assigning
them to a trigger key which can help. These are called macros or keymaps.

The most obvious use for these in ToME is for mage-types, especially sorcerors,
who rely on their spells for just about everything. Typing mbaa\*t in order to
fire a Manathrust is fine if you only have to do it once or twice, but can
quickly get annoying when you're doing it every move. Far easier to assign that
sequence of keypresses to a single trigger key which you can then press as many
times as you need. (Until your SP run out of course!)

The easiest way to assign a macro is to use the macro-recorder. Start this by
hitting the '<span>$</span>' key. You'll then receive a message telling you that the macro
recorder has now started and you will need to press the '<span>$</span>' key a second time
to stop the recorder. Preparation is all important here. It is best to be in a
situation where you really NEED to cast the spell before recording the macro,
so you use all the correct casting techniques and the game behaves as it would
in a real (combat) situation (if the spell is to be generally cast in combat).

So assuming we're going to create a macro for manathrust. We've walked into a
room and there's a nasty small kobold. What do we do?

|   |   |
| --- | --- |
| 1)  <span>$</span> | Start macro recorder |
| 2)  \*t | target monster (or player if no monster in Line of sight) |
| 3)  m | open skills menu |
| 4)  @ | enters verbose mode |
| 5)  Cast a Spell | selects skill to use - CASE SENSITIVE |
| 6)  @ | enters verbose mode |
| 7)  Manathrust | casts spell from any book/spell container - CASE SENSITIVE |
| 8)  <span>$</span> | end macro recorder |
| 9)  y | confirms macro keystrokes$`\color{#00FFFF}{\colorbox{black}{*}}`$ |
| 10) | (choose trigger key) |
| 11) @ | opens macro saving/loading screen |
| 12) 2 | appends macros to a file |
| 13) | (choose a name for the file, e.g. sorceror.prf) |
| 14) | (Hit Enter) |
| 15) | (Hit Esc to exit the editor) |

This will search for the spell in all your books and equipment. If it is found,
in either a book or a wielded item that contains a spell, then the spell is
cast at the targetted monster.

This technique can be used for all the other skills as well (Use Mindcraft,
Forge Ammo) etc.

$`\color{#00FFFF}{\colorbox{black}{*}}`$If you answer no the recorder continues recording keypresses. If
you know you have made a mistake, you need to answer yes, and then not
save the macro!

### <a id="tag-12"></a>2.3 Prevent unwanted use of an item

$`\color{#00A5A5}{\textsf{Prevent "losing" an item by "accident":}}`$

|   |   |
| --- | --- |
| 1) { | Inscribe an object |
| 2) \* | Show inventory list |
| 3) | (Choose an item) |

4\) !d!k!v\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;!d - don't drop (d)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;!k - don't destroy (k)\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;!v - don't throw (v)\
5\)      (Hit Enter)

This prevents dropping, destroying, or throwing the item. You will be
asked if you really want to do so. This is one of the most common
inscriptions used, and one of the most useful.

$`\color{#00A5A5}{\textsf{Prevent "using" an item at all:}}`$

|   |   |
| --- | --- |
| 1) { | Inscribe an object |
| 2) \* | Show inventory list |
| 3) | (Choose an item) |
| 4) !\* | Don't do anything with this item without verifying |
| 5) | (Hit Enter) |

This inscription is commonly used on Scrolls of Word of Recall...

### <a id="tag-8"></a>2.4 Saving these macros and keymaps for reuse

Save the macros and keymaps for reuse by the current character:

|   |   |
| --- | --- |
| 1) @ | Interact with macros |
| 2) 2 | Append macros to a file |

(optionally enter a filename: e.g. dump.prf or dump.txt)
(Hit Enter to save the file with the filename shown)\
3\) 6    Append keymaps to a file\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Hit Enter to save the file with the filename shown)\
4\)      (Hit Esc to exit the editor)

This pref file will be automatically loaded any time a character with
a name, race, or class matching the filename is loaded.

The "Append macros/keymaps to a file" commands will append ALL current
macros/keymaps to the given file. They will not overwrite the file.

You should edit the file to remove macros that weren't added by you,
to reduce clutter and prevent errors. Unfortunately the best way to do
this is still "by hand". Open up the pref file in a text editor and
remove the duplicate macros and keymaps added. These will be added
after the headers "# Automatic macro dump" and "# Automatic keymap
dump". The ones you added will be the very last ones in the list. The
others are the entire set of keymaps and macros from all other prefs
loaded. (This step isn't necessary, but is very helpful.)

## <a id="tag-32"></a>3. Overview

### 3.1 Inscriptions

Inscriptions are "markings" which you can inscribe on any game item.

One common use is recording where you got one of your favorite items.
Example: The Broad Sword 'Glamdring' (2d5) (+10,+15) {icky thing, 50'!}

Another is to note important resists or activations on an item to make
figuring out resist combinations easier.\
Example: The Nice Shiny Armor (-3) \[35,+25\] {resDk,resDis,A:Geno}

Inscriptions can "number" an item so that you don't have to know where
it is in your inventory.\
Example: inscribing your scrolls {@r1} lets you use '1' at the prompt
for which scroll to read, instead of having to use the inventory letter,
which can change unnoticed.

Number inscriptions work together with macros to allow reproducible
labeling of items independent of inventory position.

Note that the game produces "fake" inscriptions, which look like real
inscriptions, but are really just displayed the same way (e.g. "cursed").

Finally, if you are in symbiosis with another creature, you can name it by
inscribing it with "#named SomeName" (the word "#named" must be entered
literally at the start of the inscription).  This will tell the game that
your symbiotic partner should be referred to by its name, rather than simply
"Your white jelly".  This has no effect on game play other than the aesthetic.

### 3.2 Macros

Macros are mappings from a single "logical" keypress to a sequence of
keypresses, allowing you to use special keys on the keyboard, such as
function keys or keypad keys, possibly in conjunction with modifier
keys, to "automate" repetitive multi-key commands that you use a lot.

$`\color{#00A5A5}{\textsf{For keys which don't have a system-independent representation, such as}}`$
$`\color{#00A5A5}{\textsf{function keys, this is the only way to change their behavior.}}`$

### 3.3 Keymaps

Keymaps are vaguely related to macros. A keymap maps a single keypress
to a series of keypresses, which bypass both other keymaps and any
macros. Angband uses keymaps to map the original and the roguelike
keysets to the underlying command set, and allows the user to modify or
add keymaps of their own. All keymap actions must be specified using
underlying commands. Keymaps and macros aren't expanded. The original
keyset is almost identical to the underlying keyset, except that
"numbers" are mapped to ";" plus a direction, "5" is mapped to ",",
and a few control-keys are mapped to various things. See [command.txt](command.md)
for the full set of underlying commands. Keymaps also allow the
"disabling" of a command by mapping it to "\\x00".

### 3.4 Pref files

Preference files save commands such as macros and keymaps which are
used to customise the game. They are used to implement the "original"
and "roguelike" keysets. They provide default appearances for items.

They also implement the default behaviors which make Angband look and
play the same (for the most part) on different systems.

Pref files can be saved with the name of a player name, class, and
race, and anytime a player with a matching characteristic is loaded,
the appropriate pref file is loaded. This makes some customisations
transparent and automatic.

Pref files let you do some things that could otherwise only reasonably
be done by changing the info files or source, such as changing the
appearance of a given terrain feature, or the symbol used for the
player.

Pref files let you set up and save your favorite game options, and
have them available for new characters without having to redo them.

## <a id="tag-33"></a>4. Common macros and techniques

### <a id="tag-13"></a>4.1 Clearing the command buffer

$`\color{#FF00FF}{\textsf{++++++++++ This is one of the most important techniques! ++++++++++}}`$

Almost all action strings should begin with a sequence to clear the
buffer of existing commands and messages. These sequences are often
omitted in usenet postings and in this FAQ because they clutter the
description, but they should almost always be used.

If an unfinished command is still waiting for input when you press the
trigger key of a macro or keymap, the characters of its action string
will be taken as input for the command. The command will ignore keys
it doesn't know how to handle until it finds one that it does. This
often leads to something completely unexpected, with embarrassing
results such as your death, or losing a really nifty item.

If there are still messages waiting, the first characters in the
action will instead just clear the waiting messages. How this happens
depends on whether the [option (quick_messages)](option.md#tag-1) is set. Then the action
will start executing in the middle of its action string, with equally
dangerous results as in the above case. Note that some messages caused
by a command are quite rare, and others could be produced by a game
state change like becoming hungry that has nothing to do with the command.

These types of problems are more common when using an action such as
auto-firing where a trigger key is repeatedly pressed.

$`\color{#00A5A5}{\textsf{"eee"}}`$\
Multiple escapes are used to clear the command buffer. Escape cancels
any command/input still being processed, and also clears a \[single\]
message whether/not the (quick_messages) option is set. This string
should be used to begin all action strings. It is also wise to put it
between actions in multi-action macros. Note that this technique can
also be dangerous, hiding warnings or important information.\
Example: an action like "\*tf1" would be changed to "\\e\\e\\e\*tf1".

There are a few situations in which you do not want to use escapes.\
For example, after the spell Detect Monsters, an escape will clear the
detection. Or if the action is part of a multi-part action or is meant
to wait for user input such as the firing action "f1" which will wait
for targeting information.

$`\color{#00A5A5}{\textsf{"sss"}}`$\
Spaces are useful for clearing messages, but won't cancel a command
that is waiting for an item choice. Sometimes it is useful to split
an action into two parts and bind them to two separate trigger keys.
Prefixing spaces before the 2nd action will discard any remaining
messages without canceling unfinished commands from the 1st one. Some
players create a macro consisting of a large number of spaces to be
used to clear a flood of messages.

See sections:\
\- ["Messages and Questions"](#tag-1) for how to deal with them.\
\- ["My macro outputs "e - Floating Eye"..."](#tag-2) for an example of a common\
&nbsp;&nbsp;mistake using escape sequences.\
\- ["My macro drops/takes off my main weapon!"](#tag-3) for an example of the\
&nbsp;&nbsp;kind of thing that can go wrong when you fail to use them.\
\- ["What just killed me?"](#tag-4) for an example of skipping over messages\
&nbsp;&nbsp;\*too\* fast.

### 4.2 Swap weapons

If you followed the [Quick-Start Tutorial](#tag-5) in Section 2.1, the 'X' key has
the keymapping "w0", which will wield the first item inscribed as "@0"
or "@w0". This will swap between 2 weapons which are both inscribed with
{@0} or {@w0}. If there is more than one item in the inventory inscribed
as 0, it will use the first one.

This will also work for other wieldable items. For example, if you
have a helm which gives telepathy, which can be a real pain when you
need to rest, it can be used to swap it with another helm.

Inscribing weapons with {@w1@w0}, {@w2@w0} allows directly wielding a
specific one. If you don't want that ability, you can just inscribe
both with {@w0}. These can also be inscribed as just {@1@0} and {@2@0}
if you don't inscribe any other items with numbers, although this is
not recommended.

### 4.3 Resting

$`\color{#00A5A5}{\textsf{= Rest as needed =}}`$\
"R&\\r"

|   |   |
| --- | --- |
| R | - rest |
| & | - until 100% healthy |
| \\r | - return. |

Note that this isn't particularly dangerous, because the game will
break out of the resting command if you are disturbed by hunger,
sensing a monster, ...

$`\color{#00A5A5}{\textsf{= Rest for a specific duration =}}`$\
"R100\\r"\
R   - rest\
100 - turn count\
\\r  - return

This version is useful if you are already healed up. For fighter
pseudo-id, for example. Also useful for recovering a fixed amount of
mana before/after a spell, waiting for a Recall spell to kick in,...

Note that this is one of the few times when you can directly enter the
count after the command. Usually you need to enter the count before
the command, using the (0) count command.

$`\color{#00A5A5}{\textsf{= Maximum Rest =}}`$\
"R9999\\r"

The maximum number of turns you can use as an argument. This can be
useful when waiting for shop inventory to change, etc. Be sure to take
off any non-permanent light source, and have plenty of food when you
rest for long periods of time.

### 4.4 Activate the phial

"Am\\s\\s"

|   |   |
| --- | --- |
| A | - Activate |
| m | - light source (the phial). |
| \\s | - skip message |
| \\s | - skip message |

"Am\\s\\sR50\\r"\
Activate the phial and rest for 50 turns.

This can be bound to 'F' key since you won't need to refuel lanterns
much after you have the phial :).

### 4.5 Kill item(s) on floor

The need to destroy large numbers of items arises as one reaches
deeper levels of the dungeon. The auto-squelch feature only partially
reduces the need for this. The behavior of these actions is affected
by the option (quick_messages), and the possible presence of a pile of
items on the floor.

[(quick_messages)](option.md#tag-1) allows any key to cancel a message.

In ToME, multiple items on the floor are displayed in a list.\
This allows the player to select an item from the floor by entering an
item index when there is a pile (more than one item). This generally
complicates writing these macros.

Note that space '\\s' is used to clear messages in the action strings,
but one could use escape '\\e' just as well.

Note: you cannot destroy artifacts, so these macros are safer and more
useful than they might first appear. The (k) Destroy item command will
fail when trying to destroy an artifact, leaving any following
characters in the action string, which may be interpreted differently
than anticipated.

$`\color{#00A5A5}{\textsf{"k-yy"}}`$

|   |   |
| --- | --- |
| k | - Kill item |
| - | - Select item from floor |
| y | - "yes" to query "Really destroy a \<item>?" |
| y | - skip the "you destroy the \<item>" message. |

This version only works when (quick_messages) option is on. Here the
last 'y' key gets rid of the last message, since any key will. This
won't work for piles. The 'y' will be ignored as an invalid item choice.

$`\color{#00A5A5}{\textsf{"k-ys"}}`$

|   |   |
| --- | --- |
| k | - Kill item |
| - | - Select item from floor |
| y | - "yes" to query "Really destroy a \<item>?" |

\\s  - skip the "you destroy the \<item>" message.

This version works as above, but also when (quick_messages) is off.

$`\color{#00A5A5}{\textsf{"0k-ys"}}`$

|   |   |
| --- | --- |
| 0 | - enter count (causes to skip prompt for how many to destroy) |
| k | - Kill item |
| - | - Select item from floor |

\\s  - skip the "you destroy the \<item>" message.

Destroy a single item on floor below you. Doesn't prompt for a count.\
This won't work for piles, which will prompt you for the item. Works
correctly when (quick_messages) is off, because there is no prompt
for how many to destroy.

$`\color{#00A5A5}{\textsf{"0k-aye"}}`$

|   |   |
| --- | --- |
| 0 | - enter count (causes to skip prompt for how many to destroy) |
| k | - Kill item |
| - | - Select item from floor |
| a | - either item 'a', or ignored |

\\e  - escape (ignored), or cancel message

Destroy a single item on floor below you. Doesn't ask to confirm.\
$`\color{#FF00FF}{\textsf{WARNING:}}`$ This action can destroy the first item in your inventory if
there aren't any items on the floor below you!

The leading '0' causes a prompt for a count to be skipped. If there is
a pile, the 'a' key will select the top item in the pile. If not, the
'a' will aim a wand, the following 'y' will be ignored, and the final
escape will cancel the aiming.

$`\color{#00A5A5}{\textsf{"0k-yaye"}}`$

|   |   |
| --- | --- |
| 0 | - enter count (causes to skip prompt for how many to destroy) |
| k | - Kill item |
| - | - Select item from floor |
| y | - "yes" to query "Really destroy a \<item>?", or ignored. |
| a | - top item (a) in a pile, or activate wand. |
| y | - "yes" to query "Really destroy a \<item>?" (for piles). |

\\e  - skip the "you destroy the \<item>" message.

The above action will work in most cases. This version works correctly
for piles. If there is a pile, the 'y' is ignored and the 'a' selects
the top item. If there isn't a pile, then the 'y' will correctly answer
the yes/no question "Really destroy a \<item>?", and the following "ay"
will aim a rod, and then ignore the 'y' key press, and the final escape
will cancel the aiming. Works correctly when (quick_messages) is off.\
When (quick_messages) is on, and there is no pile, the 'a' will cancel
the message, and the following 'y' will be passed through as an
unimplemented command, and the space will cancel the error message.

Backslashes "\\\\" may be required to keep the 'y's from being
interpreted as keymaps in case 'y' has been assigned one.

### 4.6 Fire missile at nearest target

Each of these needs "\\e\\e\\e\\e" afterwards to cancel up to 4 possible
messages. The first message will always occur. Note that adding too
many escapes can cause you to miss the messages in which the monster
fights back.\
\- "You have NN \<ammo> left. -more-"\
\- "The \<ammo> hits the \<monster>. -more-"\
\- "It was a \<adj> hit! The monster ... -more-"\
\- "The \<monster> dies/grunts with pain/..."

$`\color{#00A5A5}{\textsf{"f*t"}}`$

|   |   |
| --- | --- |
| f | - fire ammo from quiver slot |
| \* | - target |
| t | - select first target |

Note that targeting is affected by the option ([use_old_target](option.md#tag-4)). If
this action is used with the (use_old_target) option set, the "f"
part will fire the missile before the targeting part "\*t" is reached.\
See section ["My auto-firing macro shoots the wrong target!"](#tag-6).

$`\color{#00A5A5}{\textsf{"*tf"}}`$\
\*t  - select first target\
f   - fire ammo from quiver slot

If (use_old_target) is on, this works correctly, by selecting the
target before firing. If the option is off, it will still prompt you
to select a target, even though you just selected one.

$`\color{#00A5A5}{\textsf{"*tf*t"}}`$\
\*t  - select first target\
f   - fire ammo from quiver slot\
\*t  - select first target

This works correctly for (use_old_target) either on/off. If the option
is on, this works by selecting the target before firing. If the option
is off, the first target selection will be ignored, and firing will
wait on the second target selection.

Note that if there are no valid targets, "\*t" will select the player's
current position. Also, it is fairly easy to make safe assumptions
about the (use_old_target) option, since a player doesn't tend to
change back and forth. It is generally easier to make one set of
actions that work for (use_old_target) on, and another for it off.

Note also that the swapping weapon macro can be very useful for swapping
the type of ammo in the quiver slot when you have two different sets of
ammo you use - your standard "fire at everyone normal" ammo (usually
not enchanted), and your big damage "Uniques and nasty monster"
enchanted ammo.

### 4.7 Preventing actions

$`\color{#00A5A5}{\textsf{= Prevent selling =}}`$\
{!d}\
Prevent selling - use on main weapon, artifacts.

$`\color{#00A5A5}{\textsf{= Prevent going up/down =}}`$\
{^\<}\
Verify before going up stairs.\
{^>}\
Inscribe boots to make confirm before going down stairs.\
This can also be useful on Charisma boosting items that you wear
around town but don't want to take into the dungeon.
{^>^r^z^m^p}\
Prevent leaving town with this item. Need to catch stairs, scrolls and
rods of Recall, and Mage and Priest Word of Recall spells.

### 4.8 Warrior macros and inscriptions

$`\color{#00A5A5}{\textsf{= Identify with list =}}`$\
Inscribe Identify scrolls {@r0}.\
Then action "r0\*" will cast Identify and bring up the inventory list.

$`\color{#00A5A5}{\textsf{= Identify floor =}}`$\
"r0-" will Identify without showing the inventory.

### 4.9 Verification techniques

$`\color{#00A5A5}{\textsf{= Verify All =}}`$\
{!\*}\
verify any attempt to use this item. Useful for some things such as
Scrolls/rods of Recall that you don't want to lose or use by accident.

$`\color{#00A5A5}{\textsf{= Verify drop, destroy, throw =}}`$\
{!d!k!v}\
don't drop, destroy, or throw this item. Prevents dropping your
favorite weapon,... This is one of the most useful inscriptions, as it
prevents the kind of typing accidents that can get you killed.

$`\color{#00A5A5}{\textsf{= Verify selling =}}`$\
{!d}\
Prevents selling as well as dropping.

$`\color{#00A5A5}{\textsf{= Multiple verification =}}`$\
These inscriptions can be repeated. So {!\*!\*} will make you confirm
twice for any action using that item.

### 4.10 Canceling targeting

$`\color{#00A5A5}{\textsf{"*es"}}`$\
\*   - start targeting\
\\e  - cancel targeting.\
\\s  - skip message "Target Aborted."

OR

$`\color{#00A5A5}{\textsf{"*qr"}}`$

|   |   |
| --- | --- |
| \* | - start targeting |
| q | - cancels targeting. |
| \\r | - skip message "Target Aborted." |

This is useful before casting Stone to Mud, or a ball spell. For ball
spells you usually want to target the middle of a pack, or sometimes
to "miss" the creature in order to get the ball to detonate on a
nearby wall.

Using a targeted action after this will cause the user to be prompted
for a target.

Canceling targeting is made necessary by the existence of the option
(use_last_target), which causes an action which requires a target to
use the last target without prompting. See section\
["My auto-firing macro shoots the wrong target!"](#tag-6) for more on this.

### <a id="tag-15"></a>4.11 Automatically loading pref files

Angband automatically loads pref files when a character is loaded or
born. Among the last ones loaded are: "\<<span>$</span>RACE>.prf", "\<<span>$</span>CLASS>.prf",
and "\<<span>$</span>PLAYER>.prf", in that order. These are the best ones to use to
customise the game for individuals. The order is important because
pref files which load later will overwrite options and macros/keymaps
from previous ones.

Here \<<span>$</span>RACE> is the name of the character's race, \<<span>$</span>CLASS> is the name
of its class, and \<<span>$</span>PLAYER> is the character's name. Both \<<span>$</span>RACE> and
\<<span>$</span>CLASS> have a fixed number of choices. These are listed for ToME
in section ["Pref file loading order"](#tag-7).

Your character's name is the one that appears during game play in the
upper left hand corner of the screen. If it isn't visible there, you
can use the (C) Character description command. Note that this name may
be different than the filename of the character's save file.

Filenames for the save and pref files are built from a "base name",
which is the player name with all non-alphanumeric characters changed
to underscores (\_). On Windows and DOS systems the base name will also
be truncated to 8 characters. This could lead to different characters
having the same (default) pref files.\
Example: "Grog the Elder" and "Grog the Younger" would both try to
load the same pref file "Grog_the.prf".

In recent versions of ToME "\<<span>$</span>PLAYER>.prf" is the default filename
when saving your macros and keymaps from the (@) Interact with macros
screen. Just hit Enter to accept that name.

On some systems you may encounter problems automatically loading this
file if your name is more than 8 characters, or if it contains spaces
or special characters.

See section ["Saving these macros and keymaps for reuse"](#tag-8) for how to
save your character's preferences.

See section ["Pref file loading order"](#tag-7) for the full list of pref files
loaded and their order.

Note: for pref files to load automatically they must end in the file
extension "prf", which is the default when saving pref files. But it
is possible to save and load pref files with any or no file extension,
from the macros and visuals editor screens.

### 4.12 Multiple macros bound to one trigger key

Angband supports using modifier keys on trigger keys. One thing this
lets you do is easily choose between variants of an action. Another is
to minimise the amount of moving your hands have to do, speeding up
play and reducing stress on your wrists.

$`\color{#00A5A5}{\textsf{You can bind multiple versions of the same macro to the same trigger}}`$
$`\color{#00A5A5}{\textsf{key, using Alt, Control, Shift in different combinations}}`$ to choose
among the different versions.\
Example: use \<Alt> for targeted, and \<Shift> for non-targeted.

Another use is to heavily use modifiers on numeric keypad keys. The
standard version already comes with Shift-\<digit> bound to running in
that direction. But by using various combinations of modifier keys, it
is possibly to play with the right hand almost always on the numeric
keypad, and the left on the modifier keys.

### 4.13 Multi-part actions

Better to only do this when spells have \~0% failure.\
Be careful of the order of commands. Commands that leave useful info
on the screen shouldn't be followed by ones that will clear it.\
Be careful of commands that set or clear targets.\
Use "\\e\\e\\e\\e" in-between commands to be safe.

### 4.14 Easy running

Bind Shift+\<keypad dir> to running for each of the directions.\
For example, running "North":

1\) @    Interact with macros\
2\) 4    Create a macro\
3\) Shift+8   (Trigger key for the macro)\
4\) \\\\.  Run\
&nbsp;&nbsp;&nbsp;8    "North"\
5\)      (Hit Enter)\
6\)      (Hit Esc to exit the editor)

Macros for the other directions are added similarly. Remember that the
original and roguelike keysets differ, but using the backslashes makes
sure that the "underlying" keyset gets used:\
&nbsp;7 8 9\
&nbsp;4   6\
&nbsp;1 2 3

These macros are already in the "pref-\*\*\*.prf" files that ship with
the standard Angband distribution for some systems, but not all.\
Systems "mac", "win", "x11" have them. If you aren't sure if you have
them, just try moving in any direction with the shift key down.

$`\color{#00A5A5}{\textsf{These do have to be macros instead of keymaps}}`$, because they rely on
keypad keys having different scan codes than the top-row number keys.

There are also default macros for Ctrl+\<dir> which applies the command
(+) Alter to that direction.

### 4.15 Farming techniques

$`\color{#FF00FF}{\textsf{+++ NOTE: This is considered scumming! (cheating) +++}}`$

Farming is the practice of automatically "harvesting" large numbers of
weaker monsters for their experience value. This is usually done to
advance a lower level character. There are apparently several methods
that the "old timers" used to use. I don't know that farming is that
popular any more. Even then it was sort of a lark.

Apparently a golf ball is just the right size and weight for many
keyboards to hold a key down and get it to auto repeat. Then you walk
away, and the next morning you have gained several levels. Ballpoint
pen caps are also supposed to be good at wedging a key down.

Using a farming macro for long periods of time like this requires a
way of getting food, so it really needs to be employed by a magic user
who can create their own food.

Use turn counts with attack (move) commands to move around the room,
mowing down creatures as you move. Periodically rest enough to
regenerate to full mana. This may not be necessary if it takes long
enough to kill the monsters as you move.

This requires an effective macro and a room full of breeders which
can't attack for enough damage to kill you. Farming for short periods
of time with a fighter class is quite feasible. The limitation for
fighters is food. The limitation for spell casters is probably hit
points. You may also need to insert action sequences for healing if
the farmed monsters are capable of significantly damaging you.

Note that red and green worm masses can knock down the doors of the
room you're in. Blues can destroy potions and flasks, so you will need
to stash your potions outside somewhere before farming.

### <a id="tag-10"></a>4.16 Macros can contain their own trigger key

It is permissible to make a macro or keymap which contains its own key
in its action. It won't cause recursion, but there are a few wrinkles.

Example: you can bind "\*tf1" to the 'f' key, to cause it to auto-fire
at the nearest target. You can still use the 'f' key for Fire in other
macros or keymaps.

If you bound 'f' as a keymap you will need to use "\\\\f" for Fire when
it is used in a macro action string. You don't need to do anything
special to use it in a keymap in its usual sense. Keymap and macro
expansion isn't done inside keymap action strings.

If you bound 'f' as a macro, the problem will be in entering the new
macro or keymap in the editor. When you try to press an 'f' key for
the action, it will expand to "\*tf1", even when you don't want it to.\
You will first have to remove the macro bound to 'f', then add the
macro or keymap that uses 'f' in its action, and then reenter the 'f'
macro. You can also create the macro in a pref file and load it using
the "Load pref file" command in the (@) Interact with macros screen.

### 4.17 Changing the player's color and character (ASCII text display)

$`\color{#00A5A5}{\textsf{= Using the Visuals Editor =}}`$

|   |   |
| --- | --- |
| 1) % | Interact with visuals. |
| 2) 6 | Change monster attr/chars |
| 3) a | (repeatedly) cycle thru colors (A moves backwards) |
| 4) c | (repeatedly) cycle thru characters (C moves backwards) |
| 5) Esc | accept changes |
| 6) Esc | exit the editor |

$`\color{#00A5A5}{\textsf{= Using the Enter User Pref command =}}`$\
1\) "    Enter user pref line\
2\) "R:0:\<attr>:\<char>"\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The user pref line.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\<attr> - the attr (color) specified as an integer index.
\<char> - the (ASCII) character specified as an integer.\
3\)     (Hit Enter)

You can't directly use the Angband attr letters to specify colors, but
must instead use their index. Eg 4 is Red. These indexes can be found
from within the game using the (&) Interact with colors command. That
editor also allows you to change the colors used by the game.

The \<char> integer is generally the index of an (ASCII) character.\
Non-ASCII characters may be available on some systems. Available
characters can found using the (%) Interact with visuals command.

These integers can be specified in decimal, hexadecimal, or octal
notation. Decimal is the default, hexadecimal numbers are prefixed
with "0x", and octal numbers are prefixed with 0 (zero). Example: the
standard character for the player is '@'. This may be entered as "64",
"0x40", or "0100". Yellow may be entered as "11", "0x0B", or "013".

This pref line can be added to any pref file to save the change for
future reuse. Changes made using the internal colors editor screen can
be dumped from that screen. Note that colors and characters saved in
pref dumps are in hexadecimal.

After making a change, you must move the character or otherwise cause
a screen redraw for the change to be visible.

If you make a mistake, you can use the (0) command in the editor to
reset the visuals to their original colors and characters.

$`\color{#00A5A5}{\textsf{= Changing Using the Monster Info file =}}`$

---

This may also be done by changing the entry for the player in the info
file "r_info.txt". The player data starts with line "N:0:Player". In
the following line G:\<c>:\<a> the character \<c> is entered directly,
and the attr (color) is specified by letter. See the section "Message
color lines" for the list of standard colors. In many versions you
will have to delete the file "lib\\data\\r_info.raw" and restart the
game for this change to take effect. Note that that char/attr pair is
entered in the opposite order as for an R: user pref line.

$`\color{#00A5A5}{\textsf{= Options which Change Player appearance =}}`$

---

These are accessible through the (=) Set options command.

[(hilite_player)](option.md#tag-2) -- causes the player's symbol to be drawn with the
"cursor" on it. It will be drawn with the same color as the character.

### 4.18 Recharging a rod using a Recharge Item spell

(You can also recharge staffs and wands with this technique.)

Inscribe the rod with {@m\<d>}, where \<d> is any decimal digit not
already used as a label.

The trick is that we want to use a digit to label the rod so we can
refer to it using its label instead of its inventory letter, but we
have usually used up many of the digits for spell books. If we were to
label the rod with {@m1} and the first spellbook was also labeled with
{@m1}, then the spellbook will sort first in the inventory so it will
be found first when looking for item '1' to use with the (m) command.\
So that would try to recharge the spellbook, which will fail. Angband
doesn't restrict itself to "appropriate" items when looking for a
labeled item. It simply finds the first one whose command letter and
digit match.

You can't get around this by omitting the letter 'm', or using 'z'
instead. Using no command letter means it will still match. And if you
use a command letter it has to be 'm', because that is the built-in
trigger for the current command.

Note that the digits used with different command triggers can be
different, so inscribing {@z1@m0} is perfectly legal. Use digit 1
when zapping the rod, and 0 when referring to it during the casting
of a \[mage\] spell.

You can also use this technique with scrolls. In that case you need to
use the inscription {@r\<d>} since the item is being referred to while
processing the (r) Read scroll command.

### 4.19 Disabling a built-in command

At times it may be useful to disable an underlying Angband command.\
For example, a dangerous key may be too easy to press by accident.\
The macro editor commands for removing macros and keymaps can't be
used in this situation. $`\color{#00A5A5}{\textsf{Instead bind the trigger key to the action}}`$
$`\color{#00A5A5}{\textsf{string "x00"}}`$. This special 'command' takes no "energy" and won't
generate an error message. It truly does "nothing". This will work for
both macros and keymaps. If possible you should use a keymap instead
of a macro to disable the key. A keymap will catch occurrences of the
key both in macros and by typing, and will still allow you to use the
key when it isn't being interpreted as a command.

If you use the "Query a macro/keymap" on a trigger key bound to this
action, it will report having found it, but no action string will be
printed.

Another technique is to use the action "\\e\\e\\e". This is used in some
of the standard pref files.

$`\color{#00A5A5}{\textsf{If you need to use the built-in command again you can use the '' key}}`$
$`\color{#00A5A5}{\textsf{at any prompt to bypass its macro/keymap.}}`$

### 4.20 "Naming" an item (patch)

$`\color{#00A5A5}{\textsf{= 'Fake artifact' name =}}`$\
\# "Name" an item\
This isn't an actual command in the interface, but a flag character
that alters the way an item description is generated. This isn't part
of standard Angband. It's added by Tom Morton's 'fake artifact' patch.

Example: inscription {#Thumper} will cause a Club (+8,+8) to display
as Club 'Thumper' (+8,+8) in your inventory and messages.

## <a id="tag-34"></a>5. Common Questions

### 5.1 Why can't I add a keymap for a function key?

Because keymaps can only be created for keys with system-independent
representations. This leaves out function keys, and several other
special keys. The "Create a keymap" command will continue waiting for
a keypress until you press a valid keymap trigger. You can, however,
create a macro for a function key.

### 5.2 How can I automatically inscribe items when I pick them up?

(Content removed because it was obsolete. Inscribe-on-pickup is now the default.)

### 5.3 Can I use macros inside other macros?

No. Macros don't expand macro triggers they contain in their actions,
in order to avoid recursion and other problems. However, keymap
substitution is done, so you can use keymaps to alter the behavior of
macros. This keymap expansion can be bypassed by preceding a trigger
with "\\\\" in the action.

Keymaps don't expand macro or keymap triggers in their actions.

Also see section ["Can I create an infinite loop using a macro?"](#tag-9).

### 5.4 How do I find out what the standard commands are?

|   |   |
| --- | --- |
| 1) ? | Angband help |
| 2) 6 | [Command Descriptions (command.txt)](command.md) |

Space - moves you down by a page\
Minus - moves up by a page

|   |   |
| --- | --- |
| 2 | - moves down by a line |
| 8 | - moves you up by a line |

Note that the original and roguelike command sets differ, and both are
different from the "underlying" command set.

### 5.5 How can I tell if a key has a keymap/macro?

$`\color{#00A5A5}{\textsf{= Query Macro/Keymap =}}`$

In ToME this is easy:

|   |   |
| --- | --- |
| 1) @ | Interact with macros |
| 2) 3 | Query a macro |
| OR 7 | Query a keymap |
| 3) | (Press the trigger key to test) |
| 4) Esc | (Exit macro editor when done) |

It will report "Found no macro" or "Found a macro" at the top of the
screen. The action it is bound to will be displayed at the bottom of
the screen, under the "Current action..." line. You must test for both
macros and keymaps, and keymaps will only show for the current "mode",
i.e. original/roguelike.

$`\color{#00A5A5}{\textsf{= Notes =}}`$

Note: on some machines, there are duplicate keys such as left and right
Shift keys. These will generally  produce different key codes and can
have different macros and keymaps.

Note: just because a key doesn't have a macro doesn't mean there isn't
a command that uses that key.

### 5.6 How can I tell if a key has a built-in command bound to it?

Er ... try pressing the key. If there is a command bound to that key
it should usually generate a message of some kind. If there isn't one,
it may respond: "Type '?' for help.". Some keys may not generate any
message at all. Function keys are a good example.

In ToME, the game will also generate "silly" error messages
which may not look like error messages at first. After a few repeated
key presses it uses the standard "Type '?' for help." message.

Failing that, look in ["command.txt"](command.md), which lists all\
commands, and is up-to-date. There is no specific method for checking if
a key has a command bound to it from within the game.

### 5.7 Can I inscribe multiple items with the same number?

You can, but it can cause problems if you aren't careful. Use the
command letter in the inscriptions to minimise problems. For example,
it is safe to inscribe both rods with {@z1} and a spell book with
{@m1} because the command letter allows distinguishing the two.

When the game looks for an item to use with a command, it tries the
first one it finds that matches. If the command fails on that item, it
doesn't continue looking. The search for a matching item also doesn't
know how to only check the right kind of item, so if you have a Spellbook
inscribed {@1} and scrolls inscribed {@1} or {@r1}, when you read a
scroll it will find the spellbook first, even though it doesn't make
sense to read it, and the command will fail.

### 5.8 How do I convert a macro to a keymap?

You can simply remove it and re-add it "by hand", but for more complex
actions there are faster, safer ways.

$`\color{#00A5A5}{\textsf{= Directly modifying the pref file =}}`$

A macro with the following form in the pref file:\
&nbsp;&nbsp;A:\<action string>\
&nbsp;&nbsp;P:\<trigger>\\r\
Should be converted to the keymap form:\
&nbsp;&nbsp;A:\<action string>\
&nbsp;&nbsp;C:0:\<trigger>\
The "\\r" needs to be removed, and the 0 (zero) means standard keyset.\
Use 1 for roguelike keyset. To make a keymap for both keysets:\
&nbsp;&nbsp;A:\<action string>\
&nbsp;&nbsp;C:0:\<trigger>\
&nbsp;&nbsp;C:1:\<trigger>

### Using the "Interact with Macros" editor

|   |   |
| --- | --- |
| 1) @ | Interact with Macros |
| 2) 3 | Query a macro |

\<k>  The trigger key for the macro\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(its action string will now become the current action)

|   |   |
| --- | --- |
| 3) 5 | Remove a macro |
| &nbsp;&nbsp;&nbsp;\<k> | The trigger key for the macro |
| 4) 8 | Create a keymap |
| &nbsp;&nbsp;&nbsp;\<k> | The trigger key for the keymap |
| 5) | (Hit Enter to accept the current action) |

(Hit Esc to clear the message "Added a keymap")

This technique can also be used to move or copy actions between macros
or keymaps of the same kind. $`\color{#00A5A5}{\textsf{And old macro MUST be removed from a key}}`$
$`\color{#00A5A5}{\textsf{before it can be used as the trigger key for a keymap}}`$, otherwise the
macro action will expand when you press the trigger key in the editor.
Converting a keymap to a macro doesn't require removing the keymap
first.

Note that not all macros can be converted to keymaps. Keymaps don't do
macro or keymap expansion on their action strings, so macros that rely
on this will no longer work. Also, keymaps can only be bound to a
trigger key with a printable internal representation. For example, a
function key can't be a trigger for a keymap.

### <a id="tag-9"></a>5.9 Can I create an infinite loop using a macro?

No. Well, okay, you can, but only if you work \*really\* hard at it and
abuse bugs in the macro handling code. This isn't something that will
happen by accident just by using the trigger key inside its action.

You also can't create recursion. So don't worry about this. See the
section ["Macros can contain their own trigger key"](#tag-10) for more info.

### <a id="tag-4"></a>5.10 What just killed me?

When you are using lots of escapes and spaces in your macros to skip
over messages, you can miss important things happening. One of these
is dying. Usually when something goes wrong, you can just use the (^P)
Previous Messages command to see what happened. But if you died the
escapes can take you past the tombstone screen, your last chance to
examine the previous messages list. This also happens without macros.

To examine your recall, load the savefile and start a new character.\
You will then be able to use the message recall command to see the
last messages of that character's previous incarnation.

## <a id="tag-35"></a>6. Common Problems

### 6.1 My macro works all the time when I press its key!

Macros \*do\* work all the time. Every time you press a key, macro
expansion is done on it, and then keymap expansion. So if you use 'y'
as a trigger key for a macro, and then you try and answer a yes/no
prompt with 'y', instead you will get the macro's action string.

The answer to this is to change your macro to a keymap. These can be
bound to keys which have a system-independent representation in the
game, which includes all keys that you would use when interacting with
the game interface.

If you don't want to change it to a keymap, try changing the trigger
key to a "special" key, such as a function key.

### <a id="tag-6"></a>6.2 My auto-firing macro shoots the wrong target!

Your macro is probably firing at the previous target. This will happen
if the option ([use_old_target](option.md#tag-4)) is set. Then a macro will like "f1\*t"
or "m1a\*t" will execute as:

|   |   |
| --- | --- |
| f | Fire |
| 1 | Ammo inscribed 1 |

(it will now fire at the last \[wrong\] target)

|   |   |
| --- | --- |
| \* | Choose a \[new\] target |
| t | Accept first target |

If there are no valid targets, the (t) targeting command will centre
on your position. If you move, the target will still be your old
square. The first time you use the "f1\*t" macro it will fire at that
square, even if there is now a valid target (monster) nearby.

One fix is to turn off the (use_old_taret) option, since the action
doesn't require it. This is done with the (=) Set Options command.

Another is to change the action to choose the target before it fires.
Example: "\*tf1".

$`\color{#00A5A5}{\textsf{Note:}}`$ just because you can "see" a monster doesn't mean you can target
it. The code used for vision (line of sight) and firing (projection)
is slightly different. So when shooting near corners or pillars it may
happen that you can "see" a monster but not target it. If your action
kills messages at the end, you could keep hitting your auto-fire macro
and the only thing happening would be a large pile of missiles quietly
accumulating underneath you.

### 6.3 I used to have items inscribed, and now they aren't!

The game only knows about inscriptions that you are carrying. There is
no way to "store" them independently of a character's save file. So if
you lose all of an item that was inscribed, picking up another of that
kind won't automatically inscribe it.

Normal inscriptions aren't affected by your player's "memory".

Note that some items, when fully identified, could have their
descriptions grow so long that no inscription will show. In that case
you can use the (I) Identify command. It will display the full
description, even if nothing special is known about that item.

### 6.4 I changed some macros in a pref file and nothing happened!

Settings loaded in later pref files will overwrite earlier ones. So if
you add macros for the same trigger key to files "\<<span>$</span>CLASS>.prf" and
"\<<span>$</span>PLAYER>.prf", the second one will get used because its file loads
later. This affects macros, keymaps, actions, attrs/colors, and other
info. See section ["Pref lines summary"](#tag-11) for all the types of settings
that can be loaded. Also see section ["Pref file loading order"](#tag-7).

### 6.5 It moves me when I try to use my bow/rod/wand!

Example: you type "f1" and it moves you in direction 1 (South West).\
What is happening is that the 'f' key isn't being handled correctly.\
It may be remapped to a bogus command, or one which doesn't take an
argument. So the 'f' command is skipped/dealt with, and the '1' key is
then treated as a direction. You can examine what is going on with the
'f' key using the (@) Interact with macros screen to check for any
macros or keymaps bound to that key. Use the appropriate "Remove ..."
command to restore the built-in Angband command.

### <a id="tag-3"></a>6.6 My macro drops/takes off my main weapon!

This is probably caused by an auto-fire macro like "\*tm1a" for magic
missile. If you hold down the trigger key to repeatedly use it, and
some game event (possibly caused by the macro) creates a message, then
the action will be interpreted as:

|   |   |
| --- | --- |
| \* | (cancel message) |
| t | Take off item |
| m | (ignored as invalid) |
| 1 | (ignored as invalid) |
| a | Item a (main weapon) |

If there is room in your inventory, it will be put there. If not, your
inventory will overflow and it will be dropped on the ground. If this
happens during combat this is a very good way to die. This is just
another good reason to have {!d!k!v} on your main weapon. See the
section ["Prevent unwanted use of an item"](#tag-12).

This can be fixed by using the escape sequence "\\e\\e\\e" before and
after the action string to cancel any pending messages or commands.\
See the section ["Clearing the command buffer"](#tag-13).

### <a id="tag-2"></a>6.7 My macro outputs "e - Floating Eye" on the message line!

It is wise to add an escape sequence "\\e\\e\\e" to the beginning and end
of all macros for which this doesn't destroy useful information. See
section ["Clearing the command buffer"](#tag-13) for more information on this.

But many players play on flavors of unix, which uses '/' as the path
separator for files, and automatically type a forward slash when they
mean to type a backslash. So many actions in macros/keymaps in usenet
posts have the wrong type of slash. Angband "gurus" are perhaps more
vulnerable to this than novices.

The game sees this as:

|   |   |
| --- | --- |
| / | Identify a character |
| e | Character to be identified |

And outputs "e - Floating Eye" on the message line.

If this sequence gets expanded when you are trying to select an item,
it will lead to different behaviors.\
Example:

|   |   |
| --- | --- |
| / | Switch between inventory and equipment |
| e | Select item e. |
| Or: |  |
| / | Switch between inventory and equipment |
| e | (ignored because invalid) Select item e. |
| / | Switch between inventory and equipment |
| e | Select item e. |

## <a id="tag-36"></a>7. Inscriptions added by the game

Some inscriptions are added by the game itself. These can overwrite
your inscriptions. There are also "fake" and "special" inscriptions,
which "look" like real inscriptions to the player.

### 7.1 Fake inscriptions

These "fake" inscriptions are "covered up" by real inscriptions, but
will reappear if the real inscription is removed.

"fake" inscriptions are unaffected by the uninscribe command (}).

{cursed} - cursed item\
{empty}  - item out of charges\
{tried}  - a "flavored" item which the character\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;has used, but whose effects are unknown.\
{N% off} - item bought on sale\
{quest}  - this item is a quest item. It may need to be taken to someone.

### 7.2 Auto-inscriptions

These added when your character gets a "feeling" about an item.\
In ToME these are "special" inscriptions, like "fake" inscriptions
above, which don't overwrite user inscriptions. They just hide user
inscriptions, which are still there.

{terrible}  - cursed or broken artifact\
{broken}    - broken item\
{cursed}    - cursed item\
{uncursed}  - previously cursed item\
{average}\
{good}      - good (magical) item\
{excellent} - ego item\
{special}   - unique item\
{on sale}   - displayed only in the store

## <a id="tag-37"></a>8. Keys and commands

This section gives short descriptions of keys and commands used in
actions and trigger key representations. They are only listed in this
section if they aren't fully described elsewhere in this FAQ. Not all
of these keys are actually for "commands". See the normal Angband help
for a fuller description of these commands. The commands and keysets
are documented in ["command.txt"](command.md).

### 8.1 Keysets

ToME supports two "keysets", which are fully customisable sets of
keymaps. The "original" command set is close to the built-in commands,
with some additions for ease of use such as number keys moving you in
that direction. The "roguelike" command set allows easy movement on a
keyboard without a numeric keypad. As a consequence its letter keys
are almost completely "full". These used to be hard-coded by the game,
but are now fully customisable. The default keymaps are in "pref.prf".

### 8.2 Item selection

(\*) - gives list of choices\
(-) - selects item on the floor\
(/) - toggles between the inventory and equipment lists.

(space) - shows list of choices. Pressing (space) again hides the list.
(lower) - selects the inventory item with that letter.\
(upper) - selects the inventory item with that letter, and requires\
&nbsp;&nbsp;&nbsp;&nbsp;confirmation.\
(digit) - selects first item inscribed with "@#" or "@x#" where 'x' is\
&nbsp;&nbsp;&nbsp;&nbsp;the command, and '#' is the digit. Only legal items are allowed.

### 8.3 Directions and Movement

Original keyset directions\
7 8 9\
4 5 6\
1 2 3

Roguelike keyset directions\
y k u\
h 5 l\
b j n

$`\color{#00A5A5}{\textsf{= Underlying command keys =}}`$

;\<dir> - walk (with pickup)\
\+\<dir> - alter\
.\<dir> - run

Digits AREN'T built-in movement commands in ToME. They are actually
keymaps found in the standard pref file "pref.prf". The digits are
direction arguments to the (;) Walk command.

### 8.4 Escape sequences

Many \[non-printable\] characters have a standard printable encoding
which uses an "escape" character to change the meaning of the
following character. The backslash character is used as in the C
language for many keys. The caret '^' is used for control keys.

$`\color{#00A5A5}{\textsf{= Escape sequences =}}`$\
\\b backspace\
\\e escape\
\\n newline\
\\r return\
\\s space\
\\t tab\
\\xNN hex ASCII char\
\\\\ (literal) backslash\
\\^ (literal) caret

$`\color{#00A5A5}{\textsf{= Backslash =}}`$\
In a macro, "\\\\" followed by a character uses the "underlying" command
for that character without translation. This is useful in macros to
avoid keymaps changing the behavior of the macro. In particular this
can be used to make macros which work for both original and roguelike
keysets. Keymaps don't have this problem.

$`\color{#00A5A5}{\textsf{= Newline and Return =}}`$\
These two characters can be used interchangeably.

$`\color{#00A5A5}{\textsf{= ASCII chars =}}`$\
Any ASCII character can be encoded in this way. So many keys will have
more than one representation. For example, \[Enter\] can be "\\r", "^M",
and "\\x09". The backslash representations are case sensitive, so "\\t"
is \[Tab\], but "\\T" will just be interpreted as "T". The hexadecimal
number must be exactly 2 digits.

$`\color{#00A5A5}{\textsf{= Escape and Space =}}`$\
See section ["Clearing the command buffer"](#tag-13) for their main uses.

### 8.5 Repeats and Counts

$`\color{#00A5A5}{\textsf{= Auto repeat =}}`$\
Some commands will automatically repeat. These are:\
(T) Tunnel\
(B) Bash\
(D) Disarm\
(o) Open\
(c) Close\
(+) Alter

$`\color{#00A5A5}{\textsf{= Number keys =}}`$

0 - starts a repeat count. Some commands take a repeat count argument.\
They can be entered as "0\<count>\<cmmd>". If the command is movement,
it can (must) be preceded by space(s) to separate the direction
(command) number from the count number.

### <a id="tag-1"></a>8.6 Messages and Questions

$`\color{#00A5A5}{\textsf{= Yes/No queries =}}`$\
Yes/No questions can be answered with 'y', 'n', or Esc. These are not
case sensitive. Only 'y' or 'Y' will respond Yes. 'n', 'N', and Esc
are No. If the option (quick_messages) is on, any other keypress is
also No. When the option is off, it will keep waiting for a valid key.

$`\color{#00A5A5}{\textsf{= "-more-" message prompts =}}`$\
These may be cleared by Esc(\\e), Space(\\s), Enter(\\r), or Newline(\\n).\
If the (quick_messages) option is on, they can be cleared by any key.

### 8.7 Special keys

$`\color{#00A5A5}{\textsf{= Function keys =}}`$\
Function keys are free for reassignment, but only as macros. $`\color{#00A5A5}{\textsf{Function}}`$
$`\color{#00A5A5}{\textsf{keys can be modified by Alt, Ctrl, Shift like other keys.}}`$

$`\color{#00A5A5}{\textsf{= Alt keys =}}`$\
Alt-modified keys are generally free for reassignment as either macros
or keymaps.

$`\color{#00A5A5}{\textsf{= Control keys =}}`$\
Control keys can be entered in as "^x" where 'x' is the key. Note
that the case of 'x' is unimportant. This also allows typing control
keys which would be intercepted by the operating system, such as ^C.\
You must type the caret '^' and the following key separately. Note
that some have special meanings, such as ^M for Return, and ^H for
backspace. Some also have special Operating System meanings, such as
"^Z" in un\*x, and "^C" in DOS. Control keys can be trigger keys for
both macros and keymaps.

$`\color{#00A5A5}{\textsf{= Interrupting the game =}}`$\
(^C) This will kill your character and quit the game, after verifying.

### 8.8 Keys used in inscriptions

$`\color{#00A5A5}{\textsf{= Confirm command =}}`$\
^ Confirm the following command.\
This isn't an actual command, but a character with a special meaning
inside command strings. {^\*} will confirm all actions for the item.

## <a id="tag-38"></a>9. Pref files

All pref files are loaded from and saved to folder "\\lib\\user". The
folder "\\lib\\pref" is unused at this time! The location and name of
this folder can be configured.

Warning: the directory "\\lib\\pref" is unused by the game. Pref files
moved there will never get used (unless the user has redirected the
folder locations).

Integers can be in hex "0x10", decimal "16", or octal "020" formats.\
These are converted using the C library fn strtol(), and are case
insensitive.

Decimal numbers start with '1'-'9'.\
Octal numbers must start with '0' (zero).\
Hex numbers start with '0x' or '0X'.

### 9.1 Standard Pref files

Below "\*\*\*" stands for the 3-letter system abbreviations, such as
"acn", "mac", "win", "x11", ...

"font.prf"\
Includes "font-\*\*\*.prf" files.\
This file defines special attr/char mappings for "text" mode.

"graf.prf"\
Includes "graf-\*\*\*.prf" files.\
This file defines special attr/char mappings for "graphics" mode.

"pref.prf"\
Includes "pref-\*\*\*.prf" files.\
This file defines "default" actions of various kinds. This includes
mapping the original and roguelike keysets to the underlying keyset.

"user.prf"\
Includes "user-\*\*\*.prf" files.\
This file defines "override" actions of various kinds. It includes the
pref files based on system, race, and class.

"xtra-\*\*\*.prf"\
This file defines special attr/char mappings for "graphics" mode.\
Currently this just maps the player icon based on race and class.
"new" refers to Adam Bolt's tiles.

$`\color{#FF00FF}{\textsf{Warning:}}`$ you shouldn't edit the base pref files without a good reason,
and understanding what you are doing. Breaking these files can make
your game unusable. They are, however, the place to make changes that
should affect all users.

### <a id="tag-7"></a>9.2 Pref file loading order

This loading order follows from the order of includes in "pref.prf".\
Files which are "hard-coded" in the source are preceded with an index.\
The rest are included by the other files. Files which come later will
overwrite settings from earlier files.

(1) "pref.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"message.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"pref-\*\*\*.prf"

(2) "graf.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"font-xxx.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"graf-\*\*\*.prf"

(3) "font.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"font-xxx.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"font-\*\*\*.prf"

(4) "user.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"user-\*\*\*.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"\<<span>$</span>RACE>.prf"\
&nbsp;&nbsp;&nbsp;&nbsp;"\<<span>$</span>CLASS>.prf"

(5) "\<<span>$</span>PLAYER>.prf"

(6) ".angband.prf"

\= <span>$</span>RACE =\
Can be one of any of the races in ToME.

\= <span>$</span>CLASS =\
Can be one of any of the classes in ToME.

\= <span>$</span>PLAYER =\
The name of the current player being loaded or born. See section
["Automatically loading pref files"](#tag-15) for more information.

$`\color{#00A5A5}{\textsf{= Specific pref files =}}`$

---

"user-mac.prf"\
This is the only user pref file with example macros that ships with
ToME. A good set of examples.

"pref-win.prf"\
This is the same as (missing) "pref-dos.prf" and "pref-ibm.prf".

"colours.prf"\
Amiga only. Contains Amiga palette.

".angband.prf"\
Only on multi-user systems. This doesn't ship with the source. This
file must be located in the directory contained in environ variable
"HOME".

### <a id="tag-11"></a>9.3 Pref lines summary

Comment lines start with a '#' and extend to end of line.

Note: integer values can be specified as decimal, as hexadecimal by
preceding with an "x", or as octal by using a leading "0" (zero).

E:\<tv>:\<a> - attr/char values for inventory objects by index
F:\<num>:\<a>:\<c> - attr/char values for features by index
K:\<num>:\<a>:\<c> - attr/char values for objects by index
R:\<num>:\<a>:\<c> - attr/char values for monsters by index
S:\<num>:\<a>:\<c> - attr/char values for special things by index

A:\<str> - action line\
&nbsp;&nbsp;An action line should be followed by a keymap trigger "C:" line
or a macro trigger "P:" line. There can be intervening comments
and lines. The same action will be \[re\]used by all keymap and
command lines which follow it until there is another action line.\
P:\<str> - macro line\
&nbsp;&nbsp;\<str> a macro encoding of a keypress. (system dependent)
C:\<mode>:\<str> - keymap line\
&nbsp;&nbsp;\<mode> 0 = "original, 1 = "roguelike".\
&nbsp;&nbsp;\<str> logical keypress, including backslash codes such as "\\e" and\
&nbsp;&nbsp;&nbsp;&nbsp;control codes such as "^K". (system independent)\
&nbsp;&nbsp;Note that there are 2 independent sets of keymaps now. Changing a\
&nbsp;&nbsp;&nbsp;&nbsp;keymap in one doesn't affect the other.

V:\<num>:\<kv>:\<rv>:\<gv>:\<bv> - specify visual information\
&nbsp;&nbsp;\<num> is the color index (0-255, only 0-15 used)\
&nbsp;&nbsp;\<kv> black (?) value -- unused\
&nbsp;&nbsp;\<rv> red value (0-255)\
&nbsp;&nbsp;\<gv> green value (0-255)\
&nbsp;&nbsp;\<bv> blue value (0-255)\
W:\<win>:\<flag>:\<value> - turn a window flag on/off.\
&nbsp;&nbsp;\<win>   window number (1-7)\
&nbsp;&nbsp;\<flag>  (0-31)\
&nbsp;&nbsp;\<value> 0 = off, 1 = on

X:\<str> - turn option off\
Y:\<str> - turn option on\
&nbsp;&nbsp;\<str> the name of an option in option_text\[\].\
&nbsp;&nbsp;These are the names displayed in the options screen (=).

?: - conditional expression\
%: - include another pref file

### 9.4 Option lines "X:" and "Y:"

Options and their descriptions are listed in help file ["option.txt"](option.md).\
These options are set within the game using the (=) Options command,
and the option names are the ones displayed within parentheses in the
options screen.

$`\color{#00A5A5}{\textsf{= Common options =}}`$\
rogue_like_commands\
use_old_target\
always_pickup\
auto_scum

### 9.5 Conditional expression lines "?:"

expressions are lisp-like prefix notation.\
names (class, race, ...) aren't placed in quotes.

|   |   |
| --- | --- |
| AND | - logical AND |
| IOR | - inclusive OR |
| EQU | - (string) equals |
| NOT | - logical negation |
| \[,\] | - group expressions |
| <span>$</span>SYS | - 3-letter system abbr in "pref-\*\*\*.prf" (ami, mac, win,...) |

0 - false\
1 - true (can't just be non-zero)

If the conditional expression is false all pref file commands
encountered until the next conditional pref line are skipped.

This isn't an actual command. It only works in pref files.

The variable <span>$</span>SYS and the string value it may take on are case
sensitive. The values also can't contain spaces. These constraints on
the values hold when they are used in a pref file, but might not when
used as pref filenames.

This can be "turned back on" using the pref line "?:1", which is
generally the last line in a file which contains conditional macros,
to make sure that any files loaded after it don't get ignored as well.

### 9.6 Macro trigger lines "P:"

All "special" keys are translated by "main-\*\*\*.c" into encoded "macro
triggers". These macro triggers have the encoded form "^\_MMMxSS\\r",
where the "modifier" flags are stored in "MMM", and the two digit
hexadecimal scan code of the keypress is stored in "SS". See source
file "main-ibm.c" and others for more info. Note that because these
scan codes are system-dependent, macro trigger encodings are as well.
Keymaps are used for system independent mapping of triggers to actions.

$`\color{#00A5A5}{\textsf{Modifier flags}}`$

A - Alt\
C - Control\
S - Shift\
O - Option key (Mac)

$`\color{#00A5A5}{\textsf{IBM Scan codes}}`$

x47 - keypad 7\
x48 - keypad 8\
x49 - keypad 9\
x4A - keypad -\
x4B - keypad 4\
x4C - keypad 5\
x4D - keypad 6\
x4E - keypad +\
x4F - keypad 1\
x50 - keypad 2\
x51 - keypad 3\
x52 - keypad Ins / .\
x53 - keypad Del / Enter\
x45 - Pause

Others can be found using the "Query a macro" feature.

Note that scan codes can't be assumed to be "in order", even for keys
like function keys which "logically" should be!

Note that you can't always just add a modifier to a known scan code
because that combination might not be recognised by the hardware or
the translation code in "main-\*\*\*.c".

Example: a Windows system will recognise function key F1, Shift-F1,
and Ctrl-F1, but not Ctrl-Shift-F1. Similarly Pause and Alt-Pause are
recognised, but not Ctrl-Pause, and Shift-Pause gives the same
encoding as Pause alone.

### 9.7 Saving to a pref file

Commands "Append macros to file" and "Append keymaps to file" don't
erase the previous macros or keymaps. Instead they are appended. Note
that this can produce \*large\* files after a while. Newer versions
append to "\<<span>$</span>PLAYER>.prf" by default, whereas older versions appended
to "user.prf". The appended sections are preceded by headers of the
form "Automatic macro/keymap dump". Using a distinctive comment line
such as ###... after your entries can make editing the appended ones
easier.

$`\color{#00A5A5}{\textsf{Note: macros and keymaps aren't saved in the character file, so they}}`$
$`\color{#00A5A5}{\textsf{must be saved separately. All macros and keymaps entered by the user}}`$
$`\color{#00A5A5}{\textsf{are lost when Angband terminates.}}`$

Note: keeping macros in the \<<span>$</span>PLAYER>.prf files allows several users
to share the same installation without interfering with each other.\
You can easily reuse or share preferences by moving them into a pref
file "\<my-name>.prf" and using the pref line "%:\<my-name>.prf" to
include them in "user.prf" for single user installations, or
\<<span>$</span>PLAYER>.prf for multi-user installations.

### 9.8 Editing pref files

This is still most easily done in a text editor.

## <a id="tag-39"></a>10. Macro editing commands

### 10.1 (") Enter a User Pref Command

This allows entering a single pref line.\
Example: "X:auto_scum" turns auto-scum off.

Example "A:\<str>" sets the current action string. If you open the
"Interact with macros" screen this action will be the default used.\
Then using the (") command again with "P:\<key>" will create a macro
for the action \<str> previously entered.

Not all pref commands can be used here, or are meaningful.\
The "pseudo" pref commands (?), (%) cannot be used here.

See section ["Advanced macro techniques"](#tag-20) for ways to \[ab\]use this.

### 10.2 (@) Interact with macros

$`\color{#00A5A5}{\textsf{= Vanilla command set = (2.8.3 - 2.9.1)}}`$

---

Load a user pref file\
Append macros to a file\
Query a macro action\
Create a macro\
Remove a macro\
Append keymaps to a file\
Query a keymap\
Create a keymap\
Remove a keymap\
Enter a new action

$`\color{#00A5A5}{\textsf{= Load a user pref file =}}`$

---

Loads a user pref file from "lib\\user". Defaults to the name of the
current character. Macros/keymaps loaded will replace existing ones.

$`\color{#00A5A5}{\textsf{= Append macros to a file =}}`$

---

Macros are dumped in macro list order. Newer ones are at the end.\
Macros are \*appended\* to the file. The old one isn't overwritten. This
prevents you from accidentally wiping out your old pref file. However,
the file can grow very long without your noticing it. Placing a line
of ###'s at the end of your macros can help sort out what is what.\
Macros are labeled with comment "# Macro 'NNN' ". These numbers are the
internal macro list numbers, and have no relation to key scan codes.\
The filename must end in ".prf". It will save correctly without this
extension, or with a different one, but if you save as "\<<span>$</span>NAME>"
instead of "\<<span>$</span>NAME>.prf", it won't be automatically loaded when you
load the character with that name.

$`\color{#00A5A5}{\textsf{= Query a macro =}}`$

---

Press the trigger key to test at the prompt.\
This will show "Found a macro" on the message line if it found one,
and the line "Trigger: \<trigger>". This will show "Found no macro"
on the message line if it didn't find a macro. Some keys such as
function keys won't be recognised by the prompt. It will wait until
you hit a key it recognises.

This command doesn't alter any settings. It will return to the main
menu after you hit any key it recognises.

$`\color{#00A5A5}{\textsf{= Create a macro =}}`$

---

After choosing this command, press the trigger key for the macro.\
The internal form will be shown after the "Trigger: " prompt.\
Note that some keys may not be recognised for remapping, such as the
new Windows keys, as well as modifier keys such as Alt, Control, Shift
pressed by themselves. In this case it will continue to wait for a
valid trigger key.

The current action (if any) will be shown \*below\* the "Trigger: "
prompt line. On the prompt line ("Action: ") will be shown the last
macro sequence entered. This is the action in the "action buffer".\
This isn't necessarily the macro sequence currently bound to this key.\
This is the action that will be bound to the current trigger key if
you hit Enter.

You may type in an action string to replace the one after the prompt.\
Hit Enter when you are finished.

For ToME you can quit the command assignment by hitting\
Esc. The new action entered won't be assigned, and the previous one
will remain unaltered.

$`\color{#00A5A5}{\textsf{= Remove a macro =}}`$

---

Removes the macro from the trigger key by creating an identity macro
on that key for itself. So the macro isn't completely removed, just
overwritten. The new identity macro will be saved when the macros are
appended to a file. This is different from the "Remove a keymap"
command, which completely removes the keymap.

---

The following "keymap" commands only apply to the current "mode"
(original/roguelike). Keymaps for the other mode will be unaffected.\
Because keymaps can only be bound to trigger keys which have a system
independent representation, some key presses won't be recognised by
these editing commands. They will instead wait until you press a valid
trigger key.

---

$`\color{#00A5A5}{\textsf{= Append keymaps to a file =}}`$

---

Works just like "Append macros to a file". These are appended after a
header comment "# Automatic keymap dump".

$`\color{#00A5A5}{\textsf{= Query a keymap =}}`$

---

Works just like "Query a macro". This will show "Found a keymap" on
the message line if it found one, and will display "Keypress: \<map>".\
This will show "Found no keymap" on the message line if it didn't
find a keymap. This command doesn't alter any settings. It will return
to the main menu after you hit any key it recognises.

$`\color{#00A5A5}{\textsf{= Create a keymap =}}`$

---

Works just like the "Create a macro" command. Keymaps can only be
assigned to keys which have a system independent representation. Note
that creating a keymap will cause the behavior of any macro whose
action string contains that key to change.

$`\color{#00A5A5}{\textsf{= Remove a keymap =}}`$

---

Removes the keymap completely from the trigger key. If the key had a
built-in command it can now be used again. Note that removing a keymap
will cause the behavior of any macro whose action string contained
that key to change. This behaves differently from the "Remove a macro"
command, which creates an identity macro.

If the original "command" was itself a keymap, removing a user-entered
keymap won't restore it. Example: the key (n) is bound to the built-in
command "Repeat last action" in file "pref.prf" via a keymap. If you
add a keymap for (n) and then remove it, the "Repeat last command"
functionality won't be restored. You will have to add it back by hand,
or reload a pref file that contains that stored keymap. $`\color{#00A5A5}{\textsf{In particular}}`$
$`\color{#00A5A5}{\textsf{almost all roguelike commands are now implemented as keymaps.}}`$

$`\color{#00A5A5}{\textsf{= Enter a new action =}}`$

---

Allows entering a new action. Actions are entered into a static buffer
which is shared by both macros and keymaps. The action string entered
will become the default action for creating a keymap or action, and
will only change when a keymap or macro is created with a different
action string, or when one is queried. Note that the same action can
be bound to multiple trigger keys by hitting Enter when using the
commands to create a keymap/macro.

## <a id="tag-20"></a>11. Advanced Macro Techniques

This section outlines advanced techniques not really required for game
play. But macros become addictive after a while ...

Action strings in this section are enclosed in braces {} because many
use a double quote (") inside the action string. These are not
inscriptions.

### 11.1 Set current action using (@) command in an action

{"@0\<str>\\r\\e}\
@    - Interact with macros\
0    - Enter a new action\
\<str>- (action string)\
\\r   - Enter the action\
\\e   - Exit the macro editor

This will work when bound to a macro.

### 11.2 Set current action using (") command in an action

{"A:\<action>\\r}  - sets the current action.\
"    - Enter pref line\
A:   - Action line\
\<str>- (action string)\
\\r   - Enter the action

This works in either a macro or keymap.

### 11.3 Create a new keymap using (") command in an action

{"A:\<act>\\r"C:0:\<key>\\r}\
Here \<act> can't contain an '\\r' or '\\e'.

Example {"A:z0\\r"C:0:J\\r} binds action "z0" to (standard) keymap 'J'.

### 11.4 Create a new macro using (") command in an action

{"A:\<act>\\r"P:\<key>\\r}\
Here \<act> can't contain an '\\r' or '\\e'.\
Here \<key> is a standard key. (not a "special" one like F1, \\b, or ^A)

Example\
{"A:\<action1>\\r"P:j\\r} binds action \<action1> to trigger 'j'.
{"A:\<action2>\\r"P:j\\r} binds action \<action2> to trigger 'j'.\
If we bind these 2 macros to different trigger keys, the action that
is on key (j) can be swapped back and forth.

### 11.5 Turning an option on/off in an action

Turn an option on:\
{"Y:\<option_name>\\r}

Turn an option of:\
{"Y:\<option_name>\\r}

Example: Turn (quick_messages) on, do an action, and turn it back off:\
{"Y:quick_messages\\r\<action>"X:quick_messages\\r}

This will work in either a macro or keymap. \<option_name> is the name
of the option as it appears in the option editor accessed through the
(=) command. These are also listed in the help file ["option.txt"](option.md). Note
that option names contain underscores instead of spaces.

### 11.6 Inscribe/Uninscribe an item in an action

(These action strings are enclosed in double quotes)

Inscribe an item:\
"{\<item>\\s\<inscr>\\r"

Uninscribe an item:\
"}\<item>\\r"

\<item> must be the inventory letter of the item, possibly preceded by
a '/' to switch to the equipment list. You can't use digit labels for
items with inscriptions that contain the command triggers '{' or '}',
but you can use "@\<digit>".

This will work in either a macro or keymap.

## <a id="tag-41"></a>12. Problems

### 12.1 Keys to avoid remapping

These don't really \*need\* to be avoided, but all carry dangers of one
kind or another. You should think through potential problems before
deciding to use them. You have been warned.

$`\color{#00A5A5}{\textsf{= Navigation keys =}}`$\
Enter, Esc, Backspace, ...\
These aren't a good choice unless you \*really\* need them. If you do it
is far better to use keymaps. If you bind a macro to the Enter key,
you will lose the ability to enter line-based commands like Inscribe.

$`\color{#00A5A5}{\textsf{= Commands generated internally =}}`$\
(\_) Enter store\
This command is generated internally by the game when the player moves
onto the door of a store. In some versions, if this key has a keymap
bound to it, that will fire when you try to enter a store.

$`\color{#00A5A5}{\textsf{= Keys with important Operating System meanings =}}`$\
^Z  (un\*x) Suspends the game and returns to the command shell. This\
&nbsp;&nbsp;&nbsp;&nbsp;is an operating system command, not an Angband command.\
&nbsp;&nbsp;&nbsp;&nbsp;Command "fg" returns to Angband.\
^\\, ^D, ^S\
&nbsp;&nbsp;&nbsp;&nbsp;These are keys that shouldn't be bound to macros or have their
behavior altered.

$`\color{#00A5A5}{\textsf{= Keys with dangerous ToME meanings =}}`$\
(Q) Quit (commit suicide), (k) destroy item, (^A) Enter Debug mode...\
Using these as triggers is dangerous in case, for some reason, you
wind up in a situation where the macro hasn't loaded or is disabled.\
You also don't want to get into a habit of typing these too fast.

$`\color{#00A5A5}{\textsf{= Selection keys =}}`$\
(e) Equipment, (i) Inventory, (-) Floor item, (/) Switch inventory
lists. You should avoid binding these as macro triggers, to prevent
making inventory and choice management next to impossible. But even as
keymaps they hold some dangers.\
Example: you bind keymap on '-' to destroy item on the floor. Now if
you try to do an action on a floor item, and it fails (such as using
rod to identify), then the '-' can be taken from the input stream and
used as a keymap, which would destroy the item you tried to identify.

$`\color{#00A5A5}{\textsf{= Response keys =}}`$\
(y) yes, (n) no, (Esc) cancel, (Space) skip message,...\
Binding macros to these is a $`\color{#FF00FF}{\textsf{Very Bad Idea.}}`$ Macro expansion will then
be done when you answer a question like "Are you sure you want to quit
the game without saving?". The expanded macro action string will be
used as the input, and may not lead to the answer you were trying for.
Keymaps don't have this problem. As a rule you should never use a
macro instead of a keymap unless necessary.

### 12.2 Num lock

Whether/not NumLock is on can make a difference for some macros.\
For example, if NumLock is on under X11 the 'X' macro won't work.

### 12.3 Recovering

Restarting ToME clears all macros entered during the last session.

You can use "Load a pref file" in the "Interact with macros" screen to
reload a good set of prefs, overwriting bad ones being used. This will
not "erase" a macro/keymap which doesn't have a corresponding saved
one in the pref file. So if you add a macro/keymap to a trigger key
which didn't have anything bound to it, reloading the pref file won't
restore the key to its original state.

If you still have problems, restore or edit any modified \*.prf files
that might be loaded.

Try saving your macros, and examine them to see what went wrong.

$`\color{#00A5A5}{\textsf{You can use the backspace '' key at the command prompt to use the}}`$
$`\color{#00A5A5}{\textsf{original "underlying" command bound to that key. For example, if you}}`$
$`\color{#00A5A5}{\textsf{bound the key '@' to a macro, you wouldn't be able to enter the macro}}`$
$`\color{#00A5A5}{\textsf{editor to rebind it to itself.}}`$ Pressing '\\' first, then '@' causes the
command handler to use the built-in command, which allows you to enter
the command editor. Note: when you use the backspace inside an action
string, you have to double it as "\\\\". Do not use just a single back-
slash, or it will be ignored, and possibly alter the meaning of the
character that follows it.

You can remove a macro/keymap from an essential key (such as the Esc
key). Use the (@) "Interact with macros" command to access the remove
commands.

### 12.4 Unrecognised keys

$`\color{#00A5A5}{\textsf{= Un*x =}}`$

Function keys may not be recognised on some Un\*x systems.

$`\color{#00A5A5}{\textsf{= PC/Dos/Windows =}}`$\
Doesn't recognise the WINDOWS key (start menu) or the APPLICATION key
(context menu).

On some systems, doesn't recognise modifier keys (Alt, Ctrl, Shift) on
keypad keys when NumLock is on.

See special_key_list\[\] in "main-win.c" for list of "special" keys that
are recognised.

### 12.5 Nonexistent commands

Macros and keymaps can only be bound to keypresses. The game state
changing isn't a keypress, so you can't trigger an action when you
become hungry, blind, confused, slowed, pseudo-id an item, pick up an
item, gain a level, have a rod recharge, or any other event that isn't
directly triggered by a keypress.

"Attacking" also isn't a command, but you can use commands (+) Alter
grid, (;) Walk, and (.) Run.

So you don't really \_attack\_ Morgoth, you just \_alter\_ him. First he's
alive, then he's not. :)

### 12.6 File permissions

If you lack write permission to the pref file currently loaded by the
game, try saving to a file with a new name. The macros can be copied
over "by hand" later.

## <a id="tag-42"></a>13. Miscellaneous

### 13.1 References

["COMMAND.TXT"](command.md)\
\- lists standard and roguelike keys and commands. full descriptions.\
\- long description of command behavior.\
\- intro to macros and user pref files.

["DUNGEON.TXT"](dungeon.md#tag-8)\
\- look under "Objects Found in the Dungeon".

["OPTION.TXT"](option.md)\
\- list of options and their descriptions.

"INSCRIPTIONS.HTML"\
\- short intro by Julian Lighton. Available from
"<http://www.fragment.com/~jl8e/angband/inscriptions.html>".

### 13.2 Contributors

This FAQ was largely compiled from newsgroup postings to "r.g.r.a".\
So thanks to the generous contributors to the newsgroup! Email
addresses have been removed to foil spam-bots.

Ben Harrison    -- maintainer: Angband 2.7.1 - 2.8.5, =Ben= in source.
Robert Ruehlman -- maintainer: Angband 2.9.0 - present.\
DarkGod         -- maintainer: PernAngband 2.9.9a - present

Scott Bigham, DamonShawX, Jonathan Ellis, George W. Harris, Roger
Hoyle, Graham S. Johnson, Chris Kern, Matthias Kurzke, Steve Lamb,
Julian Lighton, Art Mruczek, Daniel Nash, Timo Pietilä, Jack Wise,
Greg Wooledge, and others.

### 13.3 Legalese

Copyright 2000 Jim Lyon and others. Redistribution of unaltered copies
of this document is permitted without restriction. Distribution of
altered copies is permitted without restriction as long as the
alteration does not significantly alter the content. (For example,
translation and conversion to another format is permitted.)\
Distribution of all other altered copies is permitted as long as credit
for previous authors is maintained, the contact information is
replaced with that of the alterer, and redistribution is not further
restricted.

Edited for PernAngband V5.x.x by Dawnmist with permission from Jim Lyon
August 2001. All comments to angband@dawnmist.8m.com
