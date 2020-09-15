#include "Container.h"

Container::Container(string name, int storageSpace, int capacity) : Item(name, ItemType::Container, storageSpace)
{
	this->ItemHandler = *new ItemManager();
	this->Capacity(capacity);
}

bool Container::AddItem(Item* item)
{
	if (this->EnoughSpaceLeft(item->StorageSpace()))
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

bool Container::EnoughSpaceLeft(int neededSpace)
{
	return this->CurrentlyOccupiedSpace() + neededSpace < this->Capacity();
}

int Container::Capacity()
{
	return this->_capacity;
}

void Container::Capacity(int capacity)
{
	this->_capacity = capacity;
}

void Container::CurrentlyOccupiedSpace(int neededSpace)
{
	this->_capacity = this->_capacity + neededSpace;
}

int Container::CurrentlyOccupiedSpace()
{
	return this->_currentlyOccupiedSpace;
}