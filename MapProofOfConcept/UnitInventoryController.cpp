#include "UnitInventoryController.h"
#include "Container.h"
#include <iostream>

UnitInventoryController::UnitInventoryController()
{
	InitializeInventory(new Unit(), new Tile());
}

UnitInventoryController::UnitInventoryController(Unit* unit, Tile* currentTile)
{
	this->InitializeInventory(unit, currentTile);
}

void UnitInventoryController::InitializeInventory(Unit* unit, Tile* currentTile)
{
	CurrentUnit(unit);
	CurrentTile(currentTile);
	ItemManager* itemHandler = currentTile->ItemHandler();
	ItemsOnGround(itemHandler->Items(), itemHandler->NumberOfItems());
}

void UnitInventoryController::CurrentUnit(Unit* unit)
{
	this->_unit = unit;
}

Unit* UnitInventoryController::CurrentUnit()
{
	// ???
	// item on this unit is not changed.
	return this->_unit;
}

Item* UnitInventoryController::ItemsOnGround()
{
	return this->_itemsOnGround.Items();
}

void UnitInventoryController::ItemsOnGround(Item* items, int numberOfItems)
{
	this->_itemsOnGround = *new ItemManager();
	this->_itemsOnGround.Items(items);
	this->_itemsOnGround.NumberOfItems(numberOfItems);
}

Tile* UnitInventoryController::CurrentTile()
{
	return this->_tile;
}

void UnitInventoryController::CurrentTile(Tile* tile)
{
	this->_tile = tile;
}

void UnitInventoryController::AttachItemToUnit(Item* itemToAttach, UnitBodyPart bodyPart)
{
	this->CurrentUnit()->UnitItem(itemToAttach, bodyPart);
}

Item* UnitInventoryController::DetachItemFromUnit(UnitBodyPart bodyPart)
{
	Item* result = this->CurrentUnit()->UnitItem(bodyPart);
	this->CurrentUnit()->UnitItem(new Item(), bodyPart);
	return result;
}
