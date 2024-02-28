#include "Item.h"
#include "String.h"
#include "Player.h"

Item::Item() {
	name = "Podering Orb";
	description = "A translucent orb that would be perfect to ponder over.";
}

Item::Item(String name, String descript){
	this->name = name;
	this->description = descript;
}

Item::~Item() {
	//destructor
}
