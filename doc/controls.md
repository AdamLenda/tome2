# ToME Controls Reference

This is a reference for the keyboard controls in this version of ToME. It was
written by checking the in-game help (`lib/help/command.txt`) against the
command dispatcher in `src/dungeon.cc` and the default keymaps in
`lib/pref/pref.prf`. Where the old help file disagrees with the code, this
document follows the code. See [Differences from the in-game help](#differences-from-the-in-game-help).

In-game, press `?` at any time to open the built-in help browser.

## Contents

- [Basics](#basics)
- [Choosing a keyset](#choosing-a-keyset)
- [Movement](#movement)
- [Command reference (original keyset)](#command-reference-original-keyset)
- [Roguelike keyset differences](#roguelike-keyset-differences)
- [Prompts, item selection and targeting](#prompts-item-selection-and-targeting)
- [Extended commands (`#`)](#extended-commands-)
- [Repeat counts](#repeat-counts)
- [Inscriptions](#inscriptions)
- [Terminal (tome-gcu) notes](#terminal-tome-gcu-notes)
- [Differences from the in-game help](#differences-from-the-in-game-help)

---

## Basics

| Key | What it does |
|---|---|
| `?` | Help browser |
| `Esc` | Cancel the current prompt or command |
| `Space` / `Enter` | Dismiss a `-more-` message |
| `Ctrl-X` | **Save and quit** |
| `Ctrl-S` | Save without quitting |
| `Ctrl-P` | Message history |
| `Ctrl-R` | Redraw the screen |
| `=` | Options menu |

> **Warning:** `Q` is **not** "quit". It **kills your character** permanently
> (after two confirmations). Use `Ctrl-X` to quit. In the original keyset,
> `Ctrl-K` and `Ctrl-C` are also mapped to this "commit suicide" command.

## Choosing a keyset

ToME has two keysets:

- **Original** (the default): numbers move you, and letters are mnemonic
  commands (`q` = quaff, `r` = read).
- **Roguelike**: `h j k l y u b n` move you (vi-style). Several commands move
  to other keys to make room.

To switch, press `=`, open **User Interface Options**, and toggle
`rogue_like_commands`.

## Movement

```
   Original keyset          Roguelike keyset

     7  8  9                  y  k  u
      \ | /                    \ | /
   4 -  5  - 6              h -  .  - l
      / | \                    / | \
     1  2  3                  b  j  n
```

| Action | Original | Roguelike |
|---|---|---|
| Walk | `1`–`9` (not `5`), or arrow keys | `h j k l y u b n`, or `1`–`9`, or arrow keys |
| Run | `.` then a direction | `Shift` + direction (`H J K L Y U B N`), or `,` then a direction |
| Tunnel / alter adjacent grid | `T` then a direction (`+` for the general "alter") | `Ctrl` + direction (`^H ^J ^K` …) |
| Stay in place | `5` or `,` | `5` or `.` |
| Stay in place and toggle pickup (usually **pick up**) | `g` | `g` |
| Walk with the pickup setting toggled | `-` then a direction | `-` then a direction |
| Go up / down stairs | `<` / `>` | `<` / `>` |

**Picking things up:** the `always_pickup` option is **off** by default, so
walking over items leaves them on the floor. Stand on the item and press `g`.
Turning on `always_pickup` (User Interface Options) swaps the behaviour of
`g`/`,` and `-`/`;`.

**On the surface:** `<` opens the wilderness map, and `>` zooms back in from
it. `>` also enters Void Jumpgates.

**Running** follows corridors until something interesting happens or you
reach a junction. Pressing any key stops running or resting.

## Command reference (original keyset)

Underlying command keys are shown. If you use the roguelike keyset, check
[the differences table](#roguelike-keyset-differences) first.

### Items and equipment

| Key | Command |
|---|---|
| `i` | Inventory |
| `e` | Equipment |
| `w` | Wear / wield |
| `t` | Take off |
| `d` | Drop (also used to **sell** in shops) |
| `k` | Destroy an item (`X` destroys the item on the floor) |
| `I` | Inspect an item in detail |
| `{` / `}` | Inscribe / remove an inscription |
| `E` | Eat |
| `q` | Quaff a potion |
| `r` | Read a scroll |
| `F` | Refuel lantern or torch |
| `h` | Hack up a corpse (into meat) |
| `K` | Cure meat (needs salt water) |

### Combat and magic devices

Attack a monster by **walking into it**.

| Key | Command |
|---|---|
| `f` | Fire a missile (uses your launcher; throws boomerangs) |
| `v` | Throw an item |
| `a` | Aim a wand |
| `u` | Use a staff |
| `z` | Zap a rod |
| `A` | Activate an artifact (also instruments, eggs, some staves) |
| `*` | Choose a target (see [targeting](#targeting)) |

### Magic, skills and powers

| Key | Command |
|---|---|
| `m` | Cast a spell / use a mental power or class skill |
| `b` | Browse a spellbook |
| `G` | **Skills screen**: spend skill points when you level up |
| `N` | **Abilities screen**: buy abilities |
| `U` | Use a racial or class bonus power |
| `p` | Pray to your god |
| `O` | Sacrifice at an altar (starts worship of that god) |

### Doors, terrain and the dungeon

| Key | Command |
|---|---|
| `o` | Open a door or chest |
| `c` | Close a door |
| `B` | Bash a door |
| `j` | Jam a door with spikes |
| `T` | Tunnel (wield a digger for best results) |
| `+` | Alter: does the obvious thing to an adjacent grid (open, tunnel, attack…) |
| `H` | Drink from / fill bottles at a fountain |
| `x` | Engrave the floor (spell runes) |
| `_` | Re-enter a shop you are standing in front of |

### Monsters and pets

| Key | Command |
|---|---|
| `y` | Give an item to an adjacent monster |
| `Y` | Chat with a monster |
| `P` | Pet commands |
| `Z` | Steal (from shops; rogues can steal from monsters) |

### Looking and information

| Key | Command |
|---|---|
| `l` | Look around (nearby monsters and objects) |
| `M` | Full dungeon map (reduced scale) |
| `L` | Scroll the map by sector (`Esc` to recentre) |
| `/` | Identify what a map symbol means |
| `C` | Character sheet (also rename, or save to a file) |
| `~` | Knowledge menu: artifacts, uniques, objects, kills, recall depths, corruptions, pets, quests, fates, traps, towns, notes |
| `Ctrl-F` | Repeat the level feeling |
| `Ctrl-O` | Show the last message |
| `Ctrl-P` | Message history |
| `Ctrl-Q` | Quest status |
| `Ctrl-T` | Current in-game time and date |
| `V` | Version information |

### Game, interface and setup

| Key | Command |
|---|---|
| `R` | Rest (enter a number of turns, `*` for HP/SP, or `&` for "as needed") |
| `n` | Repeat the last command |
| `#` | Extended command prompt (see below) |
| `:` | Write a note into your notes file |
| `=` | Options |
| `@` | Macros and keymaps |
| `$` | Macro recorder: press once to start, type keys, press again to save |
| `%` | Visuals (symbols and colours of things) |
| `&` | Colour palette |
| `"` | Enter a single user-pref command |
| `Tab` (`Ctrl-I`) | Cycle sub-window contents (windowed front-ends) |
| `Ctrl-R` | Redraw |
| `Ctrl-S` | Save |
| `Ctrl-X` | Save and quit |
| `Q` | **Commit suicide**: permanently kills your character |
| `\` | Bypass keymaps: the next key is read as an underlying command (useful in macros) |

`Ctrl-A` (debug commands) and `Ctrl-W` (wizard mode) are cheat or developer
commands. Using them marks your character as a cheater.

## Roguelike keyset differences

Commands that keep the same key in both keysets aren't listed.

| Command | Original | Roguelike |
|---|---|---|
| Walk | `1`–`9` | `h j k l y u b n` |
| Run | `.` + dir | `Shift` + dir, or `,` + dir |
| Stay still | `,` | `.` |
| Tunnel / alter | `T` / `+` | `Ctrl-T` / `Ctrl` + dir |
| Aim a wand | `a` | `z` |
| Zap a rod | `z` | `a` |
| Use a staff | `u` | `Z` |
| Fire | `f` | `t` |
| Bash a door | `B` | `f` |
| Take off | `t` | `T` |
| Look | `l` | `x` |
| Locate (scroll map) | `L` | `W` |
| Browse a book | `b` | `P` |
| Pet commands | `P` | `X` |
| Bonus power | `U` | `O` |
| Sacrifice at altar | `O` | `Ctrl-G` |
| Destroy an item | `k` | `Ctrl-D` |
| Hack up a corpse | `h` | `$` |
| Cure meat | `K` | `Ctrl-O` |
| Drink from fountain | `H` | `V` |
| Engrave | `x` | `]` |
| Steal | `Z` | `[` |
| Give an item | `y` | `'` |
| Chat | `Y` | `(` |
| Extended command | `#` | `)` |
| Macro recorder | `$` | `S` |
| Show last message | `Ctrl-O` | *(not available, `Ctrl-O` is cure meat)* |

## Prompts, item selection and targeting

### Item prompts

When a command asks for an item:

| Key | Selects |
|---|---|
| `a`–`z` | That inventory slot, immediately |
| `A`–`Z` | That slot, after showing it and asking you to confirm |
| `-` | The item on the floor under you |
| `/` | Switch between inventory and equipment |
| `*` or `Space` | Show the list of valid choices |
| `0`–`9` | The first item inscribed `@<digit>` (see [Inscriptions](#inscriptions)) |
| `@` | Choose by name (handy in macros) |
| `Esc` | Cancel |

### Direction prompts

At a `Direction?` prompt, press a direction key, or:

| Key | Meaning |
|---|---|
| `t`, `5` or `.` | Use the current target |
| `*` | Pick a new target now |

### Targeting

Targeting is entered with `*`, or `*` at a direction prompt.

| Key | Action |
|---|---|
| `Space` / `+` | Next monster |
| `-` | Previous monster |
| Direction key | Jump to a monster in that general direction |
| `t`, `5` or `.` | Set the target |
| `r` | Recall what you know about the monster |
| `p` | Switch to free targeting of a grid, starting at you |
| `o` | Same, starting at the last monster looked at |
| `q` or `Esc` | Leave targeting |

To clear an old target, press `*` then `Esc`.

### Look mode (`l`)

`Space` shows the next thing, `-` the previous one, and a direction key jumps
in that direction. `r` recalls monster information, and `q` or `Esc` exits.

### Rest prompt (`R`)

Enter a number of turns, `*` to rest until HP and mana are full, or `&` to
rest as long as needed.

## Extended commands (`#`)

Press `#` (roguelike: `)`) and type one of these names, then `Enter`:

| Name | Shortcut | Does |
|---|---|---|
| `help` | `?` | List the extended commands |
| `time` | `T` | Show game time |
| `skills` | `S` | Skills screen |
| `ability` | `A` | Abilities screen |
| `quest` | `Q` | Quest list |
| `html-dump` | `D` | Save an HTML screenshot |
| `give` | `y` | Give an item to a monster |
| `chat` | `Y` | Talk to a monster |
| `jam` | `j` | Jam a door |

The extended-command list in `pref.prf` also defines `irc_on`, `irc_say`,
`irc_off` and `blunder`. None of these has a handler in this version, so they
only print "Type '?' for help."

## Repeat counts

Type `0`, then a number, then the command. For example, `0` `1` `5` `T` `6`
tunnels east up to 15 times. Leaving out the number means 99. In the original
keyset, to repeat a **movement**, press `Space` after the count to get a
command prompt, then press the direction.

Repeated commands stop when they succeed, when you're disturbed, or when you
press any key. The `always_repeat` option (on by default) repeats open,
tunnel, bash and alter automatically.

When a command asks for a quantity, the count is used as the quantity. For
example, `0` `d` drops a whole stack without asking.

## Inscriptions

Use `{` to inscribe items. Some inscriptions have special meanings:

| Inscription | Effect |
|---|---|
| `@3` | Pressing `3` at any item prompt selects this item |
| `@q3` | Same, but only for the `q` (quaff) command |
| `!*` | Always ask before using this item |
| `!d`, `!k`… | Ask before this item is used with that command (drop, destroy…) |
| `.` | Stops an item from randomly teleporting you (doesn't work on cursed items) |

The default `pref.prf` comments suggest inscribing your main weapon `@1@0`
and your digger or second weapon `@2@0`, then pressing `w` `0` to swap
between them.

## Terminal (tome-gcu) notes

- **Arrow keys** walk (they're mapped to `2 4 6 8`). Home, End, PgUp and PgDn
  are mapped to `7 1 9 3`, and keypad 5 to `5`. **Delete** runs (`.`) and
  **Insert** starts a repeat count (`0`).
- **Escape is slow** because the terminal has to wait to see whether it's the
  start of an arrow-key sequence. The backtick `` ` `` works as an instant
  Escape at prompts.
- **F1–F4** act as Escape.
- **Control keys** can be typed as `^` then the letter (`^` `x` = `Ctrl-X`).
  This is useful when the terminal or operating system intercepts a control
  key.
- `Ctrl-Z` suspends the game to the shell (`fg` resumes it).
- Run the game from the repository root (it loads data from `./lib`), or set
  `TOME_PATH`.

## Differences from the in-game help

The in-game `command.txt` is older than the current code. These entries
are wrong in it:

| Help file says | Actual behaviour |
|---|---|
| `s` searches, `S` (roguelike `#`) toggles search mode | Searching no longer exists in this version. Both keys do nothing. |
| `Ctrl-Q` skips to the next MIDI song | `Ctrl-Q` shows **quest status** |
| `Ctrl-E` toggles the choice window | No such command. `Tab` (`Ctrl-I`) cycles windows. |
| `!` interacts with the system | Not implemented |
| `(` / `)` load / save a screen dump | Not implemented (roguelike `(` is Chat and `)` is the extended command) |
| `Ctrl-\` takes an HTML screenshot | Use the extended command `#` `html-dump` |
| `\|` opens the knowledge menu | Only `~` does |
| `Ctrl-O` is unused (original) | Shows the last message |
| `X` is unused (original) | Destroys the item on the floor (`k` `-`) |
| `Ctrl-K` and `Ctrl-C` are unused or "break" (original) | Both are keymapped to **`Q` (commit suicide)**, which still asks for confirmation |
