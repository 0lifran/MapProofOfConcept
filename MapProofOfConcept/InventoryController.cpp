#include "InventoryController.h"
#include "Container.h"

InventoryController::InventoryController()
{
	InitializeInventory(new Unit(), new Tile());
}

InventoryController::InventoryController(Unit* unit, Tile* currentTile)
{
	this->InitializeInventory(unit, currentTile);
}



void InventoryController::InitializeInventory(Unit* unit, Tile* currentTile)
{
	CurrentUnit(unit);
	ItemManager* itemHandler = currentTile->ItemHandler();
	ItemsOnGround(itemHandler->Items());
}

void InventoryController::CurrentUnit(Unit* unit)
{
	this->_unit = unit;
}

Unit* InventoryController::CurrentUnit()
{
	return this->_unit;
}

Item* InventoryController::ItemsOnGround()
{
	return this->_itemsOnGround.Items();
}

void InventoryController::ItemsOnGround(Item* items)
{
	this->_itemsOnGround = *new ItemManager();
	this->_itemsOnGround.Items(items);
}

Tile* InventoryController::CurrentTile()
{
	return this->_tile;
}

void InventoryController::CurrentTile(Tile* tile)
{
	this->_tile = tile;
}

bool InventoryController::AttachItemToUnit(int itemId, UnitBodyPart bodyPart)
{
	bool result = false;
	Tile* tile = this->CurrentTile();
	Item* itemFromGround = new Item();
	Item* itemFromBack = new Item();

	ItemManager* itemHandler = tile->ItemHandler();
	Item* item = itemHandler->GetItemById(itemId);
	itemHandler->TakeOutItem(item->Id(), itemFromGround);

	switch (bodyPart)
	{
	case UnitBodyPart::Back:
	{
		Item* backItem = this->CurrentUnit()->Back();
		if (backItem->Type() != ItemType::None)
		{
			if (backItem->Type() == ItemType::Container)
			{
				// If the item is a container item, add the item to the container.
				Container* containerItem = static_cast<Container*>(backItem);
				containerItem->AddItem(item);
			}
			else
			{
				// Swap items.
				itemFromBack = this->CurrentUnit()->Back();
				this->CurrentUnit()->Back(itemFromGround);
			}
		}
		else
		{
			this->CurrentUnit()->Back(item);
		}
		break;
	}
	case UnitBodyPart::Head:
		this->CurrentUnit()->Head(item);
		break;
	case UnitBodyPart::Feet:
		this->CurrentUnit()->Feet(item);
		break;
	case UnitBodyPart::Hands:
		this->CurrentUnit()->Hands(item);
		break;
	case UnitBodyPart::LeftHand:
		this->CurrentUnit()->LeftHand(item);
		break;
	case UnitBodyPart::RightHand:
		this->CurrentUnit()->RightHand(item);
		break;
	case UnitBodyPart::Legs:
		this->CurrentUnit()->Legs(item);
		break;
	case UnitBodyPart::Torso:
		this->CurrentUnit()->Torso(item);
		break;
	default:
		throw new exception();
	}
}