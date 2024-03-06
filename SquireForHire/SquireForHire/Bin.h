#pragma once
#include "Item.h"


class Bin : public Item
{
public:
	Bin();
	Bin(Item* item); //create a bin with a spcific item
	~Bin() override;
	const String* GetItemName() const; //returns the name of the item in the bin
	void Use(Player* p) override; // using the bin, returns the player the item inside
	//subsequent uses, is just gross

private:
	//bin holds one item
	Item* trash;
};

