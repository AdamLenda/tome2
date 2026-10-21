<!-- Generated from lib/help/magic.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-3"></a>ToME Magic system

[Wands and Staves](#tag-2)

For the basics of how to use skills, please see [Using Skills](skills.md).

In ToME you have a basic [Magic](skills.md#tag-21) skill. This skill is one of the most
important ones for a spellcaster, since it is responsible for how much mana you
have. You can never have too much of it. If you like magical devices, the
Magical Device skill is also important, since it controls the Magical
Device ability of your character. This ability again dictates the fail rates
of use of wands/rods/staffs and activation of random-artifacts/artifacts, and
it will also increase the power of these items.

<a id="tag-1"></a>ToME uses skills to define the various schools of magic. There are 11 primary
schools:

|   |   |   |
| --- | --- | --- |
| [Mana](m_mana.md) | [Fire](m_fire.md) | [Water](m_water.md) |
| [Air](m_air.md) | [Earth](m_earth.md) | [Meta](m_meta.md) |
| [Conveyance](m_convey.md) | [Divination](m_divin.md) | [Temporal](m_tempo.md) |
| [Mind](m_mind.md) | [Nature](m_nature.md) |  |

Other magical skills, generally being used primarily by characters of a
specific class, are:

|   |   |
| --- | --- |
| [Demonology](m_demono.md) | [Necromancy](m_necrom.md) |
| [Thaumaturgy](m_thaum.md) | [Geomancy](m_geoman.md) |

The [Demonology](m_demono.md) skill is primarily used by [Demonologists](c_demono.md) for their special
spells, whereas the [Necromancy](m_necrom.md) skill is used by [Necromancers](c_necro.md) for their own set
of special spells.\
[Thaumaturgy](m_thaum.md) gives you randomly chosen\
attack spells, and as such each game with it will be different. [Geomancers](c_geoman.md)
harness the powers of the elements using [Geomancy](m_geoman.md).

In addition to the schools of magic, you can get access to special sets of
spells if you worship a God. There are currently four good Gods,
[Eru Iluvatar](g_eru.md), [Manwe Sulimo](g_manwe.md), [Yavanna Kementari](g_yavann.md) and [Tulkas](g_tulkas.md). There is also an evil
god, [Melkor](g_melkor.md). Each of them gives you access to different types of spells.

[Worshippers of Melkor](c_pr_drk.md) also have access to the special [Udun](m_udun.md) school of magic,
whereas other [Priests](c_priest.md) and [Mindcrafters](c_mindcr.md) can use [Mindcrafting Powers](m_mindcr.md).

[Symbiants](c_symbia.md) have access to their own special brand of [magic powers](m_symbio.md), and [Bards](c_bard.md) have
access to [Songs](m_music.md), which affect creatures in ways that can appear to be magical.

The 11 different primary schools give you access to different spells of
variable usefulness. The way they work is that adding skill points to a
specific school will enable you to get higher level spells for that specific
school. By level requirements for a specific spell you could actually say skill
requirement, since they correlate exactly. Let's take a simple example:\
If you have the [Mana](m_mana.md) school skill at level 24.000, it means you can use any
spell in the mana school up to and including those requiring level 24. $`\color{#00A5A5}{\textsf{There are}}`$
$`\color{#00A5A5}{\textsf{also some spells requiring a certain skill level in two schools, and there is a}}`$
$`\color{#00A5A5}{\textsf{possibility of spells requiring three or more. For this kind of spells the}}`$
$`\color{#00A5A5}{\textsf{spell level is determined by taking an average of the necessary skills.}}`$\
When calculating spell level for spells which require more than one school,
sorcery (or god-granted access) can be used in place of the primary schools in
the normal way. Once the average has been calculated, any bonus from the
spell-power skill can also be applied as normal. If one of the schools required
is the Udun school, then the appropriate bonus from character level will be
applied. Lastly, if you look at a spell, and the spell level reads -2 or some
other negative value while it's also grayed out, that means you need to
increase the corresponding school's skill level by 3, since only 2 will have
it end up on spell level 0, where it still is unusable. If it reads n/a, you
currently have no skill points in that school.

Another thing that should be explained about the skills and schools of magic
right now, is that the skill doesn't stop being useful only for gaining spells.
The higher the skill level, the higher the spell level will be, and the more
powerful your spells will be. For instance, say you have the [Mana](m_mana.md) skill at
level 24. Now, the Manathrust spell is one of the spells for that school
that only requires skill level 1, but since you've got skill at level 24, the
power of the spell is increased as well. For comparison, a level 1
Manathrust costs 1 mana and does 4d2 damage, while at level 24 it costs 12
mana and does a whopping 27d10 damage.

The [Sorcery](skills.md#tag-23) skill is a nice skill, since it gives you\
access to all the 11 primary schools of magic, just as if you'd spent an equal
amount of skill points in all the skills. It's available to any mage character,
but only a [Sorceror](c_sorcer.md) will be able to be proficient in it. Also, having this
skill at level 1 will give you a hitpoint-penalty of 1%, all the way up to
skill level 50, with a hitpoint-penalty of 50%. There are also ToHit and ToDam
penalties for sorcery, so don't choose sorcery if you plan to do much fighting.

There is also the [Spell Power](skills.md#tag-22) skill. This skill is rather nice, since it
will augment the power of spells you already know. The distinction between this
and the others, is that it will not grant you new spells, but instead increases
the levels of spells. At level 50 it grants 20 extra spell levels. $`\color{#00A5A5}{\textsf{This skill}}`$
$`\color{#00A5A5}{\textsf{only affects the 11 primary schools}}`$ (Mana, Earth, Air, Fire, Water, Meta,
Mind, Temporal, Conveyance, Divination and Nature) as well as Geomancy and the
spells granted by the Gods.

There is also the Magic-Device skill which affects your ability to use wands,
staves, rods and to activate special objects. It also affects the spell-levels
of the staff and wand spells, as explained below.

### <a id="tag-2"></a><a id="tag-4"></a><a id="tag-5"></a>Wands and Staves

Wands and staves (sticks) operate in a similar fashion, and in fact most of
them use the same spells with the same effects. When you pick up a stick, you'll
see it has two numbers in the format \[x\|y\] in addition to the number of charges
it holds. By increasing your magic-device skill you can increase the level (and
hence the power) of the spell in that stick. The x value are skill level
bonuses which the staff itself holds, and these are added onto your existing
magic-device skill for the purpose of using the staff. The y value is the
maximum possible skill level for that stick. Things are balanced by the use of a
"minimum magic-device skill level required to raise spell level". Here's an
example:\
A Staff of Sense Hidden \[1\|10\]. Your magic device skill is at 6. If you were to
identify the staff and then 'I'nspect it, you would see the following
information:

```text
 Spell describtion:
 Detects the traps in a certain radius around you
 At level 15 it allows you to sense invisible for a while
 Spell level: 3
 Minimun Magic Device level to increase spell level: 5
 Spell fail: 23
 Spell info: rad 13
```

The Spell level is the level at which the spell will actually be cast.\
Spell fail is the spell fail percentage. The spell info may contain the radius
of effect, amount of damage, or duration the spell might last.\
The Minimum Magic Device level to increase your spell level is just that. If
your magic device skill was less than this level, then the staff would be
casting the spell at level one. Our magic device skill is 6. Therefore we are
casting at level 2 (at skill level 5, we should be casting the spell at level
1\). Then we add the bonus from the staff of 1, which gives us our spell level
of 3. If our magic device in this example had been 14, this would have given us
a spell level of 1 + (14 - 5 + 1) = 11. This is calculated from the formula:\
spell level = staff bonus + (magic device - minimum magic device + 1)).
However given that the maximum spell level with this staff is 10, you'll be
casting with a spell level of 10.\
As you get deeper into the dungeons, you will find sticks with higher bonuses
and maximum spell levels.

Written by: vrak AKA Per-Arne Holtmon Akoe
Wands and Staves section added by fearoffours
