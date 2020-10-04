#pragma once

class Vector3d
{
public:
	Vector3d(int x, int y, int z);
	int X();
	int Y();
	int Z();
	void X(int x);
	void Y(int y);
	void Z(int z);

private:
	int _x;
	int _y;
	int _z;
};