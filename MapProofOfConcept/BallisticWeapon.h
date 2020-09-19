#include "RangedWeapon.h"
#include "BallisticMagazine.h"
#include "BallisticMagazineType.h"
#include "WeaponType.h"

#pragma once
class BallisticWeapon : public RangedWeapon
{
public:
	BallisticWeapon(
		string name, 
		ItemType type, 
		int storageSpace, 
		int damage, 
		WeaponType weaponSubType, 
		int closeRangeMin, 
		int closeRangeMax, 
		int mediumRangeMin, 
		int mediumRangeMax, 
		int highRangeMin, 
		int highRangeMax, 
		int extendedRangeMin, 
		int extendedRangeMax, 
		BallisticMagazine magazine, 
		BallisticMagazineType ammoType);
	BallisticWeapon();
	
	bool TakeOutMagazine(BallisticMagazine* out);
	bool Reload(BallisticMagazine* magazine, BallisticMagazine* out);
	bool Fire();
	
	BallisticMagazine* Magazine();
	BallisticMagazineType MagazineType();
private:
	void Magazine(BallisticMagazine* magazine);
	void MagazineType(BallisticMagazineType magazineType);
	
	BallisticMagazine _magazine;
	BallisticMagazineType _magazineType;
};

