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
public: //abstract class, can't be instantiated on it's own
	Item(); //default constructor
	Item(String* name, String* descript);
	virtual ~Item();
	const String* GetName() const; //returns the name as a const String
	const String* GetDescription() const; //returns the description as a const String*
	virtual void Use(Player* p) = 0;
	bool operator == (const Item& other) const; //returns true if lhs == rhs
protected:
	String* name; //item name as a String pointer
	String* description; //item description as a String pointer, displayed when item is viewed/ interacted with
};
#endif

