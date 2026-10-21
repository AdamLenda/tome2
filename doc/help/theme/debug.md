<!-- Generated from lib/mods/theme/help/debug.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-99"></a>Debug Commands

Debug commands are entered as an "underlying command" (a single key)
plus a variety of optional or required arguments.

The debug commands are used for debugging and experimenting. The game
will not be scored if you use debug commands.

## <a id="tag-100"></a>Command List Summary

|   |   |
| --- | --- |
| [a  Autorestore](#tag-1) |  |
| [b  Teleport to target](#tag-3) | [B  HP to zero](#tag-4) |
| [c  Create object](#tag-5) | [C  Create artifact](#tag-6) |
| [d  Detect all](#tag-7) | [D  Teleport to the wilderness](#tag-8) |
| [e  Edit character attributes](#tag-9) | [E  Change grid's mana](#tag-10) |
| f  (unused) | [F  Features](#tag-12) |
| [g  Create good item](#tag-13) | G  (unused) |
| [h  Change life rating](#tag-15) | [H  Hostile monster creation](#tag-16) |
| i  (unused) | I  (unused) |
| [j  Jump to other level](#tag-19) | J  (unused) |
| [k  Check attributes](#tag-21) | K  (unused) |
| l  (unused) | L  (unused) |
| [m  Magic Mapping](#tag-25) | [M  Gain corruption](#tag-26) |
| [n  Summon named monster](#tag-27) | [N  Summon \_friendly\_ named monster](#tag-28) |
| [o  Edit object attributes](#tag-29) | O  (unused) |
| [p  Phase door](#tag-31) | P  (unused) |
| [q  Get a quest](#tag-33) | Q  (unused) |
| r  (unused) | R  (unused) |
| [s  Summon monster](#tag-37) | [S  Change the feature of the map](#tag-38) |
| [t  Teleport](#tag-39) | [T  Teleport to a town](#tag-40) |
| [u  Complete map](#tag-41) | [U  Become undead](#tag-42) |
| [v  Random artifact/ego item](#tag-43) | V  (unused) |
| [w  Wizard light the level](#tag-45) | [W  Wish](#tag-46) |
| [x  XP boost](#tag-47) | X  (unused) |
| y  (unused) | Y  (unused) |
| [z  Zap monsters](#tag-51) | Z  (unused) |
| !  (unused) | ^A  (unused) |
| [@  Increment monster level](#tag-55) | ^B  (unused) |
| #  (unused) | ^C  (unused) |
| <span>$</span>  (unused) | ^D  (unused) |
| %  (unused) | ^E  (unused) |
| ^  (unused) | ^F  (unused) |
| &  (unused) | ^G  (unused) |
| [\*  Lose special powers](#tag-61) | ^H  (unused) |
| (  (unused) | ^I  (unused) |
| )  (unused) | ^J  (unused) |
| {  (unused) | ^K  (unused) |
| }  (unused) | ^L  (unused) |
| \[  (unused) | ^M  (unused) |
| \]  (unused) | ^N  (unused) |
| [-  Create object](#tag-67) | ^O  (unused) |
|  | ^P  (unused) |
| [+  Gain a fate](#tag-71) | ^Q  (unused) |
| [=  Align monster](#tag-73) | ^R  (unused) |
| ;  (unused) | ^S  (unused) |
| :  (unused) | ^T  (unused) |
| '  (unused) | ^U  (unused) |
|  | ^V  (unused) |
| ,  (unused) | ^W  (unused) |
| \<  (unused) | ^X  (unused) |
| .  (unused) | ^Y  (unused) |
|  | ^Z  (unused) |
| \\  (unused) | \|  (unused) |
| \`  (unused) | \~  (unused) |
| [/  Summon monster](#tag-91) | [?  Help](debug.md) |
|  | ^\\  (unused) |

## <a id="tag-111"></a>Command Descriptions

The following command descriptions are listed as the command name
plus the "underlying command" key. Then comes a brief description of the
command. Some commands use the "repeat count" to automatically repeat the
command several times, while others use the "repeat count" as an "argument",
for example, commands which need a "quantity" will use the "repeat count"
instead of asking for a quantity, allowing the use of "0d" for "drop all".
Commands which ask for a quantity will convert any "letters" into the
maximal legal value.

## <a id="tag-112"></a>General Commands

<a id="tag-1"></a>$`\color{#00AD00}{\textsf{Autorestore (a)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Restores all your stats.  This includes HP, SP, hunger, lost levels, etc.

<a id="tag-3"></a>$`\color{#00AD00}{\textsf{Teleport to target (b)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You first need to have a monster targeted, then you can use
this command to teleport next to the monster.

<a id="tag-4"></a>$`\color{#00AD00}{\textsf{HP to zero (B)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Bring your health down to zero.

<a id="tag-5"></a>$`\color{#00AD00}{\textsf{Create object (c)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows you to select and create a new object where you stand.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This brings up a menu where you can choose what type of object
you want created.

<a id="tag-6"></a>$`\color{#00AD00}{\textsf{Create artifact (C)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows you to select and create a new artifact where you stand.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify a number from
a_info.txt to put it on the ground where you are standing.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For example : 03^AC will create the Arkenstone of Thrane (+3)

<a id="tag-7"></a>$`\color{#00AD00}{\textsf{Detect all (d)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Sense ways out/monsters/objects.

<a id="tag-8"></a>$`\color{#00AD00}{\textsf{Teleport to the wilderness (D)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;From a dungeon this will teleport you to the wilderness level
and if used in the wilderness it acts like teleport.

<a id="tag-9"></a>$`\color{#00AD00}{\textsf{Edit character attributes (e)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Edit character attributes including Str, Int, Dex, experience, gold, luck, etc.

<a id="tag-10"></a>$`\color{#00AD00}{\textsf{Change grid's mana (E)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Alter how much mana a grid has.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify the amount of mana
that you want.

<a id="tag-12"></a>$`\color{#00AD00}{\textsf{Features (F)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify a number from
f_info.txt to put a feature on the ground where you are
standing.

<a id="tag-13"></a>$`\color{#00AD00}{\textsf{Create good item (g)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create a random good item where you stand.

<a id="tag-15"></a>$`\color{#00AD00}{\textsf{Change life rating (h)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Change your life rating.

<a id="tag-16"></a>$`\color{#00AD00}{\textsf{Hostile monster creation (H)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Summons a Pack of Creatures of the same kind.

<a id="tag-19"></a>$`\color{#00AD00}{\textsf{Jump to other level (j)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Jump to other dungeon level. This does not work in the
wilderness as it is treated as all one level.

<a id="tag-21"></a>$`\color{#00AD00}{\textsf{Check attributes (k)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Displays your characters attributes.

<a id="tag-25"></a>$`\color{#00AD00}{\textsf{Magic Mapping (m)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Like a Scroll of Magic mapping.

<a id="tag-26"></a>$`\color{#00AD00}{\textsf{Gain corruption (M)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows your character to gain a corruption.

<a id="tag-27"></a>$`\color{#00AD00}{\textsf{Summon named monster (n)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Summon a monster that will appear next to you.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify a number from
r_info.txt to summon a monster.

<a id="tag-28"></a>$`\color{#00AD00}{\textsf{Summon _friendly_ named monster (N)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The same as n but the creature will be your pet. Try this
with number 861, Darkgod is now your pet.

<a id="tag-29"></a>$`\color{#00AD00}{\textsf{Edit object attributes (o)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows you to alter the attributes of any object that you
have in your backpack.

<a id="tag-31"></a>$`\color{#00AD00}{\textsf{Phase door (p)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Like a Scroll of Phase Door.

<a id="tag-33"></a>$`\color{#00AD00}{\textsf{Get a quest (q)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Get a quest.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify a number from
1 to 25, as defined in defines.h ( the QUEST_XXX items ).\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For example : 04^Aq will get you the thieves quest.

<a id="tag-35"></a>$`\color{#00AD00}{\textsf{Gain reward (r)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Some high being grants you a reward.

<a id="tag-37"></a>$`\color{#00AD00}{\textsf{Summon monster (s)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Summon a random monster, next to where you stand.

<a id="tag-38"></a>$`\color{#00AD00}{\textsf{Change the feature of the map (S)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This allows you to change the "special" field of the current
grid. This special field is used to store things like quest
ids, dungeon entries, and so on, not to be used unless
one knows what it's doing.

<a id="tag-39"></a>$`\color{#00AD00}{\textsf{Teleport (t)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Like a Scroll of Teleport.

<a id="tag-40"></a>$`\color{#00AD00}{\textsf{Teleport to a town (T)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Teleports you to a specific town.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify a number from
wf_info.txt for where you want to go.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;standing.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For example : 02^AT will teleport you to Gondolin

<a id="tag-41"></a>$`\color{#00AD00}{\textsf{Complete map (u)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Displays the complete map of the dungeon.

<a id="tag-42"></a>$`\color{#00AD00}{\textsf{Become undead (U)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This is supposed to make you undead (as in the Necromantic power).

<a id="tag-43"></a>$`\color{#00AD00}{\textsf{Random artifact/ego item (v)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Create a random artifact/ego item where you stand.

<a id="tag-45"></a>$`\color{#00AD00}{\textsf{Wizard light the level (w)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Looks like the same as u.

<a id="tag-46"></a>$`\color{#00AD00}{\textsf{Wish (W)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Makes all your wishes come true.

Read the [wishing spoiler](wishing.md) to see how these work.

<a id="tag-47"></a>$`\color{#00AD00}{\textsf{XP boost (x)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify the increment,
if you do not specify a parameter it doubles your XP,
otherwise it increments by the specified amount.

<a id="tag-51"></a>$`\color{#00AD00}{\textsf{Zap monsters (z)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;All monsters in sight range vanish like Mass Genocide, only with no
HP price.

<a id="tag-55"></a>$`\color{#00AD00}{\textsf{Increment monster level (@)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Level up a monster.

<a id="tag-61"></a>$`\color{#00AD00}{\textsf{Lose special powers (*)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Returns your powers to a normal level.

<a id="tag-67"></a>$`\color{#00AD00}{\textsf{Create object (-)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Allows you to create a new object where you stand. You must
specify an object number from k_info.txt.

<a id="tag-71"></a>$`\color{#00AD00}{\textsf{Gain a fate (+)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Unearth more of your prophecy.

<a id="tag-73"></a>$`\color{#00AD00}{\textsf{Align monster (=)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Use the "Command count", aka 0, to specify one of the following
alignment types:\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0 monster becomes enemy\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 monster becomes neutral\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2 monster becomes friendly\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3 monster becomes pet\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4 monster becomes companion\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You then point at an enemy and press space.

<a id="tag-91"></a>$`\color{#00AD00}{\textsf{Summon monster (/)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Summons a random monster next to you.

$`\color{#00AD00}{\textsf{Help (?)}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Displays the main help file.
