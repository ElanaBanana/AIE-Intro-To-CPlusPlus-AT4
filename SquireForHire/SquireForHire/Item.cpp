#include "Item.h"
#include "String.h"
#include "Player.h"
#include <iostream>

Item::Item() {
	name =  new String("Pondering Orb");
	description = new String("A translucent orb that would be perfect to ponder.");
}

Item::Item(String* name, String* descript){
	this->name = name;
	this->description = descript;
}

Item::~Item() {
	//delete name;
	//delete description;
}

const String* Item::GetName() const
{
	return name;
}

const String* Item::GetDescription() const
{
	return description;
}

bool Item::operator==(const Item& other) const
{
	//std::cout << "they are being checked!" << std::endl;
	
	if (*this->name == *other.name)  // if the names match
	{
		//std::cout << "the names match!" << std::endl;

		if (*description == *other.description) //if the descriptions match aswell, they are the same
		{
			//std::cout << "they match!" << std::endl;
			return true;
		}
	}
	return false;
}
