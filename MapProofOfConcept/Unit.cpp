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
	this->DirectionAngle(Direction::South);

	this->Head(new Item());
	this->Torso(new Item());
	this->Back(new Item());
	this->Hands(new Item());
	this->LeftHand(new Item());
	this->RightHand(new Item());
	this->Legs(new Item());
	this->Feet(new Item());
}

Unit::Unit()
{
	this->X(-1);
	this->Y(-1);
	this->Name("None");
	this->ImagePath("None");
	this->Id(-1);
	this->DirectionAngle(Direction::None);

	this->Head(new Item());
	this->Torso(new Item());
	this->Back(new Item());
	this->Hands(new Item());
	this->LeftHand(new Item());
	this->RightHand(new Item());
	this->Legs(new Item());
	this->Feet(new Item());
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

Item* Unit::Head()
{
	return this->_head;
}

void Unit::Head(Item* item)
{
	this->_head = item;
}

Item* Unit::LeftHand()
{
	return this->_leftHand;
}

void Unit::LeftHand(Item* item)
{
	this->_leftHand = item;
}

Item* Unit::RightHand()
{
	return this->_rightHand;
}

void  Unit::RightHand(Item* item)
{
	this->_rightHand = item;
}

Item* Unit::Hands()
{
	return this->_hands;
}

void Unit::Hands(Item* item)
{
	this->_hands = item;
}

Item* Unit::Torso()
{
	return this->_torso;
}

void Unit::Torso(Item* item)
{
	this->_torso = item;
}

Item* Unit::Back()
{
	return this->_back;
}

void Unit::Back(Item* item)
{
	this->_back = item;
}

Item* Unit::Legs()
{
	return this->_legs;
}

void Unit::Legs(Item* item)
{
	this->_legs = item;
}

Item* Unit::Feet()
{
	return this->_feet;
}

void Unit::Feet(Item* item)
{
	this->_feet = item;
}

Item* Unit::UnitItem(UnitBodyPart bodyPart)
{
	switch (bodyPart)
	{
	case UnitBodyPart::Back:
	{
		return this->Back();
		break;
	}
	case UnitBodyPart::Feet:
	{
		return this->Feet();
		break;
	}
	case UnitBodyPart::Hands:
	{
		return this->Hands();
		break;
	}
	case UnitBodyPart::Head:
	{
		return this->Head();
		break;
	}
	case UnitBodyPart::LeftHand:
	{
		return this->LeftHand();
		break;
	}
	case UnitBodyPart::Legs:
	{
		return this->Legs();
		break;
	}
	case UnitBodyPart::RightHand:
	{
		return this->RightHand();
		break;
	}
	case UnitBodyPart::Torso:
	{
		return this->Torso();
		break;
	}
	default:
	{
		throw new exception("Unknown unit body part.");
	}
	}
}

void Unit::UnitItem(Item* item, UnitBodyPart bodyPart)
{
	switch (bodyPart)
	{
	case UnitBodyPart::Back:
	{
		this->Back(item);
		break;
	}
	case UnitBodyPart::Feet:
	{
		this->Feet(item);
		break;
	}
	case UnitBodyPart::Hands:
	{
		this->Hands(item);
		break;
	}
	case UnitBodyPart::Head:
	{
		this->Head(item);
		break;
	}
	case UnitBodyPart::LeftHand:
	{
		this->LeftHand(item);
		break;
	}
	case UnitBodyPart::Legs:
	{
		this->Legs(item);
		break;
	}
	case UnitBodyPart::RightHand:
	{
		this->RightHand(item);
		break;
	}
	case UnitBodyPart::Torso:
	{
		this->Torso(item);
		break;
	}
	default:
	{
		throw new exception("Unknown unit body part.");
	}
	}
}