#include <string>
#include "TileType.h"
#include "Item.h"
#include "Unit.h"

using namespace std;

#pragma once
class Tile
{
public:
	Tile();
	Tile(TileType type);
	Tile(int height);
	Tile(TileType type, int height);
	~Tile();

	// Tile data
	int Height();
	void Height(int height);

	TileType Type();
	void Type(TileType type);

	// Image data
	string ImagePath();
	void ImagePath(string path);
	void ImagePath(TileType type);

	// Item data
	Item* Items();
	void Items(Item* items);
	void AddItem(Item* item);
	bool TakeOutItem(int id, Item* out);
	int NumberOfItems();
	void NumberOfItems(int numberOfItems);
	int IncrementNumberOfItems();
	int DecrementNumberOfItems();
	Item* GetItemAtPosition(int positionAt);
	void RemoveItemAtPosition(int positionAt);

	// Unit data
	Unit* Units();
	void Units(Unit* unit);
	void AddUnit(int x, int y, Unit unit);
	bool TakeOutUnit(int id, Unit* out);
	int NumberOfUnits();
	void NumberOfUnits(int numberOfUnits);
	int IncrementNumberOfUnits();
	int DecrementNumberOfUnits();
	Unit* GetUnitAtPosition(int positionAt);
	void RemoveUnitAtPosition(int positionAt);
	void SetOccupied(bool state);
	bool IsOccupiedByUnit();

private:
	int _height = 0;
	string _path;
	TileType _type;
	Item* _items;
	int _numberOfItems = 0;
	Unit* _units;
	int _numberOfUnits = 0;
	bool _isOccupiedByUnit = false;
};

