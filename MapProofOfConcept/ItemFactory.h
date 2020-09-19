#pragma once
#include "Item.h"
#include "ItemPreset.h"
#include "Container.h"
#include "BallisticWeapon.h"
#include "ItemClassConverter.h"

class ItemFactory
{
public:
	

	Item* ProduceItem(ItemPreset preset);
	Item* CopyItem(Item item);
private:
	Item* ProduceBackpack();
	Item* ProduceSemiAutomaticPistol();

	ItemClassConverter _itemClassTransformer;
	ItemClassConverter* ItemClassTransformer();
	void ItemClassTransformer(ItemClassConverter* converter);
};

