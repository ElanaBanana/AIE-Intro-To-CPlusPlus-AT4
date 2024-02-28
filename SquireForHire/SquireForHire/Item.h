#ifndef ITEM_H
#define ITEM_H

/*
Elana Parnis
26/02/2024
*/

class Item
{
protected:
	String name;
	String description;
public: //abstract class, can't be instantiated on it's own
	Item();
	Item(String name, String descript);
	~Item();
	virtual void Use(Player& p) = 0;
};
#endif

