#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "MapController.h"

using namespace std;

int main()
{
	// test code.
	Tile** tiles = new Tile * [25];
	for (int i = 0; i < 25; i++)
	{
		tiles[i] = new Tile[25];
		for (int j = 0; j < 25; j++)
		{
			tiles[i][j] = *new Tile(TileType::Grass, 0);
		}
	}

	Item item1 = *new Item("Item_1");
	Item item2 = *new Item("Item_1");
	Unit unit1 = *new Unit(1,1,"Unit_1", "Unit.png");
	Unit unit2 = *new Unit(1,2,"Unit_2", "Unit.png");

	tiles[0][0] = *new Tile(TileType::Mud, 2);
	tiles[1][0] = *new Tile(TileType::Mud, 2);
	tiles[2][0] = *new Tile(TileType::Mud, 2);
	tiles[0][0] = *new Tile(TileType::Mud, 2);
	tiles[0][1] = *new Tile(TileType::Mud, 2);
	tiles[0][2] = *new Tile(TileType::Mud, 2);
	tiles[1][1].AddUnit(1,1,unit1);
	tiles[1][1].AddItem(&item1);

	MapController* mapController = new MapController(25, 25, tiles);
	mapController->AddUnit(&unit2);

	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			if (tiles[x][y].NumberOfUnits() == 0)
			{
				if (tiles[x][y].Type() == TileType::Grass)
				{
					cout << "g" << " ";
				}
				else if (tiles[x][y].Type() == TileType::Mud)
				{
					cout << "m" << " ";
				}
				else
				{
					cout << "?" << " ";
				}
			}
			else 
			{
				cout << "U" << " ";
			}
		}
		cout << endl;
	}
	cout << "Success";
}