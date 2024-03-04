#include <iostream>
using namespace std;
#include "Player.h"
#include "ShoppingList.h"
#include "Spyglass.h";
#include "StoreItem.h"
#include "String.h"
#include "Game.h"

//TESTS
void ShoppingListTest();

/*
Elana Parnis
23/02/2024
*/int main() {
	//run game
	Game* SquireForHire = new Game();

	SquireForHire->MainMenu();

	//SHOPPPING LIST TEST
	//ShoppingListTest();

	
	//end game
}

void ShoppingListTest() {
	
	vector<Item*> list;
	for (int i = 0; i < 3; i++) {
		Item* newItem = new Spyglass();
		list.push_back(newItem);
	}
	ShoppingList* shopList = new ShoppingList(list);

	shopList->PrintAll(true);
	
	Item* addedItem = new Spyglass(3);

	addedItem->GetName()->CStr();
	//std::cout << addedItem << std::endl;
	shopList->ItemObtained(addedItem, true);
	shopList->ItemObtained(addedItem, true);

	delete addedItem; //delete the addedItem

	shopList->PrintAll(true);

}
