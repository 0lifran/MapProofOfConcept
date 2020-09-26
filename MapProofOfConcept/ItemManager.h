#pragma once
#include "Item.h"
class ItemManager
{
public:
	Item* Items();
	void Items(Item* items);
	void AddItem(Item* item);
	Item* TakeOutItem(int id);
	int NumberOfItems();
	Item* GetItemById(int itemId);
	void NumberOfItems(int numberOfItems);
	Item* _items;

private:
	int _numberOfItems;

	Item* PullOutItemAt(int positionAt);
	void RemoveItemAtPosition(int positionAt);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();
};
