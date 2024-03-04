#ifndef GAME_H
#define GAME_H
#include "Item.h"
#include "Player.h"
#include "Vendor.h"

/*
Elana Parnis
27/02/2024
*/

class Game
{
private:
	std::vector<Vendor*> vendors; //pointer to a vector containing the vendors
	Player* player; //the player
	String* playerInput = new String("default"); //to store input from the player

	int map[5][3]; // market layout
	int Xpos, Ypos;

public:
	Game();
	//Game(Player p1); //maybe dont need this
	void MainMenu(); //displays the main menu
	void StartGame(); //plays the game
	void Credits(); //displays game credits
	void WaitingForInput(); //when waiting for user input
	~Game();

};
#endif

