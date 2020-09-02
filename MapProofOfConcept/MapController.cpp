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