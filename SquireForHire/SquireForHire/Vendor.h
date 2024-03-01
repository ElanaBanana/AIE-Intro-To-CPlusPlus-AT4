#ifndef VENDOR_H
#define VENDOR_H
#include "Merchant.h"

#include <vector>

/*
Elana Parnis
26/02/2024
*/
class String;
class StoreItems;

class Vendor
{
private:
	String* description; //description of the room/ shop
	Merchant merchant; //the merchant of current vendor
	std::vector<StoreItem*> wares; //pointer to vector of items sold by merchant
	//std::vector<Item> items; //vector of items sold by merchant
public:
	Vendor();
	Vendor(Merchant mer, String* description, std::vector<StoreItems> items);
	~Vendor();

};

#endif 
