#include "Merchant.h"
#include "String.h"

Merchant::Merchant()
{
	name = new String("Shaggy");
	description = new String("A tall lanky figure with sandy blond hair. He's wearing a green v-neck which hangs loosly from his torso. A great dane sleeps at his feet.");
	reasonableness = 10; //average
}

Merchant::Merchant(String* n, String* des, int reason)
{
	this->name = n;
	this->description = des;
	this->reasonableness = reason; 
}

Merchant::~Merchant()
{
	delete name;
	delete description;
}

void Merchant::ChangeReason(int num)
{
	reasonableness -= num;

	if (reasonableness < 1) {
		reasonableness = 1;
	}
}

int Merchant::GetReason()
{
	return reasonableness;
}

String* Merchant::GetName()
{
	return name;
}


String* Merchant::GetDescription()
{
	return description;
}
