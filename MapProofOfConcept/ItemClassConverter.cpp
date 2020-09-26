#include "ItemClassConverter.h"

Container* ItemClassConverter::ConvertToContainer(Item* input)
{
	return static_cast<Container*>(input);
}

BallisticWeapon* ItemClassConverter::ConvertToBallisticWeapon(Weapon* input)
{

	Weapon* rW = this->ConvertToRangedWeapon(input);
	return static_cast<BallisticWeapon*>(rW);
}

RangedWeapon* ItemClassConverter::ConvertToRangedWeapon(Weapon* input)
{
	return static_cast<RangedWeapon*>(input);
}

Weapon* ItemClassConverter::ConvertToWeapon(Item* input)
{
	return static_cast<Weapon*>(input);
}
