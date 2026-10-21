<!-- Generated from lib/mods/theme/help/tome_faq.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-1"></a><a id="tag-2"></a>ToME FAQ

$`\color{#FF0000}{\textsf{Updated for version 2.3.x}}`$

---

## Differences Between ToME and Vanilla Angband

The first main difference a new player to ToME will need to be aware of is
that it has implemented a skills based system.  Instead of the adventurer
automatically improving in his abilities as he becomes more experienced,
he gets 6 skill points to spend on his skills, allowing the player to
customise what type of character she will play. See the [skills](skills.md) help file
for details.

A second major difference is that the main dungeon from Angband has been split
into 4 "dungeons", each of which covers a different portion of the Angband
dungeon's levels. Each of these 4 dungeons is located either in or near one of
the four main towns so that the character can keep stocked up on supplies. As
the adventurer advances in ability, he will need to travel overland to the next
town/dungeon, which is most easily carried out using the wilderness map ("\<"
from town level). As well as these main places, there are a number of
additional dungeons which the character may or may not choose to enter, which
can have guardians, contain specific artifacts, or just be used as an
alternative place to enjoy gaining experience. Note that not all of the places
are actually "dungeons" - some are caves, forests, etc.

ToME also offers the player the ability to undertake a series of quests.
Random quests can be specified during start-up, and involve rescuing a princess
from a group of monsters within the dungeon, or recovering a lost sword from
(you guessed it...) a group of monsters. If you do not wish to play with
random quests, simply specify "0" when asked how many you want during character
generation. Other "fixed" quests are also available from the towns (whether
random quests are enabled or not), usually given by the town leaders upon the
request of the adventurer. It is not required for any adventurer to undertake
the fixed quests, but they can result in some nice rewards.

The third main difference between Vanilla Angband and ToME is the difference
in character classes and races, as well as a very different magic system.
See the help files on [Creating a character](birth.md) and the [magic](magic.md) system.\
Class abilities (generally referred to as skills) are generally accessed
through the 'm' command. Most racial abilities, or corruptions, are accessed
through the "U" command.

To balance the expansion in things like player abilities and customisation, the
list of both monsters and items has also been expanded. Be warned that items
which were by default safe in Vanilla are not necessarily safe in ToME (a
certain early artifact comes to mind here...), and picking on defenceless
creatures is frowned upon....

Happy adventuring!

### <a id="tag-3"></a><a id="tag-4"></a>Q: How do I use the altars (the 'O's) I see in the dungeon?

A: ToME introduces a new system of gods.

You can find altars only in Lothlorien and in the dungeon.\
The ones on the surface are dedicated to the good Valar (Eru, Manwe, Tulkas and
Yavanna), while altars found in the dungeons are "sacred" for Melkor.\
You can use altars to convert yourself to the service of a specific Vala by
using the "O" command while standing on them. Beware, this works only if you
don't already have a God, and as a new convert, your God won't like you that
much.  Melkor also uses his altars as a mean of collecting sacrifices from his
devotees; this function is likewise accomplished by the "O" command.

Read [gods.txt](gods.md) for more information about Gods.

### <a id="tag-5"></a>Q: How do I use the fountains (the '\_'s) I see in the dungeon?

A: Fountains in ToME act like potions, but can only be identified by
drinking from them. Each one can hold between 3 and 12 doses of the potion.
Quaffing from a fountain can be done by using the 'H' command (in the standard
keyset) and answering 'Q' at the prompt.

You can also fill empty bottles at a fountain (enabling you to identify the
potion and hence the type of fountain) by using the 'H' command and answering
'F' at the prompt.  The game will then ask you to choose bottles and how many
bottles you want to fill.  You can find empty bottles on the dungeon and
drinking pints of fine ale/wine will give you emtpy bottles.

### Q: I got killed by a Great Wyrm of Power at 50'!!! What happened?

A: You killed a defenceless creature. I told you that it was frowned upon!

### <a id="tag-18"></a><a id="tag-17"></a>Q: I've found some strange items like a Red Tome, a Voodoo Doll, ... What can I do with them?

A: You've found an unusual artifact that cannot be wielded, but always
has a sometimes-useful activation.  It will not be listed in the known
artifact list and its activation is chosen randomly. It would probably be
wise for this kind of artifact be \*identified\* before use, as the
activation can be something very nasty....

To activate it, use the normal Activation command, but when prompted for which
item to activate change to the backpack instead of wielded equipment.

### <a id="tag-12"></a>Q: Where can I store all my equipment? Theere's not enough room in my inventory? And what happened to the thieves quest in Bree?

Nor is there supposed to be enough room in your backpack. It's not
bottomless you know! If you go talk to the Mayor in Bree, he might let you know
about a slight problem that there's been in town. If you can clear up the
problem, you may find yourself with somewhere extra to keep your stuff. I've
heard tell that there are similiar problems in other towns in Middle-Earth.

### <a id="tag-13"></a>Q: I spent 500 gp at the Prophet but she said nothing. Is that a bug ?

A: No. Nor is it because Prophets are swindlers. She said nothing
because you have no fate at this moment.  You gain fates while playing, and
will be warned by a message such as "You feel your fate has changed".  A fate
can be useless like finding a broken skull at level 30, deadly like dying at
level 56, or really useful like never dying by the hand of a mortal.

### <a id="tag-14"></a>Q: Who is Mathilde, the Science Student whom I see every so often in the town?

A: Most of the time she laughs and giggles. She has no loot on her, and
she's never done you any harm. So leave her be - even if she should
happen to shout "Drop dead, creep!"

### <a id="tag-15"></a>Q: My wrists hurt a lot when playing the game. Should I take precautions?

A: Yes, you should. Repetitive strain on wrists (which results from a badly
placed keyboard, for example) can lead to serious injury of the wrist ligaments
called Carpal Tunnel Syndrome. If you feel your wrists are strained, here is
an exercise posted by Jason Maskell in rec.games.roguelike.angband which might
help:

Hold your arms out horizontally, make a fist, and then point the fist towards
the floor, as much as you can. This will stretch one side's tendons. Hold for
5 seconds. Then make a flat hand and hold it level with your arm, hold for 5
seconds. Now splay your fingers and attempt to make your hand point toward the
ceiling (this one is hard, so don't push it too much). You should feel your
tendons stretching. Repeat this a few times. Take frequent breaks and do this
if it starts to hurt a little bit. I was sliding very fast towards CTS and this
corrected it.

### <a id="tag-16"></a>Q: When I stand on void jumpgates I'm never teleported away, what's wrong?

A: Void jumpgates are not automatic. You must press '>' while standing
on one to activate it.

### Q: When it panic saves it reloads an old savefile !!

A: Now the panic saves use a different file to save, savefile.pnc.\
This file will be loaded first, if present, when the game is started.\
If it loads successfully, save the game immediately. Otherwise, delete
the panic save, and your old (non-panic) savefile should be safe.

### <a id="tag-8"></a>Q: Farmer Maggot / Melinda Proudfoot keep shouting at me, and I cannot kill them.

A: Both these people need to talk to you about something. Have a chat with them
(check the file [command.txt](command.md#tag-96) for how to chat).

### <a id="tag-9"></a>Q: I have found a sentient weapon, it says it has access to the realms of Earth and Fire. How do I use these realms?

A: You don't actually 'use' them as such. If a weapon is sentient it means it
gains experience itself as it delivers killing blows. As it levels up it has
the chance to gain pluses to hit and to damage, and also powers from any of the
available 'realms'. For instance, the realm of fire gives the chance to gain
resistance to fire, or fire branding on your weapon. The realm of earth has a
chance to confer extra attacks or the power of causing earthquakes and so on.

### <a id="tag-24"></a><a id="tag-25"></a>Q: What or who is Fumblefingers? How do I get his quests?

A: FF is short for Fumblefingers, the name that some players give to the
adventurer who keeps having his sword stolen by monsters and asking you to
find it for him. So named because he often seems to lose it to molds and
other creatures you wouldn't expect to be able to pickpocket!  During birth
you'll be asked to specify a number of random quests you would like to
attempt to complete. Some of these quests will take the form of princess
quests, others will be fumble-finger quests. If you complete the task he
sets you sucessfully, he'll offer to join you as a companion. If you do not
want him to join you, he'll offer to teach you some new skills. Quite handy.

### <a id="tag-26"></a>Q: Where has the option gone to set the number of random quests? Why aren't there any after the Barrow-downs?

A: Turning on either of the options "Allow permanent dungeon levels" or "Always
create special rooms" will disable random quests.  Random quests can only be
found in the four main dungeons (Barrowdowns, Mirkwood, Mordor and Angband).

### <a id="tag-27"></a><a id="tag-28"></a>Q: How do I get the dots to show up on floor tiles in Windows XP? I've tried changing the tile character to the brighter dot. Toggling 'Bizarre Display' mode helped with the trailing @@@@@@@@@@@@@@@@@ problem. Any suggestions? I gave up a long time ago and play with graphics tiles now, but I'd like to be able to fix this.

A: In the file ./lib/pref/font_win.prf, either remove or comment out with # the
lines that end in /0x1F, e.g.\
\# open floor\
\# F:1:0x01/0x1F\
Another possibility is to manually change the symbols used with the '%'
command, but the previous solution is faster.

### <a id="tag-29"></a>Q: Many things are written in a dark grey color which is next to impossible to read against a black background. Also, some monsters appear in dark grey and are easy to miss! What can I do to fix this?

A: Fix the gamma control of your display. If your display software does not
include such a tool, access the 'Interact with Colors' screen in ToME via
shift+7, type '4', and modify the gamma correction there.

### <a id="tag-30"></a>Q: Why don't you make X class less powerful or Y class more powerful?

A: In ToME the player determines how hard the game is. Classes, races, and
subraces are neither meant nor desired to be equal in game difficulty. So no,
we won't make Axemasters more powerful just to "balance them out", nor will we
make Sorcerors weaker.

### <a id="tag-31"></a>Q: Why do I always start in a terribly difficult, very deep dungeon instead of a town? Is the game really this hard?

A: You have chosen a "Lost soul" character subrace. That's where Lost souls
start. They tend to die very quickly, so don't choose them if you're new to
ToME.

### <a id="tag-32"></a>Q: My character is invisible. That's great, but how do I know where she is if I can't see her?!

A: You could seek for a way to see invisible things.\
You could also go to game options:\
&nbsp;&nbsp;&nbsp;&nbsp;1. Type = (game options)\
&nbsp;&nbsp;&nbsp;&nbsp;2. Type 4 (efficiency options)\
&nbsp;&nbsp;&nbsp;&nbsp;3. Arrow down to 'hilite the player with the cursor'\
&nbsp;&nbsp;&nbsp;&nbsp;4. Type y to toggle the option to 'yes'

### <a id="tag-33"></a>Q: I'm standing on a pile of items. How do I see what's in the pile without picking it all up, moving it, or destroying it all?

A:\
&nbsp;&nbsp;&nbsp;&nbsp;1. Stand on the pile in question\
&nbsp;&nbsp;&nbsp;&nbsp;2. Type shift + I (inspect)\
&nbsp;&nbsp;&nbsp;&nbsp;3. Type - (examine items on floor)\
&nbsp;&nbsp;&nbsp;&nbsp;4. Type \* (expand list of items on floor)\
&nbsp;&nbsp;&nbsp;&nbsp;5. (as needed) Type letter associated with item to look at it more closely.

### Q: If I'm standing on a pile of items. Is there a command to see if there is a stairway or jumpgate beneath the pile?

A: Stairs/jumpgates obscured by clutter do still function. You are advised to
take a good hard look at your surroundings before creating lots of dungeon
clutter.\
&nbsp;&nbsp;&nbsp;&nbsp;1. You can pick up, move, or eliminate the pile.\
&nbsp;&nbsp;&nbsp;&nbsp;2. Press l (look), then select the square you wish to inquire about. Press
\<enter>; it will scroll through everything on the ground, and eventually it
ends with "It is in a Void Jumpgate", or whatever.

### <a id="tag-34"></a><a id="tag-36"></a>Q: What is a good starting character?

A: Make sure to read the parchment you start the game with!

If you're new to ToME, understand that your characters are going to die a lot.
Be prepared for that. In fact, take advantage of it by using the various
characters you run to experiment and learn the game's various facets.

Try a warrior. A Dunadan Swordmaster is an excellent combination of race and
class.

Try a priest. A Rohan Knight Paladin gives you some magic to go with strong
combat, but your terrible stealth will give you a tougher time in some respects.

Try an archer. A Wood-elf Archer will have fewer hitpoints than you're used to,
but lets you use excellent ranged combat instead. Also note how your higher
stealth wakes up fewer monsters, letting you fight them more on your own terms.

Try a mage. A Dark-elf Mage lets you keep using weapons, while getting a taste
of the various magic schools. You have even fewer hitpoints, though, so beware.

Try another mage. A Hobbit Sorceror is a fun character, but the hitpoint
penalties make you need to be very careful. You get high-powered magic, though,
to more than make up for it.

I would just add that for those who get frustrated in the early levels and want
to run a more powerful character that I think the three easiest combinations
are probably the Zombie Rohan Knight Unbeliever, the Thunderlord (or Vampire
Half-Ogre) Sorceror, and the High-Elf (or Deathmold if you can figure it out)
Possessor. Also, you might want to try a priest of Eru or Tulkas. Most of these
have low stealth, but should be pretty easy to play up to around level 30, and
they offer an attractive range of experiences for the new player.

### <a id="tag-35"></a>Q: I'm getting killed a lot. Can you recommend some starting options to make my chances a little better?

A: Realize that getting killed a lot is to be expected. Having said that, try
this. At character creation:\
&nbsp;&nbsp;&nbsp;&nbsp;1. Turn off "always generate very unusual rooms".\
&nbsp;&nbsp;&nbsp;&nbsp;2. Turn off joke monsters.\
&nbsp;&nbsp;&nbsp;&nbsp;3. Turn off "always make small levels".\
&nbsp;&nbsp;&nbsp;&nbsp;4. Regarding the number of random quests: See the Q/A below.\
&nbsp;&nbsp;&nbsp;&nbsp;5. Do not choose a Lost Soul character.

Later, set these options:\
&nbsp;&nbsp;&nbsp;&nbsp;1. Turn on "expand the power of the look command".\
&nbsp;&nbsp;&nbsp;&nbsp;2. Turn on "allow some monsters to carry light".\
&nbsp;&nbsp;&nbsp;&nbsp;3. Turn on "map remembers all perma-lit grids".\
&nbsp;&nbsp;&nbsp;&nbsp;4. Turn on "map remembers all torch-lit grids".\
&nbsp;&nbsp;&nbsp;&nbsp;5. Turn off "monsters learn from their mistakes".\
&nbsp;&nbsp;&nbsp;&nbsp;6. Turn off "monsters exploit player weaknesses".\
&nbsp;&nbsp;&nbsp;&nbsp;7. Turn on "monsters behave stupidly".\
&nbsp;&nbsp;&nbsp;&nbsp;8. Turn off "allow unusually small dungeon levels".\
&nbsp;&nbsp;&nbsp;&nbsp;9. Turn off "allow empty 'arena' levels".

### Q: How many random quests should I choose?

A: One big question a beginner is faced with is: How many (random) optional
quests to choose?

I think this is another area where the beginner should mix it up. The early
items from princesses are a great benefit to beginners, but coming to rely on
those can be a problem when it comes time to enter deep dungeons and the real
nasty quests begin.

Also high counts, especially 98 quests, can be very frustrating for a beginner
when it puts an especially difficult quest on dungeon level 1 or 2.

### <a id="tag-37"></a>Q: Are Amulets of Anti-magic and the Anti-magic skill related?

A: No. The Anti-magic shell of the Amulet of Anti-magic has nothing to do with
the Anti-magic field given off by the skill and Dark Swords.

### <a id="tag-38"></a>Q: My Beorning character doesn't have Bearform-combat! Why?

A: You cannot put points into Bearform-combat unless you are transformed
into a bear.  Use the racial power ('U' in the original keyset, 'O' in
roguelike) to transform first.

### Q: The game is so slow...

A: Yeah :(\
Try disabling the various options marked as (slow)
