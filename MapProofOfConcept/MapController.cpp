#include "MapController.h"
#include "RenderData.h"
#include "RenderDataArray.h"


MapController::MapController(int width, int height, Tile** tiles)
{
	Tiles(width, height, tiles);
}

void MapController::Tiles(int mapWidth, int mapHeight, Tile** tiles)
{
	MapWidth(mapWidth);
	MapHeight(mapHeight);
	this->_tiles = tiles;
}

Tile** MapController::Tiles()
{
	return this->_tiles;
}

Tile* MapController::Tiles(int x, int y)
{
	return &this->_tiles[x][y];
}

void MapController::MapWidth(int width)
{
	if (width < this->_MAXMAPWIDTH)
	{
		this->_mapWidth = width;
	}
	else
	{
		this->_mapWidth = this->_MAXMAPWIDTH;
	}
}

int MapController::MapWidth()
{
	return this->_mapWidth;
}

void MapController::MapHeight(int height)
{
	if (height < this->_MAXMAPHEIGHT)
	{
		this->_mapHeight = height;
	}
	else
	{
		this->_mapHeight = this->_MAXMAPHEIGHT;
	}
}

int MapController::MapHeight()
{
	return this->_mapHeight;
}

Tile* MapController::SpecificTileAt(int x, int y)
{
	return (this->Tiles())[x];;
}

void MapController::SpecificTileAt(Tile* tile, int x, int y)
{
	Tile** tempTiles = this->Tiles();
	tempTiles[x][y] = *tile;
}

RenderDataArray* MapController::GetRenderData()
{
	int lengthX = MapWidth();
	int lengthY = MapHeight();
	int lengthXY = lengthX * lengthY;
	RenderData* renderingDataArray = new RenderData[128 * 128];

	Tile** tiles = this->Tiles();
	for (int x = 0; x < lengthX; x++)
	{
		for (int y = 0; y < lengthY; y++)
		{
			Tile tmpTile = tiles[x][y];
			renderingDataArray[x] = RenderData{ x, y, tmpTile.ImagePath() };
		}
	}
	return new RenderDataArray{ lengthXY, renderingDataArray };
}

// Item logic.
int MapController::NumberOfItems()
{
	return this->_numberOfItems;
}
void MapController::NumberOfItems(int numberOfItems)
{
	this->_numberOfItems = numberOfItems;
}
int MapController::IncrementNumberOfItems()
{
	this->_numberOfItems++;
	return this->NumberOfItems();
}
int MapController::DecrementNumberOfItems()
{
	this->_numberOfItems--;
	return this->NumberOfItems();
}
void MapController::RemoveItem(int id)
{
	int x = -1;
	int y = -1;
	Item* currentItems = Items();
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (currentItems[i].Id() == id)
		{
			x = currentItems[i].X();
			y = currentItems[i].Y();
			break;
		}
	}

	if (x != -1 && y != -1)
	{
		Tile** tiles = Tiles();
		Item* tempI = new Item();;
		tiles[x, y]->TakeOutItem(id, tempI);
		delete tempI;
	}
	else 
	{
		throw new exception();
	}
	
}
void MapController::PlaceItemOnTile(int id, int x, int y)
{
	Item* currentItems = Items();
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (currentItems[i].Id() == id)
		{
			currentItems[i].X(x);
			currentItems[i].Y(y);
			this->_tiles[x][y].AddItem(&currentItems[i]);
			return;
		}
	}
	throw new exception("This item is not part of the item list.");
}
void MapController::PushItemToMap(int id)
{
	Item* currentItems = Items();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (currentItems[i].Id() == id)
		{
			int x = currentItems[i].X();
			int y = currentItems[i].Y();
			this->_tiles[x][y].AddItem(&currentItems[i]);
			return;
		}
	}
	throw new exception("This item is not part of the item list.");
}

// Unit logic.
void MapController::RemoveUnit(int id)
{
	int x = -1;
	int y = -1;
	Unit* currentUnits = Units();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (currentUnits[i].Id() == id)
		{
			x = currentUnits[i].X();
			y = currentUnits[i].Y();
			break;
		}
	}

	if (x != -1 && y != -1)
	{
		Tile** tiles = Tiles();
		Unit* tempU = new Unit();;
		tiles[x, y]->TakeOutUnit(id, tempU);
		delete tempU;
	}
	else
	{
		throw new exception();
	}
}

void MapController::PlaceUnitOnTile(int id, int x, int y)
{
	Unit* currentUnits = Units();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (currentUnits[i].Id() == id)
		{
			currentUnits[i].X(x);
			currentUnits[i].Y(y);
			this->_tiles[x][y].AddUnit(&currentUnits[i]);
			return;
		}
	}
	throw new exception("This unit is not part of the unit list.");
}

int MapController::IncrementNumberOfUnits()
{
	this->_numberOfUnits++;
	return this->NumberOfUnits();
}

int MapController::DecrementNumberOfUnits()
{
	this->_numberOfUnits--;
	return this->NumberOfUnits();
}

void MapController::PushUnitToMap(int id)
{
	Unit* currentUnits = Units();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (currentUnits[i].Id() == id)
		{
			int x = currentUnits[i].X();
			int y = currentUnits[i].Y();
			this->_tiles[x][y].AddUnit(&currentUnits[i]);
			return;
		}
	}
	throw new exception("This unit is not part of the unit list.");
}

void MapController::MoveUnit(int id)
{
	bool movementIsAllowed = false;
	Unit* currentUnits = Units();
	if (movementIsAllowed)
	{
		for (int i = 0; i < NumberOfUnits(); i++)
		{
			if (currentUnits[i].Id() == id)
			{
				currentUnits[i].Move();
			}
		}
	}
}

bool MapController::IsMovementAllowed(Unit* unit)
{
	int x = unit->X();
	int y = unit->Y();
	Direction unitDirection = unit->DirectionAngle();
	Tile* unitTile = this->Tiles(x, y);
	bool result = false;
	switch (unitDirection)
	{
	case Direction::North:
		// Must not be out of map bounds.
		// The target tile must not be higher than +2.
		// There must be no other unit standing on target tile.
		if (y - 1 >= 0)
		{
			Tile* targetTile = this->Tiles(x, y - 1);
			int unitHeight = unitTile->Height();
			int targetHeight = targetTile->Height();
			if (targetHeight - unitHeight >= 2)
			{
				result = false;
			}
		}
		break;
	}
}

void MapController::RotateUnit(int id, RotationDirection rotationDirection)
{
	Unit* currentUnits = Units();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (currentUnits[i].Id() == id)
		{
			currentUnits[i].Rotate(rotationDirection);
		}
	}
	throw new exception("The unit list does not contain this unit.");
}

void MapController::Items(Item* items)
{
	this->_items = items;
}

void MapController::Units(Unit* units)
{
	this->_units = units;
}

Item* MapController::Items()
{
	return this->_items;
}

Unit* MapController::Units()
{
	return this->_units;
}

int MapController::NumberOfUnits()
{
	return this->_numberOfUnits;
}

void MapController::NumberOfUnits(int numberOfUnits)
{
	this->_numberOfUnits = numberOfUnits;
}