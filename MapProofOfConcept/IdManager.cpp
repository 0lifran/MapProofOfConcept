#include "IdManager.h"

int IdManager::IdCounter{ 0 };

int IdManager::GetNewId()
{
	this->IdCounter++;
 	return IdCounter;
}

IdManager::IdManager()
{
}

void IdManager::IncrementIdCounter()
{
	this->IdCounter++;
}