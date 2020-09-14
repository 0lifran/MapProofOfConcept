#pragma once
#include "Tile.h"
#include "ItemManager.h"
#include "UnitBodyPart.h"

class InventoryController
{
public:
	InventoryController();
	InventoryController(Unit* unit, Tile* currentTile);
	bool AttachItemToUnit(int itemId, UnitBodyPart bodyPart);

private:
	void InitializeInventory(Unit* unit, Tile* currentTile);
	void CurrentUnit(Unit* unit);
	Unit* CurrentUnit();
	Item* ItemsOnGround();
	void ItemsOnGround(Item* items);
	Tile* CurrentTile();
	void CurrentTile(Tile* tile);

	Unit* _unit;
	ItemManager _itemsOnGround;
	Tile* _tile;
};

