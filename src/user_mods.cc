#include "user_mods.hpp"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <sstream>

namespace fs = boost::filesystem;

namespace {

/* What the module menu has room for */
constexpr std::size_t MAX_NAME_LENGTH = 16;
constexpr std::size_t MAX_DESC_LINES = 4;
constexpr std::size_t MAX_DESC_LENGTH = 79;

mod_manifest_result failure(std::string const &error)
{
	mod_manifest_result result;
	result.error = error;
	return result;
}

std::string at_line(std::size_t line_no, std::string const &reason)
{
	return "line " + std::to_string(line_no) + ": " + reason;
}

/* A version number part: digits only, and not absurdly large */
boost::optional<int> parse_version_part(std::string const &s)
{
	if (s.empty() || (s.size() > 6) || !std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isdigit(c); }))
	{
		return boost::none;
	}

	return std::stoi(s);
}

bool parse_version(std::string const &s, mod_manifest *m)
{
	std::vector<std::string> parts;
	boost::algorithm::split(parts, s, [](char c) { return c == ':'; });

	if (parts.size() != 3)
	{
		return false;
	}

	auto major = parse_version_part(parts[0]);
	auto minor = parse_version_part(parts[1]);
	auto patch = parse_version_part(parts[2]);

	if (!major || !minor || !patch)
	{
		return false;
	}

	m->version_major = *major;
	m->version_minor = *minor;
	m->version_patch = *patch;
	return true;
}

bool contains_ignoring_case(std::vector<std::string> const &names, std::string const &name)
{
	return std::any_of(names.begin(), names.end(), [&name](std::string const &n) {
		return boost::algorithm::iequals(n, name);
	});
}

}

mod_manifest_result parse_mod_manifest(std::string const &text)
{
	mod_manifest m;
	bool have_name = false;
	bool have_base = false;
	bool have_version = false;
	bool have_author = false;
	std::size_t desc_lines = 0;

	std::istringstream in(text);
	std::string line;
	std::size_t line_no = 0;

	while (std::getline(in, line))
	{
		line_no++;

		if (!line.empty() && (line.back() == '\r'))
		{
			line.pop_back();
		}

		/* Blank lines and comments */
		if (boost::algorithm::trim_copy(line).empty() || (line[0] == '#'))
		{
			continue;
		}

		if ((line.size() < 2) || (line[1] != ':') || !std::isalpha(static_cast<unsigned char>(line[0])))
		{
			return failure(at_line(line_no, "expected <letter>:<value>"));
		}

		char field = line[0];
		auto value = boost::algorithm::trim_copy(line.substr(2));

		/* Fields that may appear once, with a value */
		auto once = [&](bool *seen) -> std::string {
			if (*seen)
			{
				return at_line(line_no, std::string("more than one ") + field + ": line");
			}
			*seen = true;
			if (value.empty())
			{
				return at_line(line_no, std::string("empty ") + field + ": line");
			}
			return "";
		};

		std::string error;

		switch (field)
		{
		case 'N':
			error = once(&have_name);
			if (error.empty() && (value.size() > MAX_NAME_LENGTH))
			{
				error = at_line(line_no, "name longer than 16 characters");
			}
			m.name = value;
			break;

		case 'B':
			error = once(&have_base);
			m.base = value;
			break;

		case 'V':
			error = once(&have_version);
			if (error.empty() && !parse_version(value, &m))
			{
				error = at_line(line_no, "version must be <major>:<minor>:<patch>");
			}
			break;

		case 'A':
			error = once(&have_author);
			if (error.empty())
			{
				auto colon = value.find(':');
				m.author_name = boost::algorithm::trim_copy(value.substr(0, colon));
				if (colon != std::string::npos)
				{
					m.author_email = boost::algorithm::trim_copy(value.substr(colon + 1));
				}
			}
			break;

		case 'D':
			if (++desc_lines > MAX_DESC_LINES)
			{
				error = at_line(line_no, "more than 4 description lines");
			}
			else if (value.size() > MAX_DESC_LENGTH)
			{
				error = at_line(line_no, "description line longer than 79 characters");
			}
			else
			{
				m.desc += ((desc_lines > 1) ? "\n" : "") + value;
			}
			break;

		case 'S':
			if (value.empty())
			{
				error = at_line(line_no, "empty S: line");
			}
			m.save_tags.push_back(value);
			break;

		default:
			error = at_line(line_no, std::string("unknown field '") + field + "'");
			break;
		}

		if (!error.empty())
		{
			return failure(error);
		}
	}

	if (!have_name)
	{
		return failure("no N: (name) line");
	}

	if (!have_base)
	{
		return failure("no B: (base module) line");
	}

	mod_manifest_result result;
	result.manifest = m;
	return result;
}

user_mods_found find_user_mods(
	std::string const &mods_dir,
	std::vector<std::string> const &bases,
	std::vector<std::string> const &taken)
{
	user_mods_found found;

	boost::system::error_code ec;
	if (!fs::is_directory(mods_dir, ec))
	{
		return found;
	}

	/* Every directory, in name order */
	std::vector<fs::path> dirs;
	for (fs::directory_iterator it(mods_dir, ec), end; !ec && (it != end); it.increment(ec))
	{
		if (fs::is_directory(it->path(), ec))
		{
			dirs.push_back(it->path());
		}
	}
	std::sort(dirs.begin(), dirs.end());

	/* Names and save tags in use: a module's saves must stay its own */
	std::vector<std::string> claimed(taken);

	for (auto const &dir : dirs)
	{
		auto dir_name = dir.filename().string();
		auto report = [&found, &dir_name](std::string const &reason) {
			found.errors.push_back(dir_name + ": " + reason);
		};

		/* Not a mod */
		auto manifest_path = dir / "module.txt";
		if (!fs::exists(manifest_path, ec))
		{
			continue;
		}

		std::ifstream in(manifest_path.string(), std::ios::binary);
		if (!fs::is_regular_file(manifest_path, ec) || !in)
		{
			report("cannot read module.txt");
			continue;
		}
		std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

		auto result = parse_mod_manifest(text);
		if (!result.manifest)
		{
			report(result.error);
			continue;
		}
		auto m = *result.manifest;

		auto base = std::find_if(bases.begin(), bases.end(), [&m](std::string const &b) {
			return boost::algorithm::iequals(b, m.base);
		});
		if (base == bases.end())
		{
			report("unknown base module '" + m.base + "'");
			continue;
		}
		m.base = *base;

		if (contains_ignoring_case(claimed, m.name))
		{
			report("the name '" + m.name + "' is already used");
			continue;
		}

		auto tag = std::find_if(m.save_tags.begin(), m.save_tags.end(), [&claimed](std::string const &t) {
			return contains_ignoring_case(claimed, t);
		});
		if (tag != m.save_tags.end())
		{
			report("the save tag '" + *tag + "' is already used");
			continue;
		}

		claimed.push_back(m.name);
		claimed.insert(claimed.end(), m.save_tags.begin(), m.save_tags.end());

		user_mod mod;
		mod.dir_name = dir_name;
		mod.path = dir.string();
		mod.manifest = m;
		found.mods.push_back(mod);
	}

	return found;
}

std::string choose_edit_file(const char *overlay_dir, const char *base_dir, std::string const &name)
{
	if (overlay_dir)
	{
		auto path = fs::path(overlay_dir) / name;

		boost::system::error_code ec;
		if (fs::is_regular_file(path, ec))
		{
			return path.string();
		}
	}

	return (fs::path(base_dir) / name).string();
}
