#ifndef GAME_H
#define GAME_H
#include "Item.h"
#include "Player.h"
#include "Vendor.h"

/*
Elana Parnis
27/02/2024
*/

const int rows = 3;
const int columns = 5;

class Game
{
private:
	std::vector<Vendor*> vendors; //pointer to a vector containing the vendors
	Player* player; //the player
	String* playerInput = new String("default"); //to store input from the player

	std::vector<int> possibleLocations;
	int map[rows][columns]; // market layout
	int Xpos, Ypos;
	void CleanText(); //cleans the input buffer
	void WaitingForInput(); //when waiting for user input
	void DisplayDescription();
public:
	Game();
	//Game(Player p1); //maybe dont need this
	void MainMenu(); //displays the main menu
	void StartGame(); //plays the game
	void DrawMap(); //draws the market map
	void Credits(); //displays game credits
	
	~Game();

};
#endif


/*
basic map layout

	 | V |[ E ][ V ][ V ]
[ P ]| = | = ][ = ][ = ]
	 | E |[ V ][ E ][ E ]
     
*/