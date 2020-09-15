#include "BallisticWeapon.h"

BallisticWeapon::BallisticWeapon(BallisticMagazineType magazineType) : RangedWeapon()
{
	this->MagazineType(magazineType);
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

bool BallisticWeapon::Reload(BallisticMagazine* magazine)
{
	if (this->Magazine()->Type() == BallisticMagazineType::None)
	{
		if (magazine->Type() == this->MagazineType())
		{
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
	if (this->Magazine()->BulletsLeft() > 0)
	{
		this->Magazine()->GetBullet();
		return true;
	}
	else
	{
		return false;
	}
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