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

	for (int i = 0; i < len; i++) 
	{
		listItems.push_back(items[i]);
		obtained.push_back(false);
	}

	//for (Item* i : items)
	//{
	//	listItems.push_back(i);
	//	obtained.push_back(false);
	//}
	
}

const std::vector<Item*> ShoppingList::GetList()
{
	return listItems;
}

const Item* ShoppingList::GetListItem(int index)
{
	return listItems[index];
}

const std::vector<bool> ShoppingList::GetCheckList()
{
	return obtained;
}

void ShoppingList::ItemObtained(Item* item, bool check)
{//check can be true OR false

	//std::cout << item << std::endl;
	//std::cout << item->GetName()->CStr() << std::endl;

	int len = listItems.size(); //size of shopping list
	//const char* name2 = item->GetName()->CStr();
	for (int i = 0; i < len; i++)
	{
		//check shopping list for item
		//if item exists and it hasn't been checked, change obtained status
		if ((*listItems[i] == *item) && this->obtained[i] != check) {
			this->obtained[i] = check;
			return;
		}
		
	}
	//std::cout << "Item is not on shopping list" << std::endl;
	return;

}

void ShoppingList::PrintAll(bool printStatus)
{
	int count = 0;
	for (Item* i : listItems)
	{//for every item in shoppinglist, print out name and if it has been obtained
		std::cout << "	Item " << count+1 << ": ";
		i->GetName()->WriteToConsole();
		//if I want to print out the obtained status of items
		if (printStatus == true)
		{
			//if obtained print Y
			if (obtained[count] == true)
			{
				std::cout << "   " << "Obtained" << std::endl;
			}
			else
			{
				std::cout << "   " << "Not Obtained" << std::endl;
			}
		}
		else
		{
			std::cout << "\n";
		}
		count++;
	}
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
