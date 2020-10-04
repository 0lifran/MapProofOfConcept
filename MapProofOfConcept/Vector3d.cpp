#include "Vector3d.h"

Vector3d::Vector3d(int x, int y, int z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

int Vector3d::X()
{
	return this->_x;
}

int Vector3d::Y()
{
	return this->_y;
}

int Vector3d::Z()
{
	return this->_z;
}

void Vector3d::X(int x)
{
	this->_x = x;
}

void Vector3d::Y(int y)
{
	this->_y = y;
}

void Vector3d::Z(int z)
{
	this->_z = z;
}