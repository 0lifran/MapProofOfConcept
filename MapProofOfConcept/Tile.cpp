#include "Tile.h"

Tile::Tile()
{
	Type(TileType::None);
	Height(0);
	this->_itemHandler = *new ItemManager();
}

Tile::Tile(TileType type, int height)
{
	Type(type);
	Height(height);
	this->_itemHandler = *new ItemManager();
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
	case TileType::WildGrass:
		ImagePath("WildGrass.png");
		break;
	case TileType::Mud:
		ImagePath("Mud.png");
		break;
	case TileType::Water:
		ImagePath("Water.png");
		break;
	case TileType::DeepWater:
		ImagePath("DeepWater.png");
		break;
	case TileType::Snow:
		ImagePath("Snow.png");
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

ItemManager* Tile::ItemHandler()
{
	return &this->_itemHandler;
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
	SetOccupied(true);
	Unit* currentUnits = Units();
	Unit* tempUnits = new Unit[currentNumberOfUnits];
	if (currentNumberOfUnits > 1)
	{
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
		this->Units(tempUnits);
	}
	else 
	{
		tempUnits[0] = *unit;
		this->Units(tempUnits);
	}
}

bool Tile::TakeOutUnit(int id, Unit* out)
{
	Unit* tempUnits = Units();
	int positionAt = -1;
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (tempUnits[i].Id() == id)
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
	return result;
}

void Tile::RemoveUnitAtPosition(int positionAt)
{
	Unit* currentUnits = Units();
	currentUnits[positionAt] = *new Unit();
	int numberOfUnits = DecrementNumberOfUnits();
	SetOccupied(false);
	Unit* tempUnits = new Unit[numberOfUnits];

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