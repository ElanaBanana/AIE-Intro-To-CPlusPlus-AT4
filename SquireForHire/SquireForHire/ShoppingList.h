#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

/*
Elana Parnis
26/02/2024
*/

class ShoppingList
{
private:
	std::vector<Item>* listItems; // a pointer to a vector of items
	std::vector<bool> obtained; //true or false if the item has been obtained
public:
	ShoppingList();
	ShoppingList(String name);
	~ShoppingList();
};
#endif
