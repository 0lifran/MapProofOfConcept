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
	for (int i = 0; i < this->NumberOfItems(); i++)
	{
		if (itemId == this->Items()[i].Id())
		{
			return &this->Items()[i];
		}
	}
}

void ItemManager::AddItem(Item* item)
{
	Item** itemArray;
	if (this->NumberOfItems() + 1 != 0)
	{
		itemArray = new Item * [this->NumberOfItems() + 1];
	}
	else
	{
		itemArray = NULL;
	}

	for (int i = 0; i < this->NumberOfItems() + 1; i++)
	{
		if (i < this->NumberOfItems())
		{
			itemArray[i] = &this->Items()[i];
		}
		else
		{
			itemArray[i] = item;
		}
	}
	this->IncrementNumberOfItems();
	this->Items(*itemArray);
}

Item* ItemManager::TakeOutItem(int id)
{
	Item* item = this->GetItemById(id);
	Item** newItems = new Item * [this->NumberOfItems() - 1];
	Item* result = new Item();

	bool past = false;
	for (int i = 0; i < this->NumberOfItems(); i++)
	{
		if (this->Items()->Id() != id)
		{
			// 1 2 3 4 5
			// 1 2 4 5
			if (past)
			{
				newItems[i] = &this->Items()[i];
			}
			else
			{
				newItems[i - 1] = &this->Items()[i];
			}
		}
		else
		{
			past = true;
			result = this->Items();
		}
	}
	this->Items(*newItems);
	this->DecrementNumberOfItems();
	return result;
}

Item* ItemManager::PullOutItemAt(int positionAt)
{
	return new Item();
}

void ItemManager::RemoveItemAtPosition(int positionAt)
{
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