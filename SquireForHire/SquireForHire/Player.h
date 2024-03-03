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
public:
	Player(ShoppingList list, int val); //takes in the shopping list and how much money the player has to start 
	~Player();
public:
	ShoppingList* shoppingList; // pointer to shoppinglist (vector of item pointers)
	void SetAppraise(int num); //set the appraisalBonus 
	int GetAppraise(); //returns the appriasalBonus
	bool SpendCoins(int val); //returns true and deducts if player has enough coins to purchase item 
	void AddInventory(Item* item); //adds an item to player inventory
	bool RemoveInventory(Item* item); //removes an item from player inventory, if item not found, returns false
	void PrintInventroy(); //prints the player inventory to console
private:
	int coins; // the amount of money the player has
	int appraiseBonus; //bonus to item appraisal
	std::vector<Item*> inventory; //vector of pointers to items
};
#endif

