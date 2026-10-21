/*
 * Checks the starting equipment described by each module's p_info.txt.
 *
 * tests/data/birth_kits_<module>.txt list, per level, the starting
 * objects each module gave before starting equipment became fully
 * data-driven (generated from the old data files and the rules then
 * hard-coded in player_outfit()).  Reading p_info.txt through the
 * birth-kit parser must give exactly the same objects.
 */

#include "birth_kit.hpp"
#include "defines.hpp"
#include "mimic.hpp"
#include "variable.hpp"

#include <bandit/bandit.h>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using namespace bandit;

namespace {

std::string source_path(std::string const &relative)
{
	return std::string(TOME_SOURCE_DIR) + "/" + relative;
}

struct module_files
{
	std::string name;
	std::string edit_dir;

	// Object kinds the data already referred to without k_info.txt
	// defining them (the game gives the placeholder "something").
	std::set<std::string> known_missing_kinds;

	// Module whose game rules apply (MODULE_*)
	int rules;

	std::string edit_file(std::string const &file) const
	{
		return source_path(edit_dir + "/" + file);
	}
};

std::vector<module_files> const modules {
	{ "tome", "lib/edit", { "70:12" }, MODULE_TOME },
	{ "theme", "lib/mods/theme/edit", { "70:12", "46:1" }, MODULE_THEME },
};

std::vector<std::string> read_lines(std::string const &path)
{
	std::ifstream in(path);
	AssertThat(bool(in), Is().True());

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(in, line))
	{
		if (!line.empty() && (line.back() == '\r'))
		{
			line.pop_back();
		}
		lines.push_back(line);
	}
	return lines;
}

std::string show(birth_amount const &a)
{
	std::string s;
	switch (a.type)
	{
	case birth_amount::kind::FIXED:
		s = std::to_string(a.a);
		break;
	case birth_amount::kind::RANGE:
		s = std::to_string(a.a) + "-" + std::to_string(a.b);
		break;
	case birth_amount::kind::DICE:
		s = std::to_string(a.a) + "d" + std::to_string(a.b);
		break;
	}
	if (a.multiplier != 1)
	{
		s += "*" + std::to_string(a.multiplier);
	}
	return s;
}

std::string show(birth_object const &o)
{
	switch (o.type)
	{
	case birth_object::kind::ARTIFACT:
		return "A" + std::to_string(o.artifact_idx);
	case birth_object::kind::SPELLBOOK:
		return "B:" + o.spell;
	case birth_object::kind::OBJECT:
		break;
	}

	std::string s = std::to_string(o.tval) + ":" + std::to_string(o.sval);
	if (o.pval)
	{
		s += ":p" + std::to_string(o.pval);
	}
	s += " x" + show(o.number);
	if (o.fuel)
	{
		s += " fuel=" + show(*o.fuel);
	}
	if (!o.form.empty())
	{
		s += " form=" + o.form;
	}
	return s;
}

std::string show(birth_filter const &f)
{
	static const std::map<birth_condition::kind, std::string> kinds {
		{ birth_condition::kind::RACE, "RACE" },
		{ birth_condition::kind::SUBRACE, "SUBRACE" },
		{ birth_condition::kind::CLASS, "CLASS" },
		{ birth_condition::kind::SPEC, "SPEC" },
		{ birth_condition::kind::TAG, "TAG" },
	};

	if (f.conditions.empty())
	{
		return "*";
	}

	std::string s;
	for (auto const &c : f.conditions)
	{
		s += (s.empty() ? "" : "&") + kinds.at(c.type) + ":";
		for (std::size_t i = 0; i < c.names.size(); i++)
		{
			s += (i ? "|" : "") + c.names[i];
		}
	}
	return s;
}

/*
 * Birth kits of one module, read from its p_info.txt the way
 * init_player_info_txt() hands the lines to the birth-kit parser.
 */
struct module_kits
{
	general_birth_kit general;
	std::map<std::string, birth_kit> races;
	std::map<std::string, birth_kit> subraces;
	std::map<std::string, birth_kit> classes;
	std::map<std::string, birth_kit> specs; // "<class>/<spec>"

	std::vector<std::string> errors;

	void add_error(std::size_t line_no, std::string const &line)
	{
		errors.push_back(std::to_string(line_no) + ": " + line);
	}
};

module_kits read_module_kits(module_files const &m)
{
	module_kits kits;

	birth_kit *race = nullptr;
	birth_kit *subrace = nullptr;
	birth_kit *klass = nullptr;
	birth_kit *spec = nullptr;
	std::string class_name;

	auto lines = read_lines(m.edit_file("p_info.txt"));

	for (std::size_t i = 0; i < lines.size(); i++)
	{
		auto const &line = lines[i];

		if (line.size() < 4 || line[0] == '#' || line[1] != ':' || line[3] != ':')
		{
			continue;
		}

		char section = line[0];
		char field = line[2];
		std::string rest = line.substr(4);

		/* Class specialty lines: C:a:<field>:<rest> */
		if ((section == 'C') && (field == 'a'))
		{
			if (rest.size() < 2 || rest[1] != ':')
			{
				continue;
			}
			field = rest[0];
			std::string spec_rest = rest.substr(2);

			if (field == 'N')
			{
				spec = &kits.specs[class_name + "/" + spec_rest];
			}
			else if (spec && (parse_birth_kit_field(field, spec_rest, spec) == birth_field_result::INVALID))
			{
				kits.add_error(i + 1, line);
			}
			continue;
		}

		/* Entry names */
		if (field == 'N')
		{
			auto name_after = [&](int colons) {
				std::size_t pos = 0;
				for (int c = 0; c < colons; c++)
				{
					pos = line.find(':', pos) + 1;
				}
				return line.substr(pos);
			};

			switch (section)
			{
			case 'R':
				race = &kits.races[name_after(3)];
				break;
			case 'S':
				subrace = &kits.subraces[name_after(3)];
				break;
			case 'C':
				class_name = name_after(4);
				klass = &kits.classes[class_name];
				spec = nullptr;
				break;
			}
			continue;
		}

		birth_field_result result = birth_field_result::NOT_HANDLED;

		switch (section)
		{
		case 'G':
			result = parse_general_birth_field(field, rest, &kits.general);
			break;
		case 'R':
			if (race) result = parse_birth_kit_field(field, rest, race);
			break;
		case 'S':
			if (subrace) result = parse_birth_kit_field(field, rest, subrace);
			break;
		case 'C':
			if (klass) result = parse_birth_kit_field(field, rest, klass);
			break;
		}

		if (result == birth_field_result::INVALID)
		{
			kits.add_error(i + 1, line);
		}
	}

	return kits;
}

/*
 * One line per starting object/exclusion, as in tests/data.
 */
std::vector<std::string> show(module_kits const &kits)
{
	std::vector<std::string> out;

	auto add = [&](std::string const &level, std::string const &name, birth_kit const &kit) {
		for (auto const &o : kit.objects)
		{
			out.push_back(level + "\t" + name + "\tO\t" + show(o));
		}
		for (auto const &x : kit.excluded)
		{
			out.push_back(level + "\t" + name + "\tX\t" + std::to_string(x.first) + ":" + std::to_string(x.second));
		}
		for (auto const &t : kit.tags)
		{
			out.push_back(level + "\t" + name + "\tT\t" + t);
		}
	};

	for (auto const &p : kits.general.objects)
	{
		out.push_back("G\t" + show(p.first) + "\tO\t" + show(p.second));
	}
	for (auto const &p : kits.races) add("R", p.first, p.second);
	for (auto const &p : kits.subraces) add("S", p.first, p.second);
	for (auto const &p : kits.classes) add("C", p.first, p.second);
	for (auto const &p : kits.specs) add("P", p.first, p.second);

	std::sort(out.begin(), out.end());
	return out;
}

std::vector<std::string> expected_kits(std::string const &module)
{
	std::vector<std::string> out;
	for (auto const &line : read_lines(source_path("tests/data/birth_kits_" + module + ".txt")))
	{
		if (!line.empty())
		{
			out.push_back(line);
		}
	}
	std::sort(out.begin(), out.end());
	return out;
}

/* "tval:sval" of every object kind in k_info.txt */
std::set<std::string> object_kinds(module_files const &m)
{
	std::set<std::string> kinds;
	for (auto const &line : read_lines(m.edit_file("k_info.txt")))
	{
		int tval, sval;
		if (2 == sscanf(line.c_str(), "I:%d:%d", &tval, &sval))
		{
			kinds.insert(std::to_string(tval) + ":" + std::to_string(sval));
		}
	}
	return kinds;
}

/* Index of every artifact in a_info.txt */
std::set<int> artifacts(module_files const &m)
{
	std::set<int> idxs;
	for (auto const &line : read_lines(m.edit_file("a_info.txt")))
	{
		int idx;
		if (1 == sscanf(line.c_str(), "N:%d:", &idx))
		{
			idxs.insert(idx);
		}
	}
	return idxs;
}

/* Every starting object of a module, whatever the level or filter */
std::vector<birth_object> all_objects(module_kits const &kits)
{
	std::vector<birth_object> out;
	for (auto const &p : kits.general.objects)
	{
		out.push_back(p.second);
	}
	for (auto const *levels : { &kits.races, &kits.subraces, &kits.classes, &kits.specs })
	{
		for (auto const &p : *levels)
		{
			out.insert(out.end(), p.second.objects.begin(), p.second.objects.end());
		}
	}
	return out;
}

std::vector<birth_object> kit_for(module_kits const &kits,
	std::string const &race, std::string const &subrace,
	std::string const &class_name, std::string const &spec)
{
	auto find = [](std::map<std::string, birth_kit> const &m, std::string const &key) -> birth_kit const * {
		auto it = m.find(key);
		AssertThat(it != m.end(), Is().True());
		return &it->second;
	};

	birth_character who;
	who.race = race;
	who.subrace = subrace;
	who.class_name = class_name;
	who.spec = spec;

	return assemble_birth_kit(kits.general, {
		find(kits.races, race),
		find(kits.subraces, subrace),
		find(kits.classes, class_name),
		find(kits.specs, class_name + "/" + spec) }, who);
}

std::vector<std::string> show(std::vector<birth_object> const &objects)
{
	std::vector<std::string> out;
	for (auto const &o : objects)
	{
		out.push_back(show(o));
	}
	std::sort(out.begin(), out.end());
	return out;
}

bool contains(std::vector<std::string> const &v, std::string const &s)
{
	return std::find(v.begin(), v.end(), s) != v.end();
}

}

go_bandit([]() {

	describe("birth kits in p_info.txt", []() {

		for (auto const &m : modules)
		{
			describe(m.name.c_str(), [m]() {

				module_kits kits;

				before_each([&]() {
					kits = read_module_kits(m);
				});

				it("parses every birth-kit line", [&]() {
					AssertThat(kits.errors, Equals(std::vector<std::string> {}));
				});

				it("gives the same starting objects as before", [&]() {
					AssertThat(show(kits), Equals(expected_kits(m.name)));
				});

				it("carries the starting objects, as before", [&]() {
					AssertThat(kits.general.wear, Is().False());
				});

				it("only names object kinds that exist, apart from known data bugs", [&]() {
					auto kinds = object_kinds(m);
					std::set<std::string> unknown;
					auto check = [&](birth_object const &o) {
						auto k = std::to_string(o.tval) + ":" + std::to_string(o.sval);
						if ((o.type == birth_object::kind::OBJECT) && !kinds.count(k))
						{
							unknown.insert(k);
						}
					};
					for (auto const &p : kits.general.objects) check(p.second);
					for (auto const *levels : { &kits.races, &kits.subraces, &kits.classes, &kits.specs })
					{
						for (auto const &p : *levels)
						{
							for (auto const &o : p.second.objects) check(o);
						}
					}
					AssertThat(unknown, Equals(m.known_missing_kinds));
				});

				it("only names artifacts that exist", [&]() {
					auto known = artifacts(m);
					std::vector<int> unknown;
					for (auto const *levels : { &kits.races, &kits.subraces, &kits.classes, &kits.specs })
					{
						for (auto const &p : *levels)
						{
							for (auto const &o : p.second.objects)
							{
								if ((o.type == birth_object::kind::ARTIFACT) && !known.count(o.artifact_idx))
								{
									unknown.push_back(o.artifact_idx);
								}
							}
						}
					}
					for (auto const &p : kits.general.objects)
					{
						if ((p.second.type == birth_object::kind::ARTIFACT) && !known.count(p.second.artifact_idx))
						{
							unknown.push_back(p.second.artifact_idx);
						}
					}
					AssertThat(unknown, Equals(std::vector<int> {}));
				});

				it("only gives mimic cloaks in forms that have a cloak name", [&]() {
					game_module_idx = m.rules;
					std::vector<std::string> bad;
					for (auto const &o : all_objects(kits))
					{
						if (o.form.empty()) continue;
						auto form = resolve_mimic_name(o.form.c_str());
						if ((form < 0) || !get_mimic_object_name(form))
						{
							bad.push_back(o.form);
						}
					}
					game_module_idx = MODULE_TOME;
					AssertThat(bad, Equals(std::vector<std::string> {}));
				});

			});
		}

		describe("complete characters", []() {

			it("ToME: a Human Warrior gets the general items and the warrior kit", [&]() {
				auto kits = read_module_kits(modules[0]);
				AssertThat(show(kit_for(kits, "Human", " ", "Warrior", "Warrior")),
					Equals(std::vector<std::string> {
						"23:16 x1d1", "37:4 x1d1", "39:0 x3-7 fuel=3-7*500",
						"45:38 x1d1", "80:35 x3-7", "8:20 x1" }));
			});

			it("ToME: a Ranger gets Phase Door", [&]() {
				auto kits = read_module_kits(modules[0]);
				AssertThat(contains(show(kit_for(kits, "Human", " ", "Archer", "Ranger")), "B:Phase Door"), Is().True());
			});

			it("Theme: a Ranger does not get Phase Door, and everyone gets Word of Recall", [&]() {
				auto kits = read_module_kits(modules[1]);
				auto kit = show(kit_for(kits, "Human", " ", "Archer", "Ranger"));
				AssertThat(contains(kit, "B:Phase Door"), Is().False());
				AssertThat(contains(kit, "70:11 x1"), Is().True());
			});

			it("Theme: a Red dragon gets Globe of Light", [&]() {
				auto kits = read_module_kits(modules[1]);
				AssertThat(contains(show(kit_for(kits, "Dragon", "Red", "Warrior", "Warrior")), "B:Globe of Light"), Is().True());
			});

		});

	});

});
