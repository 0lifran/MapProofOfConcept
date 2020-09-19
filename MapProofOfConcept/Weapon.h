#include "Item.h"
#include "WeaponType.h"

#pragma once
class Weapon : public Item
{
public:
	Weapon();
	Weapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponSubType, int closeRangeMin, int closeRangeMax, int mediumRangeMin, int mediumRangeMax, int highRangeMin, int highRangeMax, int extendedRangeMin, int extendedRangeMax);
	int Damage();
	void Damage(int damage);
	WeaponType WeaponSubType();
	void SubType(WeaponType weaponSubType);
private:
	int _damage;
	WeaponType _weaponSubType;
};

