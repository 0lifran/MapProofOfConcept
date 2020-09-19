#include <string>
#include "ItemType.h"

#pragma once

using namespace std;

class Item
{
public:
	Item(int id, string name, ItemType type, int storageSpace);
	Item(string name, ItemType type, int storageSpace);
	Item();
	void Id(int id);
	int Id();
	int X();
	int Y();
	void X(int x);
	void Y(int y);
	string Name();
	void Name(string name);
	ItemType Type();
	void Type(ItemType type);
	int StorageSpace();
	void StorageSpace(int storageSpace);

	// Image data
	string ImagePath();
	void ImagePath(string path);

private:
	

	int _id;
	int _x;
	int _y;
	string _name;
	string _imagePath;
	ItemType _type;
	int _storageSpace;
};

