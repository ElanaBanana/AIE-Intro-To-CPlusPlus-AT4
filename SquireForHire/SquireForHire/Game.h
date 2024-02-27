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
	std::vector<Vendor> vendors; //vector of vendors
	int map[5][3];
	Player player; //the player
public:
	Game();
	Game(Player p1);
	void mainMenu(); //displays the main menu
	void startGame(); //plays the game
	void credits(); //displays game credits
	~Game();

};
#endif

