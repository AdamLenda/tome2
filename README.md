ToME is a [rogue-like](https://en.wikipedia.org/wiki/Roguelike) game.

![Screenshot](/doc/images/screenshot.png)

## Documentation

The in-game help can also be read here:
[ToME help](doc/help/README.md) and
[Theme module help](doc/help/theme/README.md).

Guides written for this fork:
[keys and controls](doc/controls.md) and
[debug (wizard) mode](doc/debug-mode.md).

## Getting Started

### Prerequisites

See below for specific distribution-specific hints, if needed.

You will need to have the following libraries installed on your system
somewhere where CMake can find them:

- [Boost](https://www.boost.org/)

Version requirements may vary somewhat, but usually you should be
aiming for having at least a **recent** version of the above libraries.

### Option 1: Running In-Place

**This is currently the recommended option**, but it means that you
don't 'install' ToME as such, you just run it from the build
directory.

To configure for your system, run

    $ cmake .
    $ make

You should now be able to run one of the executables in ./src
to run ToME. For example, you'd run

    $ ./src/tome-x11

to start ToME with the X11 frontend.

**Important:** The current working directory must be at the root of
the source tree for the above command to run -- if it isn't, then
you'll get mysterious errors about ToME not being able to find files
(at best).


### Option 2: Installing System-Wide

To configure for your system, run

    $ cmake -DSYSTEM_INSTALL:BOOL=true .
    $ make
    $ sudo make install

You can now run ToME from anywhere and it will always use the files
installed in the system-specific location.


## Compiling on Ubuntu

To compile on an Ubuntu install, you'll need at least the 

- `cmake`
- `build-essential`
- `libboost-all-dev`

If the following are not installed, they'll be downloaded automatically:
- `libpcg-cpp-dev`
- `libjsoncons-dev`
- `libfmt-dev`

packages.

Note for package maintainers: `-DCPM_LOCAL_PACKAGES_ONLY=yes -DUSE_SYSTEM_PCG_RANDOM=yes` will avoid downloading deps automatically.
See [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for more details.

Each frontend requires the additional packages listed below:

- X11: `libx11-dev`
- ncurses: `libncurses5-dev`


## Compiling on OpenBSD

As of February 2010, the OpenBSD package cmake-2.4.8p2 is too old for
building ToME. You may need to compile a newer version of CMake.

If you have X11, then a bug in CMake may cause a linker error when
linking the executable. As a workaround, set the environment variable
`LDFLAGS` when running CMake. Example:

    $ env LDFLAGS=-L/usr/X11R6/lib cmake .
    $ make


## Compiling on Windows using MinGW

The source **MUST** be unpacked in a directory without spaces in the
name.

To configure and compile on Windows using MinGW, use the commands

    $ cmake -G "MinGW Makefiles"
    $ mingw32-make


## Mods

A mod changes the data of one of the built-in modules (ToME or Theme)
without touching the game's own files. Mods live in the `mods` folder
of your ToME user directory (`~/.tome/2.4/mods`, created on start-up),
one folder per mod, and appear in the module menu after the built-in
modules. A mod that can't be loaded is listed there with the reason.

Each mod folder holds:

- `module.txt`, describing the mod:

      N:My Mod
      B:ToME
      V:1:0:0
      A:Your Name:you@example.com
      D:Up to four lines describing the mod,
      D:shown in the module menu.

  `N` (the name, at most 16 characters) and `B` (the built-in module
  it builds on) are required. `S:<tag>` lines let the mod load
  savefiles made under another name, such as an earlier name of the
  mod.

- `edit/`, holding the edit files the mod changes. Any edit file not
  there is read from the base module (`lib/edit`, or
  `lib/mods/theme/edit` for Theme).

A mod plays by its base module's rules, and its savefiles are kept
apart, in `save/<mod folder>`.
