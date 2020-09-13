#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "MapController.h"
#include "Printer.h"

using namespace std;

int main()
{
	int mapWidth = 10;
	int mapHeight = 10;
	// test code.
	Printer _printer = *new Printer();
	Tile** tiles = new Tile * [mapWidth];
	for (int i = 0; i < mapWidth; i++)
	{
		tiles[i] = new Tile[mapHeight];
		for (int j = 0; j < mapHeight; j++)
		{
			tiles[i][j] = *new Tile(TileType::Grass, 0);
		}
	}

	Item item1 = *new Item("Item_1", ItemType::Common);
	Item item2 = *new Item("Item_2", ItemType::Common);
	Unit unit1 = *new Unit(1, 1, "Unit_1", "Unit.png");
	Unit unit2 = *new Unit(1, 2, "Unit_2", "Unit.png");

	Item item3 = *new Item("Backpack", ItemType::Container);
	unit1.Back(&item3);

	tiles[5][5] = *new Tile(TileType::Mud, 1);
	tiles[5][6] = *new Tile(TileType::Snow, 3);
	tiles[5][7] = *new Tile(TileType::Water, 2);

	tiles[1][1].AddUnit(1, 1, unit1);
	tiles[8][8].AddItem(&item1);

	MapController* mapController = new MapController(mapWidth, mapHeight, tiles);
	mapController->AddUnit(&unit2);

	char inputKey = ' ';

	bool toggle = false;
	while (inputKey != '0')
	{
		system("CLS");
		for (int y = 0; y < mapHeight; y++)
		{
			for (int x = 0; x < mapWidth; x++)
			{
				if (tiles[x][y].NumberOfItems() == 0 && tiles[x][y].NumberOfUnits() == 0)
				{
					if (tiles[x][y].Type() == TileType::Grass)
					{
						cout << _printer.formatString("#", TerminalColor::Green) << " ";
					}
					else if (tiles[x][y].Type() == TileType::Mud)
					{
						cout << _printer.formatString("#", TerminalColor::Yellow) << " ";
					}
					else if (tiles[x][y].Type() == TileType::Water)
					{
						cout << _printer.formatString("#", TerminalColor::Blue) << " ";
					}
					else if (tiles[x][y].Type() == TileType::Snow)
					{
						cout << _printer.formatString("#", TerminalColor::White) << " ";
					}
					else
					{
						cout << "?" << " ";
					}
				}
				else
				{
					if (tiles[x][y].NumberOfUnits() > 0)
					{
						cout << _printer.formatString("U", TerminalColor::BrightWhite) << " ";
					}
					else
					{
						cout << _printer.formatString("*", TerminalColor::BrightWhite) << " ";
					}
				}
			}
			cout << endl;
		}

		cout << "(w) Move (a) Rotate left (d) Rotate right (x) Swap unit selection (g) Take item on top on this tile (0) Exit" << endl << endl;
		cout << "Input: ";
		cin >> inputKey;
		switch (inputKey)
		{
		case 'w':
			mapController->MoveUnit(toggle ? 3 : 4);
			break;
		case 'a':
			mapController->RotateUnit(toggle ? 3 : 4, RotationDirection::Left);
			break;
		case 'd':
			mapController->RotateUnit(toggle ? 3 : 4, RotationDirection::Right);
			break;
		case 'g':

			break;
		case 'x':
			toggle = !toggle;
		default:
			break;
		}
	}
}