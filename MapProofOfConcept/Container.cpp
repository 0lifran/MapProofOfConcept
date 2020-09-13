#include "Container.h"

Container::Container(string name, ItemType type, int capacity) : Item(name, type)
{
	this->ItemHandler = *new ItemManager();
	this->Capacity(capacity);
}

bool Container::AddItem(Item* item)
{
	if (this->EnoughSpaceLeft())
	{
		this->ItemHandler.AddItem(item);
	}
	else 
	{
		return false;
	}
}

bool Container::TakeOutItem(int id, Item* out)
{
	return this->ItemHandler.TakeOutItem(id, out);
}

bool Container::EnoughSpaceLeft()
{
	return this->ItemHandler.NumberOfItems() < this->Capacity();
}

int Container::Capacity()
{
	return this->_capacity;
}

void Container::Capacity(int capacity)
{
	this->_capacity = capacity;
}