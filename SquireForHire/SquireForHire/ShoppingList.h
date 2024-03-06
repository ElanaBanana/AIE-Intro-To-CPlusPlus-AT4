#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

/*
Elana Parnis
26/02/2024
*/
#include <vector>
class Item;
class String;

//rules for shopping list
//list has a random assortment of 5 items
//list is always in alphabetical order

class ShoppingList
{
public:
	ShoppingList();
	ShoppingList(std::vector<Item*> items);
	~ShoppingList();

public:
	const std::vector<Item*> GetList() const; //returns a copy of the shopping list as a const
	const std::vector<bool> GetObtained() const; //returns a copy of the shopping list as a const
	const Item* GetListItem(int index); //returns a copy of the shopping list as a const
	const std::vector<bool> GetCheckList(); //returns a copy of the shopping list as a const
	void ItemObtained(Item* item, bool check); //updates shopping list with new obtained item 
	void SortList(int start, int end); //sorts the shopping list in alphabetical order using Quicksort
	int SearchList(String* search) const; //searches the shopping list for given item, returns index else returns -1
	void PrintAll(bool printStatus) const; //prints out the shoppinglist to console

private: //in future can do this with vector pair
	std::vector<Item*> listItems; // a pointer to a vector of item pointers
	std::vector<bool> obtained; //true or false if the item has been obtained
	int Partition(int s, int e);
};
#endif
