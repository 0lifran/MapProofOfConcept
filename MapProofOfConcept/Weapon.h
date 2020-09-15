#include "Item.h"
#include "WeaponType.h"

#pragma once
class Weapon : Item
{
public:
	Weapon();
	Weapon(int damage, WeaponType type);
	int Damage();
	void Damage(int damage);
	WeaponType Type();
	void Type(WeaponType type);
private:
	int _damage;
	WeaponType _type;
};

