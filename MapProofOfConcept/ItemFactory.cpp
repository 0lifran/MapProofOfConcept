#include "ItemFactory.h"

Item* ItemFactory::ProduceItem(ItemPreset preset)
{
	Item* result = new Item();
	switch (preset)
	{
	case ItemPreset::Backpack:
	{
		result = this->ProduceBackpack();
	}
	default:
		throw new exception("Unknown item preset.");
	}

	return result;
}

Item* ItemFactory::ProduceBackpack()
{
	return new Container("Backpack", 32);
}

Container* ItemFactory::ConvertToContainer(Item* input)
{
	return static_cast<Container*>(input);
}