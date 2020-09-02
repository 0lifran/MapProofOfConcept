#include "Tile.h"

Tile::Tile()
{
	Type(TileType::None);
	Height(0);
}

Tile::Tile(TileType type, int height)
{
	Type(type);
	Height(height);
}


Tile::Tile(TileType type)
{
	Type(type);
	Height(0);
}

Tile::Tile(int height)
{
	Height(height);
	Type(TileType::Grass);
}


Tile::~Tile()
{
	delete this;
}

TileType Tile::Type()
{
	return this->_type;
}

void Tile::Type(TileType type)
{
	this->_type = type;
	ImagePath(type);
}

void Tile::ImagePath(TileType type)
{
	switch (type)
	{
	case TileType::Grass:
		ImagePath("Grass.png");
		break;
	case TileType::Mud:
		ImagePath("Mud.png");
		break;
	case TileType::None:
		ImagePath("");
		break;
	default:
		throw new exception();
		break;
	}
}

int Tile::Height()
{
	return this->_height;
}

void Tile::Height(int height)
{
	this->_height = height;
}

string Tile::ImagePath()
{
	return this->_path;
}

void Tile::ImagePath(string path)
{
	this->_path = path;
}

// Item data
Item* Tile::Items()
{
	return this->_items;
}

void Tile::Items(Item* items)
{
	this->_items = items;
}

void Tile::AddItem(Item* item)
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
}

bool Tile::TakeOutItem(int id, Item* out)
{
	Item* tempItems = Items();
	int positionAt = -1;
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (tempItems->Id() == id)
		{
			positionAt = i;
			Item* result = GetItemAtPosition(positionAt);
			RemoveItemAtPosition(positionAt);
			out = result;
			return true;
		}
	}
	return false;
}

Item* Tile::GetItemAtPosition(int positionAt)
{
	Item* result = &this->_items[positionAt];
	RemoveItemAtPosition(positionAt);
	return result;
}

void Tile::RemoveItemAtPosition(int positionAt)
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

int Tile::NumberOfItems()
{
	return this->_numberOfItems;

}

void Tile::NumberOfItems(int numberOfItems)
{
	this->_numberOfItems = numberOfItems;
}

int Tile::IncrementNumberOfItems()
{
	this->_numberOfItems++;
	return NumberOfItems();
}

int Tile::DecrementNumberOfItems()
{
	this->_numberOfItems--;
	return NumberOfItems();
}