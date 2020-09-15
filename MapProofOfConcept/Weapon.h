#include "Item.h"
#include "WeaponType.h"

#pragma once
class Weapon : Item
{
public:
	Weapon();
	Weapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponType);
	int Damage();
	void Damage(int damage);
	WeaponType SubType();
	void SubType(WeaponType type);
private:
	int _damage;
	WeaponType _type;
};

