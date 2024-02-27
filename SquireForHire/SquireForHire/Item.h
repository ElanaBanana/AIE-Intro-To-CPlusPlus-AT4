#ifndef ITEM_H
#define ITEM_H
#include "String.h"
/*
Elana Parnis
26/02/2024
*/

class Item
{
private:
	String name;
	String description;
public:
	Item();
	Item(String descript);
	~Item();
	virtual void Use() = 0; //pure virtual 
	//should I use????
	//need to check if I need to put NPC items with user items
};
#endif

