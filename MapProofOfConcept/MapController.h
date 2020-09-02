#include "Tile.h"
#include "RenderDataArray.h"
#include "Item.h"
#include "MapItem.h"

#pragma once
class MapController
{
public:
	MapController(int width, int height, Tile** tiles);
	RenderDataArray* GetRenderData();

private:
	const short _MAXMAPWIDTH = 128;
	const short _MAXMAPHEIGHT = 128;
	const short _MAXITEMNUMBERPERTILE = 32;

	// Unit** _units;		  TTT  III	UUU
	// Item** _items;		  TTT  III	UUU
	// Tile** _tiles;         TTT  III	UUU

	Tile** _tiles;	
	
	MapItem* _mapItems;

	int _mapWidth;
	int _mapHeight;

	int MapWidth();
	void MapWidth(int width);

	int MapHeight();
	void MapHeight(int height);

	Tile* SpecificTileAt(int x, int y);
	void SpecificTileAt(Tile* tile, int x, int y);

	Tile** Tiles();
	void Tiles(int mapWidth, int mapHeight, Tile** tiles);
};

