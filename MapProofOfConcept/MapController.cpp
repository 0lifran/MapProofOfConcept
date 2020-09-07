#include "MapController.h"
#include "RenderData.h"
#include "RenderDataArray.h"

MapController::MapController(int width, int height, Tile** tiles)
{
	Tiles(width, height, tiles);
}

// Tile logic.
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
void MapController::Items(Item* items)
{
	this->_items = items;
}
Item* MapController::Items()
{
	return this->_items;
}

// Unit logic.
void MapController::RemoveUnit(int id)
{
	int x = -1;
	int y = -1;
	Unit* currentUnit = this->GetUnitById(id);
	x = currentUnit->X();
	y = currentUnit->Y();

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
	Unit* currentUnit = this->GetUnitById(id);
	currentUnit->X(x);
	currentUnit->Y(y);
	this->_tiles[x][y].AddUnit(currentUnit);
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
	Unit* currentUnit = this->GetUnitById(id);
	int x = currentUnit->X();
	int y = currentUnit->Y();
	this->_tiles[x][y].AddUnit(currentUnit);
}
Unit* MapController::GetUnitById(int id)
{
	Unit* units = Units();
	for (int i = 0; i < this->NumberOfUnits(); i++)
	{
		if (units[i].Id() == id)
		{
			return &units[i];
		}
	}
	throw new exception("Unit not in list.");
}
void MapController::MoveUnit(int id)
{
	bool movementIsAllowed = false;
	Unit* currentUnit = GetUnitById(id);
	if (this->IsMovementAllowed(currentUnit))
	{
		currentUnit->Move();
	}
}
bool MapController::IsMovementAllowed(Unit* unit)
{
	int x = unit->X();
	int y = unit->Y();
	Direction unitDirection = unit->DirectionAngle();
	Tile* unitTile = this->Tiles(x, y);
	Tile* targetTile = new Tile();
	bool isAllowed = false;

	switch (unitDirection)
	{
	case Direction::North:
		if (y - 1 >= 0)
		{
			isAllowed = true;
			targetTile = this->Tiles(x, y - 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::NorthEast:
		if (y - 1 >= 0 && x + 1 <= this->MapWidth())
		{
			isAllowed = true;
			targetTile = this->Tiles(x + 1, y - 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::East:
		if (x + 1 <= this->MapWidth())
		{
			isAllowed = true;
			targetTile = this->Tiles(x + 1, y);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::SouthEast:
		if (y + 1 <= this->MapHeight() && x + 1 <= this->MapWidth())
		{
			isAllowed = true;
			targetTile = this->Tiles(x + 1, y);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::South:
		if (y + 1 <= this->MapHeight())
		{
			isAllowed = true;
			targetTile = this->Tiles(x, y + 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::SouthWest:
		if (x - 1 >= 0 && y + 1 <= this->MapHeight())
		{
			isAllowed = true;
			targetTile = this->Tiles(x - 1, y + 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::West:
		if (x - 1 >= 0)
		{
			isAllowed = true;
			targetTile = this->Tiles(x - 1, y);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::NorthWest:
		if (y - 1 >= 0 && x - 1 >= 0)
		{
			isAllowed = true;
			targetTile = this->Tiles(x - 1, y - 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	default:
		throw new exception("Error during unit movement: The moving direction is unknown.");
	}

	if (isAllowed)
	{
		int unitHeight = unitTile->Height();
		int targetHeight = targetTile->Height();
		if (targetHeight - unitHeight >= 2)
		{
			isAllowed = false;
		}
		else
		{
			isAllowed = true;
		}
	}

	if (isAllowed)
	{
		if (targetTile->IsOccupiedByUnit())
		{
			isAllowed = false;
		}
		else
		{
			isAllowed = true;
		}
	}
	return isAllowed;
}
void MapController::RotateUnit(int id, RotationDirection rotationDirection)
{
	Unit* currentUnit = this->GetUnitById(id);
	currentUnit->Rotate(rotationDirection);
}
void MapController::Units(Unit* units)
{
	this->_units = units;
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