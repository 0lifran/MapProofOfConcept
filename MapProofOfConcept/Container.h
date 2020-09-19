#include "Item.h"
#include "ItemManager.h"

#pragma once
class Container : public Item
{
public:
	Container(string name, int storageSpace, int capacity);

	bool AddItem(Item* item);
	Item* TakeOutItem(int id);
	int Capacity();

private:
	void Capacity(int capacity);
	bool EnoughSpaceLeft(int neededSpace);
	void CurrentlyOccupiedSpace(int neededSpace);
	int CurrentlyOccupiedSpace();

	ItemManager ItemHandler;
	int _capacity;
	int _currentlyOccupiedSpace;
};

