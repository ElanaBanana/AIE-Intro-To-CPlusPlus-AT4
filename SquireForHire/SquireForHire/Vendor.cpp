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

Vendor::Vendor(Merchant* mer, String* description, std::vector<StoreItems*> items)
{
	this->description = description;
	this->merchant = mer;

	int len = items.size();

	//for each item, add to vendors wares
	for (int i = 0; i < len; i++)
	{
		items.push_back(items[i]);
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

void Vendor::SellItem(Player* pl, StoreItem* item)
{
	//check if the player has funds to purchase item and remove funds

	if (pl->SpendCoins(item->GetPrice())) //returns true if coins sucessfully removed
	{
		//add item to player inventory
		//remove item from store
	}
	else {
		std::cout << "not enough coins to purchase item" << std::endl;
	}
}
