#include <string>
#include "TileType.h"
#include "Item.h"

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

private:
	int _height;
	string _path;
	TileType _type;
	Item* _items;
	int _numberOfItems;
};

