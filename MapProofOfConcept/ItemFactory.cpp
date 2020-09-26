#include "ItemFactory.h"

Item* ItemFactory::ProduceItem(ItemPreset preset)
{
	Item* result = new Item();
	switch (preset)
	{
	case ItemPreset::Backpack:
	{
		result = this->ProduceBackpack();
		break;
	}
	case ItemPreset::SemiAutomaticPistol:
	{
		result = this->ProduceSemiAutomaticPistol();
		break;
	}
	default:
		throw new exception("Unknown item preset.");
	}

	return result;
}

Item* ItemFactory::ProduceBackpack()
{
	return static_cast<Item*>(new Container("Backpack", 32, 32));
}

Item* ItemFactory::ProduceSemiAutomaticPistol()
{
	BallisticMagazine* magazine = new BallisticMagazine(
		10,
		10,
		BallisticMagazineType::NineMm);

	BallisticWeapon* result = new BallisticWeapon(
		"Semi Automatic Pistol",
		ItemType::Weapon,
		3,
		2,
		WeaponType::Ballistic,
		1,
		5,
		6,
		10,
		11,
		15,
		16,
		20,
		magazine,
		BallisticMagazineType::NineMm);
	return static_cast<Item*>(result);
}

void ItemFactory::ItemClassTransformer(ItemClassConverter* converter)
{
	this->_itemClassTransformer = *converter;
}

ItemClassConverter* ItemFactory::ItemClassTransformer()
{
	return &this->_itemClassTransformer;
}

Item* ItemFactory::CopyItem(Item* item)
{
	if (item->Type() == ItemType::Weapon)
	{
		Weapon* w = static_cast<Weapon*>(item);
	}
	return new Item();
}

