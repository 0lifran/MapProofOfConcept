#include "RangedWeapon.h"
#include "BallisticMagazine.h"
#include "BallisticMagazineType.h"

#pragma once
class BallisticWeapon : RangedWeapon
{
public:
	BallisticWeapon(BallisticMagazineType magazineType);
	BallisticWeapon();
	
	bool TakeOutMagazine(BallisticMagazine* out);
	bool Reload(BallisticMagazine* magazine);
	bool Fire();

private:
	BallisticMagazine* Magazine();
	void Magazine(BallisticMagazine* magazine);
	BallisticMagazineType MagazineType();
	void MagazineType(BallisticMagazineType magazineType);

	BallisticMagazine _magazine;
	BallisticMagazineType _magazineType;
};

