#include "Weapon.h"

Weapon::Weapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponType, int closeRangeMin, int closeRangeMax, int mediumRangeMin, int mediumRangeMax, int highRangeMin, int highRangeMax, int extendedRangeMin, int extendedRangeMax) : Item(name, type, storageSpace)
{
	this->Damage(damage);
	this->SubType(weaponType);
}

Weapon::Weapon() : Item("None", ItemType::None, 0)
{
	this->Damage(0);
	this->SubType(WeaponType::None);
}

int Weapon::Damage()
{
	return this->_damage;
}
void Weapon::Damage(int damage)
{
	this->_damage = damage;
}
WeaponType Weapon::SubType()
{
	return this->_type;
}
void Weapon::SubType(WeaponType type)
{
	this->_type = type;
}