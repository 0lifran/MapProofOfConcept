#include <stdio.h>
#include <iostream>
#include "MapController.h"

using namespace std;

int main()
{
	Tile** tiles = new Tile * [128];

	for (int i = 0; i < 128; i++)
	{
		if (i % 2 == 0)
		{
			tiles[i] = new Tile[128]{ *new Tile(TileType::Grass) };
		}
		else 
		{
			tiles[i] = new Tile[128]{ *new Tile() };

		}
		
	}
	

	MapController mapController = 
		*new MapController(1,1, tiles,1);
}