#include <string>

using namespace std;

#pragma once
class UnitSkill
{
public:
	UnitSkill(string name, int skillLevel);
	string Name();
	void Name(string name);
	int SkillLevel();
	void SkillLevel(int skillLevel);
private:
	string _name;
	int _skillLevel;
};

