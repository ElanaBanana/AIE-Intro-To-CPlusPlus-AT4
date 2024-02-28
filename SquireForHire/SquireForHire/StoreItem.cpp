#include "StoreItem.h"
#include "Item.h"
#include "String.h"

/*
Elana Parnis
28/02/2024
*/

StoreItem::StoreItem(String n, String des, int price) :Item(n, des) {
	this->price = price;
}

void StoreItem::ModifyPrice(int val) {
	price += val;
	if (price < 0) { //if price goes below zero, set to zero
		price = 0;
	}
}