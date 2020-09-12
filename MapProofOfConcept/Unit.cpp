#include "Unit.h"
#include "IdManager.h"

Unit::Unit(int x, int y, string name, string imagePath)
{
	this->X(x);
	this->Y(y);
	this->Name(name);
	this->ImagePath(imagePath);
	IdManager idHandler = *new IdManager();
	this->Id(idHandler.GetNewId());
}

Unit::Unit()
{
	this->X(-1);
	this->Y(-1);
	this->Name("None");
	this->ImagePath("None");
	this->Id(-1);
}

int Unit::X()
{
	return this->_x;
}
int Unit::Y()
{
	return this->_y;
}
void Unit::X(int x)
{
	this->_x = x;
}
void Unit::Y(int y)
{
	this->_y = y;
}

int Unit::Id()
{
	return this->_id;
}

void Unit::Id(int id)
{
	this->_id = id;
}

string Unit::Name()
{
	return this->_name;
}
void Unit::Name(string name)
{
	this->_name = name;
}

void Unit::Rotate(RotationDirection rotationDirection)
{
	if (rotationDirection == RotationDirection::Left)
	{
		switch (this->DirectionAngle())
		{
		case Direction::North:
			DirectionAngle(Direction::NorthWest);
			break;
		default:
			int directionAsNumber = (int)this->DirectionAngle();
			directionAsNumber = directionAsNumber - 1;
			DirectionAngle((Direction)directionAsNumber);
			break;
		}
	}
	else
	{
		switch (this->DirectionAngle())
		{
		case Direction::NorthWest:
			DirectionAngle(Direction::North);
			break;
		default:
			int directionAsNumber = (int)this->DirectionAngle();
			directionAsNumber = directionAsNumber + 1;
			DirectionAngle((Direction)directionAsNumber);
			break;
		}
	}
}

Direction Unit::DirectionAngle()
{
	return this->_directionAngle;
}

void Unit::DirectionAngle(Direction direction)
{
	this->_directionAngle = direction;
}

// Image data
string Unit::ImagePath()
{
	return this->_imagePath;
}
void Unit::ImagePath(string path)
{
	this->_imagePath = path;
}

void Unit::Move()
{
	switch (DirectionAngle())
	{
	case Direction::North:
		this->Y(this->Y() - 1);
		break;

	case Direction::NorthEast:
		this->X(this->X() + 1);
		this->Y(this->Y() - 1);
		break;

	case Direction::East:
		this->X(this->X() + 1);
		break;

	case Direction::SouthEast:
		this->X(this->X() + 1);
		this->Y(this->Y() + 1);
		break;

	case Direction::South:
		this->Y(this->Y() + 1);
		break;

	case Direction::SouthWest:
		this->X(this->X() - 1);
		this->Y(this->Y() + 1);
		break;

	case Direction::West:
		this->X(this->X() - 1);
		break;

	case Direction::NorthWest:
		this->X(this->X() - 1);
		this->Y(this->Y() - 1);
		break;
	}
}