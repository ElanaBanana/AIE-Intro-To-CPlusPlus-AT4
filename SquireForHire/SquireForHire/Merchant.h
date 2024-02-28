#ifndef MERCHANT_H
#define MERCHANT_H

/*
Elana Parnis
26/02/2024
*/

class Merchant
{
private:
	String name;
	String description;
	int reasonableness;
public:
	Merchant();
	Merchant(String n);
	~Merchant();
	void ChangeReason(int num); //change the users reasonableness
	int GetReason(); //returns the reasonableness

};
#endif

