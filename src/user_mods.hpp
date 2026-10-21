#pragma once

/*
 * Mods installed by the player.
 *
 * A mod is a directory in the user's mods directory (~/.tome/<version>/mods)
 * holding a module.txt that describes it and an edit/ directory whose
 * files take the place of the base module's edit files of the same
 * name. A mod follows the rules of a built-in module, its base, and
 * reads everything else from that module.
 *
 * module.txt:
 *
 *   N:<name>                    name shown in the module menu (at most
 *                               16 characters); savefiles are tagged
 *                               with it
 *   B:<module>                  the built-in module it builds on, e.g.
 *                               ToME or Theme
 *   V:<major>:<minor>:<patch>   version (default 1:0:0)
 *   A:<name>[:<email>]          author
 *   D:<text>                    description, one line each (at most 4
 *                               lines of 79 characters)
 *   S:<tag>                     another savefile tag to accept, such as
 *                               an earlier name of the mod (repeatable)
 *
 * N and B are required. Blank lines and lines starting with '#' are
 * ignored.
 */

#include <boost/optional.hpp>
#include <string>
#include <vector>

/**
 * A mod's description, from its module.txt.
 */
struct mod_manifest
{
	std::string name;
	std::string base;
	int version_major = 1;
	int version_minor = 0;
	int version_patch = 0;
	std::string author_name;
	std::string author_email;
	std::string desc;                     /* lines joined by '\n' */
	std::vector<std::string> save_tags;   /* accepted besides 'name' */
};

/**
 * The manifest, or why there isn't one ("line <n>: <reason>").
 */
struct mod_manifest_result
{
	boost::optional<mod_manifest> manifest;
	std::string error;
};

/**
 * Read a module.txt.
 */
mod_manifest_result parse_mod_manifest(std::string const &text);

/**
 * A usable mod.
 */
struct user_mod
{
	std::string dir_name;   /* its directory's name in the mods directory */
	std::string path;       /* its directory */
	mod_manifest manifest;  /* 'base' spelled as in 'bases' */
};

struct user_mods_found
{
	std::vector<user_mod> mods;
	std::vector<std::string> errors;   /* "<directory>: <reason>" */
};

/**
 * Find the mods in 'mods_dir', ordered by directory name. A mod must
 * build on one of 'bases' and have a name that neither 'taken' nor an
 * earlier mod uses (ignoring case). Directories without a module.txt
 * are not mods and are skipped silently; mods that can't be used are
 * left out and reported. A missing 'mods_dir' holds no mods.
 */
user_mods_found find_user_mods(
	std::string const &mods_dir,
	std::vector<std::string> const &bases,
	std::vector<std::string> const &taken);

/**
 * The path of edit file 'name': in 'overlay_dir' if that is given and
 * has the file, otherwise in 'base_dir'.
 */
std::string choose_edit_file(const char *overlay_dir, const char *base_dir, std::string const &name);
