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
	
	
private:
	int _numberOfItems;
	Item* _items;

	Item* GetItemAtPosition(int positionAt);
	void RemoveItemAtPosition(int positionAt);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();

	void NumberOfItems(int numberOfItems);
};

