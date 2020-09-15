#include "Item.h"
#include "ItemManager.h"

#pragma once
class Container : public Item
{
public:
	Container(string name, int storageSpace, int capacity);

	bool AddItem(Item* item);
	bool TakeOutItem(int id, Item* out);

private:
	int Capacity();
	void Capacity(int capacity);
	bool EnoughSpaceLeft(int neededSpace);
	void CurrentlyOccupiedSpace(int neededSpace);
	int CurrentlyOccupiedSpace();

	ItemManager ItemHandler;
	int _capacity;
	int _currentlyOccupiedSpace;
};

