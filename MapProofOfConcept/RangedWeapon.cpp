#include "RangedWeapon.h"

RangedWeapon::RangedWeapon()
{

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
}