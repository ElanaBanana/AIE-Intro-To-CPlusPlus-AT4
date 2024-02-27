#ifndef SPELLLIST_H
#define SPELLLIST_H

/*
Elana Parnis
26/02/2024
*/

class SpellList
{
private:
	String spellName;
public:
	SpellList();
	SpellList(String name);
	void Cast();
	~SpellList();
};
#endif
