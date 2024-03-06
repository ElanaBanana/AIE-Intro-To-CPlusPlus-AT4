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
	this->name = new String("spyglass");
	this->description = new String("A shiny magnifying glass, great to help with appraising items!");
	this->usesLeft = 2;
}

Spyglass::Spyglass(int uses)
{
	this->name = new String("pyglass");
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
	p->SetAppraise(7); //set players appraise bonus to 7
	usesLeft--; //Once the item is used, decrease it's use timer by 1
	std::cout << "     " << "You feel the spitit of Sherlock Holmes rush through you." << std::endl;
	std::cout << "     " << "Your chance to appraise an item sucessfully has increased." << std::endl;
	std::cout << "     " << "There are " << usesLeft << " uses left." << std::endl;

	if (usesLeft <= 0)
	{
		std::cout << "The lens of the spyglass falls to the floor and shatters." << std::endl;
		//if there are no uses left for the item, delete the item
		usesLeft = 0;
		p->RemoveInventory(this);
	}

}

