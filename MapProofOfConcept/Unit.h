#pragma once
#include <string>
#include "RotationDirection.h"
#include "Direction.h"

using namespace std;

class Unit
{
public:
	int Id();
	int X();
	int Y();
	void X(int x);
	void Y(int y);
	void Move();

	string Name();
	void Name(string name);

	void Rotate(RotationDirection rotationDirection);
	Direction DirectionAngle();

	// Image data
	string ImagePath();
	void ImagePath(string path);

private:
	void Id(int id);
	void DirectionAngle(Direction direction);

	int _id;
	int _x;
	int _y;
	string _name;
	Direction _directionAngle;
	string _imagePath;
};

