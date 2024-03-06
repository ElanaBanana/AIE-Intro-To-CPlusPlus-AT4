#ifndef MERCHANT_H
#define MERCHANT_H

/*
Elana Parnis
26/02/2024
*/

class String;

class Merchant
{
public:
	Merchant();
	Merchant(String* n, String* des, int reason);
	~Merchant();
	void ChangeReason(int num); //change the users reasonableness
	int GetReason(); //returns the reasonableness
	String* GetName();
	String* GetDescription();
private:
	String* name;
	String* description;
	int reasonableness; //how likely a merchant is to give you a discount
};
#endif

