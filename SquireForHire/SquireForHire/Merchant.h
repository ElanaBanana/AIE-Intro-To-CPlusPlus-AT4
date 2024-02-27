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
	int magicAffinity;
	int reasonableness;
public:
	Merchant();
	Merchant(String n);
	~Merchant();
	int Affinity(); //returns the users magical affinity score
	void ChangeReason(int num); //change the users reasonableness
	int GetReason(); //returns the reasonableness

};
#endif

