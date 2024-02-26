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
	String name;
public:
	Player();
	~Player();
};
#endif

