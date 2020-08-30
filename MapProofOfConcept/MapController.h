#include "Tile.h"
#include "RenderDataArray.h"
#include "Item.h"
#include "MapItem.h"

#pragma once
class MapController
{
public:
	MapController(int width, int height, Tile** tiles, MapItem* items, int numberOfItems);
	RenderDataArray* GetRenderData();

private:
	const short _MAXMAPWIDTH = 128;
	const short _MAXMAPHEIGHT = 128;
	const short _MAXITEMNUMBERPERTILE = 32;

	// Unit** _units;		  TTT  III	UUU
	// Item** _items;		  TTT  III	UUU
	// Tile** _tiles;         TTT  III	UUU

	Tile** _tiles;	
	Item*** _items;
	MapItem* _mapItems;

	int _mapWidth;
	int _mapHeight;
	int _numberOfItems;


	void PlaceItem(MapItem mapItem);
	// Places item at x,y
	bool PlaceItemOnTile(Item item, int x, int y);

	// Place item in map items
	void PlaceItemInMapItems(MapItem item);

	// Move unit forward.
	void MoveUnit(int id);

	// Removes unit from unit array.
	void RemoveUnit(int id);

	// Places item at x,y
	void PlaceUnit(/*Unit unit, */int x, int y);

	// Removes an item from the item array.
	void RemoveItem(int id);

	int MapWidth();
	void MapWidth(int width);

	int MapHeight();
	void MapHeight(int height);

	Tile* SpecificTileAt(int x, int y);
	void SpecificTileAt(Tile* tile, int x, int y);

	Tile** Tiles();
	void Tiles(int mapWidth, int mapHeight, Tile** tiles);

	void Items(int numberOfItems, MapItem* items);

	int NumberOfItems();
	void NumberOfItems(int numberOfItems);
	void IncrementNumberOfItems();
	void DecrementNumberOfItems();
};

