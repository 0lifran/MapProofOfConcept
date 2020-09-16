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
	return new Container("Backpack", 32, 32);
}

Item* ItemFactory::ProduceSemiAutomaticPistol()
{
	return new BallisticWeapon(
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
		*new BallisticMagazine(
			10,
			10,
			BallisticMagazineType::NineMm), 
		BallisticMagazineType::NineMm);
}

Container* ItemFactory::ConvertToContainer(Item* input)
{
	return static_cast<Container*>(input);
}

BallisticWeapon* ItemFactory::ConvertToBallisticWeapon(Item* input)
{
	return static_cast<BallisticWeapon*>(input);
}
