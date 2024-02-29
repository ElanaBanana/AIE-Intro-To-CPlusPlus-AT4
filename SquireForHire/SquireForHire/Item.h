#ifndef ITEM_H
#define ITEM_H

/*
Elana Parnis
26/02/2024
*/
class Player;
class String;

class Item
{
protected:
	String* name; //item name
	String* description; //item description, displayed when item is viewed/ interacted with
public: //abstract class, can't be instantiated on it's own
	//Item();
	//Item(String* name, String* descript);
	//~Item();
	const String* GetName();
	virtual void Use(Player* p) = 0;
};
#endif

