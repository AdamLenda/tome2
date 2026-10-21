#pragma once

#include "h-basic.hpp"

#include <string>
#include <vector>

/**
 * Module descriptor.
 */
struct module_type
{
	/* Metadata about the module: author, description, etc. */
	struct {
		/* Module name */
		const char *name;

		/* Module version number */
		struct {
			s32b major;
			s32b minor;
			s32b patch;
		} version;

		/* Module author */
		struct {
			const char *name;
			const char *email;
		} author;

		/* Module description */
		const char *desc;

		/* Save file tag */
		const char *save_file_tag;

		/* Module directory */
		const char *module_dir;

		/* Module whose game rules apply (MODULE_*): the module
		   itself for the built-in ones, the base module for mods */
		s32b rules_module;

		/* Directory under the save directory that holds its
		   savefiles, or NULL for the save directory itself */
		const char *save_dir;

		/* Directory whose edit files take the place of the
		   module's own (a mod's edit/ directory), or NULL */
		const char *edit_overlay_dir;

		/* Savefile tags accepted besides save_file_tag */
		std::vector<std::string> other_save_tags;
	} meta;

	/* Random artifact generation chances */
	struct {
		s32b weapon_chance;
		s32b armor_chance;
		s32b jewelry_chance;
	} randarts;

	/* Skills */
	struct {
		/* Skill points per level */
		s32b skill_per_level;
		/* Maximum "overage" for skill points, i.e. how many skill
		   points you can go above your current level. */
		s32b max_skill_overage;
	} skills;

	/* Function to show introduction to module */
	void (*intro)();

	/* Function to compute race status, i.e. whether monsters
	   are friendly/neutral towards the player. Returns NULL
	   to indicate that no override happens. */
	s16b *(*race_status)(int r_idx);
};
