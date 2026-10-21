<!-- Generated from lib/help/attack.txt by scripts/help_to_markdown.py; do not edit. -->

# <a id="tag-1"></a><a id="tag-2"></a>Attacking and Being Attacked

Attacking is simple in ToME; attempting to move over a creature
attacks it. It is also possible to attack from a distance by firing a missile
or by magical means (wand, rod, spell, etc). Creatures attack in the same way.
This means that if you do not wish to melee with a creature, it is wise to keep
distant from it. This strategy is not perfect -- some monsters, such as
dragons, have a way to attack from a distance.

Some creatures, such as Ghosts, have the ability to pass through walls.\
To attack creatures (that you can see) who are currently in a wall,
attempt to move over it (even if you cannot pass through walls, the
attack will still happen). Monsters will take less damage from attacks
while they are in walls. Also, if you cannot see the monster (e.g. if you
are blind, or it is invisible and you do not have see invisible), this
will not work: you'll have to try to tunnel. Most spells and magic devices
cannot target monsters in walls. In situations like this, it is usually wise to
lure the monster out of the wall before attacking it.

Melee attacks are handled as such:

### To-hit:

Your strength grants a bonus or penalty to-hit
Your class might grant a bonus or penalty to-hit
Your skill with specific kinds of weapons gives a bonus\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;to-hit (e.g.: Swordmastery gives a to-hit bonus
when using swords)\
Enchantments on your weapon grant a bonus or penalty to-hit
Certain rings (accuracy, slaying) may also grants a bonus\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;or penalty to-hit\
Your Tactic setting may give bonuses o penalties to-hit\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(to change it, press 'C' and then 't' or 'T')
Other temporary effects (berserk, etc) might affect your\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;chance to hit\
The armor rating of the monster you're attacking makes a\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;big difference

### Blows:

Your strength and dexterity affect how many blows you get
Your class and level might affect how many blows you get
The weight of the weapon very likely will affect how many\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;blows you get\
Certain skills (e.g. Swordmastery) may affect how many blows\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;you get with particular weapons
Enchantments on your weapon might also affect how many\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;blows you get (this is rare)\
Certain very rare rings (of attacks) may also affect how\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;many blows you get

### Damage:

The base damage of your weapon is rolled
Strength grants a bonus or penalty\
Your class might grant a bonus or penalty\
Combat and Weaponmastery skills increase your melee damage
Ranged masteries increase the damage multiplier of slings,\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bows, crossbows or boomerangs(see below)
Enchantments on your weapon might also grant a bonus or\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;penalty\
Your Tactic setting may give bonuses o penalties to damage\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(to change it, press 'C' and then 't'or'T')
Temporary effects also might grant a bonus or penalty

So, each blow you are entitled to is checked for a hit. If this is the case,
the damage is then applied to the monster. Note that unless you have some
barehanded combat training or are possessing a monster, melee without a weapon
will result in a single blow that does base damage of 1d1. This might, however,
be useful in attacking certain rare monsters that destroy weapons.

Combat with a bow/sling is similar, except ammo is used (which will eventually
run out, requiring replacement). Bows don't have a base damage rating (ammo
does), instead having a damage multiplier. Bows can, however, be enchanted,
and enchantment on bows and arrows is cumulative (meaning that well-enchanted
bows and arrows can be one of the more effective weapons in the game. They
do, however, tend to be very expensive, as non-artifact arrows frequently break
after being fired).\
Using ammo without the appropriate bow generally has poor results.

## <a id="tag-3"></a>Armor

As the armor class of a monster greatly affects how hard it is for it
to be hit, your armor class affects how hard it is for it to hit you.\
A high armor rating will make it much easier to survive deep in the dungeon.
For a warrior style class (Unbelievers, Fighters, Archers, etc), it is
generally wise to wear as much and as powerful armor as possible (subject
to weight limitations, of course). Spellcasting classes, however, have
limits on how much armor they can wear before it disrupts their motion
and makes it hard for them to cast spells properly. For many of these classes,
gloves are especially bad for spellcasting. Monks and Rogues skilled
at dodging will often find heavy armor cumbersome, too.\
Armor has a base rating and an enchantment rating. The base rating is constant
for the type of armor (e.g. paper armor always has a base rating of 4), and
the enchantment depends on the item. There are also ways to further enchant
armor you have. Certain very powerful enchantments grant resistances to
specific forms of magical attacks.

## <a id="tag-4"></a><a id="tag-5"></a>Resistances and typed attacks

Many kinds of monsters, traps, and other effects do damage that has a type.
Types can have side effects in addition to the raw damage they deal. Certain
enchanted items can grant resistances, reducing the raw damage and possibly
reducing or eliminating the side effects. Some monsters also have resistances,
so watching the messages when attacking a monster can often reveal that a
particular attack is ineffective.

### <a id="tag-6"></a><a id="tag-9"></a>Low attacks

Fire - Destroys weapons, armor, scrolls, and staves. Reduces strength.
Cold - Shatters potions.\
Elec - Reduces dexterity, destroys rings and wands.\
Acid - Reduces bonuses on equipped armor, reduces charisma.

### Middle attacks

Poison - Player becomes poisoned\
Light - Blinds player, perma-lights area\
Dark - Blinds player, darkens area\
Confusion - Confuses player

### High attacks

Nether - Drains experience\
Nexus - Scrambles statistics, teleports player randomly
Disenchantment - Reduces bonuses on equipped items\
Chaos - Confuses, drains life, causes hallucination, and more
Sound - Shatters potions\
Shards - Cuts player

### Unresistable attacks

Water - Stuns player\
Ice - Stuns player, shatters potions\
Plasma - Stuns player, otherwise same as fire attacks
Force - Pushes player a few squares back\
Inertia - Slows player\
Gravity - Slows and teleports player a few squares
Disintegration - Destroys items on ground, destroys walls
Mana - Destroys items on ground

## <a id="tag-7"></a>Monster Memory

The thousands of different creatures in ToME have many different
characteristics, including spells, resistances, health, attacks, and speed.
The information you have learned about each monster from your encounters
with them is recorded in the monster memory (accessed with '/' or by 'l'ooking
at a monster). It is possible to eventually learn all the characteristics
of any given monster by interacting with them enough, but this is not always
desirable (hanging around great hell wyrms, for example, can be hazardous
to one's health). Certain spells may help you learn faster, as well as
research centres in town.
