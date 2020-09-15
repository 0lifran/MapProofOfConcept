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

bool UnitInventoryController::AttachItemToUnit(int itemId, UnitBodyPart bodyPart)
{
	bool result = false;
	Tile* tile = this->CurrentTile();
	Item itemFromGround = *new Item();
	Item* itemFromInventory = new Item();

	ItemManager* itemHandler = tile->ItemHandler();
	Item* item = itemHandler->GetItemById(itemId);
	itemHandler->TakeOutItem(item->Id(), &itemFromGround);

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
				bool response = static_cast<Container*>(backItem)->AddItem(item);
				if (response == false)
				{
					this->_itemsOnGround.AddItem(&itemFromGround);
				}
				return response;
			}
			else
			{
				// Swap items.
				itemFromInventory = this->CurrentUnit()->Back();
				this->CurrentUnit()->Back(&itemFromGround);
				this->_itemsOnGround.AddItem(itemFromInventory);
				return true;
			}
		}
		else
		{
			this->CurrentUnit()->Back(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::Head:
	{
		Item* headItem = this->CurrentUnit()->Head();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->Head();
			this->CurrentUnit()->Head(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->Head(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::Feet:
	{
		Item* headItem = this->CurrentUnit()->Feet();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->Feet();
			this->CurrentUnit()->Feet(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->Feet(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::Hands:
	{
		Item* headItem = this->CurrentUnit()->Hands();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->Hands();
			this->CurrentUnit()->Hands(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->Hands(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::LeftHand:
	{
		Item* headItem = this->CurrentUnit()->LeftHand();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->LeftHand();
			this->CurrentUnit()->LeftHand(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->LeftHand(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::RightHand:
	{
		Item* headItem = this->CurrentUnit()->RightHand();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->RightHand();
			this->CurrentUnit()->RightHand(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->RightHand(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::Legs:
	{
		Item* headItem = this->CurrentUnit()->Legs();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->Legs();
			this->CurrentUnit()->Legs(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->Legs(item);
			return true;
		}
		break;
	}
	case UnitBodyPart::Torso:
	{
		Item* headItem = this->CurrentUnit()->Torso();
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->Torso();
			this->CurrentUnit()->Torso(&itemFromGround);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->Torso(item);
			return true;
		}
		break;
	}
	default:
		throw new exception("Unknown body part.");
	}
	return false;
}