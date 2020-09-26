#include "DieType.h"
#include "CoinSide.h"

#pragma once
class DiceRoller
{
public:
	int RollDice(int numberOfDice, DieType dieType);
	CoinSide TossCoin();
};

