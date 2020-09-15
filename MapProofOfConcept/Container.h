#include "Item.h"
#include "ItemManager.h"

#pragma once
class Container : public Item
{
public:
	Container(string name, int capacity);

	bool AddItem(Item* item);
	bool TakeOutItem(int id, Item* out);

private:
	int Capacity();
	void Capacity(int capacity);
	bool EnoughSpaceLeft();
	ItemManager ItemHandler;
	int _capacity;
};

