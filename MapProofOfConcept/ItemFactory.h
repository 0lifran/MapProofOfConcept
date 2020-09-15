#pragma once
#include "Item.h"
#include "ItemPreset.h"
#include "Container.h"
#include "BallisticWeapon.h"

class ItemFactory
{
public:
	Container* ConvertToContainer(Item* item);
	Item* ProduceItem(ItemPreset preset);
private:
	Item* ProduceBackpack();
	Item* ProduceSemiAutomaticPistol();
};

