<!-- Generated from lib/mods/theme/help/option.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-5"></a>Options and Effects (ToME 2.1.x)

Most of the options are accessible through the '=' command, which provides
an interface to the various sets of options available to the player.

In the descriptions below, each option is listed as the textual summary
which is shown on the options screen, plus the internal name of the
option in brackets, followed by a textual description of the option.

Note that the internal name of the option can be used in user pref files
to force the option to a given setting; see ["command.txt"](command.md#tag-105) for more info.

Various concepts are mentioned in the descriptions below, including "disturb"
(cancel any running, resting, or repeated commands, which are in progress),
"flush" (forget any keypresses waiting in the keypress queue, including any
macros in progress), and "fresh" (dump any pending output to the screen).

## <a id="tag-6"></a>Birth/Startup Options

The birth or startup options are only able to be changed during character
creation, and can be accessed by typing '=' during the creation process. They
can also be viewed from the option menu while playing, but not changed then.

### Maximise stats \[maximize\]

Maximise causes the race and class stat bonuses to be applied like
equipment bonuses.  This usually makes the character harder at the
beginning of the game, but easier later on, since the stats are no longer
limited to a "natural" value of 28 (18/100).

### Preserve artifacts \[preserve\]

Preserve artifacts cancels all level feelings of the "special" variety,
but allows missed artifacts to be "saved" by wandering monsters and
found again at a later time.  This only works for non-identified artifacts.

### Specify 'minimal' stats \[autoroll\]

Uses the standard autoroller for character creation. This allows the player
to specify a set of minimum values for the stats, and the game will keep
rerolling until it achieves them (or 1 million rolls, whichever comes
first).  Be warned, however, that there is a maximum total power permitted
for a starting character. Setting one stat to near maximum is easily
achievable; 2 is reasonable; but 3 would require the remaining 3 stats to
be near their minimum values.

### Generate character using a point system \[point_based\]

Allows the player to distribute a certain number of points among her stats.
It results in the player being able to get one or two really high stats, at
the expense of other not-so-important stats; or to have a well-rounded
character who is above average (but not great) in all stats. Unused points
convert into starting gold for the player.

### Always generate very unusual rooms \[ironman_rooms\]

Tries to place a special room or vault on every dungeon level. Very fun,
but extremely deadly - imagine that Greater Checkerboard Vault with Lokkak
on dungeon level 1!

### Allow use of some 'joke' monsters \[joke_monsters\]

Allows monsters flagged as being some of DarkGod's jokes to be generated.

### Always make small levels \[always_small_level\]

Overrides the in-game option of small_levels, generating smaller levels
whenever possible.

### You can receive fates, good or bad \[fate_option\]

Allows the player to turn off ToME's [fates](fatespoi.md) for that character.

### Items always sell for 0 gold \[no_selling\]

Disables selling items back to shops for money. The value of gold found in the
dungeon is increased to compensate.

## <a id="tag-7"></a>IN GAME OPTIONS

These options are available from within the game, and can be toggled on and
off at will during the course of the game.

## <a id="tag-8"></a>Option Set 1 -- User Interface

### Rogue-like commands \[rogue_like_commands\]

Selects the "roguelike" command set (see ["command.txt"](command.md) for info).

### <a id="tag-1"></a>Activate quick messages \[quick_messages\]

Allows the use of any keypress as a response to the "-more-" prompt
(useful for monster farming).  Allows most keys to mean "no" to any
"\[y/n\]" prompt.

### Prompt before picking things up \[carry_query_flag\]

Forces the game to ask you for confirmation when you do something that
would normally cause an item to be picked up.

### <a id="tag-4"></a>Use old target by default \[use_old_target\]

Forces all commands which normally ask for a direction to use the
current target if there is one.  If the current target is a monster, it
becomes unset when that monster dies.  Use of this option can be dangerous
if you target locations on the ground, unless you clear them when done.

### Pick things up by default \[always_pickup\]

Tells the game that walking onto an item should attempt to pick it up.
Otherwise, you must use the "g" command, or the "-" command while walking.
Combined with "carry_query_flag" (Prompt before picking things up), allows
you to selectively pick up all items which you step on.

### Prompt before picking up heavy objects \[prompt_pickup_heavy\]

Generates a prompt whenever the character tries to pick up an item that
would slow him down.

### Repeat obvious commands \[always_repeat\]

Tells the game that when you attempt to open a door or chest, bash
a door, or tunnel through walls, that you wish to repeat the command
99 times (see ["command.txt"](command.md)).

### Audible bell (on errors, etc) \[ring_bell\]

Attempt to make a "bell" noise when various errors occur.

## <a id="tag-9"></a>Option Set 2 -- Disturbance

### Run past stairs \[find_ignore_stairs\]

Ignore stairs when running.

### Run through open doors \[find_ignore_doors\]

Ignore open doors when running.

### Run past known corners \[find_cut\]

Cut sharply around known corners when running.  This will result in
faster running, but may cause you to run into a lurking monster.

### Run into potential corners \[find_examine\]

Fully explore potential corners in hallways.  This is strongly
recommended if your light source has a small radius (e.g. a torch).

### Disturb whenever any monster moves \[disturb_move\]

Disturb the player when any monster moves, appears, or disappears.\
This includes monsters which are only visible due to telepathy, so
you should probably turn this option off if you want to "rest" near
such monsters.

### Disturb whenever viewable monster moves \[disturb_near\]

Disturb the player when any viewable monster moves, whenever any
monster becomes viewable for the first time, and also whenever any
viewable monster becomes no longer viewable.  This option ignores
the existence of telepathy for the purpose of determining whether
a monster is viewable.

### Disturb whenever map panel changes \[disturb_panel\]

This option causes you to be disturbed (stop running) when the screen
scrolls, as it does when you get close to the edge of the visible screen.

### Disturb whenever player state changes \[disturb_state\]

This option causes you to be disturbed whenever the player state
changes, including changes in hunger, resistance, confusion, etc.

### Disturb whenever boring things happen \[disturb_minor\]

This option causes you to be disturbed by various boring things,
including monsters bashing down doors, inventory feelings, and
beginning to run out of light-source fuel.

### Disturb whenever random things happen \[disturb_other\]

In ToME, uncursed teleporting items may teleport you around sometimes,
asking for your confirmation (and possibly disturbing your rest). If you
unset this option, they will stop asking you and teleporting you randomly.
Cursed items will neither ask for confirmation nor stop teleporting you
even if this option is unset.  (You may also inscribe an item with {.}
to suppress its random-teleportation power, unless it is cursed.)

### Alert user to various failures \[alert_failure\]

Produce a "bell" noise, and flushes all pending input, when various
failures occur, as described above.

### Get last words when the character dies \[last_words\]

Display a random line  from  the "death.txt" file when your character
dies. If this option is not selected, the "You die." message is displayed
instead.

### Confirm to wear/wield known cursed items \[confirm_wear\]

Some players may occasionally, due to a typing mistake, find themselves
wearing an item which they knew was cursed. If this option is set, you
should be safe from such typing mistakes: you will be prompted if you
attempt to wear or wield an item if your character knows it is cursed.

### Prompt before exiting a dungeon level \[confirm_stairs\]

Some players (such as myself) often accidentally press the '\<' key
and exit a Special feeling level. If this option is set, the program
asks for confirmation before you go up or down the stairs. Others may
find the prompt annoying; they should of course not set this option. :-)

### Disturb when visible pets move \[disturb_pets\]

The player may wish that some of the disturbance options do not apply
to pets: for example, it can be annoying if your rest is always disturbed
by a pet dog who pops in every now and then. By default, pets do not
disturb you even if full monster disturbance options are set. If you
want your pets to disturb you like normal monsters, set this option.

### Automatically open doors \[easy_open\]

Opens (and unlocks) doors by walking into them.  Also, if you are adjacent
to only one known door, using the "o"pen command will not prompt you for
a direction.

### Automatically tunnel walls \[easy_tunnel\]

Automatically tunnels into walls by walking into them.

## <a id="tag-10"></a>Option Set 3 -- Game-play

### Auto-haggle in stores \[auto_haggle\]

Disable haggling in stores, resulting in a ten percent sales tax
on items which you would have otherwise been forced to haggle for.\
When this option is on, all prices listed in stores will be the
actual price that you pay for an item, as opposed to the price
that the shop-keeper will suggest.

### Auto-scum for good levels \[auto_scum\]

This is a hack but allows you to force the generation of "good" levels
in the dungeon.  This option may be extremely slow on some machines,
especially deep in the dungeon.  The minimum "goodness" of the level
is based on the dungeon level, so the deeper you go, the better the
level will be.

### Expand the power of the look command \[expand_look\]

Expand the "l"ook command to allow the user to look at grids which
are not actually in view of the player, allowing the examination of
objects/monsters which have only been detected by spells, or sensed
via telepathy.

### Expand the power of the list commands \[expand_list\]

Expand the "listing" commands so that they wrap at the edges of
the appropriate list.  This allows the "l"ook and "t"arget commands
to cycle through all appropriate grids forever, and the "identify
symbol" to browse through all of the monsters of a given type.

### Map remembers all perma-lit grids \[view_perma_grids\]

Memorise all perma-lit floor grids which are seen by the player.\
This option allows you to keep track of which explored floor grids
were perma-lit, but does not distinguish between dark floor grids,
unexplored floor grids, and unknown grids.  Turning off this option
allows the player to always know which lit floor grids are in line
of sight, but this is better accomplished by the "view_bright_lite"
option.  Note that any non-floor grids which is seen by the player
are always memorised, and any object which is seen by the player is
memorised independently from the memorisation of the grid itself.

### Map remembers all torch-lit grids \[view_torch_grids\]

Memorise all (torch-lit) floor grids which are seen by the player.\
This option not only allows you to keep track of which floor grids
have been explored, but also which ones are dark, because the use
of this option activates a special color scheme for the display of
floor grids, in which dark grids are drawn in dark grey, lit grids
are drawn in white, and (if the "view_bright_lite" option is set)
lit grids which are also in line of sight are drawn in orange.  Note
that grids which are currently torch-lit are considered to be "lit",
and are thus drawn in white, unless the "view_yellow_lite" option is
set, in which case they are drawn in yellow.

### Allow some monsters to carry light \[monster_lite\]

This option allows some monsters to carry light sources around with them,
lighting up the space around them. It can also allow you to see when some
monsters are heading your way before they reach the bend in the corridor
where you are hiding in ambush....

### Generate dungeons with aligned rooms \[dungeon_align\]

Force all rooms to be aligned with the "panel" divisions.  This results
in a much prettier dungeon, but may result in fewer greater vaults.

### Generate dungeons with connected stairs \[dungeon_stair\]

Always generate a staircase back to the level whence you came, if you used
a staircase to get to the level.  This is more "realistic", and safer,
but less of a challenge for some people.

### Monsters chase current location (v.slow) \[flow_by_sound\]

Allow monsters to make paths to the player when they are nearby.  This
option is extremely slow, but can produce viciously smart monsters.

### <a id="tag-3"></a>Monsters learn from their mistakes \[smart_learn\]

Allow monsters to learn what spell attacks you are resistant to,
and to use this information to choose the best attacks.

### Allow unusually small dungeon levels \[small_levels\]

This option enables the creation of levels of varying sizes. Levels
that are as small as one "screen" (80x24) are possible, and they can be
quite dangerous, especially for a low level character, because they have
as many monsters and traps as their full-sized counterparts.\
Note that this option has the side effect of enabling / disabling
'destroyed' levels (they are enabled if small levels are).

### Allow empty 'arena' levels \[empty_levels\]

Normal dungeon levels consist mostly of rock. If this option is in
use, levels which have empty floor instead of solid rock may also
be created (somewhat reminiscent of Nethack's "big-room" levels).\
These levels can be extremely deadly, especially with breathing
monsters (since there are few obstructions to shield you). Arena levels
may have vaults, nests and pits in them like normal levels. Some
arena levels are dark when they are created, but most are lit.

## <a id="tag-11"></a>Option Set 4 -- Efficiency

### Reduce lite-radius when running \[view_reduce_lite\]

Reduce the radius of the player's light to that of a torch (radius 1)
when the player is running, which makes running more efficient (CPU-wise),
but is extremely annoying.  Certain older versions of Angband used
this behavior always, so "purists" should turn it on.

### Avoid checking for user abort \[avoid_abort\]

Avoid checking to see if the user has pressed a key during resting
or running or repeated commands.  This not only makes the game much
more efficient (on many systems), but also allows the use of certain
obscure macro sequences, such as turning this option on, resting until
done, turning this option off, and casting a spell.  Note that the use
of this option may be dangerous on certain "graphic" machines.  Resting
for long periods of time with this option set is dangerous since the
resting may not stop until the user takes damage from starvation.

### Avoid processing special colors \[avoid_other\]

Avoid processing the "multi-hued" or "clear" attributes of monsters.
This will cause all multi-hued monsters to appear violet and all
clear monsters to appear white, and will cause trappers and lurkers to
be visible on some machines, but it may greatly increase efficiency
especially when telepathy is active.  Certain systems may choose to set
this option if they are unable to support the special color processing,
but if they handle graphics "correctly", by using attr/char pairs with
the "high bits" set, then not only will the game correctly avoid using
any "dangerous" color processing, but it will allow such processing to
occur when it is not dangerous.  So if you are using graphics, and you
use a normal attr/char for the floor grids, then you can use the
"special lighting effects" for floors.

### Flush input on various failures \[flush_failure\]

This option forces the game to flush all pending input whenever various
"failures" occur, such as failure to cast a spell, failure to use a wand,
etc.  This is very useful if you use macros which include "directional"
components with commands that can fail, since it will prevent you from
walking towards monsters when your spells fail.

### Flush input whenever disturbed \[flush_disturb\]

This option forces the game to flush all pending input whenever the
character is "disturbed".  This is useful if you use macros which take
time, since it will prevent you from continuing your macro while being
attacked by a monster.

### Flush input before every command \[flush_command\]

This option forces the game to flush all pending input before every
command.  This option is silly, unless you are very paranoid.

### Flush output before every command \[fresh_before\]

This option forces the game to flush all output before every command.
This will give you maximal information, but may slow down the game
somewhat.  Note that this option is only useful when using macros,
resting, running, or repeating commands, since the output is always
flushed when the game is waiting for a keypress from the user.

### Flush output after every command \[fresh_after\]

This option forces the game to flush all output after not only every
player command, but also after every round of processing monsters and
objects, which will give you maximal information, but may slow down
the game a lot, especially on slower machines; and on faster machines
you normally do not have a chance to see the results anyway.

### Flush output after every message \[fresh_message\]

This option forces the game to flush all output after every message
displayed by the game.  This will give you maximal information, but
may slow down the game somewhat.

### <a id="tag-2"></a>Hilite the player with the cursor \[hilite_player\]

Place the visible cursor on the player.  This looks fine on some Unix
machines, but horrible on most graphics machines.  Note that only some
machines are able to \*not\* show the cursor, but on those machines, hiding
the cursor often speeds up the game and looks better.

### Use special colors for torch-lit grids \[view_yellow_lite\]

This option causes special colors to be used for "torch-lit" grids in
certain situations (see "view_granite_lite" and "view_special_lite").
Turning this option off will slightly improve game speed.

### Use special colors for 'viewable' grids \[view_bright_lite\]

This option causes special colors to be used for non "viewable" grids
in certain situations (see "view_granite_lite" and "view_special_lite").
When this option is set, floor grids which are normally drawn in white
but which are not currently viewable by the player are instead drawn
in dark grey.  This makes the viewable grids appear brighter than the
others, allowing the player to easily determine which floor grids are
in line of sight.  Turning this option off will probably increase the
speed of the game.

### Use special colors for wall grids (slow) \[view_granite_lite\]

This option activates a special color scheme for all wall grids which
are normally drawn in white (as walls and rubble normally are).  When
the player is blind, we use dark grey, else if the grid is torch-lit,
we use yellow (or white, depending on the "view_yellow_lite" option),
else if the "view_bright_lite" option is set, and the grid is not in line
of sight, or the grid is dark, or the grid is only "partially" lit, then
we use grey, otherwise we use the normal white.  Turning this option
off will probably increase the speed of the game.

$`\color{#00AD00}{\textsf{Use special colors for floor grids (slow)    [view_special_lite]}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;This option activates a special color scheme for all floor grids which
are normally drawn in white (as they normally are).  When the player is
blind, we use dark grey, else if the grid is torch-lit, we use yellow
(or white, depending on the "view_yellow_lite" option), else if the grid
is dark, we use dark grey, else if the "view_bright_lite" option is
set, and the grid is not in line of sight, we use grey, otherwise we
use the normal white.  Turning this option off will probably increase
the speed of the game.

### Centre the view on the player (very slow) \[center_player\]

Keeps the player's character in the centre of the screen, and moves the
dungeon around the player. Can be useful to prevent off-screen breaths.

## <a id="tag-12"></a>ToME Options

Features which are unique to ToME are collected in this menu.

### Ingame contextual help \[ingame_help\]

Setting this option allows the game to trigger a help message the first
time you come across an item or some other trigger. This is very useful
for new players.  More experienced players may wish to switch this option
off.

### Use the old(Z) coloring scheme(reload the game) \[old_colors\]

Setting this option toggles the ASCII game colour display from the
standard Angband monster colours to the Zangband-based monster colours.
Since this alters the display and monster memory display, you need to
reload the game when you alter this setting before it will display the
new colours.

### Automatically clear '-more-' prompts \[auto_more\]

Setting this option automatically clears any messages from the top
of the window. Be warned that this could be dangerous, as you don't
actually get to see the messages unless you use ^P.

### Player char represent his/her health \[player_char_health\]

Setting this option only affects the game when playing without tiles.\
As the player becomes injured, his icon changes to a figure representing
the percentage of health remaining; for example if he is down to 68% of
his maximum hitpoints, his character will be a '6' instead of an '@'.
The character used only starts changing once the player has lost at
least 30% of his maximum hitpoints.

### Stats are represented in a linear way \[linear_stats\]

Setting this option alters the display of character stats. The default
is 3 to 40 (linear), but the older 3 to 18/220 (Moria/Angband style) is
retained for players who prefer it.

$`\color{#00AD00}{\textsf{In option windows, just omit the select char    [inventory_no_move]}}`$\
&nbsp;&nbsp;&nbsp;&nbsp;If this option is set, the equipment/inventory windows don't move items
around when a prompt asks for an item.

## Stacking Options

In ToME items are allowed to stack on floors and monsters are allowed to
maintain inventories. These features are enabled by default, and aren't
accessible through the option menu, but can still be disabled through
user pref files (see ["command.txt"](command.md#tag-105)).

### Allow objects to stack on the floor \[testing_stack\]

Allows a cave grid to hold more than one object (or one kind of
object).

### Allow monsters to carry objects \[testing_carry\]

If this option is set, monsters which "pick up" objects will drop
the objects they were carrying when you kill them. Note that monsters
which "crush" objects are not affected by this option.

## <a id="tag-13"></a>Base Delay Factor

The "delay_factor" value, if non-zero, is used to slow down the game, which is
useful to allow you to observe the temporal effects of bolt, beam, and ball
attacks.  The actual delay is equal to "delay_factor" cubed, in milliseconds.
Frequently used factors are 2 or 3.

## <a id="tag-14"></a>Hitpoint Warning

The "hitpoint_warn" value, if non-zero, is the percentage of maximal hitpoints
at which the player is warned that he may die.  It is also used as the cut-off
for using red to display hitpoints, mana and sanity. It is entered as a value
between 0 and 9 (0% and 90%).

## <a id="tag-15"></a>Autosave Options

Ideally, the game should be so stable that these options are not needed
at all. However, even if the game were 100% reliable (which, to be frank, it
probably is not), the user might forget to save, and his hardware could fail
him. For all of these reasons, you may want to use these options:

### Autosave when entering new levels \[autosave_l\]

If this option is set, the program will attempt to save your
character every time before creating a new dungeon level. Useful
if you experience any game or computer crashes (or your dog enjoys
kicking your power cords out of the wall like mine does!).

### Timed autosave \[autosave_t\]

If this option is set, the program will attempt to save your
character every n game turns, where n is the "frequency".  To set
frequency, press n: it will increase the frequency to the next
category, these being every 50, 100, 250, 500, 1000, 2500, 5000,
10000 or 25000 turns. (After 25000, pressing n again will cycle back
to 0.) Note that the frequency must be higher than 0 and the
"Timed autosave" set to "yes" for timed autosaves to take place.

## <a id="tag-16"></a>The Automatizer

Allows you to set options for the game to automatically destroy or pick up
objects when you identify them, for example skeletons, essences, cursed
daggers, etc. Useful for reducing the clutter in the dungeon, and reducing the
amount of loot to have to sort through. This [Tutorial](automat.md) may help you.

## <a id="tag-17"></a>Window Flags

Selects what kind of information is displayed in which window, on platforms
which use multiple windows.

You can select a window to be able to toggle between 2 different
sets of information (e.g. Basic Character stats and monster recall)
by pressing the "y" key over the second display option.

## <a id="tag-18"></a>Cheating Options

### Peek into object creation \[cheat_peek\]

Cheaters never win.  But they can peek at object creation.

### Peek into monster creation \[cheat_hear\]

Cheaters never win.  But they can peek at monster creation.

### Peek into dungeon creation \[cheat_room\]

Cheaters never win.  But they can peek at room creation.

### Peek into something else \[cheat_xtra\]

Cheaters never win.  But they can see debugging messages.

### Know complete monster info \[cheat_know\]

Cheaters never win.  But they can know all about monsters.

### Allow player to avoid death \[cheat_live\]

Cheaters never win.  But they can cheat death.

## <a id="tag-19"></a>Dump Options

Allows the player to save the options to a file (defaults to charname.prf)
so that they can be reloaded into other character files.

## Load Options

Allows you to load a preference file saved through the "Dump Options"
command in another character file, hence saving all the initial time of having
to reset all the options every time you wish to play.

\+++ Ben +++ (Updated by Dark God and Dawnmist et al. for ToME)
