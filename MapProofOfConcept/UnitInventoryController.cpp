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

bool UnitInventoryController::AttachItemToUnit(int itemId, UnitBodyPart bodyPart)
{
	bool result = false;
	Tile* tile = this->CurrentTile();
	Item* itemFromGround = new Item();
	Item* itemFromInventory = new Item();

	ItemManager* itemHandler = tile->ItemHandler();
	Item* item = itemHandler->GetItemById(itemId);
	itemFromGround = &itemHandler->TakeOutItem(item->Id());

	switch (bodyPart)
	{
	case UnitBodyPart::Back:
	{
		Item* backItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Back);
		if (backItem->Type() != ItemType::None)
		{
			if (backItem->Type() == ItemType::Container)
			{
				// If the item is a container item, add the item to the container.
				bool response = static_cast<Container*>(backItem)->AddItem(item);
				if (response == false)
				{
					this->_itemsOnGround.AddItem(itemFromGround);
				}
				return response;
			}
			else
			{
				// Swap items.
				itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Back);
				this->CurrentUnit()->UnitItem(itemFromGround,UnitBodyPart::Back);
				this->_itemsOnGround.AddItem(itemFromInventory);
				return true;
			}
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Back);
			return true;
		}
		break;
	}
	case UnitBodyPart::Head:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Head);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Head);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::Head);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Head);
			return true;
		}
		break;
	}
	case UnitBodyPart::Feet:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Feet);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Feet);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::Feet);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Feet);
			return true;
		}
		break;
	}
	case UnitBodyPart::Hands:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Hands);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Hands);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::Hands);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Hands);
			return true;
		}
		break;
	}
	case UnitBodyPart::LeftHand:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::LeftHand);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::LeftHand);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::LeftHand);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::LeftHand);
			return true;
		}
		break;
	}
	case UnitBodyPart::RightHand:
	{
		Item* rightHandItem = this->CurrentUnit()->UnitItem(UnitBodyPart::RightHand);
		if (rightHandItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::RightHand);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::RightHand);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::RightHand);
			return true;
		}
		break;
	}
	case UnitBodyPart::Legs:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Legs);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Legs);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::Legs);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Legs);
			return true;
		}
		break;
	}
	case UnitBodyPart::Torso:
	{
		Item* headItem = this->CurrentUnit()->UnitItem(UnitBodyPart::Torso);
		if (headItem->Type() != ItemType::None)
		{
			// Swap items.
			itemFromInventory = this->CurrentUnit()->UnitItem(UnitBodyPart::Torso);
			this->CurrentUnit()->UnitItem(itemFromGround, UnitBodyPart::Torso);
			this->_itemsOnGround.AddItem(itemFromInventory);
			return true;
		}
		else
		{
			this->CurrentUnit()->UnitItem(item, UnitBodyPart::Torso);
			return true;
		}
		break;
	}
	default:
		throw new exception("Unknown body part.");
	}
	return false;
}