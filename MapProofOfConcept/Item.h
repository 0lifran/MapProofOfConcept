#include "IdManager.h"
#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item(string Name);
	Item();
	int Id();
	int X();
	int Y();
	void X(int x);
	void Y(int y);
	string Name();
	void Name(string name);

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
};

