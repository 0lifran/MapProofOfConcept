#pragma once
#include "Item.h"
class ItemManager
{
public:
	Item* Items();
	void Items(Item* items);
	void AddItem(Item* item);
	bool TakeOutItem(int id, Item* out);
	int NumberOfItems();
	void NumberOfItems(int numberOfItems);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();
	Item* GetItemAtPosition(int positionAt);
	void RemoveItemAtPosition(int positionAt);
private:
	int _numberOfItems;
	Item* _items;
};

