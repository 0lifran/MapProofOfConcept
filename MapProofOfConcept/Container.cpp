#include "Container.h"

Container::Container(string name, ItemType type, int capacity) : Item(name, type)
{
	this->Capacity(capacity);
}

int Container::Capacity()
{
	return this->_capacity;
}

void Container::Capacity(int capacity)
{
	this->_capacity = capacity;
}