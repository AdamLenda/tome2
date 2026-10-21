<!-- Generated from lib/help/birth.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-84"></a><a id="tag-11"></a>Creating a Character

|   |   |
| --- | --- |
| [Creating a Character](#tag-1) | [Character Characteristics](#tag-2) |
| [Races](#tag-3) | [Race Modifiers](#tag-4) |
| [Classes](#tag-5) | [Gods](#tag-83) |
| [Stats](#tag-6) | [Abilities](#tag-7) |
| [Combinations of Race and Class](#tag-8) | [Stat bonus tables](#tag-9) |

## <a id="tag-1"></a><a id="tag-12"></a>Creating a Character

ToME is a roleplaying game, in which you, the player, control a
character in the various dungeons and places of Arda. Perhaps the most
important thing you control is the birth of your character, in which you
choose or allow to be chosen various attributes that will affect the future
life of your character.

Character creation, or birth, is controlled through a variety of choices
as to constraints on the type of character you wish to play, followed by
a series of random calculations to generate ("roll up") a random character
matching the appropriate constraints.

Once your character has been generated, you will be given the choice to
generate a new character obeying the same constraints, and once you have
generated more than one character, you can switch back and forth between
the two most recent characters, until you are presented with a personality
that you feel comfortable with.

You may start the entire process over at any time.

Once you have accepted a character you will asked to provide a name for the
character. In general, the actual choice of a name is not important, but do
keep in mind that it may have some effect on the game itself. For example,
on some machines, the character name determines the filename that will be
used to save the character to disk. On others, the character name specifies
special "pref" files. And the character name is used on the high score list.

## <a id="tag-2"></a><a id="tag-13"></a><a id="tag-14"></a><a id="tag-37"></a><a id="tag-82"></a>Character Characteristics

Each character has four primary attributes -- gender, race, race modifier and
class -- that are chosen before the character is generated, and all but gender
stay fixed for the entire life of that character. These attributes have many
effects, which will be mentioned as they come up. Keep in mind that in the
current version of ToME, your choice of race may restrict your choice
of class.

Each character has a few secondary attributes -- height, weight, social class,
and background history -- which are randomly determined, but which are affected
by the gender and race of the character. In general, these attributes are only
used to provide "flavor" to the character, to assist in the role playing, but
they do have a few minor effects on the game. For example, background history
affects social class, which affects the amount of money the character will
start with.

Each character also has six primary "stats": strength (STR), intelligence
(INT), wisdom (WIS), dexterity (DEX), constitution (CON), and charisma (CHR).

By default, primary statistics are represented in a linear way rather than a
percentile way. You can change to percentile via the game option sequence '=',
'5' (ToME options), arrow down to 'stats are represented in a linear way', and
type 'n' for no. Don't forget to save your options when you are done.

These stats modify the abilities of the character in a variety of ways. Every
stat has a numerical value, ranging from a minimum of 3, up to a normal maximum
of 18, and even higher, into the "percentile" range, represented as "18/01"
through "18/100". Actually, every stat can be raised even above 18/100 by
magical means, up to a pure maximum of 18/220, which is represented as
"18/\*\*\*". Traditionally, a percentile stat such as "18/50" has been though of
as representing a value part way between 18 and 19, and this is one way to
think of them. However, often, the best way to view the "bonus" values after
the "18/" is as "tenth" points, since it often takes the same magic to raise a
stat from, say, 4 to 5, or 16 to 17, as it does from, say, 18/40 to 18/50. The
important thing to remember is that almost all internal calculations "ignore"
the final digit of any "bonus", so that, for example, "18/40" and "18/49"
generally have the same effects. During character generation, each stat is
rolled out as a number from 8 to 17, with a normal (bell-curve) distribution,
and is then immediately modified based on the race and class of the character.

Each character also has several primary "skills" -- disarming, magic devices,
saving throws, stealth, searching ability, searching frequency, fighting skill,
and shooting skill -- which are derived from the character's race, class, level,
stats, and current equipment. These skills have rather obvious effects, but
will be described more completely below.

Each character may have one or more "intrinsic racial skills", based on
the race of the character. These may include special resistances, abilities
such as infravision, or even activatable powers such as food creation.

<a id="tag-16"></a><a id="tag-81"></a><a id="tag-17"></a><a id="tag-18"></a>Money in ToME is referred to in gold pieces, also frequently abbreviated as AU
(the chemical symbol for gold).

Each character starts with some gold, which can be used to buy items from the
shops in town. Additionally, gold can be obtained by several means:

\* selling items you have, or find, to the shops\
\* taking it from dead monsters\
\* finding it lying around on the floor in the dungeon\
\* digging it out of the walls in certain dungeons

Each character starts out with some gold. The amount you start with is based on
social class (higher is better), charisma (higher is better), and some other
stats (less powerful characters start with more gold).

<a id="tag-85"></a>Inventory is what you are carrying and/or wearing at the moment. All items you
carry/wear have a certain weight. If the weight is very heavy for your
strength, it can slow you down, and that is not a good thing for your
character's continuing health. When your character is first created, all items
you are granted upon creation will be in your inventory. Sometimes starting
inventory includes something other than a weapon or armor (for example, a light
source, scroll, potion, or food.)

<a id="tag-86"></a>Some characters start with a weapon. If yours does, you will need to 'w'ield it
in order to gain its attack capabilities.

## <a id="tag-23"></a><a id="tag-19"></a><a id="tag-20"></a>Armour Class

Each character has an armor class, representing how well the character can
avoid damage. The armor class is affected by dexterity, the equipment, and
sometimes the race. The higher the AC, the better.

The numbers following a piece of armor's name indicate how good it is. A Metal
Cap \[3,+0\] is not as good as an Iron Helm \[5,+0\], AC-wise, since the 5 is a
bigger number than the 3. On the other hand, an Iron Helm is heavier than a
Metal Cap, and that may make a difference to you.

The plusses following the first number (e.g. the +0) indicate a magical bonus.
If the plus number is more than zero, it should be added on to the base
number. E.g. a Metal Cap \[3,+3\] has a higher AC than an Iron Helm \[5,+0\].

Some characters start with armor. If yours does, you need will need to 'w'ield
it in order to gain its protection.

<a id="tag-21"></a><a id="tag-22"></a>Each character has hit points (HP), representing how much damage the character
can sustain before death. Hit points are derived from your race, class,
level, and constitution, and can be temporarily boosted by magical means.
Hit points may be regained by resting, or by a variety of magical means.

<a id="tag-24"></a><a id="tag-25"></a>Each character has sanity points (SN), representing how much mental damage the
character can sustain before death. Sanity points are derived from your wisdom
and character level. Sanity points may only be regained by magical means and
won't be regained by resting.

<a id="tag-26"></a><a id="tag-27"></a><a id="tag-28"></a>Each character has a certain amount of mana. The amount of mana represents how
many spells of a certain difficulty a character can cast. When a spell is
cast, you lose amount of mana corresponding to the 'cost' of the spell.

When all mana is gone, or the cost of a given spell is greater than the amount
of mana you have left, you may attempt to cast a spell; beware, as there are
consequences to such a rash act.

Spell points may be regained by resting. They can also be restored by a few
magical means.

Your spell points are derived from your Magic skill, player level and the
greatest of INT and WIS.

Your total spell points are additionally affected by:

\* your character's race modifier\
\* character class

Your total spell points may be affected by:

\* your encumbrance\
\* what you wear

<a id="tag-29"></a><a id="tag-30"></a><a id="tag-31"></a>Finally, characters that have chosen to follow a [God](gods.md) will have piety points
(Pt). These points represent the character's standing with their God, a
standing which may rise or fall over time. A character may spend piety points
to cast a spell granted by his/her God. Spent piety points can be regained in
different fashions, depending on which God is involved -- each is pleased or
displeased by assorted actions. Pleasing your God gains you piety, while
displeasing your god will lose you piety.

In addition to forming the basis for God-granted spells, accumulated piety
points may also confer various benefits or penalties upon your character,
depending on the God involved.  For example, followers of Eru who have
accmulated lots of piety points gain a WIS bonus.  The actual rules are
quite specific to each God.

## <a id="tag-3"></a>Races

There are lots different races that you can choose from in ToME. Some
races are restricted as to what profession they may be, and each race has
its own adjustments to a character's stats and abilities. Most races also
have intrinsic abilities, which can be accessed via the "U" command (original
keyset, or "O" in the roguelike keyset).

|   |   |   |
| --- | --- | --- |
| [Beorning](r_beorn.md) | [Half-Elf](r_hafelf.md) | [Orc](r_orc.md) |
| [Dark Elf](r_drkelf.md) | [Half-Ogre](r_hafogr.md) | [Petty-Dwarf](r_pettyd.md) |
| [Death Mold](r_deathm.md) | [High-Elf](r_hielf.md) | [Rohan Knight](r_rohank.md) |
| [Dunadan](r_dunad.md) | [Hobbit](r_hobbit.md) | [Thunderlord](r_thlord.md) |
| [Dwarf](r_dwarf.md) | [Human](r_human.md) | [Troll](r_troll.md) |
| [Elf](r_elf.md) | [Kobold](r_kobold.md) | [Wood Elf](r_wodelf.md) |
| [Ent](r_ent.md) | [Maia](r_maia.md) | [Yeek](r_yeek.md) |
| [Gnome](r_gnome.md) |  |  |

## <a id="tag-4"></a>Race Modifiers

There are many different race modifiers from which you can choose in ToME.
Some are restricted as to what race they can be used with, and each one has
its own adjustments to a character's stats and abilities. Most also have
intrinsic abilities. If you are not asked for a race modifier, it is because
your race only supports the classical form.

|   |   |
| --- | --- |
| [Classical](rm_class.md) | [Barbarian](rm_barb.md) |
| [Hermit](rm_herm.md) | [Lost Soul](rm_lsoul.md) |
| [Skeleton](rm_skel.md) | [Spectre](rm_spec.md) |
| [Vampire](rm_vamp.md) | [Zombie](rm_zomb.md) |

## <a id="tag-5"></a>Classes

Once a race has been chosen, you will need to pick a class. Some classes will
not be available to certain races, for instance, a Troll cannot become a
Paladin. For the first few adventures it is suggested that you run a warrior
or rogue. Spell casting generally requires a more experienced player that is
familiar with survival techniques.

|   |   |   |
| --- | --- | --- |
|  | [Mage](c_mage.md) | [Rogue](c_rogue.md) |
| [Archer](c_archer.md) | [Mimic](c_mimic.md) |  |
| [Assassin](c_assass.md) | [Mindcrafter](c_mindcr.md) | [Sorceror](c_sorcer.md) |
| [Axemaster](c_axemas.md) | [Monk](c_monk.md) | [Summoner](c_summon.md) |
| [Bard](c_bard.md) | [Necromancer](c_necro.md) | [Swordmaster](c_swordm.md) |
| [Dark-Priest](c_pr_drk.md) | [Paladin](c_palad.md) | [Symbiant](c_symbia.md) |
| [Demonologist](c_demono.md) | [Polearmmaster](c_polear.md) | [Thaumaturgist](c_thaum.md) |
| [Druid](c_druid.md) | [Possessor](c_posses.md) | [Unbeliever](c_unbel.md) |
| [Geomancer](c_geoman.md) | [Priest(Eru)](c_pr_eru.md) | [Warper](c_warper.md) |
| [Haftedmaster](c_hafted.md) | [Priest(Manwe)](c_pr_man.md) | [Warrior](c_warrio.md) |
| [Loremaster](c_lorema.md) | [Ranger](c_ranger.md) |  |

## <a id="tag-83"></a>Gods

Once a class has been chosen you may be given the option to choose a god. Some
classes (notably most Priests) will be given a God to worship automatically.
Some classes are not necessarily suited to following a God, and Gods are not
recommended for new players. You can also choose your mind about who (if
anyone) to worship during the game by finding an [altar](tome_faq.md#tag-4) of that God.

Read [gods.txt](gods.md) for a little more information about Gods.

|   |   |
| --- | --- |
| [Eru Iluvatar](g_eru.md) | [Manwe Sulimo](g_manwe.md) |
| [Yavanna Kementari](g_yavann.md) | [Tulkas](g_tulkas.md) |
| [Melkor Bauglir](g_melkor.md) |  |

## <a id="tag-39"></a><a id="tag-6"></a>Stats

### <a id="tag-32"></a><a id="tag-34"></a>Strength (STR)

Strength is important in fighting with weapons and in melee
combat. A high strength can improve your chances of hitting
as well as the amount of damage done with each hit. Char-
acters with low strengths may receive penalties. Strength
is also useful in tunnelling and in carrying heavy items.

### <a id="tag-33"></a><a id="tag-35"></a>Intelligence (INT)

Intelligence affects the spellcasting abilities of mage-like
spell schools (whether these spells are learned directly through
their associated skills, or indirectly through the Prayer
skill), as well as some of the special abilities of various
classes (e.g. Symbiants).  Intelligence will affect the number
of spell points you receive. A high intelligence may also
improve your chances of successfully casting a spell. You cannot
learn spells if your intelligence is 7 or lower. A good
intelligence can also help with using magic devices, picking
locks, and disarming traps.

### <a id="tag-36"></a><a id="tag-38"></a>Wisdom (WIS)

The primary function of wisdom is to determine the ability
of a priest or paladin to use prayers (God-granted spells), just
like intelligence affects mage spells. Again, high wisdom will
increase the number of spell points you have (even though
prayers use piety points), and will improve the chance that a
prayer will be successful. A good wisdom can also help to
improve your chances of resisting magical spells cast
upon you by monsters.

### <a id="tag-40"></a><a id="tag-41"></a>Dexterity (DEX)

Dexterity is a combination of agility and quickness. A high
dexterity may allow your character to get multiple blows with
lighter weapons, thus greatly increasing your kill power, and
will increase your chances of hitting with any weapon and
dodging blows from enemies. Dexterity is also useful in
picking locks, disarming traps, and protecting yourself from
some of the thieves that inhabit the dungeons.  The unscrupulous
adventurer may also find dexterity effective in obtaining items
from stores without rendering payment.

### <a id="tag-42"></a><a id="tag-43"></a>Constitution (CON)

Constitution is a character's ability to resist damage to his
body, and to recover from damage received. Therefore a
character with a high constitution will receive more hit
points and also recover them faster while resting.

### <a id="tag-44"></a><a id="tag-45"></a>Charisma (CHR)

Charisma represents a character's personality and physical
appearance. A character with a high charisma will receive
better prices from store owners, whereas a character with a
very low charisma may be robbed blind. A high charisma will
also mean more starting money for the character.

## <a id="tag-7"></a><a id="tag-46"></a>Abilities

Characters possess some different abilities which can help them
to survive. The starting abilities of a character are based upon
race and class. Abilities may be adjusted by high or low stats,
and increase with the corresponding [skill](skills.md) level.

### <a id="tag-48"></a>Fighting

Fighting is the ability to hit and do damage with weapons or
fists. Normally  a  character  gets  a single blow from any
weapon, but if his dexterity and strength are  high  enough,
he  may  receive  more blows per round with lighter weapons.
Strength and dexterity both modify the  ability  to  hit  an
opponent. This skill increases  with the [Weaponmastery](skills.md#tag-2) skill
and its sub-skills.

### <a id="tag-50"></a>Shooting Ability (Bows/Throw)

Using  ranged  missile  weapons (and  throwing  objects) is
included  in this skill. Different stats apply to different
weapons, but this ability may modify the distance an  object
is  thrown/fired, the amount of damage done, and the ability
to hit a creature. This skill increases with the [Archery](skills.md#tag-8) skill
and its sub-skills.

### <a id="tag-52"></a>Saving Throw

A Saving Throw is the ability of a character to  resist  the
effects  of  a spell cast on him by another person/creature.
This does not include spells cast on the player by  his  own
stupidity, such  as  quaffing a nasty potion. This ability
increases with the [Spirituality](skills.md#tag-38) skill,\
A high wisdom also increases this  ability.

### <a id="tag-54"></a>Stealth

The ability to move  silently about is very useful. Charac-
ters with good stealth can usually surprise their opponents,
gaining the first blow. Also, creatures may fail to  notice
a  stealthy  character  entirely, allowing a player to avoid
certain fights. This skill is based upon race, class and the
[Stealth](skills.md#tag-15) skill.

### <a id="tag-56"></a>Disarming

Disarming is the  ability  to  remove  traps  (safely), and
includes  picking  locks  on  traps and doors. A successful
disarming will gain the character  some experience. A  trap
must  be  found  before  it  can be disarmed. Dexterity and
intelligence both modify the ability  to  disarm, and  this
ability increases with the [Disarming](skills.md#tag-16) skill.

### <a id="tag-58"></a>Magic Device

Using a magical device such as  a  wand  or  staff  requires
experience  and  knowledge. Spell  users such as  magi  and
priests are therefore much better at using a magical  device
than say a warrior. This skill is modified by intelligence,
and increases with the [Magic-Device](skills.md#tag-54) skill.

### <a id="tag-60"></a><a id="tag-61"></a><a id="tag-62"></a>Searching Frequency (Perception)

Perception  is  the  ability  to  notice  something  without
actively  seeking it out. This  skill  is  based  upon  race,
class and the [Sneakiness](skills.md) skill.

### <a id="tag-63"></a>Searching Ability (Searching)

To search is to actively look for secret doors, floor traps,
and  traps on chests. Rogues are the best at searching, but
magi, rangers, and priests are also good at it. This  skill
is  based  upon  race, class and the [Sneakiness](skills.md) skill.

### <a id="tag-66"></a>Infra-vision

Infra-vision is the ability to see heat sources. Since most
of the dungeon is cool or cold, infra-vision will not allow
the player to see walls and objects. Infra-vision will allow
a character to see any warm-blooded creatures up to a cer-
tain distance. This ability works equally well with or with
out a light source. The majority of ToME's creatures are
cold-blooded, and will not be detected unless lit up by a
light source. Most non-human races have innate infra-vision
ability. Humans can gain infra-vision only through magic
enhancement.

## <a id="tag-8"></a><a id="tag-67"></a><a id="tag-68"></a><a id="tag-69"></a><a id="tag-70"></a>Combinations of Race and Class

These are the classes that are recommended for different races. You can
still select a race that is not in the chart, but these combinations are
either rather poor (like a zombie mage), a concept so silly that they
are not recommended, or an incredibly unfair combination of race and class.
If you pick a combination that is not on the chart, don't complain if things
don't turn out as you expected them to.

$`\color{#00A5A5}{\textsf{Warrior  Archer  Rogue  Mage   Priest  Loremaster}}`$

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Beorning | Yes | No | Yes | No | No | Yes |
| Dark Elf | Yes | Yes | Yes | Yes | Yes | No |
| Death Mold | No | No | No | Yes | Yes | No |
| Dunadan | Yes | Yes | Yes | Yes | Yes | Yes |
| Dwarf | Yes | No | No | No | Yes | No |
| Elf | Yes | Yes | No | Yes | Yes | Yes |
| Ent | Yes | No | No | No | Yes | Yes |
| Gnome | Yes | No | Yes | Yes | No | No |
| Half-Elf | Yes | Yes | Yes | Yes | Yes | Yes |
| Half-Ogre | Yes | No | No | No | Yes | No |
| High-Elf | Yes | Yes | No | Yes | Yes | Yes |
| Hobbit | Yes | Yes | Yes | Yes | No | Yes |
| Human | Yes | Yes | Yes | Yes | Yes | Yes |
| Kobold | Yes | Yes | Yes | No | No | No |
| Maia | Yes | Yes | Yes | Yes | Yes | Yes |
| Orc | Yes | Yes | Yes | No | Yes | No |
| Petty Dwarf | Yes | No | Yes | No | No | No |
| RohanKnight | Yes | No | No | No | Yes | No |
| Thunderlord | Yes | Yes | No | Yes | Yes | No |
| Troll | Yes | No | No | No | No | No |
| Wood Elf | Yes | Yes | No | Yes | Yes | Yes |
| Yeek | Yes | Yes | Yes | Yes | Yes | Yes |

## <a id="tag-9"></a><a id="tag-71"></a><a id="tag-72"></a>Stat Bonus Tables

Stat, hit dice, and experience points per level modifications due to race
are listed in the following table.

### <a id="tag-75"></a>Races:

$`\color{#00A5A5}{\textsf{STR  INT  WIS  DEX  CON  CHR  Hit Dice  Rqd Exp/level}}`$

|   |   |   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Beorning | +4 | -2 | -2 | -1 | +3 | -5 | 12 | +50% |
| Dark Elf | -1 | +3 | +2 | +2 | -2 | +1 | 9 | +50% |
| Death Mold | +10 | 0 | +10 | +0 | +10 | -15 | 15 | +150% |
| Dunadan | +1 | +2 | +2 | +2 | +3 | +2 | 10 | +80% |
| Dwarf | +2 | -2 | +2 | -2 | +2 | -3 | 11 | +25% |
| Elf | -1 | +2 | +2 | +1 | -2 | +2 | 8 | +20% |
| Ent | +10 | -3 | +2 | -5 | +11 | -3 | 14 | +110% |
| Gnome | -1 | +2 | 0 | +2 | +1 | -2 | 8 | +35% |
| Half-Elf | 0 | +1 | +1 | +1 | -1 | +1 | 9 | +10% |
| Half-Ogre | +3 | -1 | -1 | -1 | +3 | -3 | 12 | +30% |
| High-Elf | +1 | +3 | +2 | +3 | +1 | +5 | 10 | +100% |
| Hobbit | -2 | +2 | +1 | +3 | +2 | +1 | 7 | +10% |
| Human | 0 | 0 | 0 | 0 | 0 | 0 | 10 | +0% |
| Kobold | +1 | -1 | 0 | +1 | 0 | -4 | 9 | +25% |
| Maia | 0 | 0 | 0 | 0 | 0 | 0 | 10 | +0% |
| Petty Dwarf | +1 | -1 | +2 | 0 | +2 | -4 | 11 | +35% |
| Orc | +2 | -1 | 0 | +1 | +1 | -4 | 10 | +10% |
| RohanKnight | +4 | -2 | +3 | +1 | +4 | +2 | 10 | +120% |
| Thunderlord | +6 | +2 | +1 | +1 | +3 | +8 | 12 | +300% |
| Troll | +4 | -4 | -2 | -4 | +3 | -6 | 12 | +37% |
| Wood Elf | -3 | +2 | +1 | +5 | -4 | +1 | 7 | +30% |
| Yeek | -5 | -5 | -5 | -5 | -5 | -5 | 6 | -75% |

### <a id="tag-76"></a>Race Modifiers:

$`\color{#00A5A5}{\textsf{STR  INT  WIS  DEX  CON  CHR  Hit Dice  Rqd Exp/level}}`$

|   |   |   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Classical | 0 | 0 | 0 | 0 | 0 | 0 | +0 | +0% |
| Barbarian | +2 | -3 | -2 | +1 | +1 | -3 | +1 | +25% |
| Hermit | -3 | +1 | +1 | -3 | -3 | +1 | -3 | +20% |
| Lost Soul | 0 | 0 | 0 | 0 | 0 | 0 | +0 | +0% |
| Skeleton | 0 | -2 | -2 | 0 | +1 | -4 | +0 | +45% |
| Spectre | -5 | +2 | +2 | +2 | -3 | -6 | -4 | +80% |
| Vampire | +3 | +2 | -3 | -2 | +1 | -4 | +1 | +100% |
| Zombie | +2 | -6 | -6 | +1 | +4 | -5 | +3 | +45% |

### <a id="tag-77"></a>Classes:

|  | STR | INT | WIS | DEX | CON | CHR |
| --- | --- | --- | --- | --- | --- | --- |
| Axemaster | +5 | -2 | -2 | +2 | +2 | -1 |
| Demonologist | +5 | -2 | -2 | +2 | +2 | -1 |
| Haftedmaster | +5 | -2 | -2 | +2 | +2 | -1 |
| Polearmmaster | +5 | -2 | -2 | +2 | +2 | -1 |
| Swordmaster | +5 | -2 | -2 | +2 | +2 | -1 |
| Unbeliever | +5 | -2 | -2 | +2 | +2 | -1 |
| Warrior | +5 | -2 | -2 | +2 | +2 | -1 |

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Geomancer | -5 | +3 | 0 | +1 | -2 | +1 |
| Mage | -5 | +3 | 0 | +1 | -2 | +1 |
| Necromancer | -5 | +3 | 0 | +1 | -2 | +1 |
| Sorceror | -5 | +3 | 0 | +1 | -2 | +1 |
| Thaumaturgist | -5 | +3 | 0 | +1 | -2 | +1 |
| Warper | -5 | +3 | 0 | +1 | -2 | +1 |

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Archer | +2 | +1 | 0 | +2 | +1 | +1 |
| Ranger | +2 | +2 | 0 | +2 | +1 | +1 |

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Assassin | +2 | +1 | -2 | +3 | +1 | -1 |
| Rogue | +2 | +1 | -2 | +3 | +1 | -1 |

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Bard | +1 | -2 | +1 | +1 | 0 | +1 |
| Loremaster | +1 | -2 | +1 | +1 | 0 | +1 |
| Mimic | +1 | -2 | +1 | +1 | 0 | +1 |
| Monk | +1 | -2 | +1 | +1 | 0 | +1 |
| Possessor | +1 | -2 | +1 | +1 | 0 | +1 |
| Summoner | +1 | -2 | +1 | +1 | 0 | +1 |
| Symbiant | +1 | -2 | +1 | +1 | 0 | +1 |

|   |   |   |   |   |   |   |
| --- | --- | --- | --- | --- | --- | --- |
| Dark-Priest | -1 | -3 | +3 | -1 | 0 | +2 |
| Druid | -1 | -3 | +3 | -1 | 0 | +2 |
| Mindcrafter | -1 | -3 | +3 | -1 | 0 | +2 |
| Paladin | -1 | -3 | +3 | -1 | 0 | +2 |
| Priest(Eru) | -1 | -3 | +3 | -1 | 0 | +2 |
| Priest(Manwe) | -1 | -3 | +3 | -1 | 0 | +2 |

## <a id="tag-10"></a><a id="tag-74"></a>Skill Tables

### <a id="tag-78"></a>Races:

|  | Disarm | Devices Sprtlty Stealth Sneak | Wepnmas Archery |
| --- | --- | --- | --- |
| Beorning | -0.6 | -0.8    -3.0    -2.0    -0.1 | +2.5    +0.5 |
| Dark-Elf | +0.5 | +1.5    +10.0   +3.0    +0.8 | -0.5    +1.0 |
| DeathMold | +1.5 | -0.5    +7.5    +25     0 | +2.5    +2.5 |
| Dunadan | +0.4 | +0.5    +2.5    +2.0    +0.8 | +1.5    +1.0 |
| Dwarf | +0.2 | +0.9    +5.0    -1.0    +0.7 | +1.5    +0.5 |
| Elf | +0.5 | +0.6    +3.0    +2.0    +0.8 | -0.5    +1.5 |
| Ent | +0.5 | +0.5    +10.0   -6.0    +0.5 | -0.3    -0.2 |
| Gnome | +1.0 | +1.2    +6.0    +3.0    +0.6 | -0.8    +1.2 |
| Half-Elf | +0.2 | +0.3    +1.5    +1.0    +0.6 | -0.1    +0.5 |
| Half-Ogre | -0.3 | -0.5    -2.5    -2.0    -0.1 | +2.0    0 |
| High-Elf | +0.4 | +2.0    +10.0   +4.0    +0.3 | +1.0    +2.5 |
| Hobbit | +1.5 | +1.8    +9.0    +5.0    +1.2 | -1.0    +2.0 |
| Human | 0 | 0       0       0       0 | 0       0 |
| Kobold | -0.2 | -0.3    -1.0    -1.0    +0.1 | +1.0    -0.8 |
| Maia | 0 | 0       0       0       0 | 0       0 |
| Orc | -0.3 | -0.3    -1.0    -1.0    0 | +1.2    -0.5 |
| Petty Dwarf | +0.3 | +0.5    +5.0    +1.0    +0.5 | 0       0 |
| RohanKnight | +1.0 | +0.5    +2.5    -8.0    +0.1 | +0.1    +0.5 |
| Thunderlord | +0.6 | 0       +5.0    -16.0   +3.0 | +1.5    +0.5 |
| Troll | -0.5 | -0.8    -4.0    -2.0    -0.1 | +2.0    -1.0 |
| Wood-Elf | +0.5 | +0.6    +3.0    +5.0    +0.8 | -2.5    +4.0 |
| Yeek | -0.5 | -0.5    -2.5    -5.0    -0.5 | -0.5    -0.5 |

In addition to the racial starting bonuses for the standard skills listed
above, there are some special bonuses to the skill modifier:

|   |   |
| --- | --- |
| Beorning | +1.0 Bearform-combat modifier (also 1.0 points to start) |
| Dark-Elf | +0.2 Magic modifier |
| DeathMold | +0.2 Necromancy modifier |
| Dwarf | +0.2 Axe-mastery modifier |
| Ent | +0.2 Barehand-combat modifier; |
|  | +0.6 Boulder-throwing modifier |
| Hobbit | +0.3 Sling-mastery modifier |
| Maia | Not allowed to use Prayer (modifier reduced to 0.000) |
| RohanKnight | +0.2 Weaponmastery modifier |
| Wood-Elf | +0.2 Archery modifier |

(If the character's class does not normally possess the skill, this racial
modifier bonus will grant the skill at a starting level of 0.000.)

### <a id="tag-79"></a>Race Modifiers:

|  | Disarm | Devices Sprtlty Stealth Sneak | Wepnmas Archery |
| --- | --- | --- | --- |
| Classical | 0 | 0       0       0       0 | 0       0 |
| Barbarian | -0.2 | -1.0    +0.2    -2.0    +0.0 | +1.2    +0.5 |
| Hermit | +0.5 | +1.0    +0.5    +3.0    +0.4 | -0.5    -0.5 |
| Lost Soul | 0 | 0       0       0       0 | 0       0 |
| Skeleton | -0.5 | -0.5    +0.5    -1.0    -0.1 | +0.8    0 |
| Spectre | +0.2 | +0.8    +0.7    +2.0    +0.2 | -0.5    -0.2 |
| Vampire | 0 | 0       0       0       0 | 0       0 |
| Zombie | -0.2 | -0.2    +0.5    -1.0    -0.1 | +0.5    0 |
