#include <iostream>
#include <time.h>
#include <algorithm>
#include <random>

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

//console stuff
const char* CSI = "\x1b[";

//THESE SUCK AT WHAT THEY ARE MEANT TO DO >:(
//const char* CLEAR = "\x1b[2J";
//const char* RESET_CURSER = "\x1b[H";

const char* INDENT = "\x1b[5C";

//colours
const char* RED = "\x1b[91m";
const char* GREEN = "\x1b[92m";
const char* YELLOW = "\x1b[93m";
const char* BLUE = "\x1b[94m";
const char* MAGENTA = "\x1b[95m";
const char* WHITE = "\x1b[97m";
const char* RESET_COLOR = "\x1b[0m";

//might need these, idk
const int PLAYER_INPUT_X = 30;
const int PLAYER_INPUT_Y = 11;

void Game::CleanText()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

Game::Game()
{
	srand(time(0)); //random seed

	//create 5 merchants for each vendor
	//create wares for each vendor
	//create each vendor

		//witch - VENDOR 1 (SAME CODE for each vendor)
	String* tempName = new String("Agatha");
	String* tempDes = new String("a witch adorning purple robes.");
	Merchant* witch = new Merchant(tempName, tempDes, 10);

	//vendor items
	//creates name and des for item
	tempName = new String("Health Potion");
	tempDes = new String("A vial with bright red liquid.");
	//creates a new item 
	StoreItem* item1 = new StoreItem(tempName, tempDes, 5);
	tempName = new String("Greater Health Potion");
	tempDes = new String("A large vial with bright red liquid.");
	StoreItem* item2 = new StoreItem(tempName, tempDes, 10);

	//saves items in list
	std::vector<StoreItem*> wares;
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	//creates a vendor from the list of items
	tempDes = new String("A shabby pop up stall with all manner of potions and trinkets, sitting between the vials is");
	Vendor* witchHut = new Vendor (witch, tempDes, wares);

		//soldier - VENDOR 2
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

	//vendor
	tempDes = new String("A very well put together store, with racks of various weapons and armour. Arming the stall is");
	Vendor* armoury = new Vendor(witch, tempDes, wares);

		//dwarf - VENDOR 3
	tempName = new String("Dwalin");
	tempDes = new String("a proud and physically imposing dwarf and a rather majestic beard.");
	Merchant* dwarf = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Bread");
	tempDes = new String("Hard as a brick");
	item1 = new StoreItem(tempName, tempDes, 6);
	tempName = new String("Apple Pie");
	tempDes = new String("Just like grandma would make it.");
	item2 = new StoreItem(tempName, tempDes, 7);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("A homey store with many amazing smells coming from various baked goods. The owner is ");
	Vendor* bakery = new Vendor(dwarf, tempDes, wares);

		// elf/vampire - VENDOR 4
	tempName = new String("Astarion");
	tempDes = new String("a pale elf with perfectly styled white hair.");
	Merchant* vampire = new Merchant(tempName, tempDes, 10);
	
	//vendor items
	tempName = new String("Map of Mars");
	tempDes = new String("What even is that?");
	item1 = new StoreItem(tempName, tempDes, 10);
	tempName = new String("Map of Narnia");
	tempDes = new String("Commonly found in ecentric gentleman's closets.");
	item2 = new StoreItem(tempName, tempDes, 11);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("Ink and paper cover the stalls walls, with maps of all shapes and shades. The individual manning the stall looks quite out of place,  ");
	Vendor* cartographer = new Vendor(vampire, tempDes, wares);

		// ratman! the wondering cheese seller - VENDOR 5
	tempName = new String("Remy");
	tempDes = new String("a rather cheeky looking rat wearing a dirty cloak.");
	Merchant* ratman = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Swiss Cheese");
	tempDes = new String("Holy!");
	item1 = new StoreItem(tempName, tempDes, 6);
	tempName = new String("Blue Cheese");
	tempDes = new String("People like this?");
	item2 = new StoreItem(tempName, tempDes, 7);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("Out of no-where appears ");
	Vendor* cheese = new Vendor(ratman, tempDes, wares);
	
	//make a vector of all the vendors
	std::vector<Vendor*> vendors;
	vendors.push_back(witchHut);
	vendors.push_back(armoury);
	vendors.push_back(bakery);
	vendors.push_back(cartographer);
	vendors.push_back(cheese);

	//from each vendor, pick a random item form their wares for the shopping list
	std::vector<Item*> list;
	int budget = 0;

	int len = vendors.size() - 1; //not including the cheese seller
	for (int i = 0; i < len; i++)
	{
		//generates a random number between 0-1
		int ran = rand() % 2;
		//adds a random item from the vendors wares
		list.push_back(vendors[i]->ReturnWares()[ran]);
		//adds the cost of the item to the player budget
		budget += vendors[i]->ReturnWares()[ran]->GetPrice();
	}

	//create a vector of items for shopping list, randomised from vendor wares (cal price off all items)
	//crearte a shopping list
	ShoppingList* shoppingList = new ShoppingList(list);

	//create a player (with provided shopping list)
	player = new Player(shoppingList, budget);

	//1,0 is the player spawn point
	Ypos = 1;
	Xpos = 0;
	
	//initialises the map with values 1-15
	int count = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			map[i][j] = count++;
		}
	}
	//there are 4 vendors, (which spawn randomly in 8 possible locations) which are -> (2,3,4,5,12,13,14,15)
	possibleLocations = { 2,3,4,5,12,13,14,15 };
	//shuffle the possible locations to get random spawn order
	std::random_device ran;
	std::mt19937 seed(ran());
	std::shuffle(possibleLocations.begin(), possibleLocations.end(), seed);

	//the first 4 numbers in the sequence are were the vendors will spawn
	// the next 3 numbers are EMPTY spaces
	// the last number is a EMPTY location with a spyglass in a bin (-> triggers unique dialogue with all merchants)
}

void Game::MainMenu()
{

	//clears the console
	system("cls");
	std::cout << R"(
              /\                                                 /\
    _         )( ______________________   ______________________ )(         _
   (_)///////(**)______________________> <______________________(**)\\\\\\\(_)
              )(                                                 )(
              \/                                                 \/
)";
std::cout << RED << R"(
	 __             _             __                     _
	/ _\ __ _ _   _(_)_ __ ___   / _| ___  _ __    /\  /(_)_ __ ___ 
	\ \ / _` | | | | | '__/ _ \ | |_ / _ \| '__|  / /_/ / | '__/ _ \
	_\ \ (_| | |_| | | | |  __/ |  _| (_) | |    / __  /| | | |  __/
	\__/\__, |\__,_|_|_|  \___| |_|  \___/|_|    \/ /_/ |_|_|  \___|
	       |_|                                                      
)" << RESET_COLOR;

		std::cout << R"(
		   +========+    +===========+    +========+	
  		   [  PLAY  ]    [  CREDITS  ]    [  QUIT  ]
		   +========+    +===========+    +========+

)";
		
	bool waiting = true;
	while (waiting)
	{
		std::cout << INDENT << "Input: PLAY, CREDITS or QUIT." << std::endl;
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
	std::cout << YELLOW << R"(
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

	std::cout << "\n";
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

)" << RESET_COLOR;

    std::cout << INDENT << "The markets are about to open... Press 'Enter' to proceed.";
    
	//waits for any input from the user to 
	CleanText();
    std::cin.get();
	CleanText();

	//GAMEEEE
	bool inGame = true;
	while (inGame == true)
	{
		//clear previous console
		system("cls");

		//draw current map 
		DrawMap();
		//display room description
		DisplayDescription();

		std::cout << INDENT << "What shall you do? (move + n/s/e/w)" << std::endl;
		//gets player input from user
		WaitingForInput();
		//converts input to lowercase for checks
		playerInput->ToLower();
		//checks for first character to determin whether it is move/ browse/ buy/ use/ search
		switch (playerInput->CharacterAt(0))
		{
		case 'm':
			if (playerInput->EqualTo("move n"))
			{
				//if Ypos is > 0, move up
				if (Ypos > 0)
				{
					Ypos--;
				}
			}
			else if (playerInput->EqualTo("move s"))
			{
				if (Ypos < rows - 1)
				{
					Ypos++;
				}
			}
			else if (playerInput->EqualTo("move e"))
			{
				if (Xpos < columns - 1)
				{
					Xpos++;
				}
			}
			else if (playerInput->EqualTo("move w"))
			{
				if (Xpos > 0)
				{
					Xpos--;
				}
			}
			else
			{
				std::cout << "Invalid Command." << std::endl;
			}
			break;
		default:
			std::cout << "I have not done other commands yet!" << std::endl;
			break;
		}
		//FOR BASIC FUNCTIONALITY
		//move + n/s/e/w
		//browse -> displays wares
		//buy [ITEM] to buy
		//search [ITEM] to check if it's on shopping list and if it's been obtained
				//sort list - quick sort
				// search list - binary sort
		//leave to leave the market
	}
	
	//waits for input
	std::cout << "entering the market, you SHALL NOT PASS (jkjk.. unless..)" << std::endl;
	//move + n/s/e/w to traverse the map
	//when on a tile that contains a vendor
	// options include, move/ talk / browse
	//atm talk just provides a line of dialouge to display
	//browse displays the current wares
	//when browse it selected 
	//player can purchase items with buy [ITEM]
	//this removes the item from the store

}

void Game::DrawMap()
{
	std::cout << "\n";
	std::cout << INDENT << "Market Map: \n" << std::endl;
	std::cout << INDENT << RED << " V " << RESET_COLOR << " - Vendor" << std::endl;
	std::cout << INDENT << " E " << RESET_COLOR << " - Empty" << std::endl;
	std::cout << INDENT << YELLOW << " = " << RESET_COLOR << " - Path" << std::endl;
	std::cout << INDENT << GREEN << " P " << RESET_COLOR << " - Player\n" << std::endl;


	//for every position of the map, draw
	for (int i = 0; i < rows; i++)
	{
		std::cout << INDENT << INDENT;
		for (int j = 0; j < columns; j++)
		{
			//if player is at current position, draw player
			if ((i == Ypos) && (j == Xpos))
			{
				std::cout << "[ " << GREEN << " P " << RESET_COLOR << " ]";
			}
			else //otherwise draw map
			{
				//THIS CODE -> stops the top left and bottom left sqaures from being drawn, if I want to disclude them
				////if position is 0,0 or 2,0, draw empty space
				//if (map[i][j] == 1 || map[i][j] == 11)
				//{
				//	std::cout << "       "; //this is 7 spaces
				//}
				//if the position includes a vendor, draw the vendor marker
				if (map[i][j] == possibleLocations[0] || map[i][j] == possibleLocations[1] || map[i][j] == possibleLocations[2] || map[i][j] == possibleLocations[3])
				{
					std::cout << "[ " << RED << " V " << RESET_COLOR << " ]";
				}
				//if the position is empty space
				else if (map[i][j] == possibleLocations[4] || map[i][j] == possibleLocations[5] || map[i][j] == possibleLocations[6] || map[i][j] == possibleLocations[7])
				{
					std::cout << "[  E  ]";

				}
				//if the position is any other space, draw pathing
				else
				{
					std::cout << "[ " << YELLOW << " = " << RESET_COLOR << " ]";
				}
			}
			
		}
		//each path of map should be on a new line
		std::cout << "\n";
	}
	//makes some space under the 
	std::cout << "\n";

}

void Game::Credits()
{
	//clears the console
	system("cls");

	std::cout << YELLOW << R"( 
                                             _______________________
   _______________________-------------------                       `\
 /:--__                                                              |
||< > |                                   ___________________________/
| \__/_________________-------------------                         |
|                                                                  |
 |                           CREDITS                               |
 |                                                                  |
 |                     Programmer(s)                                |
  |                         Elana Parnis                            |
  |                    Writer(s)                                     |
  |                         Elana Parnis                             |
  |                         Samuel Bokland                            |
   |                                                                  |
   |                   Special Thanks                                 |
   |                        Julian Pahor                             |
   |                                                                 |
  |                                              ____________________|_
  |  ___________________-------------------------                      `\
  |/`--_                                                                 |
  ||[ ]||                                            ___________________/
   \===/___________________--------------------------


)" << RESET_COLOR;

	//player input to either return to menu or quit game
	std::cout << INDENT << "Input: BACK or QUIT." << std::endl;
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
}

void Game::DisplayDescription()
{
	///BUGGGG
	//currently the vendors vector is no longer storing data after it exits the constructor
	// 
	// 
	//based on current map position, display description of what is at that location

	//work out which space I am on -> what the space corresonds too in the possibleLocation
	int searchVal = map[Ypos][Xpos];
	int len = possibleLocations.size();

	int size = vendors.size();
	//indenting the description text for FLAVOUR
	std::cout << INDENT;
	//for each possible Location
	for (int i = 0; i < len; i++)
	{
		//if match was found
		if (possibleLocations[i] == searchVal)
		{
			switch (i)
			{
			case 0: //prints out the first vendor listed in vendors
				vendors[0]->GetDescription()->WriteToConsole();
				std::cout << " ";
				vendors[0]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 1:
				vendors[1]->GetDescription()->WriteToConsole();
				std::cout << " ";
				vendors[1]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 2:
				vendors[2]->GetDescription()->WriteToConsole();
				std::cout << " ";
				vendors[2]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 3:
				vendors[3]->GetDescription()->WriteToConsole();
				std::cout << " ";
				vendors[3]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 4: //4-6 are all the same
			case 5:
			case 6:
				std::cout << "An empty stall sits before you, throughly stripped off all its goods.\n" << std::endl;
				return;
				break;
			case 7:
				//MAGIC BIN 
				std::cout << "GO GO MAGIC BIN\n" << std::endl;
				return;
				break;
			}
		}
	}

	//if no match was found
	std::cout << "You stand on a dusty path, surrounded by the hustle and bustle of market goers.\n" << std::endl;
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
