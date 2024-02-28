#ifndef STOREITEM_H
#define STOREITEM_H

/*
Elana Parnis
28/02/2024
*/

class StoreItem: public Item
{
private:
	int price;
public:
	StoreItem(String n, String des, int price); // create a new store item
	void ModifyPrice(int val); //modify the price of an item (higher or lower)
};
#endif

