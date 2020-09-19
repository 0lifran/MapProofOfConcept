#include "ItemFactory.h"

Item* ItemFactory::ProduceItem(ItemPreset preset)
{
	Item* result = new Item();
	switch (preset)
	{
	case ItemPreset::Backpack:
	{
		result = this->ProduceBackpack();
		break;
	}
	case ItemPreset::SemiAutomaticPistol:
	{
		result = this->ProduceSemiAutomaticPistol();
		break;
	}
	default:
		throw new exception("Unknown item preset.");
	}

	return result;
}

Item* ItemFactory::ProduceBackpack()
{
	return static_cast<Item*>(new Container("Backpack", 32, 32));
}

Item* ItemFactory::ProduceSemiAutomaticPistol()
{
	return static_cast<Item*>(new BallisticWeapon(
		"Semi Automatic Pistol",
		ItemType::Weapon,
		3,
		2,
		WeaponType::Ballistic,
		1,
		5,
		6,
		10,
		11,
		15,
		16,
		20,
		*new BallisticMagazine(
			10,
			10,
			BallisticMagazineType::NineMm),
		BallisticMagazineType::NineMm));
}

void ItemFactory::ItemClassTransformer(ItemClassConverter* converter)
{
	this->_itemClassTransformer = *converter;
}

ItemClassConverter* ItemFactory::ItemClassTransformer()
{
	return &this->_itemClassTransformer;
}

Item* ItemFactory::CopyItem(Item item)
{
	switch (item.Type())
	{
	case ItemType::Common:
	{
		return new Item(item.Id(), item.Name(), item.Type(), item.StorageSpace());
		break;
	}
	case ItemType::Container:
	{
		Container containerItem = *this->ItemClassTransformer()->ConvertToContainer(&item);
		Container result = *new Container(containerItem.Name(), containerItem.StorageSpace(), containerItem.Capacity());
		return &result;
		break;
	}
	case ItemType::Weapon:
	{
		Weapon weaponItem = *this->ItemClassTransformer()->ConvertToWeapon(&item);
		switch (weaponItem.WeaponSubType())
		{
		case WeaponType::Ballistic:
		{
			Weapon w = *this->ItemClassTransformer()->ConvertToWeapon(&item);
			RangedWeapon rW = *this->ItemClassTransformer()->ConvertToRangedWeapon(&w);
			BallisticWeapon ballisticWeaponItem = *this->ItemClassTransformer()->ConvertToBallisticWeapon(&rW);

			BallisticWeapon result = *new BallisticWeapon(
				ballisticWeaponItem.Name(),
				ballisticWeaponItem.Type(),
				ballisticWeaponItem.StorageSpace(),
				ballisticWeaponItem.Damage(),
				ballisticWeaponItem.WeaponSubType(),
				ballisticWeaponItem.CloseRangeMin(),
				ballisticWeaponItem.CloseRangeMax(),
				ballisticWeaponItem.MediumRangeMin(),
				ballisticWeaponItem.MediumRangeMax(),
				ballisticWeaponItem.HighRangeMin(),
				ballisticWeaponItem.HighRangeMax(),
				ballisticWeaponItem.ExtendedRangeMin(),
				ballisticWeaponItem.ExtendedRangeMax(),
				*ballisticWeaponItem.Magazine(),
				ballisticWeaponItem.MagazineType());
			break;
		}
		default:
		{
			throw new exception("Unknown weapon type.");
		}
		}
		break;
	}
	default:
	{
		throw new exception("Unknown item type.");
	}
	}
}

