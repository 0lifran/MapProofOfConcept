#include "Item.h"

Item::Item()
{
	Id(0);
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