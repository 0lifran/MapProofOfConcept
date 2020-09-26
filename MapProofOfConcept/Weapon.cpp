#include "Weapon.h"

Weapon::Weapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponSubType, int closeRangeMin, int closeRangeMax, int mediumRangeMin, int mediumRangeMax, int highRangeMin, int highRangeMax, int extendedRangeMin, int extendedRangeMax) : Item(name, type, storageSpace)
{
	this->Damage(damage);
	this->SubType(weaponSubType);
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
WeaponType Weapon::WeaponSubType()
{
	return this->_weaponSubType;
}

void Weapon::SubType(WeaponType weaponSubType)
{
	this->_weaponSubType = weaponSubType;
}

WeaponType Weapon::SubType()
{
	return this->_weaponSubType;
}