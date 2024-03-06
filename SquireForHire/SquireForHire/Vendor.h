#ifndef VENDOR_H
#define VENDOR_H
#include "Merchant.h"

#include <vector>


/*
Elana Parnis
26/02/2024
*/

class String;
class StoreItem;
class Player;

class Vendor
{
public:
	Vendor(); //default constructor
	Vendor(Merchant* mer, String* description, std::vector<StoreItem*> items);
	~Vendor();
public:
	const std::vector<StoreItem*> ReturnWares();
	StoreItem* FindItem(String* name); //returns an item with given name
	void DisplayWares();
	void SellItem(Player* pl, StoreItem* item); //sell item to player, removes item from wares and adds to player inventory
	String* GetDescription(); //returns the vendor description
	Merchant* GetMerchant();
private:
	String* description; //description of the room/ shop
	Merchant* merchant; //the merchant of current vendor
	std::vector<StoreItem*> wares; //vector of item pointers of wares sold by merchant
	//std::vector<Item> items; //vector of items sold by merchant
};

#endif 
