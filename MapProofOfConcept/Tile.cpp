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

Unit* Tile::Units()
{
	return this->_units;
}

void Tile::Units(Unit* units)
{
	this->_units = units;
}
void Tile::AddUnit(int x, int y, Unit* unit)
{
	int currentNumberOfUnits = IncrementNumberOfUnits();
	Unit* currentUnits = Units();
	Unit* tempUnits = new Unit[currentNumberOfUnits];
	for (int i = 0; i < currentNumberOfUnits; i++)
	{
		if (i == 0)
		{
			tempUnits[i] = *unit;
		}
		else
		{
			tempUnits[i] = currentUnits[i - 1];
		}
	}
}

bool Tile::TakeOutUnit(int id, Unit* out)
{
	Unit* tempUnits = Units();
	int positionAt = -1;
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (tempUnits->Id() == id)
		{
			positionAt = i;
			Unit* result = GetUnitAtPosition(positionAt);
			RemoveUnitAtPosition(positionAt);
			out = result;
			return true;
		}
	}
	return false;
}

int Tile::NumberOfUnits()
{
	return this->_numberOfUnits;
}

void Tile::NumberOfUnits(int numberOfUnits)
{
	this->_numberOfUnits = numberOfUnits;
}

int Tile::IncrementNumberOfUnits()
{
	this->_numberOfUnits++;
	return NumberOfUnits();
}

int Tile::DecrementNumberOfUnits()
{
	this->_numberOfUnits--;
	return NumberOfUnits();
}

Unit* Tile::GetUnitAtPosition(int positionAt)
{
	Unit* result = &this->_units[positionAt];
	RemoveUnitAtPosition(positionAt);
	return result;
}

void Tile::RemoveUnitAtPosition(int positionAt)
{
	int numberOfUnits = DecrementNumberOfUnits();
	Unit* tempUnits = new Unit[numberOfUnits];
	Unit* currentUnits = Units();

	for (int i = 0; i < numberOfUnits; i++)
	{
		if (i < positionAt)
		{
			tempUnits[i] = currentUnits[i];
		}
		else
		{
			tempUnits[i] = currentUnits[i + 1];
		}
	}
}

void Tile::SetOccupied(bool state)
{
	this->_isOccupiedByUnit = state;
}
bool Tile::IsOccupiedByUnit()
{
	return this->_isOccupiedByUnit;
}