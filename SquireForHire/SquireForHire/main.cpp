#include <iostream>
#include <windows.h>

#include "Player.h"
#include "ShoppingList.h"
#include "Spyglass.h";
#include "StoreItem.h"
#include "String.h"
#include "Game.h"


//TESTS
void ShoppingListTest();
bool enableVirtualTerminal();

/*
Elana Parnis
23/02/2024
*/
int main() {
	//run game
	if (enableVirtualTerminal() == false)
	{
		std::cout << "Unable to enable virtual terminal sequences." << std::endl;
		std::cout << "Program failed to run." << std::endl;
		std::cout << "Exit program by pressing 'Enter'" << std::endl;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();

		return 0;
	}
	Game* SquireForHire = new Game();

	SquireForHire->MainMenu();

	//SHOPPPING LIST TEST
	//ShoppingListTest();

	
	//end game
	return 0;
}

bool enableVirtualTerminal()
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return false;
	}
	return true;
}

void ShoppingListTest() {
	
	std::vector<Item*> list;
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
