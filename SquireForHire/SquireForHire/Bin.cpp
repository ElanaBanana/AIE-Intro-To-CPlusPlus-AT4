#include <iostream>

#include "Bin.h"
#include "Spyglass.h"
#include "Player.h"
#include "String.h"

const char* INDENT = "\x1b[5C";

Bin::Bin()
{
	trash = new Spyglass();
}

Bin::Bin(Item* item)
{
	trash = item;
}

Bin::~Bin()
{
	delete trash;
}

const String* Bin::GetItemName() const
{
	return trash->GetName();
}

void Bin::Use(Player* player)
{
	//if the bin has an item
	if (trash != nullptr)
	{
		std::cout << INDENT << "You rummage around in the bin..\n" << std::endl;
		system("pause");
		std::cout << INDENT << "\x1b[91m" << "What is wrong with you?" << "\x1b[0m" << std::endl;
		std::cout << INDENT << "You loose some dignity but find a " << "\x1b[94m" << GetItemName()->CStr() << "\x1b[0m" << ".\n" << std::endl;
		player->AddInventory(trash);
		player->UpdateSmell(true);
		trash = nullptr;
	}
	else
	{
		std::cout << INDENT << "You rummage around in the bin..\n" << std::endl;
		system("pause");
		std::cout << INDENT << "\x1b[91m" << "You find moldy cheese and a soggy boot." << "\x1b[0m" << std::endl;
		std::cout << INDENT << "Did you expect anything else?" << std::endl;
		std::cout << INDENT << "You're dumpster diving for trash. Please get professional help.\n" << std::endl;
	}
	
}
