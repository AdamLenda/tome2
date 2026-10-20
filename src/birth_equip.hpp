#pragma once

/*
 * Choosing which starting objects a new character wears.
 *
 * After the starting equipment is in the pack, every wearable object
 * that fits a free equipment slot is put on:
 *
 * - artifacts are placed first, then the other objects from the most to
 *   the least valuable; objects of equal standing keep their order;
 * - each slot type holds as many objects as the body has slots of that
 *   type;
 * - one object of a stack is worn, except ammunition, which goes to the
 *   quiver as a whole stack, and only if a launcher firing it is worn;
 * - weapons are placed before shields, and no shield goes on an arm
 *   whose weapon is two-handed (or can be used two-handed);
 * - cursed objects are never put on.
 */

#include <map>
#include <vector>

/**
 * A pack object that could be put on.
 */
struct equip_candidate
{
	/* The caller's handle for the object, e.g. its pack index */
	int id = 0;

	/* Ideal equipment slot (INVEN_*), or -1 if not wearable */
	int slot = -1;

	/* Stack size */
	int number = 1;

	bool artifact = false;
	bool cursed = false;

	/* Preference among objects of the same standing */
	long value = 0;

	/* Two-handed weapon: never with a shield / better without one */
	bool must_two_hand = false;
	bool could_two_hand = false;

	/* Launchers: the kind of ammunition fired (non-zero);
	   ammunition: its kind (non-zero) */
	int launches = 0;
	int ammo = 0;
};

/**
 * An object to put on: the candidate's id, the equipment slot (the slot
 * type's INVEN_* index plus the position among slots of that type) and
 * how many of the stack to put there.
 */
struct equip_choice
{
	int id = 0;
	int slot = 0;
	int number = 0;
};

/**
 * Choose which candidates to put on, given how many slots of each type
 * (keyed by the type's INVEN_* index) the body has.  Slots of a type
 * are filled in order; a weapon in slot INVEN_WIELD + k and a shield in
 * slot INVEN_ARM + k are held by the same arm.  Returns the choices in
 * the order made.
 */
std::vector<equip_choice> plan_birth_equipment(
	std::vector<equip_candidate> const &candidates,
	std::map<int, int> const &slot_counts);
