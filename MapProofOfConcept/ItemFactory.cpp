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
	return new BallisticWeapon("Semi Automatic Pistol")
}

Container* ItemFactory::ConvertToContainer(Item* input)
{
	return static_cast<Container*>(input);
}