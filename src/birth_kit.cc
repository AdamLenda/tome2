#include "birth_kit.hpp"

#include "z-rand.hpp"

#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <algorithm>
#include <climits>
#include <cstddef>

namespace {

/* Largest stack the game allows (MAX_STACK_SIZE - 1) */
constexpr int MAX_BIRTH_NUMBER = 99;

/* TV_BOOK and BOOK_RANDOM */
constexpr int SPELLBOOK_TVAL = 111;
constexpr int SPELLBOOK_SVAL = 255;

std::string trim_right(std::string const &s)
{
	return boost::algorithm::trim_right_copy(s);
}

/*
 * Parse a non-negative decimal number made of digits only.
 */
boost::optional<int> parse_natural(std::string const &s)
{
	if (s.empty() || (s.size() > 9) ||
	    !std::all_of(s.begin(), s.end(), [](char c) { return (c >= '0') && (c <= '9'); }))
	{
		return boost::none;
	}

	return std::stoi(s);
}

/*
 * Parse a decimal number with an optional leading '-'.
 */
boost::optional<int> parse_integer(std::string const &s)
{
	if (!s.empty() && (s[0] == '-'))
	{
		auto n = parse_natural(s.substr(1));
		if (!n) return boost::none;
		return -*n;
	}

	return parse_natural(s);
}

std::vector<std::string> split(std::string const &s, char sep)
{
	std::vector<std::string> parts;
	boost::algorithm::split(parts, s, [sep](char c) { return c == sep; });
	return parts;
}

bool names_contain(std::vector<std::string> const &names, std::string const &name)
{
	return std::any_of(names.begin(), names.end(), [&name](std::string const &n) {
		return boost::algorithm::iequals(n, name);
	});
}

bool is_excluded(birth_object const &o, std::vector<std::pair<int, int>> const &excluded)
{
	if (o.type == birth_object::kind::ARTIFACT)
	{
		return false;
	}

	return std::find(excluded.begin(), excluded.end(), std::make_pair(o.tval, o.sval)) != excluded.end();
}

}

int birth_amount::min() const
{
	switch (type)
	{
	case kind::FIXED:
		return a * multiplier;
	case kind::RANGE:
		return a * multiplier;
	case kind::DICE:
		return a * multiplier;
	}

	return 0;
}

int birth_amount::max() const
{
	switch (type)
	{
	case kind::FIXED:
		return a * multiplier;
	case kind::RANGE:
		return b * multiplier;
	case kind::DICE:
		return a * b * multiplier;
	}

	return 0;
}

int birth_amount::roll() const
{
	switch (type)
	{
	case kind::FIXED:
		return a * multiplier;
	case kind::RANGE:
		return rand_range(a, b) * multiplier;
	case kind::DICE:
		return damroll(a, b) * multiplier;
	}

	return 0;
}

boost::optional<birth_amount> parse_birth_amount(std::string const &text)
{
	auto s = trim_right(text);

	birth_amount amount;

	/* Multiplier */
	auto star = s.find('*');
	if (star != std::string::npos)
	{
		auto m = parse_natural(s.substr(star + 1));
		if (!m || (*m < 1)) return boost::none;
		amount.multiplier = *m;
		s = s.substr(0, star);
	}

	/* Range */
	auto dash = s.find('-');
	if (dash != std::string::npos)
	{
		auto lo = parse_natural(s.substr(0, dash));
		auto hi = parse_natural(s.substr(dash + 1));
		if (!lo || !hi || (*lo > *hi)) return boost::none;
		amount.type = birth_amount::kind::RANGE;
		amount.a = *lo;
		amount.b = *hi;
	}
	/* Dice */
	else if (s.find('d') != std::string::npos)
	{
		auto d = s.find('d');
		auto num = parse_natural(s.substr(0, d));
		auto sides = parse_natural(s.substr(d + 1));
		if (!num || !sides || (*num < 1) || (*sides < 1)) return boost::none;
		amount.type = birth_amount::kind::DICE;
		amount.a = *num;
		amount.b = *sides;
	}
	/* Fixed */
	else
	{
		auto n = parse_natural(s);
		if (!n) return boost::none;
		amount.type = birth_amount::kind::FIXED;
		amount.a = *n;
	}

	/* Keep every result well inside an int */
	long long largest = amount.a;
	if (amount.type == birth_amount::kind::RANGE) largest = amount.b;
	if (amount.type == birth_amount::kind::DICE) largest = static_cast<long long>(amount.a) * amount.b;
	if ((largest > INT_MAX / 2) || (largest * amount.multiplier > INT_MAX / 2))
	{
		return boost::none;
	}

	return amount;
}

boost::optional<birth_object> parse_birth_object(std::string const &text)
{
	auto s = trim_right(text);

	birth_object o;

	/* Artifact */
	if (boost::algorithm::starts_with(s, "A:"))
	{
		auto idx = parse_natural(s.substr(2));
		if (!idx || (*idx < 1)) return boost::none;
		o.type = birth_object::kind::ARTIFACT;
		o.artifact_idx = *idx;
		return o;
	}

	/* Single-spell book */
	if (boost::algorithm::starts_with(s, "B:"))
	{
		auto spell = boost::algorithm::trim_copy(s.substr(2));
		if (spell.empty()) return boost::none;
		o.type = birth_object::kind::SPELLBOOK;
		o.tval = SPELLBOOK_TVAL;
		o.sval = SPELLBOOK_SVAL;
		o.spell = spell;
		return o;
	}

	/* Ordinary object */
	auto fields = split(s, ':');
	if (fields.size() < 3) return boost::none;

	auto tval = parse_natural(fields[0]);
	auto sval = parse_natural(fields[1]);
	if (!tval || !sval) return boost::none;
	o.type = birth_object::kind::OBJECT;
	o.tval = *tval;
	o.sval = *sval;

	/* Positional fields, then key=value fields */
	std::vector<std::string> positional;
	std::size_t i = 2;
	for (; (i < fields.size()) && (fields[i].find('=') == std::string::npos); i++)
	{
		positional.push_back(fields[i]);
	}

	boost::optional<birth_amount> number;
	if (positional.size() == 1)
	{
		number = parse_birth_amount(positional[0]);
	}
	else if (positional.size() == 2)
	{
		auto pval = parse_integer(positional[0]);
		if (!pval) return boost::none;
		o.pval = *pval;
		number = parse_birth_amount(positional[1]);
	}

	if (!number || (number->min() < 1) || (number->max() > MAX_BIRTH_NUMBER))
	{
		return boost::none;
	}
	o.number = *number;

	for (; i < fields.size(); i++)
	{
		auto eq = fields[i].find('=');
		if (eq == std::string::npos) return boost::none;

		auto key = fields[i].substr(0, eq);
		auto value = fields[i].substr(eq + 1);

		if (key == "fuel")
		{
			auto fuel = parse_birth_amount(value);
			if (!fuel) return boost::none;
			o.fuel = *fuel;
		}
		else if (key == "form")
		{
			if (boost::algorithm::trim_copy(value).empty()) return boost::none;
			o.form = value;
		}
		else
		{
			return boost::none;
		}
	}

	return o;
}

boost::optional<birth_filter> parse_birth_filter(std::string const &text)
{
	auto s = trim_right(text);

	birth_filter f;

	if (s == "*")
	{
		f.type = birth_filter::kind::ANY;
		return f;
	}

	auto colon = s.find(':');
	if (colon == std::string::npos) return boost::none;

	auto kind = s.substr(0, colon);
	if (kind == "RACE") f.type = birth_filter::kind::RACE;
	else if (kind == "SUBRACE") f.type = birth_filter::kind::SUBRACE;
	else if (kind == "CLASS") f.type = birth_filter::kind::CLASS;
	else if (kind == "SPEC") f.type = birth_filter::kind::SPEC;
	else if (kind == "TAG") f.type = birth_filter::kind::TAG;
	else return boost::none;

	f.names = split(s.substr(colon + 1), '|');
	for (auto const &name : f.names)
	{
		if (name.empty()) return boost::none;
	}

	return f;
}

bool birth_filter_matches(birth_filter const &filter, birth_character const &who)
{
	switch (filter.type)
	{
	case birth_filter::kind::ANY:
		return true;
	case birth_filter::kind::RACE:
		return names_contain(filter.names, who.race);
	case birth_filter::kind::SUBRACE:
		return names_contain(filter.names, who.subrace);
	case birth_filter::kind::CLASS:
		return names_contain(filter.names, who.class_name);
	case birth_filter::kind::SPEC:
		return names_contain(filter.names, who.spec);
	case birth_filter::kind::TAG:
		return std::any_of(who.tags.begin(), who.tags.end(), [&filter](std::string const &tag) {
			return names_contain(filter.names, tag);
		});
	}

	return false;
}

birth_field_result parse_birth_kit_field(char field, std::string const &rest, birth_kit *kit)
{
	switch (field)
	{
	case 'O':
		{
			auto o = parse_birth_object(rest);
			if (!o) return birth_field_result::ERROR;
			kit->objects.push_back(*o);
			return birth_field_result::OK;
		}

	case 'X':
		{
			auto fields = split(trim_right(rest), ':');
			if (fields.size() != 2) return birth_field_result::ERROR;
			auto tval = parse_natural(fields[0]);
			auto sval = parse_natural(fields[1]);
			if (!tval || !sval) return birth_field_result::ERROR;
			kit->excluded.emplace_back(*tval, *sval);
			return birth_field_result::OK;
		}

	case 'T':
		{
			auto tag = trim_right(rest);
			if (tag.empty() ||
			    std::any_of(tag.begin(), tag.end(), [](char c) { return (c == ' ') || (c == '|') || (c == '\t'); }))
			{
				return birth_field_result::ERROR;
			}
			kit->tags.push_back(tag);
			return birth_field_result::OK;
		}
	}

	return birth_field_result::NOT_HANDLED;
}

birth_field_result parse_general_birth_field(char field, std::string const &rest, general_birth_kit *kit)
{
	switch (field)
	{
	case 'O':
		{
			auto o = parse_birth_object(rest);
			if (!o) return birth_field_result::ERROR;
			kit->objects.emplace_back(kit->current_filter, *o);
			return birth_field_result::OK;
		}

	case 'W':
		{
			auto f = parse_birth_filter(rest);
			if (!f) return birth_field_result::ERROR;
			kit->current_filter = *f;
			return birth_field_result::OK;
		}
	}

	return birth_field_result::NOT_HANDLED;
}

std::set<std::string> birth_kit_tags(std::vector<birth_kit const *> const &levels)
{
	std::set<std::string> tags;

	for (auto level : levels)
	{
		if (!level) continue;

		for (auto const &tag : level->tags)
		{
			tags.insert(boost::algorithm::to_lower_copy(tag));
		}
	}

	return tags;
}

std::vector<birth_object> assemble_birth_kit(
	general_birth_kit const &general,
	std::vector<birth_kit const *> const &levels,
	birth_character const &who)
{
	/* Tags and exclusions from every level */
	auto tagged = who;
	for (auto const &tag : birth_kit_tags(levels))
	{
		tagged.tags.insert(tag);
	}

	std::vector<std::pair<int, int>> excluded;
	for (auto level : levels)
	{
		if (!level) continue;
		excluded.insert(excluded.end(), level->excluded.begin(), level->excluded.end());
	}

	/* General objects, then each level's */
	std::vector<birth_object> objects;

	for (auto const &p : general.objects)
	{
		if (birth_filter_matches(p.first, tagged) && !is_excluded(p.second, excluded))
		{
			objects.push_back(p.second);
		}
	}

	for (auto level : levels)
	{
		if (!level) continue;

		for (auto const &o : level->objects)
		{
			if (!is_excluded(o, excluded))
			{
				objects.push_back(o);
			}
		}
	}

	return objects;
}
