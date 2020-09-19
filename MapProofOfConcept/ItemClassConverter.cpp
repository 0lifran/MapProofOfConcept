#include "ItemClassConverter.h"

Container* ItemClassConverter::ConvertToContainer(Item* input)
{
	return static_cast<Container*>(input);
}

BallisticWeapon* ItemClassConverter::ConvertToBallisticWeapon(RangedWeapon* input)
{
	Weapon* w = this->ConvertToWeapon(input);
	Weapon* rW = this->ConvertToRangedWeapon(w);
	return static_cast<BallisticWeapon*>(input);
}

RangedWeapon* ItemClassConverter::ConvertToRangedWeapon(Weapon* input)
{
	return static_cast<RangedWeapon*>(input);
}

Weapon* ItemClassConverter::ConvertToWeapon(Item* input)
{
	return static_cast<Weapon*>(input);
}
