#include "BallisticWeapon.h"

BallisticWeapon::BallisticWeapon(
	string name, 
	ItemType type, 
	int storageSpace, 
	int damage, 
	WeaponType weaponType, 
	int closeRangeMin, 
	int closeRangeMax, 
	int mediumRangeMin, 
	int mediumRangeMax, 
	int highRangeMin, 
	int highRangeMax, 
	int extendedRangeMin, 
	int extendedRangeMax, 
	BallisticMagazine* magazine, 
	BallisticMagazineType ammoType) 
	: RangedWeapon(
		name, 
		type, 
		storageSpace, 
		damage, 
		weaponType, 
		closeRangeMin, 
		closeRangeMax, 
		mediumRangeMin, 
		mediumRangeMax, 
		highRangeMin, 
		highRangeMax, 
		extendedRangeMin, 
		extendedRangeMax)
{
	this->Magazine(magazine);
	this->MagazineType(ammoType);
}

BallisticWeapon::BallisticWeapon() : RangedWeapon()
{
	this->MagazineType(BallisticMagazineType::None);
}

bool BallisticWeapon::TakeOutMagazine(BallisticMagazine* out)
{
	if (this->Magazine()->Type() != BallisticMagazineType::None)
	{
		out = this->Magazine();
		Magazine(new BallisticMagazine());
		return true;
	}
	else
	{
		return false;
	}
}

bool BallisticWeapon::Reload(BallisticMagazine* magazine, BallisticMagazine* out)
{
	if (this->Magazine()->Type() == BallisticMagazineType::None)
	{
		if (magazine->Type() == this->MagazineType())
		{
			if (this->Magazine()->Type() != BallisticMagazineType::None)
			{
				this->TakeOutMagazine(out);
			}
			this->Magazine(magazine);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool BallisticWeapon::Fire()
{
	return this->Magazine()->GetBullet();
}

BallisticMagazine* BallisticWeapon::Magazine()
{
	return &this->_magazine;
}

void BallisticWeapon::Magazine(BallisticMagazine* magazine)
{
	this->_magazine = *magazine;
}

BallisticMagazineType BallisticWeapon::MagazineType()
{
	return this->_magazineType;
}

void BallisticWeapon::MagazineType(BallisticMagazineType magazineType)
{
	this->_magazineType = magazineType;
}
