#include <iostream>
using namespace std;
#include "Player.h"
#include "ShoppingList.h"
#include "Spyglass.h";
#include "StoreItem.h"
#include "String.h"

//TESTS
void ShoppingListTest();

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
		   +========+    +===========+    +========+	
  		   [  PLAY  ]    [  CREDITS  ]    [  QUIT  ]
		   +========+    +===========+    +========+

)";

	//SHOPPPING LIST TEST
	ShoppingListTest();

	
	//end game
}

void ShoppingListTest() {
	
	vector<Item*> list;
	for (int i = 0; i < 3; i++) {
		Item* newItem = new Spyglass();
		list.push_back(newItem);
	}
	ShoppingList shopList(list);

	shopList.PrintAll();
	
	Item* addedItem = new Spyglass(3);

	addedItem->GetName()->CStr();
	//std::cout << addedItem << std::endl;
	shopList.ItemObtained(addedItem, true);
	shopList.ItemObtained(addedItem, true);

	delete addedItem; //delete the addedItem

	shopList.PrintAll();

}
