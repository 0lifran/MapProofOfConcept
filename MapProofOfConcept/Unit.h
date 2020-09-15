#pragma once
#include <string>
#include "RotationDirection.h"
#include "Direction.h"
#include "Item.h"
#include "UnitBodyPart.h"

using namespace std;

class Unit
{
public:
	Unit();
	Unit(int x, int y, string name, string imagePath);

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

	Item* UnitItem(UnitBodyPart bodyPart);
	void UnitItem(Item* item, UnitBodyPart bodyPart);

	

private:
	void Id(int id);
	void DirectionAngle(Direction direction);

	int _id;
	int _x;
	int _y;
	string _name;
	Direction _directionAngle;
	string _imagePath;

	Item* _head;
	Item* _leftHand;
	Item* _rightHand;
	Item* _hands;
	Item* _torso;
	Item* _back;
	Item* _legs;
	Item* _feet;

	Item* Head();
	void Head(Item* item);
	Item* LeftHand();
	void LeftHand(Item* item);
	Item* RightHand();
	void  RightHand(Item* item);
	Item* Hands();
	void Hands(Item* item);
	Item* Torso();
	void Torso(Item* item);
	Item* Back();
	void Back(Item* item);
	Item* Legs();
	void Legs(Item* item);
	Item* Feet();
	void Feet(Item* item);

};

