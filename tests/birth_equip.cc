#include "birth_equip.hpp"
#include "inventory.hpp"
#include <bandit/bandit.h>
#include <string>
using namespace bandit;

//
// Helpers
//

namespace {

// Ammunition kinds, as the caller maps them
constexpr int SHOT = 1;
constexpr int ARROW = 2;

equip_candidate item(int id, int slot)
{
	equip_candidate c;
	c.id = id;
	c.slot = slot;
	return c;
}

equip_candidate artifact(int id, int slot)
{
	auto c = item(id, slot);
	c.artifact = true;
	return c;
}

equip_candidate valued(int id, int slot, long value)
{
	auto c = item(id, slot);
	c.value = value;
	return c;
}

equip_candidate stack(int id, int slot, int number)
{
	auto c = item(id, slot);
	c.number = number;
	return c;
}

// A humanoid body: what calc_body() gives a plain Human
std::map<int, int> human_body()
{
	return {
		{ INVEN_WIELD, 1 }, { INVEN_BOW, 1 }, { INVEN_RING, 2 }, { INVEN_NECK, 1 },
		{ INVEN_LITE, 1 }, { INVEN_BODY, 1 }, { INVEN_OUTER, 1 }, { INVEN_ARM, 1 },
		{ INVEN_HEAD, 1 }, { INVEN_HANDS, 1 }, { INVEN_FEET, 1 }, { INVEN_CARRY, 1 },
		{ INVEN_AMMO, 1 }, { INVEN_TOOL, 1 },
	};
}

// "id@slot xN" for each choice, for comparing whole plans
std::vector<std::string> show(std::vector<equip_choice> const &choices)
{
	std::vector<std::string> out;
	for (auto const &c : choices)
	{
		out.push_back(std::to_string(c.id) + "@" + std::to_string(c.slot) + " x" + std::to_string(c.number));
	}
	return out;
}

std::string at(int id, int slot, int number = 1)
{
	return std::to_string(id) + "@" + std::to_string(slot) + " x" + std::to_string(number);
}

}

//
// Tests
//

go_bandit([]() {

	describe("plan_birth_equipment", []() {

		it("puts on nothing when there is nothing", [&]() {
			AssertThat(plan_birth_equipment({}, human_body()).size(), Equals(0u));
		});

		it("leaves objects that cannot be worn in the pack", [&]() {
			AssertThat(plan_birth_equipment({ item(0, -1), stack(1, -1, 5) }, human_body()).size(), Equals(0u));
		});

		it("never puts on cursed objects", [&]() {
			auto ring = item(0, INVEN_RING);
			ring.cursed = true;
			AssertThat(plan_birth_equipment({ ring }, human_body()).size(), Equals(0u));
		});

		it("puts a weapon in the first weapon slot", [&]() {
			AssertThat(show(plan_birth_equipment({ item(3, INVEN_WIELD) }, human_body())),
				Equals(std::vector<std::string> { at(3, INVEN_WIELD) }));
		});

		it("puts on a warrior's starting kit and leaves the rest", [&]() {
			// food, ring, torches, chain mail, sword, guide
			auto plan = plan_birth_equipment({
				stack(0, -1, 5),
				item(1, INVEN_RING),
				stack(2, INVEN_LITE, 6),
				item(3, INVEN_BODY),
				item(4, INVEN_WIELD),
				item(5, -1),
			}, human_body());
			AssertThat(show(plan), Equals(std::vector<std::string> {
				at(1, INVEN_RING), at(2, INVEN_LITE), at(3, INVEN_BODY), at(4, INVEN_WIELD) }));
		});

		it("puts one object of a stack on, such as one torch", [&]() {
			AssertThat(show(plan_birth_equipment({ stack(0, INVEN_LITE, 6) }, human_body())),
				Equals(std::vector<std::string> { at(0, INVEN_LITE, 1) }));
		});

		it("fills every slot of a type, in order", [&]() {
			AssertThat(show(plan_birth_equipment({ item(0, INVEN_RING), item(1, INVEN_RING) }, human_body())),
				Equals(std::vector<std::string> { at(0, INVEN_RING), at(1, INVEN_RING + 1) }));
		});

		it("does not overfill a slot type", [&]() {
			auto plan = plan_birth_equipment({ item(0, INVEN_RING), item(1, INVEN_RING), item(2, INVEN_RING) }, human_body());
			AssertThat(show(plan), Equals(std::vector<std::string> { at(0, INVEN_RING), at(1, INVEN_RING + 1) }));
		});

		it("leaves objects for slots the body lacks in the pack", [&]() {
			auto no_weapons = human_body();
			no_weapons.erase(INVEN_WIELD);
			no_weapons[INVEN_FEET] = 0;
			AssertThat(plan_birth_equipment({ item(0, INVEN_WIELD), item(1, INVEN_FEET) }, no_weapons).size(), Equals(0u));
		});

		it("uses extra slots of bodies that have them", [&]() {
			auto body = human_body();
			body[INVEN_WIELD] = 2;
			body[INVEN_RING] = 4;
			auto plan = plan_birth_equipment({ item(0, INVEN_WIELD), item(1, INVEN_WIELD), item(2, INVEN_WIELD),
			                                   item(3, INVEN_RING), item(4, INVEN_RING), item(5, INVEN_RING) }, body);
			AssertThat(show(plan), Equals(std::vector<std::string> {
				at(0, INVEN_WIELD), at(1, INVEN_WIELD + 1),
				at(3, INVEN_RING), at(4, INVEN_RING + 1), at(5, INVEN_RING + 2) }));
		});

		it("prefers artifacts over other objects", [&]() {
			auto plan = plan_birth_equipment({ valued(0, INVEN_RING, 90000), valued(1, INVEN_RING, 80000), artifact(2, INVEN_RING) }, human_body());
			AssertThat(show(plan), Equals(std::vector<std::string> { at(2, INVEN_RING), at(0, INVEN_RING + 1) }));
		});

		it("prefers more valuable objects among non-artifacts", [&]() {
			auto plan = plan_birth_equipment({ valued(0, INVEN_LITE, 10), valued(1, INVEN_LITE, 500), valued(2, INVEN_LITE, 50) }, human_body());
			AssertThat(show(plan), Equals(std::vector<std::string> { at(1, INVEN_LITE) }));
		});

		it("prefers more valuable objects among artifacts", [&]() {
			auto a = artifact(0, INVEN_LITE);
			a.value = 10000;
			auto b = artifact(1, INVEN_LITE);
			b.value = 32500;
			AssertThat(show(plan_birth_equipment({ a, b }, human_body())), Equals(std::vector<std::string> { at(1, INVEN_LITE) }));
		});

		it("keeps the given order among objects of equal standing", [&]() {
			auto plan = plan_birth_equipment({ valued(7, INVEN_RING, 5), valued(3, INVEN_RING, 5), valued(5, INVEN_RING, 5) }, human_body());
			AssertThat(show(plan), Equals(std::vector<std::string> { at(7, INVEN_RING), at(3, INVEN_RING + 1) }));
		});

		it("puts on only one ultimate object", [&]() {
			auto staff = artifact(0, INVEN_WIELD);
			staff.ultimate = true;
			staff.value = 9000000;
			auto ring = artifact(1, INVEN_RING);
			ring.ultimate = true;
			auto other = artifact(2, INVEN_RING);
			AssertThat(show(plan_birth_equipment({ ring, staff, other }, human_body())),
				Equals(std::vector<std::string> { at(0, INVEN_WIELD), at(2, INVEN_RING) }));
		});

		describe("ammunition", [&]() {

			it("goes to the quiver as a whole stack with a matching launcher", [&]() {
				auto bow = item(0, INVEN_BOW);
				bow.launches = ARROW;
				auto arrows = stack(1, INVEN_AMMO, 20);
				arrows.ammo = ARROW;
				AssertThat(show(plan_birth_equipment({ bow, arrows }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_BOW), at(1, INVEN_AMMO, 20) }));
			});

			it("is placed after the launcher even if listed first", [&]() {
				auto arrows = stack(0, INVEN_AMMO, 20);
				arrows.ammo = ARROW;
				auto bow = item(1, INVEN_BOW);
				bow.launches = ARROW;
				AssertThat(show(plan_birth_equipment({ arrows, bow }, human_body())),
					Equals(std::vector<std::string> { at(1, INVEN_BOW), at(0, INVEN_AMMO, 20) }));
			});

			it("stays in the pack without a launcher", [&]() {
				auto arrows = stack(0, INVEN_AMMO, 20);
				arrows.ammo = ARROW;
				AssertThat(plan_birth_equipment({ arrows }, human_body()).size(), Equals(0u));
			});

			it("stays in the pack if the worn launcher fires something else", [&]() {
				auto sling = item(0, INVEN_BOW);
				sling.launches = SHOT;
				auto arrows = stack(1, INVEN_AMMO, 20);
				arrows.ammo = ARROW;
				AssertThat(show(plan_birth_equipment({ sling, arrows }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_BOW) }));
			});

			it("fills the quiver only once", [&]() {
				auto bow = item(0, INVEN_BOW);
				bow.launches = ARROW;
				auto arrows = stack(1, INVEN_AMMO, 20);
				arrows.ammo = ARROW;
				auto more = stack(2, INVEN_AMMO, 30);
				more.ammo = ARROW;
				more.value = 10;
				AssertThat(show(plan_birth_equipment({ bow, arrows, more }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_BOW), at(2, INVEN_AMMO, 30) }));
			});

		});

		describe("weapons and shields", [&]() {

			it("puts on a one-handed weapon and a shield", [&]() {
				AssertThat(show(plan_birth_equipment({ item(0, INVEN_WIELD), item(1, INVEN_ARM) }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_WIELD), at(1, INVEN_ARM) }));
			});

			it("places the weapon first even if the shield is listed first or worth more", [&]() {
				auto plan = plan_birth_equipment({ valued(0, INVEN_ARM, 99999), item(1, INVEN_WIELD) }, human_body());
				AssertThat(show(plan), Equals(std::vector<std::string> { at(1, INVEN_WIELD), at(0, INVEN_ARM) }));
			});

			it("puts no shield on with a two-handed weapon", [&]() {
				auto sword = item(0, INVEN_WIELD);
				sword.must_two_hand = true;
				AssertThat(show(plan_birth_equipment({ sword, artifact(1, INVEN_ARM) }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_WIELD) }));
			});

			it("puts no shield on with a weapon that can be used two-handed", [&]() {
				auto staff = artifact(0, INVEN_WIELD);
				staff.could_two_hand = true;
				AssertThat(show(plan_birth_equipment({ staff, item(1, INVEN_ARM) }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_WIELD) }));
			});

			it("puts a shield on the arm of a one-handed weapon when another weapon is two-handed", [&]() {
				auto body = human_body();
				body[INVEN_WIELD] = 2;
				body[INVEN_ARM] = 2;
				auto great = artifact(0, INVEN_WIELD);
				great.must_two_hand = true;
				auto shield = item(2, INVEN_ARM);
				auto plan = plan_birth_equipment({ great, item(1, INVEN_WIELD), shield }, body);
				AssertThat(show(plan), Equals(std::vector<std::string> {
					at(0, INVEN_WIELD), at(1, INVEN_WIELD + 1), at(2, INVEN_ARM + 1) }));
			});

			it("puts a shield on a free arm that holds no weapon", [&]() {
				AssertThat(show(plan_birth_equipment({ item(0, INVEN_ARM) }, human_body())),
					Equals(std::vector<std::string> { at(0, INVEN_ARM) }));
			});

		});

	});

});
