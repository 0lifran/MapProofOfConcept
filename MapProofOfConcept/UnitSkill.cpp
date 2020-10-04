#include "UnitSkill.h"

UnitSkill::UnitSkill(string name, int skillLevel)
{
	this->Name(name);
	this->SkillLevel(skillLevel);
}

string UnitSkill::Name()
{
	return this->_name;
}

void UnitSkill::Name(string name) 
{
	this->_name = name;
}

int UnitSkill::SkillLevel()
{
	return this->_skillLevel;
}

void UnitSkill::SkillLevel(int skillLevel)
{
	this->_skillLevel = skillLevel;
}