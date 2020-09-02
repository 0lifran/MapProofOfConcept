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
	const short _MAXMAPWIDTH = 128;
	const short _MAXMAPHEIGHT = 128;

	Tile** _tiles;	
	int _mapWidth;
	int _mapHeight;

	int MapWidth();
	void MapWidth(int width);

	int MapHeight();
	void MapHeight(int height);

	Tile* SpecificTileAt(int x, int y);
	void SpecificTileAt(Tile* tile, int x, int y);

	// Item logic.
	void RemoveItem(int id);
	void PlaceItem(int id, int x, int y);

	// Unit logic.
	void RemoveUnit(int id);
	void PlaceUnit(int id, int x, int y);
	void MoveUnit(int id);
	void RotateUnit(RotationDirection rotationDirection);

	// TileMap.
	Tile** Tiles();

	Item* Items();
	Unit* Units();


	void Tiles(int mapWidth, int mapHeight, Tile** tiles);
};

