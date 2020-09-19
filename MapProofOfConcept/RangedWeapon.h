#include "Weapon.h"

#pragma once
class RangedWeapon : public Weapon
{
public:
	RangedWeapon(string name, ItemType type, int storageSpace, int damage, WeaponType weaponSubType, int closeRangeMin, int closeRangeMax, int mediumRangeMin, int mediumRangeMax, int highRangeMin, int highRangeMax, int extendedRangeMin, int extendedRangeMax);
	RangedWeapon();

	int CloseRangeMin();
	int CloseRangeMax();
	int MediumRangeMin();
	int MediumRangeMax();
	int HighRangeMin();
	int HighRangeMax();
	int ExtendedRangeMin();
	int ExtendedRangeMax();

	void CloseRangeMin(int range);
	void CloseRangeMax(int range);
	void MediumRangeMin(int range);
	void MediumRangeMax(int range);
	void HighRangeMin(int range);
	void HighRangeMax(int range);
	void ExtendedRangeMin(int range);
	void ExtendedRangeMax(int range);
private:
	int _closeRangeMin;
	int _closeRangeMax;
	int _mediumRangeMin;
	int _mediumRangeMax;
	int _highRangeMin;
	int _highRangeMax;
	int _extendedRangeMin;
	int _extendedRangeMax;

};

