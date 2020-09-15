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
	Item* GetItemById(int itemId);
	void NumberOfItems(int numberOfItems);
	
	
private:
	int _numberOfItems;
	Item* _items;

	Item* PullOutItemAt(int positionAt);
	void RemoveItemAtPosition(int positionAt);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();

};

