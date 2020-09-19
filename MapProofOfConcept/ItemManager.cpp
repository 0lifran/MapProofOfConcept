#include "ItemManager.h"
#include "ItemFactory.h"

Item* ItemManager::Items()
{
	return this->_items;
}

void ItemManager::Items(Item* items)
{
	this->_items = items;
}


Item* ItemManager::GetItemById(int itemId)
{
	Item* items = Items();
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (items[i].Id() == itemId)
		{
			return &items[i];
		}
	}
	throw new exception("Item is not in list.");
}

void ItemManager::AddItem(Item* item)
{
	int currentNumberOfItems = IncrementNumberOfItems();
	Item* currentItems = Items();
	Item* tempItems = new Item[currentNumberOfItems];
	for (int i = 0; i < currentNumberOfItems; i++)
	{
		if (i == 0)
		{
			tempItems[i] = *item;
		}
		else
		{
			tempItems[i] = currentItems[i - 1];
		}
	}
	this->Items(tempItems);
}

Item ItemManager::TakeOutItem(int id)
{
	ItemFactory factory = *new ItemFactory();
	Item* tempItems = Items();
	int positionAt = -1;
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (tempItems->Id() == id)
		{
			positionAt = i;
			Item result = *PullOutItemAt(positionAt);
			Item* r = factory.CopyItem(result);
			Item response = *new Item(result.Id(), result.Name(), result.Type(), result.StorageSpace());
			RemoveItemAtPosition(positionAt);
			return response;
		}
	}
	return *new Item();
}

Item* ItemManager::PullOutItemAt(int positionAt)
{
	Item* result = &this->_items[positionAt];
	
	return result;
}

void ItemManager::RemoveItemAtPosition(int positionAt)
{
	int numberOfItems = DecrementNumberOfItems();
	Item* tempItems = new Item[numberOfItems];
	Item* currentItems = Items();

	for (int i = 0; i < numberOfItems; i++)
	{
		if (i < positionAt)
		{
			tempItems[i] = currentItems[i];
		}
		else
		{
			tempItems[i] = currentItems[i + 1];
		}
	}
}

int ItemManager::NumberOfItems()
{
	return this->_numberOfItems;
}

void ItemManager::NumberOfItems(int numberOfItems)
{
	this->_numberOfItems = numberOfItems;
}

int ItemManager::IncrementNumberOfItems()
{
	this->_numberOfItems++;
	return NumberOfItems();
}

int ItemManager::DecrementNumberOfItems()
{
	if (_numberOfItems - 1 >= 0)
	{
		this->_numberOfItems--;
	}
	else 
	{
		throw new exception("The number of items must not be less than zero.");
	}
	return NumberOfItems();
}