#include <iostream>
using namespace std;
#include "Player.h"
#include "ShoppingList.h"
#include "Spyglass.h";
#include "StoreItem.h"
#include "String.h"

void ShoppingListTest();
void PrintShoppingList(ShoppingList list);

/*
Elana Parnis
23/02/2024
*/int main() {
	//run game
	//https://patorjk.com/software/taag/#p=display&f=Ogre&t=Squire%20for%20Hire Orge Font
	cout << R"(
	 __             _             __                     _          
	/ _\ __ _ _   _(_)_ __ ___   / _| ___  _ __    /\  /(_)_ __ ___ 
	\ \ / _` | | | | | '__/ _ \ | |_ / _ \| '__|  / /_/ / | '__/ _ \
	_\ \ (_| | |_| | | | |  __/ |  _| (_) | |    / __  /| | | |  __/
	\__/\__, |\__,_|_|_|  \___| |_|  \___/|_|    \/ /_/ |_|_|  \___|
	       |_|                                                      
)";

	cout << R"(
				 +========+		
  				 [  PLAY  ]     
				 +========+	
)";

	//SHOPPPING LIST TEST
	while (true)
	{
		ShoppingListTest();
	}
	

	//end game
}

void ShoppingListTest() {
	
	vector<Item*> list;
	for (int i = 0; i < 3; i++) {
		Item* newItem = new Spyglass();
		list.push_back(newItem);
	}
	//ShoppingList shopList(list);

	PrintShoppingList(list);
	//// 
	////Item* addedItem = new Spyglass(3);

	////shopList.ItemObtained(addedItem, true);
	////shopList.ItemObtained(addedItem, true);

	////PrintShoppingList(list);

	//delete addedItem;
	//while (!list.empty())
	//{
	//	delete list.back();
	//	list.pop_back();
	//}

	//for (auto item : list)
	//{
	//	delete item;
	//}

	list.clear();
}

void PrintShoppingList(ShoppingList list) {
	//gets the shopping list

	int len = list.GetListItems().size();
	for (int i = 0; i < len; i++) 
	{

		std::cout << "Item " << i << ": " << list.GetListItems()[i]->GetName()->CStr();
		if (list.GetCheckList()[i] == true)
		{
			cout << "   " << "Y" << endl;
		}
		else
		{
			cout << "   " << "N" << endl;
		}
	}
}