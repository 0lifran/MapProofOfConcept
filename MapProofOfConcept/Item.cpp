#include "Item.h"

Item::Item(string name)
{
	Name(name);
	ImagePath("Item.png");
	Id(IdManager::GetNewId());
}

Item::Item()
{
	Id(-1);
	Name("None");
	ImagePath("None.png");
}

string Item::Name()
{
	return this->_name;
}

void Item::Name(string name)
{
	this->_name = name;
}

int Item::Id()
{
	return this->_id;
}

void Item::Id(int id)
{
	this->_id = id;
}

string Item::ImagePath()
{
	return this->_imagePath;
}

void Item::ImagePath(string imagePath)
{
	this->_imagePath = imagePath;
}

int Item::X()
{
	return this->_x;
}
int Item::Y()
{
	return this->_y;
}
void Item::X(int x)
{
	this->_x = x;
}
void Item::Y(int y)
{
	this->_y = y;
}