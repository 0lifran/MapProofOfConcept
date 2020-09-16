#include "BallisticMagazine.h"

BallisticMagazine::BallisticMagazine()
{
	this->Capacity(0);
	this->BulletsLeft(0);
	this->Type(BallisticMagazineType::None);
}

BallisticMagazine::BallisticMagazine(int capacity, int bulletsLeft, BallisticMagazineType type)
{
	this->Capacity(capacity);
	this->BulletsLeft(bulletsLeft);
	this->Type(type);
}

bool BallisticMagazine::GetBullet()
{
	if (this->DecrementBulletsLeft())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BallisticMagazine::AddBullet()
{
	if (this->BulletsLeft() != this->Capacity())
	{
		IncrementBulletsLeft();
		return true;
	}
	else
	{
		return false;
	}
}

int	BallisticMagazine::Capacity()
{
	return this->_capacity;
}

void BallisticMagazine::Capacity(int capacity)
{
	this->_capacity = capacity;
}
int	BallisticMagazine::BulletsLeft()
{
	return this->_bulletsLeft;
}

void BallisticMagazine::BulletsLeft(int bulletsLeft)
{
	this->_bulletsLeft = bulletsLeft;
}

bool BallisticMagazine::DecrementBulletsLeft()
{
	if (this->BulletsLeft() > 0)
	{
		this->_bulletsLeft--;
		return true;
	}
	else
	{
		return false;
	}
}

bool BallisticMagazine::IncrementBulletsLeft()
{
	if (this->BulletsLeft() == this->Capacity())
	{
		this->_bulletsLeft++;
		return true;
	}
	else
	{
		return false;
	}
}

BallisticMagazineType BallisticMagazine::Type()
{
	return this->_type;
}

void BallisticMagazine::Type(BallisticMagazineType type)
{
	this->_type = type;
}