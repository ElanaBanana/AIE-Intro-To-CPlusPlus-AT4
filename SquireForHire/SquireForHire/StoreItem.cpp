#include <iostream>
#include "StoreItem.h"
#include "String.h"

/*
Elana Parnis
28/02/2024
*/

StoreItem::StoreItem(){
	name =  new String("Pondering Orb");
	description = new String("A translucent orb that would be perfect to ponder.");
	price = 5;
}

StoreItem::StoreItem(String* n, String* des, int price){
	this->price = price;
	this->name = n;
	this->description = des;
}

int StoreItem::GetPrice()
{
	return price;
}

void StoreItem::ModifyPrice(int val) {
	price += val; //modify the item price by x amount (-ive or +ive)
	if (price < 0) { //if price goes below zero, set to one -> minimum price
		price = 1;
	}
}

void StoreItem::Use(Player* p)
{
	std::cout << "     " << description->CStr() << std::endl;
}

StoreItem::~StoreItem()
{
	delete name;
	delete description;
}
