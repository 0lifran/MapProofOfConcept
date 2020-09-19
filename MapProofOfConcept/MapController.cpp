#include "MapController.h"
#include "RenderData.h"
#include "RenderDataArray.h"
#include <iostream>

MapController::MapController(int width, int height, Tile** tiles)
{
	this->_inventoryHandler = *new UnitInventoryController();
	Tiles(width, height, tiles);
}

void MapController::InitializeInventory(int unitId)
{
	Unit* unit = this->GetUnitById(unitId);
	int tileX = unit->X();
	int tileY = unit->Y();
	Tile* tile = this->SpecificTileAt(tileX, tileY);
	this->_inventoryHandler = *new UnitInventoryController(unit, tile);
}

UnitInventoryController* MapController::InventoryHandler()
{
	return &this->_inventoryHandler;
}

// Tile logic.
void MapController::Tiles(int mapWidth, int mapHeight, Tile** tiles)
{
	MapWidth(mapWidth);
	MapHeight(mapHeight);
	this->_tiles = tiles;

	this->AddUnitsOnTilesToRepository();
	
	SetTileDataHasChanged(true);
	SetItemDataHasChanged(true);
	SetUnitDataHasChanged(true);
}

void MapController::AddUnitsOnTilesToRepository()
{
	Tile** curTiles = Tiles();
	for (int x = 0; x < MapWidth(); x++)
	{
		for (int y = 0; y < MapHeight(); y++)
		{
			int numberOfUnitsOnTile = curTiles[x][y].NumberOfUnits();
			if (numberOfUnitsOnTile > 0)
			{
				Unit* unitsOnThisTile = curTiles[x][y].Units();
				for (int i = 0; i < numberOfUnitsOnTile; i++)
				{
					this->AddToUnitRepository(unitsOnThisTile[i]);
				}
			}
		}
	}
}

void MapController::AddItemsOnTilesToRepository()
{
	Tile** curTiles = Tiles();
	for (int x = 0; x < MapWidth(); x++)
	{
		for (int y = 0; y < MapHeight(); y++)
		{
			int numberOfItemsOnTile = curTiles[x][y].NumberOfUnits();
			if (numberOfItemsOnTile > 0)
			{
				ItemManager* itemHandler = curTiles[x][y].ItemHandler();
				Item* itemsOnThisTile = itemHandler->Items();
				for (int i = 0; i < numberOfItemsOnTile; i++)
				{
					this->AddItem(&itemsOnThisTile[i]);
				}
			}
		}
	}
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
	Tile* specificTile = &this->Tiles()[x][y];
	return specificTile;
}
void MapController::SpecificTileAt(Tile* tile, int x, int y)
{
	Tile** tempTiles = this->Tiles();
	tempTiles[x][y] = *tile;
	SetTileDataHasChanged(true);
}
RenderDataArray* MapController::GetRenderData()
{
	RenderDataArray* tileData;
	RenderDataArray* itemData;
	RenderDataArray* unitData;

	if (this->TileDataHasChanged())
	{
		tileData = this->GetTileRenderData();
		this->SetTileDataHasChanged(false);
	}
	else
	{
		RenderData emptyRenderData = RenderData{ 0,0,"" };
		tileData = new RenderDataArray{ 0,  &emptyRenderData };
	}

	if (this->UnitDataHasChanged())
	{
		unitData = this->GetTileRenderData();
		this->SetUnitDataHasChanged(false);
	}
	else
	{
		RenderData emptyRenderData = RenderData{ 0,0,"" };
		unitData = new RenderDataArray{ 0,  &emptyRenderData };
	}

	if (this->ItemDataHasChanged())
	{
		itemData = this->GetTileRenderData();
		this->SetItemDataHasChanged(false);
	}
	else
	{
		RenderData emptyRenderData = RenderData{ 0,0,"" };
		itemData = new RenderDataArray{ 0,  &emptyRenderData };
	}

	int expectedLengthOfRenderData = tileData->Length + itemData->Length + unitData->Length;
	RenderData* allRenderData = new RenderData[expectedLengthOfRenderData];
	int cursorPos = 0;
	for (int i = 0; i < tileData->Length; i++)
	{
		allRenderData[i] = tileData->Data[i];

		if (i + 1 == tileData->Length)
		{
			cursorPos == i;
		}
	}

	for (int i = 0; i < itemData->Length; i++)
	{
		allRenderData[cursorPos + i] = itemData->Data[i];
		if (i + 1 == itemData->Length)
		{
			cursorPos == cursorPos + i;
		}
	}

	for (int i = 0; i < unitData->Length; i++)
	{
		allRenderData[cursorPos + i] = unitData->Data[i];
		if (i + 1 == unitData->Length)
		{
			cursorPos == cursorPos + i;
		}
	}
	return new RenderDataArray
	{
		expectedLengthOfRenderData,
		allRenderData
	};
}

bool MapController::TileDataHasChanged()
{
	return this->_tileDataHasChanged;
}
void MapController::SetTileDataHasChanged(bool state)
{
	this->_tileDataHasChanged = state;
}
bool MapController::UnitDataHasChanged()
{
	return this->_unitDataHasChanged;
}
void MapController::SetUnitDataHasChanged(bool state)
{
	this->_unitDataHasChanged = state;
}
bool MapController::ItemDataHasChanged()
{
	return this->_itemDataHasChanged;
}
void MapController::SetItemDataHasChanged(bool state)
{
	this->_itemDataHasChanged = state;
}

RenderDataArray* MapController::GetTileRenderData()
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
RenderDataArray* MapController::GetItemRenderData()
{
	int numberOfItems = this->NumberOfItems();
	Item* items = Items();
	RenderData* renderingDataArray = new RenderData[numberOfItems];
	for (int i = 0; i < numberOfItems; i++)
	{
		renderingDataArray[i] = RenderData{ items[i].X(), items[i].Y(), items[i].ImagePath() };
	}
	return new RenderDataArray{ numberOfItems, renderingDataArray };
}
RenderDataArray* MapController::GetUnitRenderData()
{
	int numberOfUnits = this->NumberOfUnits();
	Unit* units = Units();
	RenderData* renderingDataArray = new RenderData[numberOfUnits];
	for (int i = 0; i < numberOfUnits; i++)
	{
		renderingDataArray[i] = RenderData{ units[i].X(), units[i].Y(), units[i].ImagePath() };
	}
	return new RenderDataArray{ numberOfUnits, renderingDataArray };
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
		Item* tempI = new Item();
		ItemManager* itemHandler = tiles[x, y]->ItemHandler();
		tempI = &itemHandler->TakeOutItem(id);
		SetItemDataHasChanged(true);
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
			ItemManager* itemHandler = this->_tiles[x][y].ItemHandler();
			itemHandler->AddItem(&currentItems[i]);
			SetItemDataHasChanged(true);
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
			ItemManager* itemHandler = this->_tiles[x][y].ItemHandler();
			itemHandler->AddItem(&currentItems[i]);
			SetItemDataHasChanged(true);

			return;
		}
	}
	throw new exception("This item is not part of the item list.");
}
void MapController::Items(Item* items)
{
	this->_items = items;
	SetItemDataHasChanged(true);

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
		Unit* tempU = new Unit();
		tiles[x, y]->TakeOutUnit(id, tempU);
		SetUnitDataHasChanged(true);
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
	this->_tiles[x][y].AddUnit(x,y,currentUnit);
	SetUnitDataHasChanged(true);
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
	this->_tiles[x][y].AddUnit(x,y,currentUnit);
	SetUnitDataHasChanged(true);
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
		Tile * tempTile = SpecificTileAt(currentUnit->X(), currentUnit->Y());
		tempTile->TakeOutUnit(currentUnit->Id(), currentUnit);
		currentUnit->Move();

		PlaceUnitOnTile(currentUnit->Id(), currentUnit->X(), currentUnit->Y());
		SetUnitDataHasChanged(true);
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
		if (y - 1 >= 0 && x + 1 < this->MapWidth())
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
		if (x + 1 < this->MapWidth())
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
		if (y + 1 < this->MapHeight() && x + 1 < this->MapWidth())
		{
			isAllowed = true;
			targetTile = this->Tiles(x + 1, y + 1);
		}
		else
		{
			isAllowed = false;
		}
		break;
	case Direction::South:
		if (y + 1 < this->MapHeight())
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
		if (x - 1 >= 0 && y + 1 < this->MapHeight())
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
	SetUnitDataHasChanged(true);
}
void MapController::Units(Unit* units)
{
	this->_units = units;
	SetUnitDataHasChanged(true);
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
void MapController::AddUnit(Unit* unit)
{
	this->AddToUnitRepository(*unit);
	PushUnitToMap(unit->Id());
}

void MapController::AddToUnitRepository(Unit unit)
{
	IncrementNumberOfUnits();
	Unit* tempUnits = new Unit[NumberOfUnits()]();
	Unit* currentUnits = Units();
	for (int i = 0; i < NumberOfUnits(); i++)
	{
		if (i != NumberOfUnits() - 1)
		{
			tempUnits[i] = currentUnits[i];
		}
		else
		{
			tempUnits[i] = unit;
		}
	}

	Units(tempUnits);
	delete[]currentUnits;
}

void MapController::AddItem(Item* item)
{
	IncrementNumberOfItems();
	Item* tempItems = new Item[NumberOfItems()]();
	Item* currentItems = Items();
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (i != NumberOfItems() - 1)
		{
			tempItems[i] = currentItems[i];
		}
		else
		{
			tempItems[i] = *item;
		}
	}

	Items(tempItems);
	delete[]currentItems;
}