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
}

void Player::SetAppraise(int num)
{
	if (num < 0) 
	{
		appraiseBonus = 0;
	}
	else
	{
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
