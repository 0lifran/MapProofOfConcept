#pragma once
#include "Container.h"
#include "BallisticWeapon.h"
class ItemClassConverter
{
public:
	Container* ConvertToContainer(Item* item);
	BallisticWeapon* ConvertToBallisticWeapon(Weapon* item);
	Weapon* ConvertToWeapon(Item* item);
	RangedWeapon* ConvertToRangedWeapon(Weapon* input);

private:

};

