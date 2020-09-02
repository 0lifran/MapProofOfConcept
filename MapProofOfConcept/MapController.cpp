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

// Item logic.
int MapController::NumberOfItems()
{
	return this->_numberOfItems;
}
void MapController::NumberOfItems(int numberOfItems)
{
	this->_numberOfItems = numberOfItems;
}
void MapController::IncrementNumberOfItems()
{
	this->_numberOfItems++;
}
void MapController::DecrementNumberOfItems()
{
	this->_numberOfItems--;
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
			this->_tiles[x][y].AddItem(currentItems);
			return;
		}
	}
	throw new exception("test");
}

// Unit logic.
void MapController::RemoveUnit(int id)
{

}
void MapController::PlaceUnit(int id, int x, int y)
{

}
void MapController::MoveUnit(int id)
{

}
void MapController::RotateUnit(int id, RotationDirection rotationDirection)
{

}

Item* MapController::Items()
{
	return this->_items;
}

Unit* MapController::Units()
{
	return this->_units;
}