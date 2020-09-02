#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "MapController.h"

using namespace std;

int main()
{
	Tile** tiles = new Tile * [128]{ };
	MapItem* items = new MapItem[256]{};

	for (int j = 0; j < 128; j++)
	{
		Tile* tilesT = new Tile[128]{};
		for (int i = 0; i < 128; i++)
		{
			tilesT[i] = *new Tile[128]{ *new Tile((TileType)(rand() % 2 + 1), rand() % 3 + 1) };
		}
		tiles[j] = tilesT;
	}

	ofstream myfile;
	myfile.open("mapresult.txt");
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			myfile << to_string((int)tiles[i][j].Type()) + to_string(tiles[i][j].Height()) + " ";
		}
		myfile << "\n";
	}
	myfile.close();

	for (int i = 0; i < 256; i++)
	{
		items[i] = MapItem{ 0, 0, *new Item("Item_" + to_string(i)) };
	}

	MapController mapController =
		*new MapController(1, 1, tiles);
}