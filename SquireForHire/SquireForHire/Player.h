#ifndef PLAYER_H
#define PLAYER_H


/*
Elana Parnis
26/02/2024
*/

#include <vector>
class ShoppingList;
class Item;
class String;

class Player
{
public:
	Player() = default;
	Player(ShoppingList* list, int val); //takes in the shopping list and how much money the player has to start 
	~Player();
public:
	ShoppingList* GetShoppingList(); //returns the player shopping list
	void SetAppraise(int num); //set the appraisalBonus 
	int GetAppraise(); //returns the appriasalBonus
	const int GetCoins(); //returns the players current amount of coins
	bool SpendCoins(int val); //returns true and deducts if player has enough coins to purchase item 
	void AddInventory(Item* item); //adds an item to player inventory
	bool RemoveInventory(Item* item); //removes an item from player inventory, if item not found, returns false
	void PrintInventroy(); //prints the player inventory to console
	Item* FindItem(String* item); //returns item from player inventory
	void UpdateSmell(bool stink); //updates the players smelly status
	bool Smell(); //returns the players smell status
private:
	int coins; // the amount of money the player has
	int appraiseBonus; //bonus to item appraisal
	std::vector<Item*> inventory; //vector of pointers to items
	ShoppingList* shoppingList; // pointer to shoppinglist (vector of item pointers)
	bool smelly;
};
#endif

