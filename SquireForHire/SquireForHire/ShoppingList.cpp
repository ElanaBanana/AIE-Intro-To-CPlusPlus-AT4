#include "ShoppingList.h"
#include "Item.h"
#include "String.h"
#include <iostream>

ShoppingList::ShoppingList()
{
	//default constructor
}

ShoppingList::ShoppingList(std::vector<Item*> items)
{
	int len = items.size();
	
	//for every item provided, create a new instace in listItems
	//and a corresponding bool value in the obtained list
	listItems = std::vector<Item*>();
	obtained = std::vector<bool>();

	for (int i = 0; i < len; i++) 
	{
		listItems.push_back(items[i]);
		obtained.push_back(false);
	}
	
}

const std::vector<Item*> ShoppingList::GetListItems()
{
	return listItems;
}

const std::vector<bool> ShoppingList::GetCheckList()
{
	return obtained;
}

void ShoppingList::ItemObtained(Item* item, bool obtained)
{
	int len = listItems.size(); //size of shopping list

	for (int i = 0; i < len; i++)
	{
		//check shopping list for item
		//if item exists and hasn't already been marked off, update obtained table to true
		if ((strcmp(listItems[i]->GetName()->CStr(), item->GetName()->CStr()) == 0) && this->obtained[i] != true) {
			this->obtained[i] = obtained;
			return;
		}
	}
	std::cout << "Item is not on shopping list" << std::endl;
	return;

}

ShoppingList::~ShoppingList()
{
	//int len = listItems.size();
	//for (int i = 0; i < len; i++) {
	//	delete listItems.at(i); //deletes all instances of dynamically allocated items in the list
	//}
	while (!listItems.empty())
	{ //while the list is not empty
		delete listItems.back();
		listItems.pop_back();
	}
	listItems.clear();
	//delete[] obtained;
}
