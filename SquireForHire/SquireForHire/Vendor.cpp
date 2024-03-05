#include "Vendor.h"
#include "Player.h"
#include "String.h"
#include "StoreItem.h"
#include <iostream>

Vendor::Vendor()
{
	//dont really want this
	description = nullptr;
	merchant = nullptr;
}

Vendor::Vendor(Merchant* mer, String* description, std::vector<StoreItem*> items)
{
	this->description = description;
	this->merchant = mer;

	int len = items.size();

	//for each item, add to vendors wares
	for (int i = 0; i < len; i++)
	{
		wares.push_back(items[i]);
	}
}

Vendor::~Vendor()
{
	delete description;
	delete merchant;
	//delete all Store Item pointers stored in the vector
	while (!wares.empty())
	{ //while the list is not empty
		delete wares.back();
		wares.pop_back();
	}
	wares.clear();
}

const std::vector<StoreItem*> Vendor::ReturnWares()
{
	return wares;
}

void Vendor::DisplayWares()
{
	std::cout << "Items for Sale: \n" << std::endl;
	for (StoreItem* i : wares)
	{
		i->GetName()->WriteToConsole();
		std::cout << "\n" << std::endl;
	}
}

void Vendor::SellItem(Player* pl, StoreItem* item)
{
	//check if the player has funds to purchase item and remove funds

	if (pl->SpendCoins(item->GetPrice())) //returns true if coins sucessfully removed
	{
		int len = wares.size();

		for (int i = 0; i < len; i++) 
		{
			if (wares[i] == item)
			{
				//add item to player inventory
				pl->AddInventory(wares[i]);
				//remove item from vendor
				wares.erase(wares.begin() + i);
			}
		}
	}
	else {
		std::cout << "not enough coins to purchase item" << std::endl;
	}
}

String* Vendor::GetDescription()
{
	return description;
}

Merchant* Vendor::GetMerchant()
{
	return merchant;
}
