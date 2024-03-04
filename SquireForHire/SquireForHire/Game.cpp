//#include "Game.h"
////#include "Game.h"
//
///*
//Elana Parnis
//04/03/2024
//*/
//
//
//Game::Game()
//{
//	//create wares for each vendor
//	//create merchants for each vendor
//	//create each vendor
//	//make a vector of all the vendors
//
//	//create a vector of items for shopping list, randomised from vendor wares (cal price off all items)
//	//crearte a shopping list
//	//create a player (with provided shopping list)
//
//	//create 5x3 map row 2-> empty pathway with a 25% chance to meet Remy the cheese trader on each tile after 1,0
//	//1,0 if the spawn point
//	//there are 4 vendors, which spawn randomly in 8 locations, 
//	// the other 4 spaces are 3 empty and 1 empty which contains a spyglass (in a bin -> triggers unique dialogue with all merchants)
//
//}
//
//void Game::MainMenu()
//{
//	//draw main menu
//	//waits for input of either 'play', 'credits', or 'quit'
//
//	//play -> destorys menu screen and loads up StartGame()
//	//quit -> quits game
//	//credits -> TBA (draw credits)
//}
//
//void Game::StartGame()
//{
//	//GAMEEEE
//	//spawns player in 1,0
//	//waits for input
//	//move + n/s/e/w to traverse the map
//	//when on a tile that contains a vendor
//	// options include, move/ talk / browse
//	//atm talk just provides a line of dialouge to display
//	//browse displays the current wares
//	//when browse it selected 
//	//player can purchase items with buy [ITEM]
//	//this removes the item from the store
//}
//
//void Game::Credits()
//{
//	//display credits for game
//	//this is optional, will do later
//}
//
//Game::~Game()
//{
//	delete player;
//
//	while (!vendors.empty())
//	{ //while the list is not empty
//		delete vendors.back();
//		vendors.pop_back();
//	}
//	vendors.clear();
//}
