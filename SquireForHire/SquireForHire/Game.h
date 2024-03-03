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
	int map[5][3]; // market layout
	Player* player; //the player
public:
	Game();
	//Game(Player p1); //maybe dont need this
	void mainMenu(); //displays the main menu
	void startGame(); //plays the game
	void credits(); //displays game credits
	~Game();

};
#endif

