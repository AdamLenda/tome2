#include "birth_equip.hpp"

#include "inventory.hpp"

#include <algorithm>
#include <functional>

std::vector<equip_choice> plan_birth_equipment(
	std::vector<equip_candidate> const &candidates,
	std::map<int, int> const &slot_counts)
{
	/* Order of preference: artifacts, then value; stable for ties */
	std::vector<equip_candidate const *> ordered;
	for (auto const &c : candidates)
	{
		if ((c.slot >= 0) && !c.cursed)
		{
			ordered.push_back(&c);
		}
	}

	std::stable_sort(ordered.begin(), ordered.end(), [](equip_candidate const *a, equip_candidate const *b) {
		if (a->artifact != b->artifact) return a->artifact;
		return a->value > b->value;
	});

	std::vector<equip_choice> choices;

	/* Objects worn so far, per slot type, by position */
	std::map<int, std::vector<equip_candidate const *>> worn;

	auto capacity = [&slot_counts](int slot) {
		auto it = slot_counts.find(slot);
		return (it == slot_counts.end()) ? 0 : it->second;
	};

	auto wear = [&](equip_candidate const *c, int position, int number) {
		worn[c->slot].resize(std::max<std::size_t>(worn[c->slot].size(), position + 1), nullptr);
		worn[c->slot][position] = c;
		choices.push_back({ c->id, c->slot + position, number });
	};

	/* First free position of a slot type, or -1 */
	auto free_position = [&](int slot, std::function<bool(int)> const &allowed) {
		for (int position = 0; position < capacity(slot); position++)
		{
			auto const &w = worn[slot];
			bool taken = (position < static_cast<int>(w.size())) && w[position];
			if (!taken && allowed(position))
			{
				return position;
			}
		}
		return -1;
	};

	auto anywhere = [](int) { return true; };

	/* Everything but shields and ammunition */
	for (auto c : ordered)
	{
		if ((c->slot == INVEN_ARM) || (c->slot == INVEN_AMMO)) continue;

		int position = free_position(c->slot, anywhere);
		if (position >= 0)
		{
			wear(c, position, 1);
		}
	}

	/* Shields, on arms whose weapon is not (possibly) two-handed */
	for (auto c : ordered)
	{
		if (c->slot != INVEN_ARM) continue;

		int position = free_position(INVEN_ARM, [&worn](int k) {
			auto const &weapons = worn[INVEN_WIELD];
			if (k >= static_cast<int>(weapons.size()) || !weapons[k]) return true;
			return !(weapons[k]->must_two_hand || weapons[k]->could_two_hand);
		});

		if (position >= 0)
		{
			wear(c, position, 1);
		}
	}

	/* Ammunition, as a whole stack, if a worn launcher fires it */
	for (auto c : ordered)
	{
		if (c->slot != INVEN_AMMO) continue;

		auto const &launchers = worn[INVEN_BOW];
		bool fired = std::any_of(launchers.begin(), launchers.end(), [c](equip_candidate const *l) {
			return l && (c->ammo != 0) && (l->launches == c->ammo);
		});

		int position = fired ? free_position(INVEN_AMMO, anywhere) : -1;
		if (position >= 0)
		{
			wear(c, position, c->number);
		}
	}

	return choices;
}
