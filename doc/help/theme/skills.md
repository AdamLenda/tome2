<!-- Generated from lib/mods/theme/help/skills.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-55"></a>ToME Skills System

One of the big differences between standard "Vanilla" Angband and ToME is the
implementation of a skill system where the player can choose what skills she
will improve as her character progresses. As such, many abilities such as
spell casting, fighting and trap disarming \*do not\* increase automatically -
the player must choose to use skill points to improve those abilities. This
gives the player the chance to tailor a character to suit their playing style
with a lot more flexibility than has existed with a fixed progression system
in the past. However, not all types of characters are able to gain skills to
the same degree; while a fighter can learn some magic, he's unlikely to become
as good at it as a mage can. So the number of skill points required to raise
a skill to the next level varies according to the starting "type" of character.

You can also spend skill points in "one-off purchase" [Abilities](ability.md).

### <a id="tag-56"></a>The Skills Menu

Each time you gain a level of experience, you receive 6 skill points to spread
around as you wish. To use these skill points, you need to access the skills
menu ("G" for both keysets). This opens up a long list of abilities that can
be improved.  The menu may look something like this:

```text
                            ToME Skills Screen
Enter to develop a branch, up/down to move, right/left to modify, ? for help
Skill points left: 6
General ability to fight and to pseudo-id armors and weapons.
It also allows to use heavier armours without penalties
[-]Combat                                                   02.000 [0.800]
     - Weaponmastery                                        01.000 [0.850]
         . Sword-mastery                                    00.000 [0.400]
         . Axe-mastery                                      00.000 [0.400]
         . Hafted-mastery                                   00.000 [0.400]
         . Polearm-mastery                                  00.000 [0.400]
     . Archery                                              01.000 [0.600]
     . Antimagic                                            00.000 [0.550]
 + Sneakiness                                               01.000 [0.900]
 + Magic                                                    01.000 [0.300]
 - Spirituality                                             01.000 [0.400]
     . Prayer                                               00.000 [0.500]
 . Monster-lore                                             00.000 [0.500]
```

Now, looking at this screen, there are several things to be aware of. The
first line lets you know if you have any available skill points to spend, and
how many there are. Following that are 2 description lines for the currently
selected skill - in this case they are describing the "Combat" skill. When
looking at the list of skills, there are a few different colours used - the
light green coloured skill (which also has its starting character in square
brackets \[\]) is the currently selected one - Combat in the example above.
Skills that you cannot learn are omitted from the list. Skills that you are
capable of learning, but as yet have not, are coloured in orange, while skills
of which you have some knowledge are shown in white.

At the end of each skill is a pair of numbers. The first represents your
current level of knowledge in the skill, and the second how much an advance
in this knowledge investing one skill point in this skill would produce. So,
in the above example, if the player invested one skill point in their Combat
skill, the skill would increase from 02.000 to 02.800.

In addition, investing in some skills may raise your knowledge in others.
This improvement is based on the modifier in the related class (the one which
gets the free points).  For example, a skill point put into Weaponmastery
raises Combat by 0.5 skill points. This is actually multiplied by the skill
modifier that your character has in the Combat skill.  For example, a
Swordmaster investing a skill point into Weaponmastery would have his Combat
skill raised by 0.5 \* \[0.900\].

As well as this, skills are grouped together in similar types. Looking under
the Combat skill, there are subtypes of Weaponmastery, Archery and Antimagic.
An increase of one of these subskills may also increase the main skill by a
small amount. You can tell which skills have subskills by the + (or -) in front
of their name. The + indicates that there are more skills within this category.
To open a skill category up, move the cursor up/down until the skill category
is green, then hit the "Enter" key. Likewise, the - indicates that the category
is already opened, and selecting this and hitting the "Enter" key will close it
up again. Skills which don't have usable subskills start with a ".".

To spend points on a skill (including skill categories), use the left/right
arrow (right arrow or "6" adds one skill point, left arrow or "4" removes
one). Spending points on a sub-skill will also marginally improve the parent
skill (or skill category). When you've finished spending skill points (and any
unspent points \*will\* be saved), hit the "Esc" key to finish. This will give
a confirmation prompt to check that you really do want to spend your points as
you've assigned them. Saying 'y' saves the changes and allows you to use or
apply your new skills :).

All skills have a maximum level of 50, and as long as you can learn a skill,
and have enough skill points to pump into it, it is theoretically possible to
get it to level 50 no matter what your race, class or how you learned it.

Each skill affects your character differently. It may be worth getting one or
more of your characters skills to 50, but it may not be worth investing $`\color{#00A5A5}{\textsf{any}}`$
skill points in some other skills. As general and personal advice, which may
not work for you, I'd say concentrate on a few skills, and leave the others
empty. Just because you $`\color{#00A5A5}{\textsf{can}}`$ learn a skill, it doesn't mean you have to.\
It often pays to have a plan ("I'm going to make this assassin the
stealthiest, most able-dodging, backstabber around. I'm not going to bother
with trapping or thieving ability") which you can stick to for the whole game.

### <a id="tag-57"></a>The Skills Themselves

So you want to know what each of the skills do so that you can decide how to
spend you're hard-earned points, huh? Well, each skill affects different
abilities, and not all of them are intuitive - but they don't take all that
long to learn :).\
If you don't find this informative enough, and would like more detailed spoilers
on what each skill does, try <http://www.killerbunnies.org/angband/skill-220.html>
for some third party help!\
The skills are:

|   |   |   |   |
| --- | --- | --- | --- |
| [Air](#tag-27) | [Antimagic](#tag-50) | [Archery](#tag-8) |  |
| [Axe-mastery](#tag-5) | [Backstab](#tag-18) | [Barehand-combat](#tag-13) | [Bearform-combat](#tag-61) |
| [Boomerang-mastery](#tag-12) | [Boulder-throwing](#tag-58) | [Bow-mastery](#tag-10) | [Combat](#tag-1) |
| [Conveyance](#tag-30) | [Corpse-preservation](#tag-44) | [Critical-hits](#tag-4) | [Crossbow-mastery](#tag-11) |
| [Demonology](#tag-52) | [Disarming](#tag-16) | [Divination](#tag-31) | [Dodging](#tag-20) |
| [Earth](#tag-28) | [Fire](#tag-25) | [Geomancy](#tag-60) | [Hafted-mastery](#tag-6) |
| [Magic](#tag-21) | [Magic-device](#tag-54) | [Mana](#tag-24) | [Meta](#tag-29) |
| [Mimicry](#tag-47) | [Mind](#tag-33) | [Mindcraft](#tag-41) | [Monster-lore](#tag-42) |
| [Music](#tag-59) | [Nature](#tag-34) | [Necromancy](#tag-35) | [Polearm-mastery](#tag-7) |
| [Possession](#tag-45) | [Prayer](#tag-39) | [Sling-mastery](#tag-9) |  |
| [Spell-power](#tag-22) | [Spirituality](#tag-38) | [Sorcery](#tag-23) | [Stealing](#tag-19) |
| [Stealth](#tag-15) | [Stunning-blows](#tag-53) | [Summoning](#tag-43) | [Sword-mastery](#tag-3) |
| [Symbiosis](#tag-46) | [Temporal](#tag-32) | [Thaumaturgy](#tag-37) | [Udun](#tag-48) |
| [Water](#tag-26) | [Weaponmastery](#tag-2) |  |  |

<a id="tag-1"></a>$`\color{#00A5A5}{\textsf{Combat}}`$\
The combat skill is used to determine the maximum combined weight of armour
you can wear before you become encumbered by it. It also affects your general
fighting ability, although not to as great an extent as Weaponmastery, and
determines the speed and strength of pseudo-id of weapons and armour.

Investing in the combat skill? You might be interested in the
[Extra Max Blow(1)](ability.md#tag-5) and [(2)](ability.md#tag-6) abilities.

Sub-skills of Combat are Weaponmastery, Archery, Barehand-combat,
Boulder-throwing and Anti-magic.

<a id="tag-2"></a>$`\color{#00A5A5}{\textsf{Weaponmastery}}`$\
This skill is a sub-skill of the Combat skill. It affects your general
ability to use melee weapons of all sorts. Spending 1 skill point on
Weaponmastery adds 0.5 bonus skill points to Combat.

Investing in the weaponmastery skill? You might be interested in the
[Spread Blows](ability.md#tag-2) ability.

Sub-skills of Weaponmastery are Sword-mastery, Axe-mastery, Hafted-mastery
and Polearm-mastery.

<a id="tag-3"></a>$`\color{#00A5A5}{\textsf{Sword-mastery}}`$\
This skill is a sub-skill of the Weaponmastery skill. It affects your ability
to use bladed weapons (e.g. daggers, swords). Spending 1 skill point on your
Sword-mastery skill adds 0.25 bonus skill points to your Weaponmastery skill
and adds 0.07 bonus skill points to your Combat skill.

Critical-hits is a sub-skill of Sword-mastery.

<a id="tag-4"></a>$`\color{#00A5A5}{\textsf{Critical-hits}}`$\
This skill is a sub-skill of the Sword-mastery skill. It affects your ability
to deal critical hits to monsters using a bladed weapon that weighs less than 5
pounds. Spending one skill point on your Critical-hits skill also increases
your Sword-mastery skill by 0.05 skill points.

<a id="tag-5"></a>$`\color{#00A5A5}{\textsf{Axe-mastery}}`$\
This skill is a sub-skill of the Weaponmastery skill. It affects your ability
to use axes. Spending 1 skill point on your Axe-mastery skill adds 0.25 bonus
skill points to your Weaponmastery skill and adds 0.07 bonus skill points to
your Combat skill.

<a id="tag-6"></a>$`\color{#00A5A5}{\textsf{Hafted-mastery}}`$\
This skill is a sub-skill of the Weaponmastery skill. It affects your ability
to use hafted weapons (e.g. whips & maces). Spending 1 skill point on your
Hafted-mastery skill adds 0.25 bonus skill points to your Weaponmastery skill
and adds 0.07 bonus skill points to your Combat skill.

Stunning-blows is a sub-skill of Hafted-mastery.

<a id="tag-53"></a>$`\color{#00A5A5}{\textsf{Stunning-blows}}`$\
This skill is a sub-skill of the Hafted-mastery skill. It affects your ability
to stun opponents when doing critical hits with a hafted weapon that weighs
more than 5 lbs. Spending one skill point on your Stunning-blows skill also
increases your Hafted-mastery skill by 0.05 skill points.

<a id="tag-7"></a>$`\color{#00A5A5}{\textsf{Polearm-mastery}}`$\
This skill is a sub-skill of the Weaponmastery skill. It affects your ability
to use polearms (e.g. pikes & halberds). Spending 1 skill point on your
Polearm-mastery skill adds 0.25 bonus skill points to your Weaponmastery skill
and adds 0.07 bonus skill points to your Combat skill.

Investing in the Polearm-mastery skill? You might be interested in the
[Far reaching attack](ability.md#tag-10) ability.

<a id="tag-8"></a>$`\color{#00A5A5}{\textsf{Archery}}`$\
This skill is a sub-skill of the Combat skill. It affects your general
ability to use ranged weapons of all sorts. Spending one skill point on your
Archery skill adds 0.5 bonus skill points to your Combat skill.

Investing in the Archery skill? You might be interested in the
[Ammo creation](ability.md#tag-7) ability.

Sub-skills of Archery include Sling-mastery, Bow-mastery, Crossbow-mastery
and Boomerang-mastery.

<a id="tag-9"></a>$`\color{#00A5A5}{\textsf{Sling-mastery}}`$\
This skill is a sub-skill of the Archery skill. It affects your ability to
use Slings. Spending 1 skill point on your Sling-mastery skill adds 0.25
bonus skill points to your Archery skill and 0.07 bonus skill points to your
Combat skill.

<a id="tag-10"></a>$`\color{#00A5A5}{\textsf{Bow-mastery}}`$\
This skill is a sub-skill of the Archery skill. It affects your ability to
use both Long and Short Bows. Spending 1 skill point on your Bow-mastery
skill adds 0.25 bonus skill points to your Archery skill and 0.07 bonus skill
points to your Combat skill.

<a id="tag-11"></a>$`\color{#00A5A5}{\textsf{Crossbow-mastery}}`$\
This skill is a sub-skill of the Archery skill. It affects your ability
to use both Heavy and Light Crossbows. Spending 1 skill point on your
Crossbow-mastery skill adds 0.25 bonus skill points to your Archery skill
and 0.07 bonus skill points to your Combat skill.

<a id="tag-12"></a>$`\color{#00A5A5}{\textsf{Boomerang-mastery}}`$\
This skill is a sub-skill of the Archery skill. It affects your ability to
use all boomerangs. Spending 1 skill point on your Boomerang-mastery skill
adds 0.25 bonus skill points to your Archery skill and 0.07 bonus skill
points to your Combat skill.

<a id="tag-13"></a>$`\color{#00A5A5}{\textsf{Barehand-combat}}`$\
This skill is a sub-skill of the Combat skill. It affects your general ability
to fight using martial arts. In order to utilise it, you must be capable of
using a weapon in the first place, but choose not to. Spending 1 skill point
on your Barehand-combat skill adds 0.5 bonus skill points to your Combat skill.
Barehand-combat fighters develop stronger and faster attacks, and also gain
speed bonuses, as they advance in skill.  However, they cannot use this skill
whilst wearing heavy armour.

<a id="tag-61"></a>$`\color{#00A5A5}{\textsf{Bearform-combat}}`$\
This skill is a sub-skill of the Combat skill. It affects your ability to fight
while in the form of a bear. In order to utilise it, you must be in bearform.
[Beornings](r_beorn.md) are the adventurers most likely to use this form of skill.

<a id="tag-58"></a>$`\color{#00A5A5}{\textsf{Boulder-throwing}}`$\
This skill is a sub-skill of the Combat skill. It affects your ability to
throw boulders and make them from granite walls. Spending 1 skill point on
your Boulder-throwing skill adds 0.4 bonus skill points to your Combat skill.

<a id="tag-50"></a>$`\color{#00A5A5}{\textsf{Antimagic}}`$\
This skill is a sub-skill of the Combat skill.  It generates a field around
the character within which magic cannot work. As such, it can be very useful
to prevent monsters from casting offensive spells against you or from
teleporting away from you just before you kill them - but it will also prevent
you from casting spells, or teleporting away when they've almost killed you!
It also inhibits your ability to do magic, affecting \*all\* the magic and
spirituality sub-skills.

This skill does not affect your ability to use scrolls and potions, but other
items that require \[Self\]Magic-Device are affected. At higher levels you gain
the ability to detect traps and disrupt all teleportation.

<a id="tag-15"></a>$`\color{#00A5A5}{\textsf{Stealth}}`$\
This skill is a sub-skill of the Sneakiness skill. It affects your ability
to move around the dungeon quietly so that you are not noticed by its
inhabitants. Spending 1 skill point on your Stealth skill adds 0.15 bonus
skill points to your Sneakiness skill.

<a id="tag-16"></a>$`\color{#00A5A5}{\textsf{Disarming}}`$\
This skill is a sub-skill of the Sneakiness skill. It affects your ability
to safely disarm any traps you find. Spending 1 skill point on your Disarming
skill adds 0.1 bonus skill points to your Sneakiness skill.

Investing in the Disarming skill? You might be interested in the [Trapping](ability.md#tag-11)
ability.

<a id="tag-18"></a>$`\color{#00A5A5}{\textsf{Backstab}}`$\
This skill is a sub-skill of the Sneakiness skill. It affects your ability
to sneak up on monsters and do extra damage to them before they wake up.\
It also affects monsters who have turned to flee from you.  Spending 1 skill
point on your Backstab skill adds 0.05 bonus skill points to your Sneakiness
skill.

<a id="tag-19"></a>$`\color{#00A5A5}{\textsf{Stealing}}`$\
This skill is a sub-skill of the Sneakiness skill. It affects your ability
to steal items from monsters and shops. Be careful when stealing from shops;
if you're caught, the shopkeeper will close his doors to you and not open
them again. I have heard that shop keepers do not stay in one shop forever
though. Spending 1 skill point on your Stealing skill adds 0.15 bonus skill
points to your Sneakiness skill.

<a id="tag-20"></a>$`\color{#00A5A5}{\textsf{Dodging}}`$\
This skill is a sub-skill of the Sneakiness skill. It affects your ability
to dodge out of the way of monster blows and bolts. The less armour you wear
and the less you carry, the greater your chance of dodging a blow. Rings and
amulets do not affect your chance to dodge, but full armour will almost render
the effect of the skill obsolete. Spending 1 skill point on your Dodging skill
adds 0.1 bonus skill points to your Sneakiness skill.

<a id="tag-21"></a>$`\color{#00A5A5}{\textsf{Magic}}`$\
The Magic skill affects your general use of magic items, the amount of mana
you can handle, and in general your ability to do magic. It can also affect
the strength of wands and staffs.

Investing in the Magic skill? You might be interested in the [Perfect Casting](ability.md#tag-4)
ability.

Sub-skills include: Magic-device, Spell-power, Sorcery, Mana, Fire, Water, Air,
Earth, Meta, Conveyance, Divination, Temporal, Mind, Nature, Udun, Demonology,
Necromancy, and Thaumaturgy.

<a id="tag-54"></a>$`\color{#00A5A5}{\textsf{Magic-device}}`$\
This skill is a sub-skill of the Magic skill. It eases the use of magical
devices, such as wands, staves, and rods, and boosts the casting level of spells
stored in a wand or a staff. [More on this](magic.md#tag-2). It also helps pseudo-id of magic
objects. Spending 1 skill point on your Magic-device skill adds 0.07 bonus skill
points to your Magic skill.

<a id="tag-22"></a>$`\color{#00A5A5}{\textsf{Spell-power}}`$\
This skill is a sub-skill of the Magic skill. It boosts the casting level of
most spells you are capable of casting. For example, if you have level one in
the mana school, you could cast "Manathrust". For every 2.5 skill levels of
Spell-power, Manathrust becomes more powerful, adding +1 casting level to the
spell. Note that this is not exactly the same as certain magic items which
boost spell power. Spending 1 skill point on your Spell-power skill adds 0.2
bonus skill points to your Magic skill.

$`\color{#00A5A5}{\textsf{This skill only affects the 11 primary schools}}`$ (Mana, Earth, Air, Fire,
Water, Meta, Mind, Temporal, Conveyance, Divination and Nature), as well as
Geomancy and the spells granted by the Gods.

<a id="tag-23"></a>$`\color{#00A5A5}{\textsf{Sorcery}}`$\
This skill is a sub-skill of the Magic skill. It allows you to access any
spell in the 11 schools up to the sorcery skill level. For example, if you
have a sorcery skill of 1, you could cast "Manathrust", which is a level 1
mana school spell; and "Phase Door", which is a level 1 conveyance school
spell. Spending 1 skill point on your Sorcery skill adds 0.2 bonus skill
points to your Magic skill.

$`\color{#00A5A5}{\textsf{This skill only affects the 11 primary schools}}`$ (Mana, Earth, Air, Fire,
Water, Meta, Mind, Temporal, Conveyance, Divination and Nature).

However, handling that much magic is hazardous to your health, and as such
reduces both your hit points and your fighting ability. Any ability in sorcery
affects your Weaponmastery, Archery, Barehand-combat and gives a negative
percentage modifier to your total hit points, equal to the level of your
sorcery skill (i.e. if sorcery is 12.500, hit points get modified by -12.5%).

<a id="tag-24"></a>$`\color{#00A5A5}{\textsf{Mana}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [mana](m_mana.md) school, and as it increases so does the casting level of
spells already attained in the school. For example, if you have level 1 in
the mana school, you could cast "Manathrust" at a casting level of 1. For
every skill level you add to Mana, Manathrust will become more powerful,
adding 1 casting level to the spell. Spending 1 skill point on your Mana
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-60"></a>$`\color{#00A5A5}{\textsf{Geomancy}}`$\
This skill is a subskill of the Magic skill. It gives access to spells
within the [Geomancy](m_geoman.md) school, and as it increases so does the casting level of
spells already attained in the school. Most spells from this school rely
on the Fire, Water, Air and Earth skills as well. Spending 1 skill point
on your Geomancy skill adds 0.45 bonus skill points to your Fire, Water,
Air and Earth skills.

<a id="tag-25"></a>$`\color{#00A5A5}{\textsf{Fire}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [fire](m_fire.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Fire
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-26"></a>$`\color{#00A5A5}{\textsf{Water}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [water](m_water.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Water
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-27"></a>$`\color{#00A5A5}{\textsf{Air}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [air](m_air.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Air
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-28"></a>$`\color{#00A5A5}{\textsf{Earth}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [earth](m_earth.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Earth
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-29"></a>$`\color{#00A5A5}{\textsf{Meta}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [meta](m_meta.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Meta
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-30"></a>$`\color{#00A5A5}{\textsf{Conveyance}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [conveyance](m_convey.md) school, and as it increases so does the casting level
of spells already attained in the school. Spending 1 skill point on your
Conveyance skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-31"></a>$`\color{#00A5A5}{\textsf{Divination}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [divination](m_divin.md) school, and as it increases so does the casting level
of spells already attained in the school. Spending 1 skill point on your
Divination skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-32"></a>$`\color{#00A5A5}{\textsf{Temporal}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [temporal](m_tempo.md) school, and as it increases so does the casting level
of spells already attained in the school. Spending 1 skill point on your
Temporal skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-33"></a>$`\color{#00A5A5}{\textsf{Mind}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [mind](m_mind.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Mind
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-34"></a>$`\color{#00A5A5}{\textsf{Nature}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [nature](m_nature.md) school, and as it increases so does the casting level of
spells already attained in the school. Spending 1 skill point on your Nature
skill adds 0.1 bonus skill points to your Magic skill.

Investing in the Nature skill? You might be interested in the [Tree Walking](ability.md#tag-3)
ability.

<a id="tag-48"></a>$`\color{#00A5A5}{\textsf{Udun}}`$\
This skill is a sub-skill of the Magic skill. It gives access to spells
within the [Udun](m_udun.md) school, and is available only to worshippers of Melkor.\
As it increases so does the casting level of spells already attained in the
school. Spending 1 skill point on your Udun skill adds 0.1 bonus skill
points to your Magic skill.

<a id="tag-52"></a>$`\color{#00A5A5}{\textsf{Demonology}}`$\
This skill is a sub-skill of the Magic skill. [Demonology](m_demono.md) gives access to spells
contained within special Demon-blades, -shields and -horns (helms), and as it
increases so does the casting level of spells already attained in the school.
This skill is available only to Demonologists, or those sufficiently
corrupted with demon-like powers. Spending 1 skill point on your Demonology
skill adds 0.1 bonus skill points to your Magic skill.

<a id="tag-35"></a>$`\color{#00A5A5}{\textsf{Necromancy}}`$\
This skill is a sub-skill of the Magic skill. It grants access to [necromancy](m_necrom.md)
spells. This is the base skill of the Necromancer class. Spending 1 skill
point on your Necromancy skill adds 0.04 bonus skill points to your Magic skill.

Investing in the Necromancy skill? You might be interested in the
[Touch of Death](ability.md#tag-8) and [Undead Form](ability.md#tag-12) abilities.

<a id="tag-37"></a>$`\color{#00A5A5}{\textsf{Thaumaturgy}}`$\
This skill is a sub-skill of the Magic skill. Each level of [thaumaturgy](m_thaum.md) gives
a few random attack spells that can be cast without the use of spell books of
any sort. However, once learned these spells do not gain in levels as the
thaumaturgy skill or the spell-power skills are increased. Spending 1 skill
point on your Thaumaturgy skill adds 0.06 bonus skill points to your Magic
skill.

<a id="tag-38"></a>$`\color{#00A5A5}{\textsf{Spirituality}}`$\
The spirituality skill influences things which have a "helping hand" from the
Gods, like your saving throw, and the general spirituality skills.

Sub-skills of Spirituality are Prayer, Mindcraft and Music.

<a id="tag-39"></a>$`\color{#00A5A5}{\textsf{Prayer}}`$\
This skill is a sub-skill of the Spirituality skill. It affects what level of
your [God's](gods.md) special magic you can access (and what levels of the additional
schools that each God also provides). Spending 1 skill point on your Prayer
skill adds 0.1 bonus skill points to your Spirituality skill and 0.1 bonus
skill points to your Magic skill.

<a id="tag-41"></a>$`\color{#00A5A5}{\textsf{Mindcraft}}`$\
This skill is a sub-skill of the Spirituality skill. It affects what level of
[Mindcrafter powers](m_mindcr.md) you can access, which is done without books and is
available under the "m" menu. Spending 1 skill point on your Mindcraft skill
adds 0.1 bonus skill points to your Spirituality skill and 0.1 bonus skill
points to your Magic skill.

<a id="tag-59"></a>$`\color{#00A5A5}{\textsf{Music}}`$\
This skill is a sub-skill of the Spirituality skill. It affects what level of
[Musical songs](m_music.md) you can access through instruments. This power\
is available under the "m" menu. Spending 1 skill point on your Music skill
adds 0.1 bonus skill points to your Spirituality skill and 0.1 bonus skill
points to your Magic skill.

<a id="tag-42"></a>$`\color{#00A5A5}{\textsf{Monster-lore}}`$\
The monster-lore skill affects your general ability at the monster related
skills. It determines how much experience you will gain if your [pets](dungeon.md#tag-18) kill a
monster, and how many companions you can have. At skill level 12, it allows
you to turn a pet into a loyal companion.

Sub-skills of Monster-lore are Summoning, Corpse-preservation, Possession,
Symbiosis, and Mimicry.

<a id="tag-43"></a>$`\color{#00A5A5}{\textsf{Summoning}}`$\
This skill is a sub-skill of the Monster-lore skill. It affects your ability
to create "totems" and use them to summon monsters to your aid. Spending 1
skill point on your Summoning skill adds 0.1 bonus skill points to your
Monster-lore skill.

<a id="tag-44"></a>$`\color{#00A5A5}{\textsf{Corpse-preservation}}`$\
This skill is a sub-skill of the Monster-lore skill. It affects your ability
to kill monsters without destroying their bodies, so the corpses will be
available to use. Spending 1 skill point on your Corpse-preservation skill
adds 0.1 bonus skill points to your Monster-lore skill.

<a id="tag-45"></a>$`\color{#00A5A5}{\textsf{Possession}}`$\
This skill is a sub-skill of the Monster-lore skill. It affects your ability
to possess a dead monster's corpse. Spending 1 skill point on your Possession
skill adds 0.1 bonus skill points to your Monster-lore skill.

<a id="tag-46"></a>$`\color{#00A5A5}{\textsf{Symbiosis}}`$\
This skill is a sub-skill of the Monster-lore skill. It affects your ability
to go into symbiosis with monsters that cannot move, and to cast [Symbiotic](m_symbio.md)
spells. Spending 1 skill point on your Symbiosis skill adds 0.1 bonus skill
points to your Monster-lore skill.

<a id="tag-47"></a>$`\color{#00A5A5}{\textsf{Mimicry}}`$\
This skill is a sub-skill of the Monster-lore skill. It affects your ability
to use cloaks of mimicry to change form and to cast [Mimicry spells](m_mimic.md).\
Spending 1 skill point on your Mimicry skill adds 0.1 bonus skill points to
your Monster-lore skill.
