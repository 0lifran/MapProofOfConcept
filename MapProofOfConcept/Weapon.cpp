#include "Weapon.h"

Weapon::Weapon()
{

}

Weapon::Weapon(int damage, WeaponType type)
{
	Damage(damage);
	Type(type);
}
int Weapon::Damage()
{
	return this->_damage;
}
void Weapon::Damage(int damage)
{
	this->_damage = damage;
}
WeaponType Weapon::Type()
{
	return this->_type;
}
void Weapon::Type(WeaponType type)
{
	this->_type = type;
}