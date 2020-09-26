#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponType, int closeRangeMin, int closeRangeMax, int mediumRangeMin, int mediumRangeMax, int highRangeMin, int highRangeMax, int extendedRangeMin, int extendedRangeMax) : Weapon(name, type, storageSpace, damage, weaponType, closeRangeMin, closeRangeMax, mediumRangeMin, mediumRangeMax, highRangeMin, highRangeMax, extendedRangeMin, extendedRangeMax)
{
	CloseRangeMin(closeRangeMin);
	CloseRangeMax(closeRangeMax);
	MediumRangeMin(mediumRangeMin);
	MediumRangeMax(mediumRangeMax);
	HighRangeMin(highRangeMin);
	HighRangeMax(highRangeMax);
	ExtendedRangeMin(extendedRangeMin);
	ExtendedRangeMax(extendedRangeMax);
}

RangedWeapon::RangedWeapon()
{
	CloseRangeMin(0);
	CloseRangeMax(0);
	MediumRangeMin(0);
	MediumRangeMax(0);
	HighRangeMin(0);
	HighRangeMax(0);
	ExtendedRangeMin(0);
	ExtendedRangeMax(0);
}

int RangedWeapon::CloseRangeMin()
{
	return this->_closeRangeMin;
}

int RangedWeapon::CloseRangeMax()
{
	return this->_closeRangeMax;
}

int RangedWeapon::MediumRangeMin()
{
	return this->_mediumRangeMin;
}

int RangedWeapon::MediumRangeMax()
{
	return this->_mediumRangeMax;
}

int RangedWeapon::HighRangeMin()
{
	return this->_highRangeMin;
}

int RangedWeapon::HighRangeMax()
{
	return this->_highRangeMax;
}

int RangedWeapon::ExtendedRangeMin()
{
	return this->_extendedRangeMin;
}

int RangedWeapon::ExtendedRangeMax()
{
	return this->_extendedRangeMax;
}

void RangedWeapon::CloseRangeMin(int range)
{
	this->_closeRangeMin = range;
}
void RangedWeapon::CloseRangeMax(int range)
{
	this->_closeRangeMax = range;
}

void RangedWeapon::MediumRangeMin(int range)
{
	this->_mediumRangeMin = range;
}

void RangedWeapon::MediumRangeMax(int range)
{
	this->_mediumRangeMax = range;
}

void RangedWeapon::HighRangeMin(int range)
{
	this->_highRangeMin = range;
}

void RangedWeapon::HighRangeMax(int range)
{
	this->_highRangeMax = range;
}

void RangedWeapon::ExtendedRangeMin(int range)
{
	this->_extendedRangeMin = range;
}

void RangedWeapon::ExtendedRangeMax(int range)
{
	this->_extendedRangeMax = range;
	this->MaximumRange(range);
}

int  RangedWeapon::MaximumRange()
{
	return this->_maximumRange;
}

void RangedWeapon::MaximumRange(int range)
{
	this->_maximumRange = range;
}