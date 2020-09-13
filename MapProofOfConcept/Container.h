#include "Item.h"
#include "ItemManager.h"

#pragma once
class Container : public Item
{
public:
	Container(string name, ItemType type, int capacity);

	int Capacity();
	void Capacity(int capacity);

	ItemManager ItemHandler;
private:
	int _capacity;
};

