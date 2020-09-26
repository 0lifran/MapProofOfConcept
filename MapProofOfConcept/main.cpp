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
	MapController* mapController = new MapController(mapWidth, mapHeight, tiles);

	Item* item1 = itemProducer.ProduceItem(ItemPreset::SemiAutomaticPistol);
	Unit* unit1 = new Unit(1, 1, "Unit1", "Unit.png");
	mapController->AddUnit(unit1);

	tiles[0][0].ItemHandler()->AddItem(item1);
	//unit1->UnitItem(tiles[0][0].ItemHandler()->TakeOutItem(item1->Id()),UnitBodyPart::RightHand);

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

		cout << unit1->UnitItem(UnitBodyPart::RightHand)->Name() << endl;

		cin >> inputKey;
		switch (inputKey)
		{
		case 'a':
		{
			mapController->RotateUnit(unit1, RotationDirection::Left);
			break;
		}
		case 'd':
		{
			mapController->RotateUnit(unit1, RotationDirection::Right);
			break;
		}
		case 'w':
		{
			mapController->MoveUnit(unit1);
			break;
		}
		case 't':
		{
			// Pick up item from ground.
			if (tiles[unit1->X()][unit1->Y()].ItemHandler()->NumberOfItems() != 0)
			{
				int id = tiles[unit1->X()][unit1->Y()].ItemHandler()->Items()[0].Id();
				Item* item = tiles[unit1->X()][unit1->Y()].ItemHandler()->TakeOutItem(id);
				mapController->InitializeInventory(unit1);
				mapController->InventoryHandler()->AttachItemToUnit(item, UnitBodyPart::RightHand);
			}
			else 
			{
				cout << "Nothing there!" << endl;
				cin.get();
			}
			break;
		}
		case 'r':
		{
			Item* item = mapController->InventoryHandler()->DetachItemFromUnit(UnitBodyPart::RightHand);
			tiles[unit1->X()][unit1->Y()].ItemHandler()->AddItem(item);
		}
		case 'i':
		{
			cout << "Inventory" << endl;
			cout << "*********" << endl;
			cout << "Head: " << unit1->UnitItem(UnitBodyPart::Head)->Name() << endl;
			cout << "Torso: " << unit1->UnitItem(UnitBodyPart::Torso)->Name() << endl;
			cout << "Back: " << unit1->UnitItem(UnitBodyPart::Back)->Name() << endl;
			cout << "Hands: " << unit1->UnitItem(UnitBodyPart::Hands)->Name() << endl;
			cout << "LeftHand: " << unit1->UnitItem(UnitBodyPart::LeftHand)->Name() << endl;
			cout << "RightHand: " << unit1->UnitItem(UnitBodyPart::RightHand)->Name() << endl;
			cout << "Legs: " << unit1->UnitItem(UnitBodyPart::Legs)->Name() << endl;
			cout << "Feet: " << unit1->UnitItem(UnitBodyPart::Feet)->Name() << endl;
			char inputInventory = ' ';
			while (inputInventory != 'c')
			{
				cin >> inputInventory;
			}
			break;
		}
		case 'f':
		{
			// mapController->AttackWithUnit();
			if (unit1->UnitItem(UnitBodyPart::RightHand)->Type() == ItemType::Weapon)
			{
				ItemClassConverter* ic = new ItemClassConverter();
				Weapon* ui = ic->ConvertToWeapon(unit1->UnitItem(UnitBodyPart::RightHand));
				if (ui->SubType() == WeaponType::Ballistic)
				{
					BallisticWeapon* bW = ic->ConvertToBallisticWeapon(ui);
					// double distance = GetDistanceToTargetTile(startTile, targetTile);
					// Vector3d vector = CalculateTargetVector();

					double distance = 0;

					if (bW->MaximumRange() < distance)
					{
						if (bW->Fire())
						{
							
						}
						else
						{
							if (bW->Magazine()->BulletsLeft() == 0)
							{
								cout << "Weapon is empty.";
							}
						}
					}
					else
					{
						cout << "Target is too far away for this weapon.";
					}
					
				}
			}
			else
			{
				cout << "This is not a weapon!" << endl;
				cin.get();
			}
		}
		}
	}
}