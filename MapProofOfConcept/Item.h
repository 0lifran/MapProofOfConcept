#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item();

	int Id();

	// Image data
	string ImagePath();
	void ImagePath(string path);

private:
	void Id(int id);

	int _id;
	string _imagePath;
};

