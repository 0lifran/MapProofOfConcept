#include "Tile.h"
#include "RenderDataArray.h"
#include "Item.h"
#include "Unit.h"

#pragma once
class MapController
{
public:
	MapController(int width, int height, Tile** tiles);
	RenderDataArray* GetRenderData();
	void AddUnit(Unit* unit);

private:
	 bool _tileDataHasChanged = true;
	 bool _itemDataHasChanged = true;
	 bool _unitDataHasChanged = true;
	 const short _MAXMAPWIDTH = 128;
	 const short _MAXMAPHEIGHT = 128;
	 Tile** _tiles;
	 int _mapWidth = 16;
	 int _mapHeight = 16;
	 int _numberOfItems = 0;
	 Item* _items;
	 Unit* _units;
	 int _numberOfUnits = 0;

	RenderDataArray* GetTileRenderData();
	RenderDataArray* GetItemRenderData();
	RenderDataArray* GetUnitRenderData();

	
	bool TileDataHasChanged();
	bool ItemDataHasChanged();
	bool UnitDataHasChanged();
	void SetTileDataHasChanged(bool state);
	void SetItemDataHasChanged(bool state);
	void SetUnitDataHasChanged(bool state);

	// TileMap.
	
	void Tiles(int mapWidth, int mapHeight, Tile** tiles);
	Tile** Tiles();
	int MapWidth();
	void MapWidth(int width);
	int MapHeight();
	void MapHeight(int height);
	Tile* SpecificTileAt(int x, int y);
	void SpecificTileAt(Tile* tile, int x, int y);
	Tile* Tiles(int x, int y);
	void AddUnitsOnTilesToRepository();
	void AddItemsOnTilesToRepository();


	// Item logic.
	
	Item* Items();
	void Items(Item* items);
	void RemoveItem(int id);
	void PlaceItemOnTile(int id, int x, int y);
	void PushItemToMap(int id);
	int NumberOfItems();
	void NumberOfItems(int numberOfItems);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();
	void AddToItemRepository(Item* item);


	// Unit logic.
	
	Unit* Units();
	void Units(Unit* units);
	void RemoveUnit(int id);
	void PlaceUnitOnTile(int id, int x, int y);
	void MoveUnit(int id);
	void RotateUnit(int id, RotationDirection rotationDirection);
	int NumberOfUnits();
	void NumberOfUnits(int numberOfUnits);
	void PushUnitToMap(int id);
	int IncrementNumberOfUnits();
	int DecrementNumberOfUnits();
	Unit* GetUnitById(int id);
	bool IsMovementAllowed(Unit* unit);
	void AddToUnitRepository(Unit unit);
};

