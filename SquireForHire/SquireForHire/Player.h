#ifndef PLAYER_H
#define PLAYER_H


/*
Elana Parnis
26/02/2024
*/

#include <vector>
class ShoppingList;
class Item;

class Player
{
private:
	int coins; // the amount of money the player has
	int appraiseBonus; //bonus to item appraisal
public:
	std::vector<ShoppingList>* shoppingList; // pointer to vector of items
	std::vector<Item>* Inventory; //pointer to vector of items
	Player();
	~Player();

	void SetAppraise(int num);
};
#endif

