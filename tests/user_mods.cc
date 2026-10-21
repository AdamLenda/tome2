#include "user_mods.hpp"

#include <bandit/bandit.h>
#include <boost/filesystem.hpp>
#include <fstream>
#include <string>
using namespace bandit;

namespace fs = boost::filesystem;

//
// Helpers
//

namespace {

mod_manifest must_parse(std::string const &text)
{
	auto result = parse_mod_manifest(text);
	AssertThat(result.error, Equals(""));
	AssertThat(bool(result.manifest), Is().True());
	return result.manifest ? *result.manifest : mod_manifest();
}

std::string parse_error(std::string const &text)
{
	auto result = parse_mod_manifest(text);
	AssertThat(bool(result.manifest), Is().False());
	return result.error;
}

void write_file(fs::path const &path, std::string const &text)
{
	fs::create_directories(path.parent_path());
	std::ofstream out(path.string(), std::ios::binary);
	out << text;
}

// A scratch mods directory, removed afterwards
struct scratch_dir
{
	fs::path path = fs::temp_directory_path() / fs::unique_path("tome-mods-test-%%%%-%%%%-%%%%");

	scratch_dir()
	{
		fs::create_directories(path);
	}

	~scratch_dir()
	{
		boost::system::error_code ec;
		fs::remove_all(path, ec);
	}

	void add_mod(std::string const &dir, std::string const &module_txt)
	{
		write_file(path / dir / "module.txt", module_txt);
	}
};

std::vector<std::string> names(user_mods_found const &found)
{
	std::vector<std::string> out;
	for (auto const &m : found.mods)
	{
		out.push_back(m.manifest.name);
	}
	return out;
}

std::vector<std::string> const bases { "ToME", "Theme" };

}

//
// Tests
//

go_bandit([]() {

	describe("parse_mod_manifest", []() {

		it("reads a name and a base, with defaults for the rest", [&]() {
			auto m = must_parse("N:Adam's Mod\nB:ToME\n");
			AssertThat(m.name, Equals("Adam's Mod"));
			AssertThat(m.base, Equals("ToME"));
			AssertThat(m.version_major, Equals(1));
			AssertThat(m.version_minor, Equals(0));
			AssertThat(m.version_patch, Equals(0));
			AssertThat(m.author_name, Equals(""));
			AssertThat(m.author_email, Equals(""));
			AssertThat(m.desc, Equals(""));
			AssertThat(m.save_tags.size(), Equals(0u));
		});

		it("reads every field", [&]() {
			auto m = must_parse(
				"# Adam's Mod\n"
				"N:Adam's Mod\n"
				"B:ToME\n"
				"V:2:4:13\n"
				"A:Adam Lenda:adam@example.com\n"
				"D:The standard ToME game,\n"
				"D:with a few changes.\n"
				"S:ToME Plus\n"
				"S:Older Name\n");
			AssertThat(m.version_major, Equals(2));
			AssertThat(m.version_minor, Equals(4));
			AssertThat(m.version_patch, Equals(13));
			AssertThat(m.author_name, Equals("Adam Lenda"));
			AssertThat(m.author_email, Equals("adam@example.com"));
			AssertThat(m.desc, Equals("The standard ToME game,\nwith a few changes."));
			AssertThat(m.save_tags, Equals(std::vector<std::string> { "ToME Plus", "Older Name" }));
		});

		it("reads an author without an email address", [&]() {
			auto m = must_parse("N:x\nB:ToME\nA:Someone\n");
			AssertThat(m.author_name, Equals("Someone"));
			AssertThat(m.author_email, Equals(""));
		});

		it("ignores comments, blank lines and Windows line endings", [&]() {
			auto m = must_parse("\r\n# comment\r\n\r\nN:Mod\r\n   \r\nB:Theme\r\n");
			AssertThat(m.name, Equals("Mod"));
			AssertThat(m.base, Equals("Theme"));
		});

		it("trims spaces around values", [&]() {
			auto m = must_parse("N: Mod \nB: ToME\nS: Old \nD:  Indented text  \n");
			AssertThat(m.name, Equals("Mod"));
			AssertThat(m.base, Equals("ToME"));
			AssertThat(m.save_tags, Equals(std::vector<std::string> { "Old" }));
			AssertThat(m.desc, Equals("Indented text"));
		});

		it("accepts a file without a final newline", [&]() {
			AssertThat(must_parse("N:Mod\nB:ToME").base, Equals("ToME"));
		});

		it("requires a name and a base", [&]() {
			AssertThat(parse_error(""), Equals("no N: (name) line"));
			AssertThat(parse_error("B:ToME\n"), Equals("no N: (name) line"));
			AssertThat(parse_error("N:Mod\n"), Equals("no B: (base module) line"));
		});

		it("reports lines it does not understand", [&]() {
			AssertThat(parse_error("N:Mod\nB:ToME\nQ:what\n"), Equals("line 3: unknown field 'Q'"));
			AssertThat(parse_error("N:Mod\nnonsense\n"), Equals("line 2: expected <letter>:<value>"));
			AssertThat(parse_error("NN:Mod\n"), Equals("line 1: expected <letter>:<value>"));
		});

		it("reports repeated single fields", [&]() {
			AssertThat(parse_error("N:Mod\nN:Other\nB:ToME\n"), Equals("line 2: more than one N: line"));
			AssertThat(parse_error("N:Mod\nB:ToME\nB:Theme\n"), Equals("line 3: more than one B: line"));
			AssertThat(parse_error("N:Mod\nB:ToME\nV:1:0:0\nV:1:0:1\n"), Equals("line 4: more than one V: line"));
			AssertThat(parse_error("N:Mod\nB:ToME\nA:a\nA:b\n"), Equals("line 4: more than one A: line"));
		});

		it("reports empty values", [&]() {
			AssertThat(parse_error("N:\nB:ToME\n"), Equals("line 1: empty N: line"));
			AssertThat(parse_error("N:Mod\nB:  \n"), Equals("line 2: empty B: line"));
			AssertThat(parse_error("N:Mod\nB:ToME\nS:\n"), Equals("line 3: empty S: line"));
			AssertThat(parse_error("N:Mod\nB:ToME\nA:\n"), Equals("line 3: empty A: line"));
		});

		it("keeps empty description lines", [&]() {
			AssertThat(must_parse("N:Mod\nB:ToME\nD:First\nD:\nD:Third\n").desc, Equals("First\n\nThird"));
		});

		it("reports bad versions", [&]() {
			for (auto v : { "V:1", "V:1:2", "V:1:2:3:4", "V:a:b:c", "V:1:-2:3", "V:1::3", "V:1:2:3x", "V:99999999999:0:0" })
			{
				AssertThat(parse_error(std::string("N:Mod\nB:ToME\n") + v + "\n"),
					Equals("line 3: version must be <major>:<minor>:<patch>"));
			}
		});

		it("limits names to what the module menu can show", [&]() {
			AssertThat(must_parse("N:0123456789abcdef\nB:ToME\n").name, Equals("0123456789abcdef"));
			AssertThat(parse_error("N:0123456789abcdefg\nB:ToME\n"), Equals("line 1: name longer than 16 characters"));
		});

		it("limits descriptions to what the module menu can show", [&]() {
			std::string line79(79, 'x');
			AssertThat(must_parse("N:Mod\nB:ToME\nD:" + line79 + "\n").desc, Equals(line79));
			AssertThat(parse_error("N:Mod\nB:ToME\nD:" + line79 + "y\n"), Equals("line 3: description line longer than 79 characters"));
			AssertThat(parse_error("N:Mod\nB:ToME\nD:1\nD:2\nD:3\nD:4\nD:5\n"), Equals("line 7: more than 4 description lines"));
		});

	});

	describe("find_user_mods", []() {

		it("finds nothing in a directory that does not exist", [&]() {
			scratch_dir dir;
			auto found = find_user_mods((dir.path / "missing").string(), bases, { "ToME", "Theme" });
			AssertThat(found.mods.size(), Equals(0u));
			AssertThat(found.errors.size(), Equals(0u));
		});

		it("finds mods in directory-name order", [&]() {
			scratch_dir dir;
			dir.add_mod("zeta", "N:Last\nB:ToME\n");
			dir.add_mod("alpha", "N:First\nB:Theme\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(names(found), Equals(std::vector<std::string> { "First", "Last" }));
			AssertThat(found.mods[0].dir_name, Equals("alpha"));
			AssertThat(found.mods[0].path, Equals((dir.path / "alpha").string()));
			AssertThat(found.errors.size(), Equals(0u));
		});

		it("skips directories without a module.txt and plain files", [&]() {
			scratch_dir dir;
			dir.add_mod("mod", "N:Mod\nB:ToME\n");
			fs::create_directories(dir.path / "not-a-mod" / "edit");
			write_file(dir.path / "README.txt", "N:Fake\nB:ToME\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(names(found), Equals(std::vector<std::string> { "Mod" }));
			AssertThat(found.errors.size(), Equals(0u));
		});

		it("reports mods whose module.txt has errors, and keeps the others", [&]() {
			scratch_dir dir;
			dir.add_mod("broken", "N:Broken\n");
			dir.add_mod("good", "N:Good\nB:ToME\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(names(found), Equals(std::vector<std::string> { "Good" }));
			AssertThat(found.errors, Equals(std::vector<std::string> { "broken: no B: (base module) line" }));
		});

		it("names the base module as the game spells it", [&]() {
			scratch_dir dir;
			dir.add_mod("mod", "N:Mod\nB:theme\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(found.mods.size(), Equals(1u));
			AssertThat(found.mods[0].manifest.base, Equals("Theme"));
		});

		it("reports unknown base modules", [&]() {
			scratch_dir dir;
			dir.add_mod("mod", "N:Mod\nB:Zangband\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(found.mods.size(), Equals(0u));
			AssertThat(found.errors, Equals(std::vector<std::string> { "mod: unknown base module 'Zangband'" }));
		});

		it("reports names already in use, ignoring case", [&]() {
			scratch_dir dir;
			dir.add_mod("a", "N:Mod\nB:ToME\n");
			dir.add_mod("b", "N:MOD\nB:ToME\n");
			dir.add_mod("c", "N:theme\nB:ToME\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(names(found), Equals(std::vector<std::string> { "Mod" }));
			AssertThat(found.errors, Equals(std::vector<std::string> {
				"b: the name 'MOD' is already used",
				"c: the name 'theme' is already used" }));
		});

		it("reports save tags that are another module's name, so its saves can't be taken over", [&]() {
			scratch_dir dir;
			dir.add_mod("a", "N:Mod\nB:ToME\nS:tome\n");
			dir.add_mod("b", "N:Other\nB:ToME\nS:Old Name\n");
			dir.add_mod("c", "N:Old name\nB:ToME\n");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(names(found), Equals(std::vector<std::string> { "Other" }));
			AssertThat(found.errors, Equals(std::vector<std::string> {
				"a: the save tag 'tome' is already used",
				"c: the name 'Old name' is already used" }));
		});

		it("reports a module.txt that cannot be read", [&]() {
			scratch_dir dir;
			fs::create_directories(dir.path / "odd" / "module.txt");
			auto found = find_user_mods(dir.path.string(), bases, { "ToME", "Theme" });
			AssertThat(found.mods.size(), Equals(0u));
			AssertThat(found.errors, Equals(std::vector<std::string> { "odd: cannot read module.txt" }));
		});

	});

	describe("choose_edit_file", []() {

		it("reads from the base directory without an overlay", [&]() {
			scratch_dir dir;
			auto base = (dir.path / "base").string();
			AssertThat(choose_edit_file(nullptr, base.c_str(), "p_info.txt"), Equals((fs::path(base) / "p_info.txt").string()));
		});

		it("prefers the overlay's file", [&]() {
			scratch_dir dir;
			write_file(dir.path / "overlay" / "p_info.txt", "x");
			write_file(dir.path / "base" / "p_info.txt", "x");
			auto overlay = (dir.path / "overlay").string();
			auto base = (dir.path / "base").string();
			AssertThat(choose_edit_file(overlay.c_str(), base.c_str(), "p_info.txt"), Equals((dir.path / "overlay" / "p_info.txt").string()));
		});

		it("falls back to the base directory for files the overlay lacks", [&]() {
			scratch_dir dir;
			write_file(dir.path / "overlay" / "p_info.txt", "x");
			auto overlay = (dir.path / "overlay").string();
			auto base = (dir.path / "base").string();
			AssertThat(choose_edit_file(overlay.c_str(), base.c_str(), "k_info.txt"), Equals((dir.path / "base" / "k_info.txt").string()));
		});

	});

});
