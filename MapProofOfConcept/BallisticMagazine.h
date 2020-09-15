#include "BallisticMagazineType.h"

#pragma once
class BallisticMagazine
{
public:
	BallisticMagazine();
	BallisticMagazine(int capacity, int bulletsLeft, BallisticMagazineType type);

	bool GetBullet();
	bool AddBullet();
	int Capacity();
	void Capacity(int capacity);
	int BulletsLeft();
	void BulletsLeft(int bulletsLeft);
	bool DecrementBulletsLeft();
	bool IncrementBulletsLeft();
	BallisticMagazineType Type();
	void Type(BallisticMagazineType type);
private:
	int _capacity;
	int _bulletsLeft;
	BallisticMagazineType _type;
};

