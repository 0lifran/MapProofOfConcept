#include <string>
#include "TileType.h"

using namespace std;

#pragma once
class Tile
{
public:
	Tile(int x, int y);
	Tile(int x, int y, TileType type);
	Tile(int x, int y, int height);
	Tile(int x, int y, TileType type, int height);
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

private:
	int _height;
	string _path;
	TileType _type;
};

