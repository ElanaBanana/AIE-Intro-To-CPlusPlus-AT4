#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

/*
Elana Parnis
26/02/2024
*/
#include <vector>
class Item;

//rules for shopping list
//list has a random assortment of 5 items
//list is always in alphabetical order

class ShoppingList
{
private: //in future can do this with vector pair
	std::vector<Item*> listItems; // a pointer to a vector of item pointers
	std::vector<bool> obtained; //true or false if the item has been obtained
public:
	ShoppingList();
	ShoppingList(std::vector<Item*> items);
	const std::vector<Item*> GetList(); //returns a copy of the shopping list as a const
	const Item* GetListItem(int index); //returns a copy of the shopping list as a const
	const std::vector<bool> GetCheckList(); //returns a copy of the shopping list as a const
	void ItemObtained(Item* item, bool check); //updates shopping list with new obtained item 

	void PrintAll(); //prints out the shoppinglist to console

	~ShoppingList();
};
#endif
