#ifndef STOREITEM_H
#define STOREITEM_H

/*
Elana Parnis
28/02/2024
*/

#include "Item.h"
class String;
class PLayer;

class StoreItem: public Item
{
public:
	StoreItem(); //default constructor
	StoreItem(String* n, String* des, int price); // create a new store item
	~StoreItem();
public:
	int GetPrice(); //returns the price of an item
	void ModifyPrice(int val); //modify the price of an item (higher or lower)
	void Use(Player* p) override; //for StoreItem this returns the description (maybe)
private:
	int price; //how much the item costs at any given time
};
#endif

