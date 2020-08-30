#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item(string Name);
	Item();
	int Id();
	string Name();
	void Name(string name);

	// Image data
	string ImagePath();
	void ImagePath(string path);

private:
	void Id(int id);

	int _id;
	string _name;
	string _imagePath;
};

