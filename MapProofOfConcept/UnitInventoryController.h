#pragma once
#include "Tile.h"
#include "ItemManager.h"
#include "UnitBodyPart.h"

class UnitInventoryController
{
public:
	UnitInventoryController();
	UnitInventoryController(Unit* unit, Tile* currentTile);
	bool AttachItemToUnit(int itemId, UnitBodyPart bodyPart);

private:
	void InitializeInventory(Unit* unit, Tile* currentTile);
	void CurrentUnit(Unit* unit);
	Unit* CurrentUnit();
	Item* ItemsOnGround();
	void ItemsOnGround(Item* items, int numberOfItems);
	Tile* CurrentTile();
	void CurrentTile(Tile* tile);

	Unit* _unit;
	ItemManager _itemsOnGround;
	Tile* _tile;
};

