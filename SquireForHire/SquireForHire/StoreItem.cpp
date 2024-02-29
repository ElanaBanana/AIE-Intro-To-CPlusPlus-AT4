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

void StoreItem::ModifyPrice(int val) {
	price += val;
	if (price < 0) { //if price goes below zero, set to zero
		price = 0;
	}
}

void StoreItem::Use(Player* p)
{
	//do nothing
}
