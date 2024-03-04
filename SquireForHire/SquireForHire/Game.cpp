#include <iostream>
#include <time.h>

#include "String.h"

#include "Game.h"
#include "Vendor.h"
#include "StoreItem.h"
#include "Spyglass.h"
#include "Item.h"
#include "ShoppingList.h"

/*
Elana Parnis
04/03/2024
*/


Game::Game()
{
	srand(time(0)); //random seed

	//create 5 merchants for each vendor
	//create wares for each vendor
	//create each vendor

	//player shopping list
	std::vector<Item*> list;
	int budget = 0;

	//witch
	String* tempName = new String("Agatha");
	String* tempDes = new String("a witch adorning purple robes.");
	Merchant* witch = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Health Potion");
	tempDes = new String("A vial with bright red liquid.");
	StoreItem* item1 = new StoreItem(tempName, tempDes, 5);
	tempName = new String("Greater Health Potion");
	tempDes = new String("A large vial with bright red liquid.");
	StoreItem* item2 = new StoreItem(tempName, tempDes, 10);
	std::vector<StoreItem*> wares;
	wares.push_back(item1);
	wares.push_back(item2);

	//temp shopping list
	list.push_back(item1);
	budget += item1->GetPrice();

	//vendor
	tempDes = new String("A shabby pop up stall with all manner of potions and trinkets, sitting between the vials is");
	Vendor* witchHut = new Vendor (witch, tempDes, wares);

	//soldier
	tempName = new String("Anduin");
	tempDes = new String("a knight with shinning golden armour, a lion sits proudly upon his breatplate.");
	Merchant* soldier = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Short Sword");
	tempDes = new String("Ye old reliable.");
	item1 = new StoreItem(tempName, tempDes, 8);
	tempName = new String("Chainmail Armour");
	tempDes = new String("Armour in pristine condition.");
	item2 = new StoreItem(tempName, tempDes, 12);
	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//temp shopping list
	list.push_back(item1);
	budget += item1->GetPrice();

	//vendor
	tempDes = new String("A very well put together store, with racks of various weapons and armour. Arming the stall is");
	Vendor* armoury = new Vendor(witch, tempDes, wares);

	////dwarf
	//tempName = new String("Dwalin");
	//tempDes = new String("a proud and physically imposing dwarf and a rather majestic beard.");
	//Merchant* dwarf = new Merchant(tempName, tempDes, 10);

	//// elf/vampire
	//tempName = new String("Astarion");
	//tempDes = new String("a pale elf with perfectly styled white hair.");
	//Merchant* vampire = new Merchant(tempName, tempDes, 10);

	//// ratman! the wondering cheese seller
	//tempName = new String("Remy");
	//tempDes = new String("a rather cheeky looking rat head protrudes from a dirty cloak.");
	//Merchant* ratman = new Merchant(tempName, tempDes, 10);

	
	
	//make a vector of all the vendors
	std::vector<Vendor*> vendors;
	vendors.push_back(witchHut);
	vendors.push_back(armoury);
	//vendors.push_back(food);
	//vendors.push_back(cartographer);
	//vendors.push_back(cheese);

	//create a vector of items for shopping list, randomised from vendor wares (cal price off all items)
	//crearte a shopping list
	ShoppingList* shoppingList = new ShoppingList(list);

	//create a player (with provided shopping list)
	player = new Player(shoppingList, budget);

	//create 5x3 map row 2-> empty pathway with a 25% chance to meet Remy the cheese trader on each tile after 1,0
	//1,0 if the spawn point
	//there are 4 vendors, which spawn randomly in 8 locations, 
	// the other 4 spaces are 3 empty and 1 empty which contains a spyglass (in a bin -> triggers unique dialogue with all merchants)

}

void Game::MainMenu()
{
	//clears the console
	bool waiting = true;
	while (waiting)
	{
		system("cls");
		std::cout << R"(
              /\                                                 /\
    _         )( ______________________   ______________________ )(         _
   (_)///////(**)______________________> <______________________(**)\\\\\\\(_)
              )(                                                 )(
              \/                                                 \/
	 __             _             __                     _          
	/ _\ __ _ _   _(_)_ __ ___   / _| ___  _ __    /\  /(_)_ __ ___ 
	\ \ / _` | | | | | '__/ _ \ | |_ / _ \| '__|  / /_/ / | '__/ _ \
	_\ \ (_| | |_| | | | |  __/ |  _| (_) | |    / __  /| | | |  __/
	\__/\__, |\__,_|_|_|  \___| |_|  \___/|_|    \/ /_/ |_|_|  \___|
	       |_|                                                      
)";

		std::cout << R"(
		   +========+    +===========+    +========+	
  		   [  PLAY  ]    [  CREDITS  ]    [  QUIT  ]
		   +========+    +===========+    +========+

)";
		std::cout << "Please Input: PLAY, CREDITS or QUIT." << std::endl;
		//waits for input of either 'play', 'credits', or 'quit'

		WaitingForInput();
		playerInput->ToLower();
		//play -> destorys menu screen and loads up StartGame()
		//quit -> quits game
		//credits -> displays credits
		if (*playerInput == "play" || *playerInput == "credits" || *playerInput == "quit")
		{
			if (*playerInput == "play")
			{
				waiting = false;
				StartGame();
			}
			else if (*playerInput == "credits")
			{
				waiting = false;
				Credits();
			}
			else
			{ //it was quit
				waiting = false;
				return;
			}
		}
		else
		{
			std::cout << "That input in invalid." << std::endl;
		}
	}
}

void Game::StartGame()
{
	//clears the console
	system("cls");
	std::cout << R"(
                                             _______________________
   _______________________-------------------                       `\
 /:--__                                                              |
||< > |                                   ___________________________/
| \__/_________________-------------------                         |
|                                                                  |
 |                           SQUIRE FOR HIRE                        |
 |                                                                  |
 |      Dear Squire,                                                |
  |        Find attached a list of items I require,                  |
  |      aswell as the funds necessary to procure them:              |

)";

	std::cout << "\n" << std::endl;
	player->shoppingList->PrintAll(false);

std::cout << R"(

  |        As always your payment will be whatever remains.          |
  |      Please have my items delivered by sunset today.              |
   |                                                                  |
   |       Signed,                                                    |
   |     Sir Androleo Chadingston III of Chadstown                   |
  |                                              ____________________|_
  |  ___________________-------------------------                      `\
  |/`--_                                                                 |
  ||[ ]||                                            ___________________/
   \===/___________________--------------------------
)";

	system("pause"); //wait for player to continue game
	//GAMEEEE
	//spawns player in 1,0
	//waits for input
	//move + n/s/e/w to traverse the map
	//when on a tile that contains a vendor
	// options include, move/ talk / browse
	//atm talk just provides a line of dialouge to display
	//browse displays the current wares
	//when browse it selected 
	//player can purchase items with buy [ITEM]
	//this removes the item from the store
}

void Game::Credits()
{
	//clears the console
	system("cls");

	std::cout << "The credits are being displayed!!!" << std::endl;

	std::cout << "Please Input: BACK or QUIT." << std::endl;
	bool waiting = true;
	while (waiting)
	{
		WaitingForInput();
		playerInput->ToLower();
		if (*playerInput == "back" || *playerInput == "quit")
		{
			if (*playerInput == "back")
			{
				waiting = false;
				MainMenu();
			}
			else
			{ //it was quit
				waiting = false;
				return;
			}
		}
		else
		{
			std::cout << "That input in invalid." << std::endl;
		}
	}
	//display credits for game
	//this is optional, will do later
}

void Game::WaitingForInput()
{
	std::cout << "	> ";
	playerInput->ReadFromConsole();

}

Game::~Game()
{
	delete player;

	while (!vendors.empty())
	{ //while the list is not empty
		delete vendors.back();
		vendors.pop_back();
	}
	vendors.clear();
}
