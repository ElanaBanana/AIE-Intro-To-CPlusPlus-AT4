#ifndef PLAYER_H
#define PLAYER_H
#include "SpellList.h"

/*
Elana Parnis
26/02/2024
*/

class Player
{
private:
	SpellList spellist;
	String name; //the players name
	int coins; // the amount of money the player has
	int spellBonus; //spellcasting modifier
public:
	Player();
	~Player();
};
#endif

