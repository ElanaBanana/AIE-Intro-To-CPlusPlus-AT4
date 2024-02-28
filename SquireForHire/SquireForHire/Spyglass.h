#ifndef SPYGLASS_H
#define SPYGLASS_H

/*
Elana Parnis
28/02/2024
*/
class Spyglass: public Item
{
private:
	int uses; //how many uses are left for the current item
public:
	Spyglass(String n, String d, int uses);
	void Use(Player& p);
};
#endif

