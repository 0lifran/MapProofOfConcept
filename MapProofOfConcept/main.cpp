#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "MapController.h"
#include "Printer.h"

using namespace std;

int main()
{
	// test code.
	Printer _printer = *new Printer();
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
	Unit unit1 = *new Unit(1, 1, "Unit_1", "Unit.png");
	Unit unit2 = *new Unit(1, 2, "Unit_2", "Unit.png");

	tiles[5][5] = *new Tile(TileType::Mud, 0);
	tiles[5][6] = *new Tile(TileType::Snow, 0);
	tiles[5][7] = *new Tile(TileType::Water, 0);

	tiles[1][1].AddUnit(1, 1, unit1);
	tiles[8][8].AddItem(&item1);

	MapController* mapController = new MapController(25, 25, tiles);
	mapController->AddUnit(&unit2);

	char inputKey = ' ';
	while (inputKey != '0')
	{
		system("CLS");
		for (int y = 0; y < 25; y++)
		{
			for (int x = 0; x < 25; x++)
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

		cout << tiles[1][1].NumberOfUnits();
		cout << "Input: ";
		cin >> inputKey;
		switch (inputKey)
		{
		case 'w':
			mapController->MoveUnit(3);
			break;
		case 'a':
			mapController->RotateUnit(3, RotationDirection::Left);
			break;
		case 'd':
			mapController->RotateUnit(3, RotationDirection::Right);
			break;
		default:
			break;
		}
	}
}