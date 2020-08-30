#include "Tile.h"

Tile::Tile(int x, int y)
{
	Type(TileType::Grass);
	Height(0);
}

Tile::Tile(int x, int y, TileType type)
{
	Type(type);
	Height(0);
}

Tile::Tile(int x, int y, int height)
{
	Height(height);
	Type(TileType::Grass);
}

Tile::Tile(int x, int y, TileType type, int height)
{
	Height(height);
	Type(type);
}

Tile::~Tile()
{
	delete this;
}

TileType Tile::Type()
{
	return this->_type;
}

void Tile::Type(TileType type)
{
	this->_type = type;
	ImagePath(type);
}

void Tile::ImagePath(TileType type)
{
	switch (type)
	{
	case TileType::Grass:
		ImagePath("Grass.png");
		break;
	default:
		break;
	}
}

int Tile::Height()
{
	return this->_height;
}

void Tile::Height(int height)
{
	this->_height = height;
}

string Tile::ImagePath()
{
	return this->_path;
}

void Tile::ImagePath(string path)
{
	this->_path = path;
}