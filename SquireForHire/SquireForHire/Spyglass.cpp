#include "Spyglass.h"
#include "Item.h"
#include "String.h"
#include "Player.h"

Spyglass::Spyglass(String n, String des, int uses) :Item(n, des) {
	this->uses = uses;
}

void Spyglass::Use(Player& p) {
	p.SetAppraise(7);
}