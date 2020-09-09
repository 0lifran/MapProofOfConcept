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

private:
	RenderDataArray* GetTileRenderData();
	RenderDataArray* GetItemRenderData();
	RenderDataArray* GetUnitRenderData();
	bool TileDataHasChanged();
	bool ItemDataHasChanged();
	bool UnitDataHasChanged();
	void SetTileDataHasChanged(bool state);
	void SetItemDataHasChanged(bool state);
	void SetUnitDataHasChanged(bool state);

	bool _tileDataHasChanged;
	bool _itemDataHasChanged;
	bool _unitDataHasChanged;

	// TileMap.
	const short _MAXMAPWIDTH = 128;
	const short _MAXMAPHEIGHT = 128;
	Tile** _tiles;
	int _mapWidth;
	int _mapHeight;
	void Tiles(int mapWidth, int mapHeight, Tile** tiles);
	Tile** Tiles();
	int MapWidth();
	void MapWidth(int width);
	int MapHeight();
	void MapHeight(int height);
	Tile* SpecificTileAt(int x, int y);
	void SpecificTileAt(Tile* tile, int x, int y);
	Tile* Tiles(int x, int y);


	// Item logic.
	int _numberOfItems;
	Item* _items;
	Item* Items();
	void Items(Item* items);
	void RemoveItem(int id);
	void PlaceItemOnTile(int id, int x, int y);
	void PushItemToMap(int id);
	int NumberOfItems();
	void NumberOfItems(int numberOfItems);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();


	// Unit logic.
	Unit* _units;
	int _numberOfUnits;
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
};

