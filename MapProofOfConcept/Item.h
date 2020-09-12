#include <string>
#include "ItemType.h"

#pragma once

using namespace std;

class Item
{
public:
	Item(string name, ItemType type);
	Item();
	int Id();
	int X();
	int Y();
	void X(int x);
	void Y(int y);
	string Name();
	void Name(string name);
	ItemType Type();
	void Type(ItemType type);

	// Image data
	string ImagePath();
	void ImagePath(string path);

private:
	void Id(int id);

	int _id;
	int _x;
	int _y;
	string _name;
	string _imagePath;
	ItemType _type;
};

