# ToME Debug and Wizard Mode Reference

This is a reference for the cheat and developer tools in this version of ToME:
wizard mode, the debug commands, and the cheating options. It was written by
checking the in-game help (`lib/help/debug.txt`) against the code:
`do_cmd_debug()` and its helpers in `src/wizard2.cc`, the mode checks in
`src/dungeon.cc`, the cheat options in `src/options.hpp` and `src/cmd4.cc`,
and the command-line parsing in `src/main.cc`. Where the old help file
disagrees with the code, this document follows the code. See
[Differences from the in-game help](#differences-from-the-in-game-help).

> **Warning:** Using any of these tools marks your character **permanently**.
> The character can never get onto the high-score list. Turning wizard mode off
> again does not undo this. Details are in [Consequences](#consequences).

## Contents

- [Wizard mode and debug commands](#wizard-mode-and-debug-commands)
- [Consequences](#consequences)
- [Entering a debug command](#entering-a-debug-command)
- [Debug command reference](#debug-command-reference)
- [Item tools in detail](#item-tools-in-detail)
- [Finding the number you need](#finding-the-number-you-need)
- [Walkthroughs](#walkthroughs)
- [What wizard mode changes](#what-wizard-mode-changes)
- [Cheating options](#cheating-options)
- [Differences from the in-game help](#differences-from-the-in-game-help)

---

## Wizard mode and debug commands

These are two separate things:

| | Wizard mode | Debug commands |
|---|---|---|
| Key | `Ctrl-W` (toggles on and off) | `Ctrl-A`, then a command key |
| What it is | A **state** that stays on until you turn it off. It changes how the normal game behaves: you see all monsters on screen, you get extra numbers in messages, you can avoid death, and so on. | A **one-shot** menu of cheat actions: create items, teleport, summon, edit stats, and so on. |
| Needs the other? | No | **No.** Debug commands work without wizard mode. |
| On screen | Your title shows `[=-WIZARD-=]` | Nothing |

Both keys work the same in the original and roguelike keysets. If your terminal
or OS intercepts a control key, type `^` then the letter (`^` `a` for
`Ctrl-A`, `^` `w` for `Ctrl-W`).

### Turning wizard mode on

Press `Ctrl-W`. The first time on a character that hasn't cheated yet, the
game shows:

```
Wizard mode is for debugging and experimenting.
The game will not be scored if you enter wizard mode.
Are you sure you want to enter wizard mode? [y/n]
```

Answer `y` to turn it on ("Wizard mode on."). Press `Ctrl-W` again to turn it
off ("Wizard mode off."). There's no prompt for turning it off.

Once the character is marked as a cheater by anything (wizard mode, debug
commands or a cheating option), there's no prompt any more. `Ctrl-W` simply
toggles.

Wizard mode is stored in the savefile. If you save while it's on, the
character loads with it still on.

### Using debug commands

Press `Ctrl-A`. The first time on a character that hasn't cheated and isn't in
wizard mode, the game shows:

```
The debug commands are for debugging and experimenting.
The game will not be scored if you use debug commands.
Are you sure you want to use debug commands? [y/n]
```

Answer `y`. You then get the `Debug Command:` prompt. Press one of the keys in
the [reference](#debug-command-reference). `Esc`, `Space` or `Enter` cancels.
Any other key prints "That is not a valid debug command."

After the first time, `Ctrl-A` goes straight to the `Debug Command:` prompt.

### Starting the game in wizard mode (`-w`)

The command-line flag `-w` (or `-W`) requests wizard mode at start-up:

```
./src/tome-gcu -w
```

The usual confirmation prompt is shown if the character hasn't cheated yet.
`-w` also lets you **load a dead character's savefile**. Instead of starting a
new character, the game loads the dead one, notices that it's dead, and (since
wizard mode is on) asks `Die?`. Answer `n` to bring it back with
[cheat death](#cheat-death). This doesn't work for a character that retired as
a winner.

## Consequences

The game tracks cheating in a `noscore` value in the savefile. Each kind of
cheating sets a flag in it:

| Action | Effect on the savefile |
|---|---|
| Entering wizard mode (`Ctrl-W` or `-w`) | Marked |
| Using `Ctrl-A` outside wizard mode | Marked |
| Turning on a cheating option (most of them, see [Cheating options](#cheating-options)) | Marked |
| Cheating death | Marked |

**These flags are never cleared.** They stay for the rest of that character's
life. Turning wizard mode off, or turning the cheat option off again, makes no
difference. Only a new character starts clean.

What a marked character loses or changes:

- **No high score.** When the character dies or retires, the game shows "Score
  not registered for wizards." and the character is not added to the score
  file.
- **Character sheet / dump** (`C`, then save to a file) includes the line
  "You have done something illegal."
- **Suicide (`Q`)** skips the extra "type `@` to confirm" step. Only the
  `y`/`n` question is left, so be careful.

There's no other lasting effect on gameplay. But note that many debug commands
change the character or the dungeon permanently (stats, items, quest states,
the map), and can't be undone.

## Entering a debug command

### Prompts and the command count

Some debug commands ask for input. Others take their number from the
**command count** instead, and never ask. For those, type the count **before**
`Ctrl-A`:

1. Press `0`. The top line shows `Count:`.
2. Type the number (0 to 9999).
3. Press `Ctrl-A` (or `^` `a`), then the command key.

For example, `0` `2` `Ctrl-A` `T` teleports you to town 2 (Gondolin).

Things to watch for:

- **Pressing `0` and then a command, with no digits, gives a count of 99.**
  You can never pass 0 this way. To get 0, don't use a count at all.
- **No count means 0.** Commands that need a monster, dungeon, feature or form
  number then use number 0, which is often a placeholder entry (monster 0 is
  "Player", feature 0 is "nothing"). Always supply a count for those.
- In tome-gcu, `Insert` also starts a count.

In the table below, **"Count"** means the number is taken from the command
count. **"Prompt"** means the game asks for it.

## Debug command reference

All keys are typed at the `Debug Command:` prompt (after `Ctrl-A`). Upper and
lower case are different commands. There are **39** commands.

### Character

| Key | What it does | Input |
|---|---|---|
| `a` | **Cure everything.** Removes curses from equipment, restores all stats and lost experience, fills HP, mana and sanity, cures blindness, confusion, poison, fear, paralysis, hallucination, stun, cuts, slowness and the Black Breath, sets you to "full" (not gorged), and heals a monster you are carrying. | None |
| `e` | **Edit character.** Asks in turn for Str, Int, Wis, Dex, Con, Chr, then Gold, Experience, Piety and base Luck. | Prompts. Each shows the current value; `Enter` keeps it. `Esc` stops (earlier answers are kept). Stats are 3–118, where 19–118 mean 18/01–18/100. Experience sets both current and max and can level you up. |
| `x` | **Gain experience.** With no count, adds your current experience + 1 (roughly doubles it). With a count, adds that many points. | Count (optional) |
| `h` | **Re-roll hit points.** Rolls a new set of HP gains for every level and prints `Current Life Rating is NN/100.` You can't choose the result. Repeat until you like it. | None |
| `M` | **Gain a random corruption.** | None |
| `+` | **Gain a fate.** Adds a new fate and marks **all** your fates as known. With no count, the fate type is random. With a count: 1 find object, 2 never die by a mortal, 3 find artifact, 4 meet monster, 5 `FATE_FIND_V`, 6 death. Other values set an invalid type. | Count (optional, 1–6) |
| `B` | **Change body.** Sets your body to monster race number *count* (an `r_info.txt` number) and sets HP to that race's maximum. With no count, race 0 (your normal body). The code warns this may cause problems with equipment slots; take everything off first. | Count |
| `*` | **Mimic form.** Sets your mimic form to number *count* for 100 turns. With no count, returns you to your normal form. Forms: 1 Mouse, 2 Eagle, 3 Eagle (the two Eagles belong to different modules), 4 Wolf, 5 Spider, 6 Elder Ent, 7 Vapour, 8 Serpent, 9 Mumak, 10 Bear, 11 Balrog, 12 Maia, 13 Fire Elem. **Values over 13 are out of range and can crash the game.** | Count (1–13) |
| `U` | **Become undead** (the Necromancer's undead form). Also **summons a hostile Wild rabbit** (monster 5) next to you. | None |

### Items

| Key | What it does | Input |
|---|---|---|
| `c` | **Create an item from menus.** Pick a category, then a kind. The item gets normal random magic for the current depth and drops at your feet. See [Item tools in detail](#item-tools-in-detail). | Menus |
| `-` | **Create an item by number.** The number is the `k_info.txt` index. The item gets normal random magic for the current depth and drops at your feet. Prints "Allocated." on success. Invalid numbers do nothing. | Prompt: `Number of the object :` |
| `g` | **Create good items.** Creates *count* random "good" items (default 1) at your feet, using the current dungeon's item rules. | Count (number of items) |
| `v` | **Create excellent items.** Like `g`, but "great" items: usually egos, sometimes artifacts. | Count (number of items) |
| `o` | **Play with an item.** Inspect and change any item in your pack, equipment, or on the floor. See [Item tools in detail](#item-tools-in-detail). | Item prompt, then a menu |
| `W` | **Make a wish.** Type an item or monster name. See `lib/help/wishing.txt`. Anything containing "wish" is refused. A monster name can start with `enemy`, `neutral`, `friendly`, `pet` or `companion`. Unique monsters can't be wished for. | Prompt: `Wish for what?` |

### Artifacts

| Key | What it does | Input |
|---|---|---|
| `C` | **Create a named artifact.** The number is the `a_info.txt` index. The artifact drops at your feet and "Allocated." is shown. Invalid or empty numbers do nothing, silently. This doesn't check whether the artifact already exists, so you can make duplicates. | Prompt: `Number of the artifact:` (the count is **not** used) |

### Monsters

| Key | What it does | Input |
|---|---|---|
| `n` | **Summon a named monster.** Places monster race *count* (an `r_info.txt` number) next to you, **asleep** and hostile. Its escorts or group may come with it. | Count (**required**) |
| `N` | **Summon a pet.** Same as `n`, but the monster is your pet. See the note on uniques below. | Count (**required**) |
| `s` | **Summon random monsters.** Summons *count* (default 1) random monsters for the current level next to you. | Count (number) |
| `/` | **Summon by type.** Summons one monster of summon type *count*, at the deepest level you have reached in the current dungeon. With no count, any type. The types are the `SUMMON_*` values in `src/defines.hpp` (11 ant, 12 spider, 13 hound, 14 hydra, 15 angel, 16 demon, 17 undead, 18 dragon, 21 greater undead, 22 greater dragon, 31 wraith, 32 unique, and so on up to 57). | Count (optional) |
| `H` | **Summon a horde.** Picks a random non-unique monster for the current level and places it awake near you, then 6–15 more monsters with the same symbol around it. | None |
| `z` | **Zap monsters.** Removes every monster within 20 squares of you, in sight or not. They're deleted, not killed: no drops and no experience. | None |
| `=` | **Set a monster's attitude.** Asks you to target a grid, then sets the monster there to attitude *count*. 0 (no count) neutral, 1 neutral, 2 friendly, 3 pet, 4 companion. You **can't** make a monster hostile with this. | Count, then targeting |
| `@` | **Level up a monster.** Asks you to target a grid, then raises the monster there by *count* levels. With no count, nothing changes. | Count, then targeting |

> **Friendly uniques:** outside wizard mode, a unique monster that is friendly
> or a pet turns hostile ("suddenly becomes hostile!"), unless the monster is
> marked as a natural pet. A unique you summon with `N` (or make a pet with
> `=`) only stays on your side while wizard mode is on.

### Movement, dungeon and level

| Key | What it does | Input |
|---|---|---|
| `p` | **Phase door.** Short-range teleport (range 10). | None |
| `t` | **Teleport.** Long-range teleport (range 100). This ignores anti-teleport, continuum resistance and no-teleport levels. | None |
| `b` | **Teleport to target.** Moves you next to your current target. Set a target first with `*` (monster or grid). Does nothing if there is no target. | None |
| `j` | **Jump to a level** of the **current** dungeon. With a count, jumps straight to that level. Without one, prints `dungeon_type : N` and asks for a level. Values are clamped to the dungeon's maximum depth. In the wilderness the maximum is 0, so use `D` first. Leaves any quest you are in. | Count, or prompt: `Jump to level (0-MAX):` |
| `D` | **Change dungeon.** Moves you into dungeon *count* (a `d_info.txt` index) at its minimum depth. No count (0) is the Wilderness at depth 0, which takes you back to the surface. Out-of-range numbers do nothing. | Count |
| `T` | **Teleport to a town.** Puts you on the wilderness map at that town's entrance and leaves the level. Only 1 up to the maximum number of real towns is accepted. See [Town numbers](#town-numbers). | Count |
| `q` | **Take a quest.** Sets quest *count* to "taken" and starts it. Accepted values are 1–29, except 5 (the random quest). See [Quest numbers](#quest-numbers). Each quest belongs to a "plot" line, and this command also overwrites that plot's progress, which can break the normal quest order. | Count |

### Map, detection and terrain

| Key | What it does | Input |
|---|---|---|
| `d` | **Detect everything** within 25 squares: doors, stairs, treasure, gold, objects, and visible and invisible monsters. | None |
| `m` | **Magic mapping** of the local area. | None |
| `w` | **Wizard light.** Lights and maps the whole level. | None |
| `u` | **Complete map.** Marks **every** grid on the level as lit and known (including solid rock), then does a wizard light. | None |
| `F` | **Set the feature under you.** Prints `Old feature:` and `Special:` for your grid, then changes it to feature *count* (an `f_info.txt` index). No count sets feature 0 ("nothing"). | Count |
| `S` | **Set your grid's "special" value.** This value stores things like quest numbers and dungeon entrances. Only use it if you know what you're doing. | Count |
| `E` | **Set your grid's mana** to *count*. In wizard mode, the "sense grid mana" command shows the exact value. | Count |

### Help

| Key | What it does | Input |
|---|---|---|
| `?` | Opens the **main** help index (not the debug help page). | None |

## Item tools in detail

### Creating from menus (`c`)

The first screen lists the item categories. Choose with these keys:

| Keys | Categories |
|---|---|
| `a`–`t` | Sword, Polearm, Hafted Weapon, Axe, Bow, Boomerang, Arrows, Bolts, Shots, Shield, Crown, Helm, Gloves, Boots, Cloak, Dragon Scale Mail, Hard Armor, Soft Armor, Ring, Amulet |
| `A`–`T` | Lite, Potion, Potion (the second set of potions), Scroll, Wand, Staff, Rod, Rod Tip, Schools Spellbook, Symbiotic Spellbook, Elemental Stone, Music Book, Daemon Book, Spikes, Digger, Food, Flask, Mage Staff, Parchment, Musical Instrument |
| `0` | Junk |

The second screen lists the kinds in that category, labelled the same way:
`a`–`t`, then `A`–`T`, then `0`–`9` and `:` `;` `<` `=` `>` `?` `@`. Only the
first 57 kinds can be selected. The Potion and Ring categories have about that
many kinds or more, so a few at the end can't be reached. Use `-` with the
item's number for those. Kinds that are always artifacts (such as the Phial)
are left out. Use `C` for those.

### Playing with an item (`o`)

Choose an item from your pack, equipment, or the floor. The screen shows the
item's internal data: `kind` (its `k_info.txt` number), `level`, `tval`,
`sval`, number, weight, AC, damage, `pval`, to-hit/to-dam/to-AC, `name1` (the
artifact number), `name2` (the ego number), value, `pval2`, `ident`, `timeout`,
and every flag the item has. This is also a handy way to **look up an item's
numbers** in-game.

The menu is:

```
[a]ccept [s]tatistics [r]eroll [t]weak [q]uantity apply[m]agic?
```

| Key | Does |
|---|---|
| `a` / `A` | Keep the changes and exit ("Changes accepted.") |
| `Esc` | Throw away all changes and exit ("Changes ignored.") |
| `s` / `S` | **Statistics.** Asks `Roll for [n]ormal, [g]ood, or [e]xcellent treasure?`, then generates up to 100,000 random items at the current depth. It counts how many have the same kind and are equal, better, worse or different. Press any key to stop early. |
| `r` (lowercase only) | **Reroll.** Opens a second menu: `[a]ccept, [b]ad, [n]ormal, [g]ood, [e]xcellent, [r]andart?`. `a`/`A`, `b`/`B` and `n`/`N` work in either case. `g`, `e` and `r` only work in **lower case**. `Esc` cancels. Artifacts can't be rerolled; the command silently does nothing. |
| `t` / `T` | **Tweak.** Asks in turn for `pval`, `pval2`, `pval3`, `to_a`, `to_h`, `to_d`, `name2` (ego), `name2b` (second ego), `sval`, `obj exp` and `timeout`. `Enter` keeps a value. `Esc` stops (earlier values are kept). |
| `q` / `Q` | **Quantity**, from 1 to 99. |
| `m` / `M` | **Apply magic.** Resets the item and applies normal magic for the current depth, keeping its ego types. |

The code warns that changing an artifact this way may destroy it.

## Finding the number you need

Most commands need an index from the data files. **Each module has its own
files and numbers**, so look in the right place:

| Module | Folder |
|---|---|
| ToME (default) | `lib/edit/` |
| Theme | `lib/mods/theme/edit/` |

| Command | File | Line format |
|---|---|---|
| `C` (artifact) | `a_info.txt` | `N:<number>:<name>`. The name is only the suffix (`N:1:of Galadriel`); the comment line above gives the full name (`# The Phial of Galadriel`) |
| `-` (item) | `k_info.txt` | `N:<number>:<name>`, then `G:<symbol>:<colour>`. Many names repeat, so check the symbol: `!` potion, `?` scroll, `_` staff, `-` wand/rod, `=` ring |
| `n`, `N`, `B` (monster) | `r_info.txt` | `N:<number>:<name>` |
| `D` (dungeon) | `d_info.txt` | `N:<number>:<name>`, then `W:<min depth>:<max depth>:...` |
| `F` (feature) | `f_info.txt` | `N:<number>:<name>` |
| `T` (town) | `wf_info.txt` | The town number is the **second** field of the `W:` line, not the `N:` number. See [Town numbers](#town-numbers) |

Search from the repository root. Use `grep -a`, because some files (such as
Theme's `a_info.txt`) are not plain ASCII and some `grep` versions skip them
as binary:

```
grep -a -n -B3 "^N:.*:of Galadriel" lib/edit/a_info.txt
grep -a -n -A1 "^N:[0-9]*:Healing$" lib/edit/k_info.txt
grep -a -n "^N:[0-9]*:Smeagol$" lib/edit/r_info.txt
```

Some examples (checked in both modules):

| Thing | ToME | Theme |
|---|---|---|
| Phial of Galadriel (artifact) | 1 | 1 |
| Arkenstone of Thrain (artifact) | 3 | 3 |
| Palantir of Orthanc (artifact) | 202 | 202 |
| Key of Orthanc (artifact) | — | 15 |
| Potion of Healing (item) | 242 | 242 |
| Smeagol (monster) | 63 | 63 |
| Sauron, the Sorcerer (monster) | 860 | 860 |
| Morgoth, Lord of Darkness (monster) | 862 | 862 |
| DarkGod, the Mighty Coder of Hell (monster) | 861 | 861 |

Numbers have gaps. An unused number does nothing.

### Town numbers

For `T`:

| Number | ToME | Theme |
|---|---|---|
| 1 | Bree | Bree |
| 2 | Gondolin | Gondolin |
| 3 | Minas Anor | Minas Anor |
| 4 | Lothlorien | Caras Galadhon |
| 5 | Khazad-dum | Khazad-dum |
| 6 | — | Beorn's Halls |
| 7 | — | Cerin Amroth |
| 8 | — | Dale |
| 9 | — | Edoras |
| 10 | — | Esgaroth |
| 11 | — | Helm's Deep |
| 12 | — | Henneth Annun |
| 13 | — | Hobbiton |
| 14 | — | Rivendell |
| 15 | — | Osgiliath |
| 16 | — | Pelargir |
| 17 | — | Thranduil's Halls |

The maximum comes from the `M:t:` line in `misc.txt` (5 in ToME, 17 in Theme).

### Dungeon numbers

For `D` (minimum–maximum depth in brackets). ToME `lib/edit/d_info.txt`:

| # | Dungeon | # | Dungeon |
|---|---|---|---|
| 0 | Wilderness (0) | 17 | Illusory Castle (35–52) |
| 1 | Mirkwood (11–33) | 18 | Maze (25–37) |
| 2 | Mordor (34–66) | 19 | Orc Cave (10–22) |
| 3 | Angband (67–127) | 20 | Erebor (60–72) |
| 4 | Barrow-Downs (1–10) | 21 | The Old Forest (13–25) |
| 5 | Mount Doom (85–99) | 22 | Moria (30–50) |
| 6 | Nether Realm (666–696) | 23 | Dol Guldur (57–70) |
| 7 | Submerged Ruins (35–50) | 24 | The Small Water Cave (32–34) |
| 8 | Halls of Mandos (1–98) | 25 | The Sacred Land Of Mountains (45–70) |
| 9 | Cirith Ungol (25–50) | 26 | The Land Of Rhun (26–40) |
| 10 | Heart of the Earth (25–36) | 27 | The Sandworm lair (22–30) |
| 11 | The Void (128–150) | 28 | Death fate (1) |
| 12 | Test (1–10) | 29 | The Helcaraxe (20–40) |
| 16 | Paths of the Dead (40–70) | 30 | a lost temple (1–50) |

Theme uses the same numbers with a few renames: 2 Barad-Dur, 3 Angband
(67–100), 5 Orodruin, 8 Halls of Waiting, 27 The Withered Heath. It also adds
31 Forodwaith, 32 Emyn Luin, 33 Dol Amroth, 34 Angmar, 35 Near Harad,
36 Isengard, 37 Tol Eressea, 38 Utumno, 39 Bilbo's trail and 40 Thorin's trail.
Numbers 13–15 are unused in both modules.

Your position on the wilderness map doesn't change when you use `D`. Where you
come out when you leave that dungeon hasn't been verified.

### Quest numbers

For `q` (from `src/defines.hpp` and the quest table in `src/tables.cc`):

| # | Quest | # | Quest |
|---|---|---|---|
| 1 | Dol Guldur (Necromancer) | 16 | The Last Alliance |
| 2 | Sauron | 17 | The One Ring |
| 3 | Morgoth | 18 | Mushroom supplies |
| 4 | Thieves! | 19 | The prisoner of Dol Guldur |
| 5 | *(random quests, refused)* | 20 | Falling Toward Apotheosis (good) |
| 6 | Lost Hobbit | 21 | Falling Toward Apotheosis (evil) |
| 7 | The Dark Horseman | 22 | Wolves! |
| 8 | The Trolls Glade | 23 | Dragons! |
| 9 | The Wight Grave | 24 | Haunted House! |
| 10 | Spiders of Mirkwood | 25 | Evil! |
| 11 | Poisoned Water | 26 | Bounty quest |
| 12 | The Broken Sword | 27 | Old Mages quest |
| 13 | Eol the Dark Elf | 28 | Library quest |
| 14 | Nirnaeth Arnoediad | 29 | God quest |
| 15 | Invasion of Gondolin | | |

## Walkthroughs

In these examples, `Ctrl-A` can always be typed as `^` `a`.

### Create a specific artifact (the Phial of Galadriel)

The Phial is artifact **1** in both ToME and Theme.

1. Press `Ctrl-A`. Confirm with `y` if asked.
2. Press `C`.
3. At `Number of the artifact:`, type `1` and press `Enter`.
4. "Allocated." appears and the Phial is on the floor under you. Press `g` to
   pick it up.

For any other artifact, find its number in the right `a_info.txt` first (see
[Finding the number you need](#finding-the-number-you-need)). Don't put a count
before `C`; it's ignored.

### Create a specific item (a Potion of Healing)

1. Look up the number: `grep -a -n -A1 "^N:[0-9]*:Healing$" lib/edit/k_info.txt`.
   Pick the entry whose `G:` line has `!` (a potion): **242**.
2. `Ctrl-A` `-`, type `242`, `Enter`.
3. To get more than one, use `Ctrl-A` `o`, choose the potion, press `q` and
   enter a quantity, then `a` to accept.

Or browse instead: `Ctrl-A` `c`, `B` (Potion), then the letter for Healing.

### Gain levels and stats

- **Max level:** `Ctrl-A` `e`. Press `Enter` through the six stats and Gold. At
  `Experience:`, type `99999999` (the maximum) and press `Enter`. Press `Esc`
  at Piety to stop there.
- **A few levels:** `Ctrl-A` `x` roughly doubles your experience each time. Or
  use a count: `0` `5` `0` `0` `0` `Ctrl-A` `x` adds 5000 points.
- **Stats:** `Ctrl-A` `e` and type the new values. `118` is 18/100.
- **Skills (wizard mode only):** turn on wizard mode, open the skills screen
  (`G`), and press `+` or `-` on a skill to change it by one point without
  spending skill points.
- **Abilities (wizard mode only):** in the abilities screen (`N`), `+` gives
  the selected ability and `-` removes it, at no cost.

### Go to a dungeon level

- **Deeper in the current dungeon:** `0` `3` `0` `Ctrl-A` `j` jumps to level
  30. Or `Ctrl-A` `j` and type the level at the prompt.
- **A different dungeon:** `0` `2` `2` `Ctrl-A` `D` puts you on Moria's first
  level (30). Then use `j` for a deeper level.
- **From the wilderness:** `j` can't go below 0 there. Use `D` first.
- **Back to a town:** `0` `1` `Ctrl-A` `T` (Bree).

### Summon a monster

- **A specific monster:** look up its `r_info.txt` number, then for example
  `0` `6` `3` `Ctrl-A` `n` summons Smeagol (asleep). Use `N` instead of `n` to
  get a pet.
- **Random monsters:** `0` `5` `Ctrl-A` `s` summons 5.
- **A test pack:** `Ctrl-A` `H`.
- **Clean up:** `Ctrl-A` `z` removes everything within 20 squares.

Don't use `n` or `N` without a count. That tries to place monster 0, the
"Player" placeholder.

### Heal and cure

`Ctrl-A` `a` cures everything and fills HP, mana and sanity. To avoid dying
altogether, turn on wizard mode; see [Cheat death](#cheat-death).

### Map and detect

| Want | Keys |
|---|---|
| See monsters, objects, doors and stairs nearby | `Ctrl-A` `d` |
| Map the local area | `Ctrl-A` `m` |
| Map and light the whole level | `Ctrl-A` `w` |
| Reveal literally every grid | `Ctrl-A` `u` |
| See all monsters on screen permanently | Turn on wizard mode (`Ctrl-W`) |

## What wizard mode changes

While wizard mode is on, the normal game behaves differently:

| Area | Change |
|---|---|
| Title | Shows `[=-WIZARD-=]` (unless you are in a mimic form) |
| Monsters | You see **every monster on the current screen**, as if you had perfect telepathy |
| Combat | Melee, missile and throwing hits print `You do X (out of Y) damage.` |
| Monsters | Messages when a monster gains experience. Warnings when a monster can't be placed |
| Uniques | Friendly and pet uniques stay friendly (outside wizard mode they turn hostile) |
| Monster drops | A monster with a set artifact drop **always** drops that artifact (if it doesn't exist yet), instead of only by chance |
| Death | You get the [cheat death](#cheat-death) `Die?` prompt |
| Equipment | You can take off **cursed** items |
| Skills screen (`G`) | All skills are shown. `+` / `-` change the selected skill by one point for free |
| Abilities screen (`N`) | `+` gives the selected ability, `-` removes it, for free |
| Shops | Examining an item in a shop drops a **free copy** of it at your position. The shop keeps its item |
| Look / targeting | The description adds `(feature:mimic:special)` numbers for the grid, and the free-targeting cursor can go to the very edge of the map |
| Sense grid mana | Shows the exact grid mana and the average value |
| HTML dump | Asks `WIZARD MODE: Do an help file dump?` |
| Wilderness | Each step on the overview map prints your `y:` / `x:` coordinates. Town generation details are shown |
| Fates | New fates are described in detail when you get them |
| Quests | Some quests print hidden setup details (such as the level of the lost hobbit or Thrain) |
| Items | Extra internal messages, such as `(breakage)` or `(no floor space)` |

### Cheat death

When you die while wizard mode is on, or with the `cheat_live` option on, the
game asks `Die?`. Answer `n` and you get "You invoke wizard mode and cheat
death." This marks the savefile. Then:

- HP, mana and sanity are restored to full, and blindness, confusion, poison,
  fear, paralysis, hallucination, stun, cuts and the Black Breath are cured.
- Food is set to "full". Undead form is removed. Any pending Word of Recall is
  cancelled.
- A new level is generated at the same depth (any quest level is left).
- The death cause on record becomes "Cheating death".

Other ways of avoiding death (a god's resurrection, the Blood of Life) are
checked first, before this prompt.

## Cheating options

Press `=` to open the options menu, then `C` (capital only) for **Cheating
Options**. The page title is "Cheaters never win". Move with `8`/`2` (or
`-`/`Enter`/`Space`), and press `y` or `6` to turn an option on, `n` or `4` to
turn it off. `Esc` leaves.

| Option | Description in game | What it does |
|---|---|---|
| `cheat_peek` | Peek into object creation | Messages when objects are created (and their level), when a shop item is discounted, and when random artifacts are made |
| `cheat_hear` | Peek into monster creation | Messages when monsters, especially uniques, are created. Warnings when a monster can't be placed |
| `cheat_room` | Peek into dungeon creation | Messages describing level generation: room and vault types, special level types, and so on |
| `cheat_xtra` | Peek into something else | Extra internal messages (such as life-drain amounts). With wizard mode also on: martial arts attack choice and the names of help files as they load |
| `cheat_live` | Allow player to avoid death | The [cheat death](#cheat-death) prompt, without needing wizard mode |

The savefile is marked when you **leave** the menu with an option turned on.
Turning it off later doesn't remove the mark. Cheat options are saved with the
character and reset to off for each new character.

> **Note from the code:** the mark is built from each option's bit number
> (`src/cmd4.cc`, `do_cmd_options_cheat`). `cheat_peek` has bit number 0, so
> turning it on **doesn't actually mark the savefile**. The other four do, and
> the score code then treats the character as a wizard ("Score not registered
> for wizards."). This looks like a bug. Don't rely on it either way.

## Differences from the in-game help

The in-game `lib/help/debug.txt` (Theme has an identical copy) is older than
the current code. These entries are wrong in it:

| Help file says | Actual behaviour |
|---|---|
| `B`: HP to zero | Changes your **body** to monster race number *count* (no count: normal body) |
| `C`: give the artifact number as the count (`03^AC`) | The count is ignored. `C` **prompts** `Number of the artifact:` |
| `D`: teleport to the wilderness | Moves you into **dungeon number *count*** at its minimum depth. No count happens to mean the Wilderness (dungeon 0) |
| `h`: change life rating | Re-rolls your HP at random and reports the new life rating. You can't choose it |
| `k`: check attributes | **Doesn't exist.** Gives "That is not a valid debug command." |
| `r`: gain reward | **Doesn't exist** (and the summary table lists `r` as unused) |
| `v`: random artifact/ego item | Creates *count* "great" items using the normal item rules (usually ego, sometimes artifact) |
| `g`: create a good item | Creates *count* good items (default 1) |
| `s`: summon a random monster | Summons *count* random monsters (default 1) |
| `/`: summon a random monster | The count picks the **summon type** (no count: any type). Uses the deepest level reached in the current dungeon |
| `H`: a pack of creatures of the same kind | One random monster plus 6–15 monsters with the **same symbol** (not necessarily the same kind) |
| `w`: looks like the same as `u` | `w` lights and maps the level. `u` also marks **every** grid, including solid rock, as known |
| `z`: monsters in sight range vanish | Deletes all monsters within 20 squares, **whether in sight or not** |
| `*`: lose special powers | Sets your **mimic form** to *count* for 100 turns. No count returns you to normal form |
| `U`: supposed to make you undead | Makes you undead **and summons a hostile Wild rabbit** |
| `=`: 0 enemy, 1 neutral, 2 friendly, 3 pet, 4 companion | The count is stored as is: 0 or 1 neutral, 2 friendly, 3 pet, 4 companion. **"Enemy" can't be set.** A bare `0` gives 99, an invalid value |
| `q`: quest numbers 1–25 from `defines.h` | Accepts 1–29 except 5. The constants are in `src/defines.hpp` |
| `T`: a number from `wf_info.txt` | The number is the town (entrance) number in the `W:` lines, not the `N:` index. See [Town numbers](#town-numbers) |
| `o`: alter an object in your backpack | Works on the pack, equipment, **or the floor** |
| `a`: restores stats, HP, SP, hunger, lost levels | Also removes curses, restores sanity, cures the Black Breath, and heals a carried monster |
| `N`: try 861, DarkGod is now your pet | 861 is still DarkGod in both modules, but as a unique it **turns hostile** once wizard mode is off |
| `?`: displays the main help file | Correct. It opens the main help index, not this page |

`lib/help/command.txt` links `^A` to anchor 101 in `debug.txt`. That file has
no anchor 101 (it has 99, 100, 111 and 112), so the link probably doesn't go to
the right place.

Every key in the help's command summary that has a handler in the code is
listed in this document. The only keys in the help with no handler are `k` and
`r`. No implemented command is missing from the help.
