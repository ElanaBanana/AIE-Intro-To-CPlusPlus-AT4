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
#include "Bin.h"

/*
Elana Parnis
04/03/2024
*/

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
	tempName->ToLower(); //THIS IS SO MY BINARY SEARCH WORKS
	//creates a new item 
	StoreItem* item1 = new StoreItem(tempName, tempDes, 5);
	tempName = new String("Greater Health Potion");
	tempDes = new String("A large vial with bright red liquid.");
	tempName->ToLower();
	StoreItem* item2 = new StoreItem(tempName, tempDes, 10);

	//saves items in list
	std::vector<StoreItem*> wares;
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	//creates a vendor from the list of items
	tempDes = new String("A shabby pop up stall with all manner of potions and trinkets, sitting between the vials is female wicth.");
	Vendor* witchHut = new Vendor (witch, tempDes, wares);

		//soldier - VENDOR 2
	tempName = new String("Anduin");
	tempDes = new String("a knight with shining golden armour, a lion sits proudly upon his breastplate.");
	Merchant* soldier = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Short Sword");
	tempDes = new String("Ye old reliable.");
	tempName->ToLower();
	item1 = new StoreItem(tempName, tempDes, 8);
	tempName = new String("Chainmail Armour");
	tempDes = new String("Armour in pristine condition.");
	tempName->ToLower();
	item2 = new StoreItem(tempName, tempDes, 12);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("A very well put together store, with racks of various weapons and armour. Arming the stall is a human male.");
	Vendor* armoury = new Vendor(soldier, tempDes, wares);

		//dwarf - VENDOR 3
	tempName = new String("Dwalin");
	tempDes = new String("a proud and physically imposing dwarf and a rather majestic beard.");
	Merchant* dwarf = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Bread");
	tempDes = new String("Hard as a brick");
	tempName->ToLower();
	item1 = new StoreItem(tempName, tempDes, 6);
	tempName = new String("Apple Pie");
	tempName->ToLower();
	tempDes = new String("Just like grandma would make it.");
	item2 = new StoreItem(tempName, tempDes, 7);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("A homey store with many amazing smells coming from various baked goods. The owner is a dwarven man.");
	Vendor* bakery = new Vendor(dwarf, tempDes, wares);

		// elf/vampire - VENDOR 4
	tempName = new String("Astarion");
	tempDes = new String("a pale elf with perfectly styled white hair and fangs protruding from behind his upper lip.");
	Merchant* vampire = new Merchant(tempName, tempDes, 10);
	
	//vendor items
	tempName = new String("Map of Mars");
	tempDes = new String("What even is that?");
	tempName->ToLower();
	item1 = new StoreItem(tempName, tempDes, 10);
	tempName = new String("Map of Narnia");
	tempDes = new String("Commonly found in ecentric gentleman's closets.");
	tempName->ToLower();
	item2 = new StoreItem(tempName, tempDes, 11);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("Ink and paper cover the stalls walls, with maps of all shapes and shades. Manning the stall is a male elf.");
	Vendor* cartographer = new Vendor(vampire, tempDes, wares);

		// ratman! the wondering cheese seller - VENDOR 5
	tempName = new String("Remy");
	tempDes = new String("a rather cheeky looking rat pokes his head from behind his hood.");
	Merchant* ratman = new Merchant(tempName, tempDes, 10);

	//vendor items
	tempName = new String("Swiss Cheese");
	tempDes = new String("Holy!");
	tempName->ToLower();
	item1 = new StoreItem(tempName, tempDes, 6);
	tempName = new String("Blue Cheese");
	tempDes = new String("People like this?");
	tempName->ToLower();
	item2 = new StoreItem(tempName, tempDes, 7);

	wares.clear(); //cleans out current vector
	wares.push_back(item1);
	wares.push_back(item2);

	//vendor
	tempDes = new String("Out of no-where appears a sus individual in a dirty cloak. ");
	Vendor* cheese = new Vendor(ratman, tempDes, wares);
	
	//make a vector of all the vendors
	vendors.push_back(witchHut);
	vendors.push_back(armoury);
	vendors.push_back(bakery);
	vendors.push_back(cartographer);
	vendors.push_back(cheese);

	bin = new Bin(); //create a bin

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
	//crearte a shopping list, it will automatically sort itself in alphabetical order
	ShoppingList* shoppingList = new ShoppingList(list);

	//create a player (with provided shopping list)
	player = new Player(shoppingList, budget);

	//start the player with 1 basic spyglass in their inventory
	Spyglass* startingItem = new Spyglass();
	player->AddInventory(startingItem);

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
	bool waiting = true;
	while (waiting)
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
				exit(0);
				return;
			}
		}
		else
		{
			std::cout << INDENT << "That input in invalid.\n" << std::endl;
		}
		//formatting
		std::cout << "\n";
		system("pause");
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
	player->GetShoppingList()->PrintAll(false);

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

    std::cout << INDENT << "The markets are about to open... Press 'Enter' to proceed.\n\n";
	std::cout << INDENT;
	//waits for any input from the user to 
	CleanText();
    std::cin.get();
	CleanText();

	//GAMEEEE
	bool inGame = true;
	while (inGame == true)
	{
		//draw current map 
		DrawMap();
		//display room description
		DisplayVendorDescription();

		std::cout << INDENT << "What shall you do? (move + n/s/e/w) (vendors -> talk/ browse) (use /search + [item]) (leave)" << std::endl;
		//gets player input from user
		CleanText();
		WaitingForInput();
		CleanText();
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
				std::cout << INDENT << "Invalid Command.\n" << std::endl;
				//formatting
				std::cout << "\n";
				system("pause");
			}
			break;
		case 'b':
			if (playerInput->EqualTo("browse"))
			{

				//if browsing you can either buy an item or leave
				//replace "buy " in the input with "", so only the search value is left
				bool inShop = true;
				while (inShop == true)
				{
					//draw current map 
					DrawMap();
					//display room description
					DisplayVendorDescription();

					int currentVendor = -1;
					std::cout << "\n";
					//check if a vendor is being viwed and for which vendor is being viewed
					//if item was NOT found, it will return the last element of the vector
					if (map[Ypos][Xpos] == possibleLocations[0])
					{ //display vendors wares
						vendors[0]->DisplayWares();
						currentVendor = 0;
					}
					else if (map[Ypos][Xpos] == possibleLocations[1])
					{
						vendors[1]->DisplayWares();
						currentVendor = 1;
					}
					else if (map[Ypos][Xpos] == possibleLocations[2])
					{
						vendors[2]->DisplayWares();
						currentVendor = 2;
					}
					else if (map[Ypos][Xpos] == possibleLocations[3])
					{
						vendors[3]->DisplayWares();
						currentVendor = 3;
					}
					else
					{
						std::cout << INDENT << "There is no vendor here.\n" << std::endl;
						break;
					}
					std::cout << INDENT << "What shall you do? (buy + [item]) (search + [item]) (leave)" << std::endl;
					//gets player input from user
					CleanText();
					WaitingForInput();
					CleanText();

					//converts input to lowercase for checks
					playerInput->ToLower();

					if (playerInput->EqualTo("leave"))
					{
						inShop = false;
					}
					else if (playerInput->Find("buy") == 0)
					{
						playerInput->Replace("buy ", "");
						//get the index of item in list
						StoreItem* itemToBuy = vendors[currentVendor]->FindItem(playerInput);
						std::cout << "\n";
						if (itemToBuy != nullptr)
						{
							vendors[currentVendor]->SellItem(player, itemToBuy);
						}
						else
						{
							std::cout << INDENT << "Item is not for sale!" << std::endl;
						}
					}
					//if player wants to search for item
					else if (playerInput->CharacterAt(0) == 's')
					{
						SearchItem();
					}
					else
					{
						std::cout << INDENT << "That is not a command :(\n" << std::endl;
					}
				}
				
				std::cout << "\n";
				system("pause");
			}
			//For buy, check if the buy keyword is found at the start of the input
			//If it is for all characters after buy+" " to be the search string,  search Shopping List for item
			else if (playerInput->Find("buy") == 0)
			{

			}
			break;
		case 't':
			if (playerInput->EqualTo("talk"))
			{
				std::cout << "\n";
				//check if a vendor is being viwed and for which vendor is being viewed
				//if item was NOT found, it will return the last element of the vector
				if (map[Ypos][Xpos] == possibleLocations[0])
				{ //display vendors wares
					std::cout << INDENT << "Standing before you is ";
					vendors[0]->GetMerchant()->GetDescription()->WriteToConsole();
				}
				else if (map[Ypos][Xpos] == possibleLocations[1])
				{
					std::cout << INDENT << "Standing before you is ";
					vendors[1]->GetMerchant()->GetDescription()->WriteToConsole();
				}
				else if (map[Ypos][Xpos] == possibleLocations[2])
				{
					std::cout << INDENT << "Standing before you is ";
					vendors[2]->GetMerchant()->GetDescription()->WriteToConsole();
				}
				else if (map[Ypos][Xpos] == possibleLocations[3])
				{
					std::cout << INDENT << "Standing before you is ";
					vendors[3]->GetMerchant()->GetDescription()->WriteToConsole();
				}
				else
				{
					std::cout << INDENT << "There is no vendor here.\n" << std::endl;
				}
				//formatting
				std::cout << "\n";
				system("pause");
			}
			break;
		case 's':
			SearchItem();
			break;
		case 'i':
			if (playerInput->EqualTo("inventory") || playerInput->EqualTo("i"))
			{
				player->PrintInventroy();

				std::cout << "\n";
				system("pause");
			}
		case 'u':
			//if input is use bin and player is on the speical bin tile
			if (playerInput->EqualTo("use bin") && map[Ypos][Xpos] == possibleLocations[7])
			{
				bin->Use(player);
				std::cout << "\n";
				system("pause");
				continue;
			}
			if (playerInput->Find("use") == 0)
			{
				//check if item is in inventory
				//if it is call use()
				playerInput->Replace("use ", "");
				//get the index of item in list
				Item* itemToUse = player->FindItem(playerInput);
				std::cout << "\n";
				//if item is not null (aka if an item was found)
				if (itemToUse != nullptr)
				{
					itemToUse->Use(player);
				}
				else
				{
					std::cout << INDENT << "You don't have that item!\n" << std::endl;

				}
				std::cout << "\n";
				system("pause");
			}
		case 'l':
			if (playerInput->EqualTo("leave"))
			{
				//return to main menu 
				MainMenu();
			}
			break;
		default:
			std::cout << "That is not a command :(\n" << std::endl;
			//formatting
			std::cout << "\n";
			system("pause");
			break;
		}
	}
}

void Game::DrawMap()
{
	//clear previous console
	system("cls");

	//player funds, temp location
	std::cout << "\n";
	std::cout << INDENT << "Current Funds: ";
	std::cout << YELLOW << player->GetCoins() << "G" << RESET_COLOR << std::endl;

	std::cout << "\n";
	std::cout << INDENT << "Market Map: \n" << std::endl;
	std::cout << INDENT << RED << " V " << RESET_COLOR << " - Vendor" << std::endl;
	std::cout << INDENT << " E " << RESET_COLOR << " - Empty Stall" << std::endl;
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
	bool waiting = true;
	while (waiting)
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
  |                                                                  |
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
		//waits for player input
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
		std::cout << "\n";
		system("pause");
	}
}

void Game::DisplayVendorDescription()
{
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
				//vendors[0]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 1:
				vendors[1]->GetDescription()->WriteToConsole();
				//vendors[1]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 2:
				vendors[2]->GetDescription()->WriteToConsole();
				//vendors[2]->GetMerchant()->GetDescription()->WriteToConsole();
				std::cout << "\n";
				return;
				break;
			case 3:
				vendors[3]->GetDescription()->WriteToConsole();
				//vendors[3]->GetMerchant()->GetDescription()->WriteToConsole();
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
				std::cout << "A lone bin sits in an otherwise empty stall. Nothing odd here.\n" << std::endl;
				return;
				break;
			}
		}
	}

	//if no match was found
	std::cout << "You stand on a dusty path, surrounded by the hustle and bustle of market goers.\n" << std::endl;
}

void Game::SearchItem()
{
	//checks if search is found at the start of the command
	if (playerInput->Find("search") == 0)
	{
		//replace "search " in the input with "", so only the search value is left
		playerInput->Replace("search ", "");

		//get the index of item in list
		int index = player->GetShoppingList()->SearchList(playerInput);
		std::cout << "\n";
		if (index == -1)
		{
			std::cout << INDENT << "Item was not found in the shopping list." << std::endl;
		}
		else
		{
			std::cout << INDENT << "Item was found in the shopping list!" << std::endl;
			std::cout << INDENT;
			player->GetShoppingList()->GetList()[index]->GetName()->WriteToConsole();
			if (player->GetShoppingList()->GetObtained()[index])
			{
				std::cout << "   " << "Obtained" << std::endl;
			}
			else
			{
				std::cout << "   " << "Not Obtained" << std::endl;
			}
		}

		//searches list for item and if found display item and if it's been obtained
		//std::cout << "Sorted Shopping List\n";
		//player->GetShoppingList()->PrintAll(false);

		//formatting
		std::cout << "\n";
		system("pause");
	}
}

void Game::WaitingForInput()
{
	std::cout << "	> ";
	playerInput->ReadFromConsole();

}

const char* Game::GetIndent() const
{
	return INDENT;
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
