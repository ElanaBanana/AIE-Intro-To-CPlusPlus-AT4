#include "Item.h"
#include "String.h"
#include "Player.h"

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

const String* Item::GetName()
{
	return name;
}
