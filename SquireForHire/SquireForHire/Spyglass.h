#ifndef SPYGLASS_H
#define SPYGLASS_H

/*
Elana Parnis
28/02/2024
*/

#include "Item.h"
class Player;
class String;

class Spyglass: public Item
{
public:
	//Spyglass(String* n, String* d, int uses);
	Spyglass(); //default constructor
	Spyglass(int uses);
	void Use(Player* p) override;
	~Spyglass() override;

private:
	int usesLeft; //how many uses are left for the current item
};
#endif
