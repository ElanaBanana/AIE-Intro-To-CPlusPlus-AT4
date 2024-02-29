#include "Spyglass.h"
#include "String.h"
#include "Player.h"
#include <iostream>

//Thanks Julian :D

//Spyglass::Spyglass(String* n, String* d, int uses) : Item(n, d)
//{
//	this->uses = uses;
//};

Spyglass::Spyglass()
{
	this->name = new String("Spyglass");
	this->description = new String("A shiny magnifying glass, great to help with appraising items!");
	this->usesLeft = 3;
}

Spyglass::Spyglass(int uses)
{
	this->name = new String("Spyglass");
	this->description = new String("A shiny magnifying glass, great to help with appraising items!");
	this->usesLeft = uses;
}

Spyglass::~Spyglass()
{
	delete name;
	delete description;
}

void Spyglass::Use(Player* p)
{
	if (usesLeft <= 0)
	{
		std::cout << "The item is broken and can no longer be used" << std::endl;
		return;
	}
	p->SetAppraise(7);
	usesLeft--; //Once the item is used, decrease it's use timer by 1
	if (usesLeft <= 0)
	{
		usesLeft = 0;
	}

}

