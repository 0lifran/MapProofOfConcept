#include "Item.h"

Item::Item(string name)
{
	Name(name);
	ImagePath("Item.png");
	Id(0);
}

Item::Item()
{

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