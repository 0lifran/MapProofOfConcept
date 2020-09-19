#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "MapController.h"
#include "Printer.h"
#include "ItemFactory.h"
#include "ItemClassConverter.h"

using namespace std;

int main()
{
	int mapWidth = 10;
	int mapHeight = 10;
	// test code.
	Printer _printer = *new Printer();
	Tile** tiles = new Tile * [mapWidth];
	ItemFactory itemProducer = *new ItemFactory();
	ItemClassConverter itemClassTransformer = *new ItemClassConverter();

	for (int i = 0; i < mapWidth; i++)
	{
		tiles[i] = new Tile[mapHeight];
		for (int j = 0; j < mapHeight; j++)
		{
			tiles[i][j] = *new Tile(TileType::Grass, 0);
		}
	}

	Item item1 = *new Item("Item_1", ItemType::Common, 1);
	Item item2 = *new Item("Item_2", ItemType::Common, 1);

	Unit* unit1 = new Unit(1, 1, "Unit_1", "Unit.png");
	Unit* unit2 = new Unit(1, 2, "Unit_2", "Unit.png");

	unit2->UnitItem(itemProducer.ProduceItem(ItemPreset::Backpack), UnitBodyPart::Back);

	tiles[5][5] = *new Tile(TileType::Mud, 1);
	tiles[5][6] = *new Tile(TileType::Snow, 3);
	tiles[5][7] = *new Tile(TileType::Water, 2);

	tiles[1][1].AddUnit(1, 1, unit1);

	Weapon w = *new Weapon("test", ItemType::Weapon, 32, 2, WeaponType::Ballistic, 0, 0, 0, 0, 0, 0, 0, 0);
	BallisticWeapon www = *new BallisticWeapon(
		"bal", 
		ItemType::Weapon, 
		32, 
		2, 
		WeaponType::Ballistic, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		*new BallisticMagazine(
			0,
			0,
			BallisticMagazineType::NineMm), 
		BallisticMagazineType::NineMm);

	tiles[4][5].ItemHandler()->AddItem(static_cast<Item*>(&w));
	tiles[4][5].ItemHandler()->AddItem(static_cast<Item*>(&www));

	Item* ww = itemProducer.ProduceItem(ItemPreset::SemiAutomaticPistol);
	tiles[4][4].ItemHandler()->AddItem(ww);
	ItemManager* itemHandler = tiles[8][8].ItemHandler();

	itemHandler->AddItem(&item1);

	MapController* mapController = new MapController(mapWidth, mapHeight, tiles);
	mapController->AddUnit(unit2);

	char inputKey = ' ';

	bool toggle = false;
	while (inputKey != '0')
	{
		system("CLS");
		for (int y = 0; y < mapHeight; y++)
		{
			for (int x = 0; x < mapWidth; x++)
			{
				ItemManager* itemHandler = tiles[x][y].ItemHandler();
				if (itemHandler->NumberOfItems() == 0 && tiles[x][y].NumberOfUnits() == 0)
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

		/*cout << "Inventory unit 1" << endl;
		cout << "================" << endl;
		cout << "Head: " << unit1->UnitItem(UnitBodyPart::Head)->Name() << endl;
		cout << "Torso: " << unit1->UnitItem(UnitBodyPart::Torso)->Name() << endl;
		cout << "Left Hand: " << unit1->UnitItem(UnitBodyPart::LeftHand)->Name() << endl;
		cout << "Right Hand: " << unit1->UnitItem(UnitBodyPart::RightHand)->Name() << endl;
		cout << "Back: " << unit1->UnitItem(UnitBodyPart::Back)->Name() << endl;
		cout << "Legs: " << unit1->UnitItem(UnitBodyPart::Legs)->Name() << endl;
		cout << "Feet: " << unit1->UnitItem(UnitBodyPart::Feet)->Name() << endl;

		cout << endl << endl;

		cout << "Inventory unit 2" << endl;
		cout << "================" << endl;
		cout << "Head: " << unit2->UnitItem(UnitBodyPart::Head)->Name() << endl;
		cout << "Torso: " << unit2->UnitItem(UnitBodyPart::Torso)->Name() << endl;
		cout << "Left Hand: " << unit2->UnitItem(UnitBodyPart::LeftHand)->Name() << endl;
		cout << "Right Hand: " << unit2->UnitItem(UnitBodyPart::RightHand)->Name() << endl;
		cout << "Back: " << unit2->UnitItem(UnitBodyPart::Back)->Name() << endl;
		cout << "Legs: " << unit2->UnitItem(UnitBodyPart::Legs)->Name() << endl;
		cout << "Feet: " << unit2->UnitItem(UnitBodyPart::Feet)->Name() << endl;*/

		cout << "1: " << unit1->UnitItem(UnitBodyPart::RightHand)->Name() << endl;
		cout << "2: " << unit2->UnitItem(UnitBodyPart::RightHand)->Name() << endl;

		if (toggle)
		{
			cout << "3" << endl;
		}
		else
		{
			cout << "4" << endl;
		}

		cout << "(w) Move (a) Rotate left (d) Rotate right (x) Swap unit selection (g) Add item from ground to rucksack as unit 3 (j) Take pistol from ground (0) Exit" << endl << endl;
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
		{
			cout << "g";
			cin.get();
			break;
		}
		case 'j':
		{
			Item* fromGround = &tiles[4][4].ItemHandler()->TakeOutItem(6);
			Unit* current = mapController->GetUnitById(toggle ? 3 : 4);
			current->UnitItem(fromGround, UnitBodyPart::RightHand);
			if (toggle)
			{
				unit1 = current;
			}
			else
			{
				unit2 = current;
			}
			cout << "j";
			cin.get();
			break;
		}
		case 'x':
			toggle = !toggle;
		default:
			break;
		}
	}
}