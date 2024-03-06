#ifndef GAME_H
#define GAME_H
#include "Item.h"
#include "Player.h"
#include "Vendor.h"

/*
Elana Parnis
27/02/2024
*/

class Bin;

const int rows = 3;
const int columns = 5;

class Game
{
private:
	std::vector<Vendor*> vendors; //pointer to a vector containing the vendors
	Player* player; //the player
	String* playerInput = new String("default"); //to store input from the player
	Bin* bin; //pointer to the lone bin 

	std::vector<int> possibleLocations;
	int map[rows][columns]; // market layout
	int Xpos, Ypos;
	void CleanText(); //cleans the input buffer
	void WaitingForInput(); //when waiting for user input
	void DisplayVendorDescription(); //displays the description of the current vendor
	void SearchItem(); //searches for item in shopping list
	
	//I tried implementing it Julian, I got lost (O_O )
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
public:
	Game();
	//Game(Player p1); //maybe dont need this
	void MainMenu(); //displays the main menu
	void StartGame(); //plays the game
	void DrawMap(); //draws the market map
	void Credits(); //displays game credits
	const char* GetIndent() const; //returns the value of INDENT
	~Game();

};
#endif


/*
basic map layout

	 | V |[ E ][ V ][ V ]
[ P ]| = | = ][ = ][ = ]
	 | E |[ V ][ E ][ E ]
     
*/