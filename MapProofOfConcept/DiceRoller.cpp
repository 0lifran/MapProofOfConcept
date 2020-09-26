#include "DiceRoller.h"
#include <stdlib.h>

int DiceRoller::RollDice(int numberOfDice, DieType dieType)
{
	switch (dieType)
	{
	case DieType::DSix: 
	{
		int sum = 0;
		for (int i = 0; i < numberOfDice; i++)
		{
			sum += rand() % 6 + 1;
		}
		return sum;
	}
	case DieType::DTwenty: 
	{
		int sum = 0;
		for (int i = 0; i < numberOfDice; i++)
		{
			sum += rand() % 20 + 1;
		}
		return sum;
	}
	default: 
	{
		break;
	}
	}
	
}

CoinSide DiceRoller::TossCoin()
{
	int result = rand() % 2 + 1;
	if (result == 1)
	{
		return CoinSide::Head;
	}
	else
	{
		return CoinSide::Tails;
	}
}