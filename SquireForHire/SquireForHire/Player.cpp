#include "Player.h"
//#include "String.h"
#include "ShoppingList.h"
#include "Spyglass.h"
#include "StoreItem.h"

/*
Elana Parnis
29/02/2024
*/

Player::Player(ShoppingList list, int val)
{
	shoppingList = &list;
	appraiseBonus = 0;
	coins = val;
}

Player::~Player()
{
	while (!inventory.empty())
	{ //while the list is not empty
		delete inventory.back();
		inventory.pop_back();
	}
	inventory.clear();
}

void Player::SetAppraise(int num)
{
	if (num < 0) // cannot have negative appraiseBonus, default is 0
	{
		appraiseBonus = 0;
	}
	else
	{ //set appraise bonus to provided num
		appraiseBonus = num; 
	}
}

int Player::GetAppraise()
{
	return appraiseBonus;
}

bool Player::SpendCoins(int val)
{
	//if the player does not have enough coins to purchase item
	if (val > coins)
	{
		return false;
	}
	else
	{// deduct spent amount from player
		coins -= val;
		return true;
	}
}

void Player::AddInventory(Item* item)
{
	inventory.push_back(item); //adds item to inventory
}

bool Player::RemoveInventory(Item* item)
{
	//check if item is in inventory, if yes, remove first instance
	int len = inventory.size();

	for (int i = 0; i < len; i++)
	{
		//if item has been found in inventory
		if (inventory[i] == item) {
			//deletes the memory
			delete inventory.at(i); 
			//removes the pointer from the inventory
			inventory.erase(inventory.begin() + i); 
			//sucessfully removed
			return true;
		}
	}

	//else return nullptr
	return false;
}
