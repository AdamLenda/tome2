#include "birth_kit.hpp"
#include <bandit/bandit.h>
using namespace bandit;

//
// Helpers
//

namespace {

birth_amount must_parse_amount(std::string const &s)
{
	auto a = parse_birth_amount(s);
	AssertThat(bool(a), Is().True());
	return *a;
}

birth_object must_parse_object(std::string const &s)
{
	auto o = parse_birth_object(s);
	AssertThat(bool(o), Is().True());
	return *o;
}

birth_filter must_parse_filter(std::string const &s)
{
	auto f = parse_birth_filter(s);
	AssertThat(bool(f), Is().True());
	return *f;
}

void must_parse_kit(birth_kit *kit, char field, std::string const &rest)
{
	AssertThat(parse_birth_kit_field(field, rest, kit) == birth_field_result::OK, Is().True());
}

void must_parse_general(general_birth_kit *kit, char field, std::string const &rest)
{
	AssertThat(parse_general_birth_field(field, rest, kit) == birth_field_result::OK, Is().True());
}

// Short description of an object, for comparing whole kits
std::string show(birth_object const &o)
{
	switch (o.type)
	{
	case birth_object::kind::ARTIFACT:
		return "A" + std::to_string(o.artifact_idx);
	case birth_object::kind::SPELLBOOK:
		return "B" + o.spell;
	case birth_object::kind::OBJECT:
		break;
	}
	return std::to_string(o.tval) + ":" + std::to_string(o.sval);
}

std::vector<std::string> show(std::vector<birth_object> const &os)
{
	std::vector<std::string> out;
	for (auto const &o : os)
	{
		out.push_back(show(o));
	}
	return out;
}

birth_character character(std::string race, std::string subrace, std::string class_name, std::string spec)
{
	birth_character who;
	who.race = race;
	who.subrace = subrace;
	who.class_name = class_name;
	who.spec = spec;
	return who;
}

}

//
// Tests
//

go_bandit([]() {

	describe("parse_birth_amount", []() {

		it("parses a fixed number", [&]() {
			auto a = parse_birth_amount("5");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(5));
			AssertThat(a->max(), Equals(5));
		});

		it("parses zero", [&]() {
			auto a = parse_birth_amount("0");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(0));
			AssertThat(a->max(), Equals(0));
		});

		it("parses a range", [&]() {
			auto a = parse_birth_amount("3-7");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(3));
			AssertThat(a->max(), Equals(7));
		});

		it("parses a single-value range", [&]() {
			auto a = parse_birth_amount("4-4");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(4));
			AssertThat(a->max(), Equals(4));
		});

		it("parses dice", [&]() {
			auto a = parse_birth_amount("2d3");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(2));
			AssertThat(a->max(), Equals(6));
		});

		it("parses a multiplier on a range", [&]() {
			auto a = parse_birth_amount("3-7*500");
			AssertThat(bool(a), Is().True());
			AssertThat(a->min(), Equals(1500));
			AssertThat(a->max(), Equals(3500));
		});

		it("parses a multiplier on dice and on a fixed number", [&]() {
			AssertThat(must_parse_amount("1d4*10").max(), Equals(40));
			AssertThat(must_parse_amount("6*100").min(), Equals(600));
		});

		it("rejects malformed numbers", [&]() {
			for (auto s : { "", "x", "-3", "3-", "-", "7-3", "d6", "2d", "0d6", "2d0",
			                "3-7*", "3-7*0", "3*-2", "1.5", "3 - 7", "2d3d4", "3-7-9", "+4" })
			{
				AssertThat(bool(parse_birth_amount(s)), Is().False());
			}
		});

		it("rolls fixed numbers exactly", [&]() {
			auto a = must_parse_amount("6*100");
			for (int i = 0; i < 20; i++)
			{
				AssertThat(a.roll(), Equals(600));
			}
		});

		it("rolls ranges within bounds, reaching both ends", [&]() {
			auto a = must_parse_amount("3-7*500");
			std::set<int> seen;
			for (int i = 0; i < 2000; i++)
			{
				int v = a.roll();
				AssertThat(v, Is().GreaterThanOrEqualTo(1500).And().LessThanOrEqualTo(3500));
				AssertThat(v % 500, Equals(0));
				seen.insert(v);
			}
			AssertThat(seen.size(), Equals(5u));
		});

		it("rolls dice within bounds, reaching both ends", [&]() {
			auto a = must_parse_amount("2d3");
			std::set<int> seen;
			for (int i = 0; i < 2000; i++)
			{
				int v = a.roll();
				AssertThat(v, Is().GreaterThanOrEqualTo(2).And().LessThanOrEqualTo(6));
				seen.insert(v);
			}
			AssertThat(seen.size(), Equals(5u));
		});

	});

	describe("parse_birth_object", []() {

		it("parses tval:sval:dice (existing format)", [&]() {
			auto o = must_parse_object("70:32:2d3");
			AssertThat(o.type == birth_object::kind::OBJECT, Is().True());
			AssertThat(o.tval, Equals(70));
			AssertThat(o.sval, Equals(32));
			AssertThat(o.pval, Equals(0));
			AssertThat(o.number.min(), Equals(2));
			AssertThat(o.number.max(), Equals(6));
			AssertThat(bool(o.fuel), Is().False());
			AssertThat(o.form, Equals(""));
		});

		it("parses tval:sval:pval:dice (existing format)", [&]() {
			auto o = must_parse_object("45:38:5:1d1");
			AssertThat(o.tval, Equals(45));
			AssertThat(o.sval, Equals(38));
			AssertThat(o.pval, Equals(5));
			AssertThat(o.number.min(), Equals(1));
			AssertThat(o.number.max(), Equals(1));
		});

		it("parses a negative pval", [&]() {
			AssertThat(must_parse_object("45:38:-2:1d1").pval, Equals(-2));
		});

		it("parses a quantity range and a fixed quantity", [&]() {
			auto o = must_parse_object("80:35:3-7");
			AssertThat(o.number.min(), Equals(3));
			AssertThat(o.number.max(), Equals(7));
			AssertThat(must_parse_object("8:20:1").number.max(), Equals(1));
		});

		it("parses fuel", [&]() {
			auto o = must_parse_object("39:0:3-7:fuel=3-7*500");
			AssertThat(o.tval, Equals(39));
			AssertThat(o.sval, Equals(0));
			AssertThat(o.pval, Equals(0));
			AssertThat(bool(o.fuel), Is().True());
			AssertThat(o.fuel->min(), Equals(1500));
			AssertThat(o.fuel->max(), Equals(3500));
		});

		it("parses form", [&]() {
			auto o = must_parse_object("35:100:1:form=Mouse");
			AssertThat(o.tval, Equals(35));
			AssertThat(o.sval, Equals(100));
			AssertThat(o.form, Equals("Mouse"));
		});

		it("parses a form name containing spaces", [&]() {
			AssertThat(must_parse_object("35:100:1:form=Cave spider").form, Equals("Cave spider"));
		});

		it("parses pval together with keys", [&]() {
			auto o = must_parse_object("39:0:2:1d1:fuel=100:form=Mouse");
			AssertThat(o.pval, Equals(2));
			AssertThat(bool(o.fuel), Is().True());
			AssertThat(o.fuel->max(), Equals(100));
			AssertThat(o.form, Equals("Mouse"));
		});

		it("parses an artifact", [&]() {
			auto o = must_parse_object("A:202");
			AssertThat(o.type == birth_object::kind::ARTIFACT, Is().True());
			AssertThat(o.artifact_idx, Equals(202));
		});

		it("parses a single-spell book", [&]() {
			auto o = must_parse_object("B:Phase Door");
			AssertThat(o.type == birth_object::kind::SPELLBOOK, Is().True());
			AssertThat(o.spell, Equals("Phase Door"));
			AssertThat(o.tval, Equals(111));
			AssertThat(o.sval, Equals(255));
			AssertThat(o.number.max(), Equals(1));
		});

		it("keeps punctuation in spell names", [&]() {
			AssertThat(must_parse_object("B:Manwe's Blessing").spell, Equals("Manwe's Blessing"));
		});

		it("ignores trailing whitespace", [&]() {
			AssertThat(must_parse_object("70:32:2d3  \r").number.max(), Equals(6));
			AssertThat(must_parse_object("A:7 ").artifact_idx, Equals(7));
			AssertThat(must_parse_object("B:Geyser\r").spell, Equals("Geyser"));
		});

		it("rejects malformed objects", [&]() {
			for (auto s : {
				"", "70", "70:32", "70:x:1", "x:32:1", "70:32:0", "70:32:0d1",
				"70:32:1:2:3", "70:32:99d2", "70:32:100", "70:32:1:fuel=", "70:32:1:fuel=x",
				"70:32:1:form=", "70:32:1:colour=red", "70:32:1:=5", "70:32:fuel=5",
				"A:", "A:0", "A:-3", "A:x", "A:1:2", "B:", "B: ", "Q:1" })
			{
				AssertThat(bool(parse_birth_object(s)), Is().False());
			}
		});

		it("accepts the largest stack", [&]() {
			AssertThat(must_parse_object("70:32:99").number.max(), Equals(99));
			AssertThat(must_parse_object("70:32:33d3").number.max(), Equals(99));
		});

	});

	describe("parse_birth_filter", []() {

		it("parses '*'", [&]() {
			AssertThat(must_parse_filter("*").type == birth_filter::kind::ANY, Is().True());
		});

		it("parses each kind with a single name", [&]() {
			AssertThat(must_parse_filter("RACE:Maia").type == birth_filter::kind::RACE, Is().True());
			AssertThat(must_parse_filter("SUBRACE:Red").type == birth_filter::kind::SUBRACE, Is().True());
			AssertThat(must_parse_filter("CLASS:Mage").type == birth_filter::kind::CLASS, Is().True());
			AssertThat(must_parse_filter("SPEC:Priest(Eru)").type == birth_filter::kind::SPEC, Is().True());
			AssertThat(must_parse_filter("TAG:spellcaster").type == birth_filter::kind::TAG, Is().True());
			AssertThat(must_parse_filter("SPEC:Priest(Eru)").names, Equals(std::vector<std::string> { "Priest(Eru)" }));
		});

		it("splits names on '|'", [&]() {
			AssertThat(must_parse_filter("SPEC:Ranger|Geomancer|Dark-Priest").names,
				Equals(std::vector<std::string> { "Ranger", "Geomancer", "Dark-Priest" }));
		});

		it("ignores trailing whitespace", [&]() {
			AssertThat(must_parse_filter("TAG:spellcaster \r").names, Equals(std::vector<std::string> { "spellcaster" }));
			AssertThat(must_parse_filter("* ").type == birth_filter::kind::ANY, Is().True());
		});

		it("rejects malformed filters", [&]() {
			for (auto s : { "", "RACE", "RACE:", "RACE:Maia|", "RACE:|Maia", "RACE:Maia||Elf",
			                "GOD:Eru", "race:Maia", "*:Maia", "**" })
			{
				AssertThat(bool(parse_birth_filter(s)), Is().False());
			}
		});

	});

	describe("birth_filter_matches", []() {

		auto who = character("Maia", "Classical", "Mage", "Geomancer");
		who.tags = { "spellcaster", "immortal" };

		it("'*' matches everyone", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("*"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("*"), birth_character()), Is().True());
		});

		it("matches each kind against its own field only", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("RACE:Maia"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("SUBRACE:Classical"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("CLASS:Mage"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("SPEC:Geomancer"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("RACE:Mage"), who), Is().False());
			AssertThat(birth_filter_matches(must_parse_filter("CLASS:Maia"), who), Is().False());
			AssertThat(birth_filter_matches(must_parse_filter("SPEC:Mage"), who), Is().False());
			AssertThat(birth_filter_matches(must_parse_filter("SUBRACE:Maia"), who), Is().False());
		});

		it("matches any of several names", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("RACE:Elf|Maia|Human"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("RACE:Elf|Human"), who), Is().False());
		});

		it("matches names ignoring case", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("RACE:maia"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("SPEC:GEOMANCER"), who), Is().True());
		});

		it("does not match partial names", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("RACE:Mai"), who), Is().False());
			AssertThat(birth_filter_matches(must_parse_filter("SPEC:Geomancers"), who), Is().False());
		});

		it("matches tags", [&]() {
			AssertThat(birth_filter_matches(must_parse_filter("TAG:spellcaster"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("TAG:Immortal"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("TAG:archer|immortal"), who), Is().True());
			AssertThat(birth_filter_matches(must_parse_filter("TAG:archer"), who), Is().False());
		});

	});

	describe("parse_birth_kit_field", []() {

		it("adds objects for 'O'", [&]() {
			birth_kit kit;
			must_parse_kit(&kit, 'O', "70:32:2d3");
			must_parse_kit(&kit, 'O', "A:202");
			must_parse_kit(&kit, 'O', "B:Geyser");
			AssertThat(show(kit.objects), Equals(std::vector<std::string> { "70:32", "A202", "BGeyser" }));
		});

		it("adds exclusions for 'X'", [&]() {
			birth_kit kit;
			must_parse_kit(&kit, 'X', "39:0");
			must_parse_kit(&kit, 'X', "8:20 ");
			AssertThat(kit.excluded, Equals(std::vector<std::pair<int, int>> { { 39, 0 }, { 8, 20 } }));
		});

		it("adds tags for 'T'", [&]() {
			birth_kit kit;
			must_parse_kit(&kit, 'T', "spellcaster");
			must_parse_kit(&kit, 'T', "immortal\r");
			AssertThat(kit.tags, Equals(std::vector<std::string> { "spellcaster", "immortal" }));
		});

		it("reports errors without changing the kit", [&]() {
			birth_kit kit;
			for (auto p : std::vector<std::pair<char, std::string>> {
				{ 'O', "70:32" }, { 'O', "" }, { 'X', "39" }, { 'X', "39:x" }, { 'X', "39:0:1" },
				{ 'X', "" }, { 'T', "" }, { 'T', " " }, { 'T', "two words" }, { 'T', "a|b" } })
			{
				AssertThat(parse_birth_kit_field(p.first, p.second, &kit) == birth_field_result::ERROR, Is().True());
			}
			AssertThat(kit.objects.size(), Equals(0u));
			AssertThat(kit.excluded.size(), Equals(0u));
			AssertThat(kit.tags.size(), Equals(0u));
		});

		it("leaves other fields alone", [&]() {
			birth_kit kit;
			for (auto f : { 'A', 'N', 'D', 'k', 'W', 'G', 'a' })
			{
				AssertThat(parse_birth_kit_field(f, "anything", &kit) == birth_field_result::NOT_HANDLED, Is().True());
			}
		});

	});

	describe("parse_general_birth_field", []() {

		it("applies '*' until the first 'W'", [&]() {
			general_birth_kit kit;
			must_parse_general(&kit, 'O', "8:20:1");
			AssertThat(kit.objects.size(), Equals(1u));
			AssertThat(kit.objects[0].first.type == birth_filter::kind::ANY, Is().True());
		});

		it("applies each 'W' to the objects that follow it", [&]() {
			general_birth_kit kit;
			must_parse_general(&kit, 'O', "8:20:1");
			must_parse_general(&kit, 'W', "TAG:spellcaster");
			must_parse_general(&kit, 'O', "111:0:1");
			must_parse_general(&kit, 'O', "111:1:1");
			must_parse_general(&kit, 'W', "*");
			must_parse_general(&kit, 'O', "70:11:1");
			AssertThat(kit.objects.size(), Equals(4u));
			AssertThat(kit.objects[0].first.type == birth_filter::kind::ANY, Is().True());
			AssertThat(kit.objects[1].first.type == birth_filter::kind::TAG, Is().True());
			AssertThat(kit.objects[2].first.type == birth_filter::kind::TAG, Is().True());
			AssertThat(kit.objects[3].first.type == birth_filter::kind::ANY, Is().True());
		});

		it("reports errors", [&]() {
			general_birth_kit kit;
			AssertThat(parse_general_birth_field('O', "70", &kit) == birth_field_result::ERROR, Is().True());
			AssertThat(parse_general_birth_field('W', "GOD:Eru", &kit) == birth_field_result::ERROR, Is().True());
			AssertThat(kit.objects.size(), Equals(0u));
			AssertThat(kit.current_filter.type == birth_filter::kind::ANY, Is().True());
		});

		it("leaves other fields alone, including race-level ones", [&]() {
			general_birth_kit kit;
			for (auto f : { 'k', 'X', 'T', 'N' })
			{
				AssertThat(parse_general_birth_field(f, "anything", &kit) == birth_field_result::NOT_HANDLED, Is().True());
			}
		});

	});

	describe("birth_kit_tags", []() {

		it("collects tags from every level, skipping missing levels", [&]() {
			birth_kit race, spec;
			race.tags = { "immortal" };
			spec.tags = { "spellcaster", "immortal" };
			AssertThat(birth_kit_tags({ &race, nullptr, &spec }),
				Equals(std::set<std::string> { "immortal", "spellcaster" }));
		});

		it("stores tags in lower case", [&]() {
			birth_kit race;
			race.tags = { "SpellCaster" };
			AssertThat(birth_kit_tags({ &race }), Equals(std::set<std::string> { "spellcaster" }));
		});

	});

	describe("assemble_birth_kit", []() {

		general_birth_kit general;
		birth_kit race, subrace, class_kit, spec;

		before_each([&]() {
			general = general_birth_kit();
			race = subrace = class_kit = spec = birth_kit();
		});

		auto levels = [&]() {
			return std::vector<birth_kit const *> { &race, &subrace, &class_kit, &spec };
		};
		auto who = character("Maia", "Classical", "Mage", "Geomancer");

		it("is empty when nothing is configured", [&]() {
			AssertThat(assemble_birth_kit(general, levels(), who).size(), Equals(0u));
		});

		it("gives general objects first, then race, subrace, class and specialty", [&]() {
			must_parse_kit(&spec, 'O', "4:4:1");
			must_parse_kit(&class_kit, 'O', "3:3:1");
			must_parse_kit(&subrace, 'O', "2:2:1");
			must_parse_kit(&race, 'O', "1:1:1");
			must_parse_general(&general, 'O', "9:9:1");
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "9:9", "1:1", "2:2", "3:3", "4:4" }));
		});

		it("gives only matching general objects, in file order", [&]() {
			must_parse_general(&general, 'O', "1:1:1");
			must_parse_general(&general, 'W', "RACE:Elf");
			must_parse_general(&general, 'O', "2:2:1");
			must_parse_general(&general, 'W', "SPEC:Geomancer|Druid");
			must_parse_general(&general, 'O', "3:3:1");
			must_parse_general(&general, 'W', "*");
			must_parse_general(&general, 'O', "4:4:1");
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "1:1", "3:3", "4:4" }));
		});

		it("matches general objects on tags from any level", [&]() {
			must_parse_general(&general, 'W', "TAG:spellcaster");
			must_parse_general(&general, 'O', "111:0:1");
			AssertThat(assemble_birth_kit(general, levels(), who).size(), Equals(0u));

			for (auto level : { &race, &subrace, &class_kit, &spec })
			{
				race = subrace = class_kit = spec = birth_kit();
				must_parse_kit(level, 'T', "spellcaster");
				AssertThat(show(assemble_birth_kit(general, levels(), who)),
					Equals(std::vector<std::string> { "111:0" }));
			}
		});

		it("keeps tags already given in 'who'", [&]() {
			must_parse_general(&general, 'W', "TAG:chosen");
			must_parse_general(&general, 'O', "1:1:1");
			auto tagged = who;
			tagged.tags = { "chosen" };
			AssertThat(assemble_birth_kit(general, levels(), tagged).size(), Equals(1u));
		});

		it("lets any level exclude objects from every level", [&]() {
			must_parse_general(&general, 'O', "39:0:3-7");
			must_parse_kit(&race, 'O', "39:0:1");
			must_parse_kit(&class_kit, 'O', "39:0:1");
			must_parse_kit(&spec, 'O', "23:4:1");
			must_parse_kit(&spec, 'O', "39:1:1");

			for (auto level : { &race, &subrace, &class_kit, &spec })
			{
				level->excluded.clear();
			}
			spec.excluded = { { 39, 0 } };
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "23:4", "39:1" }));

			spec.excluded.clear();
			race.excluded = { { 39, 0 }, { 23, 4 } };
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "39:1" }));
		});

		it("excludes single-spell books by TV_BOOK:BOOK_RANDOM", [&]() {
			must_parse_kit(&spec, 'O', "B:Geyser");
			must_parse_kit(&spec, 'O', "111:50:1");
			race.excluded = { { 111, 255 } };
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "111:50" }));
		});

		it("never excludes artifacts", [&]() {
			must_parse_kit(&race, 'O', "A:1");
			race.excluded = { { 39, 100 }, { 0, 0 } };
			AssertThat(show(assemble_birth_kit(general, levels(), who)),
				Equals(std::vector<std::string> { "A1" }));
		});

		it("skips missing levels", [&]() {
			must_parse_kit(&race, 'O', "1:1:1");
			must_parse_kit(&spec, 'O', "4:4:1");
			AssertThat(show(assemble_birth_kit(general, { &race, nullptr, nullptr, &spec }, who)),
				Equals(std::vector<std::string> { "1:1", "4:4" }));
		});

		it("keeps every field of the objects it returns", [&]() {
			must_parse_kit(&spec, 'O', "35:100:2:1d1:fuel=3-7*500:form=Mouse");
			auto kit = assemble_birth_kit(general, levels(), who);
			AssertThat(kit.size(), Equals(1u));
			AssertThat(kit[0].pval, Equals(2));
			AssertThat(bool(kit[0].fuel), Is().True());
			AssertThat(kit[0].fuel->max(), Equals(3500));
			AssertThat(kit[0].form, Equals("Mouse"));
		});

	});

});
