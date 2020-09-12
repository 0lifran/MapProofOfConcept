#include "IdManager.h"

int IdManager::_idCounter{ 0 };

int IdManager::GetNewId()
{
	this->_idCounter++;
	return _idCounter;
}

IdManager::IdManager()
{
	this->_idCounter = 0;
}

void IdManager::IncrementIdCounter()
{
	this->_idCounter++;
}