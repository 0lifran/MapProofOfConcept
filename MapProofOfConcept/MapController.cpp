#include "MapController.h"
#include "RenderData.h"
#include "RenderDataArray.h"


MapController::MapController(int width, int height, Tile** tiles, MapItem* items, int numberOfItems)
{
	Tiles(width, height, tiles);
	Items(numberOfItems, items);
}

void MapController::Items(int numberOfItems, MapItem* items)
{
	NumberOfItems(numberOfItems);

	_items[128][128][1] = {};
	_mapItems[1024] = {NULL};
	for (int i = 0; i < numberOfItems; i++)
	{
		PlaceItem(items[i]);
	}
}

void MapController::PlaceItem(MapItem item)
{
	if (PlaceItemOnTile(item.Item, item.X, item.Y))
	{
		PlaceItemInMapItems(item);
	}
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

void MapController::MoveUnit(int id)
{
}

void MapController::RemoveUnit(int id)
{
}

void MapController::PlaceUnit(/*Unit unit, */int x, int y)
{
}

void MapController::RemoveItem(int id)
{
}

bool MapController::PlaceItemOnTile(Item item, int x, int y)
{
	// Temporary solution.
	for (int i = 0; i < NumberOfItems(); i++)
	{
		if (this->_mapItems[i].X == x && this->_mapItems[i].Y == y)
		{
			this->_mapItems[i].Item = item;
			this->_items[x][y][0] = item;
			return true;
		}
	}

	IncrementNumberOfItems();
	this->_mapItems[NumberOfItems() - 1].Item = item;
	this->_items[x][y][0] = item;
	return true;
}

void MapController::PlaceItemInMapItems(MapItem item)
{
	_mapItems[NumberOfItems() - 1] = item;
}

int MapController::NumberOfItems()
{
	return this->_numberOfItems;
}

void MapController::NumberOfItems(int numberOfItems)
{
	if (numberOfItems > _MAXITEMNUMBERPERTILE)
	{
		this->_numberOfItems = _MAXITEMNUMBERPERTILE;
	}
	else 
	{
		this->_numberOfItems = numberOfItems;
	}
}

void MapController::IncrementNumberOfItems()
{
	this->_numberOfItems++;
}
void MapController::DecrementNumberOfItems()
{
	this->_numberOfItems--;
}