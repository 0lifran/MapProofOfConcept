#include "Item.h"
#include "IdManager.h"

Item::Item(string name, ItemType type)
{
	Name(name);
	ImagePath("Item.png");
	Type(type);

	IdManager idHandler = *new IdManager();
	Id(idHandler.GetNewId());
}

Item::Item()
{
	Id(-1);
	Name("None");
	ImagePath("None.png");
	Type(ItemType::None);
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

ItemType Item::Type()
{
	return this->_type;
}

void Item::Type(ItemType type)
{
	this->_type = type;
}