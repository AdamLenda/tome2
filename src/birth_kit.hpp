#pragma once

/*
 * Starting equipment ("birth kit") as described in p_info.txt.
 *
 * Every level of the character -- the general section (G), race (R),
 * subrace (S), class (C) and class specialty (C:a) -- accepts:
 *
 *   O:<tval>:<sval>[:<pval>]:<number>[:key=value...]   starting object
 *   O:A:<a_info index>                                 starting artifact
 *   O:B:<spell name>                                   single-spell book
 *   X:<tval>:<sval>       never give this (non-artifact) starting object
 *   T:<tag>               character tag, usable in G:W:TAG: filters
 *
 * The general section additionally accepts:
 *
 *   W:<filter>            the G:O lines that follow apply only to
 *                         characters matching the filter; one of
 *                         '*', RACE:, SUBRACE:, CLASS:, SPEC: or TAG:
 *                         followed by '|'-separated names.
 *
 * Numbers are "N", "A-B" (uniform) or "XdY" (dice), optionally
 * followed by "*M" to multiply the result.  Object keys are
 * fuel=<number> (light source turns) and form=<monster name>
 * (mimic cloak form).
 */

#include <boost/optional.hpp>
#include <set>
#include <string>
#include <utility>
#include <vector>

/**
 * A number given in p_info.txt.
 */
struct birth_amount
{
	enum class kind { FIXED, RANGE, DICE };

	kind type = kind::FIXED;

	/* FIXED: value in a; RANGE: a..b; DICE: a d b */
	int a = 1;
	int b = 0;

	int multiplier = 1;

	int min() const;
	int max() const;

	/* Random value between min() and max(), using the game RNG */
	int roll() const;
};

boost::optional<birth_amount> parse_birth_amount(std::string const &s);

/**
 * A single starting object.
 */
struct birth_object
{
	enum class kind { OBJECT, ARTIFACT, SPELLBOOK };

	kind type = kind::OBJECT;

	/* OBJECT and SPELLBOOK (TV_BOOK, BOOK_RANDOM) */
	int tval = 0;
	int sval = 0;
	int pval = 0;

	/* OBJECT */
	birth_amount number;
	boost::optional<birth_amount> fuel;
	std::string form;

	/* ARTIFACT */
	int artifact_idx = 0;

	/* SPELLBOOK */
	std::string spell;
};

boost::optional<birth_object> parse_birth_object(std::string const &s);

/**
 * Filter for the general section's starting objects.
 */
struct birth_filter
{
	enum class kind { ANY, RACE, SUBRACE, CLASS, SPEC, TAG };

	kind type = kind::ANY;

	std::vector<std::string> names;
};

boost::optional<birth_filter> parse_birth_filter(std::string const &s);

/**
 * What a filter is matched against.
 */
struct birth_character
{
	std::string race;
	std::string subrace;
	std::string class_name;
	std::string spec;
	std::set<std::string> tags;
};

bool birth_filter_matches(birth_filter const &filter, birth_character const &who);

/**
 * Starting equipment of one level (race, subrace, class or specialty).
 */
struct birth_kit
{
	std::vector<birth_object> objects;
	std::vector<std::pair<int, int>> excluded;
	std::vector<std::string> tags;
};

/**
 * Starting equipment of the general section.
 */
struct general_birth_kit
{
	std::vector<std::pair<birth_filter, birth_object>> objects;

	/* Filter set by the last G:W line; used while parsing */
	birth_filter current_filter;
};

enum class birth_field_result { NOT_HANDLED, OK, ERROR };

/**
 * Parse one field of a race, subrace, class or specialty entry.
 * 'field' is the field letter and 'rest' everything after "<field>:".
 */
birth_field_result parse_birth_kit_field(char field, std::string const &rest, birth_kit *kit);

/**
 * Parse one field of the general section.
 */
birth_field_result parse_general_birth_field(char field, std::string const &rest, general_birth_kit *kit);

/**
 * The tags given by all the character's levels.
 */
std::set<std::string> birth_kit_tags(std::vector<birth_kit const *> const &levels);

/**
 * The objects a character starts with: the general objects whose filter
 * matches, then each level's objects in order, leaving out non-artifact
 * objects excluded by any level.  The character's tags are taken from
 * the levels; any tags already in 'who' are kept.
 */
std::vector<birth_object> assemble_birth_kit(
	general_birth_kit const &general,
	std::vector<birth_kit const *> const &levels,
	birth_character const &who);
