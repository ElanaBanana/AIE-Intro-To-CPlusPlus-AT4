#ifndef STRING_H
#define STRING_H

/*
Elana Parnis
07/02/2024
*/

//const before the function means it is returning a const value (cant be changed)
//const after the function, means it cannot modify the the objects state

class String {
public:
	String();
	String(const char* str);
	String(const String& otherString);
	~String();
public:
	int Length() const; // returns the size of the length using strlen()
	char CharacterAt(int index); // returns the character at index specified
	bool EqualTo(const String& other) const; // returns true if the string provided is == the stored string
	void Append(const String& str); //adds the provided string to the end current string
	void Prepend(const String& str); //adds the provided string to the start of the current string
	const char* CStr() const; //get my epic string LITERALLY
	void ToLower(); // converts all the values in the current string to lowercase returns as String pointer
	void ToUpper(); // converts all the values in the current string to UPPERCASE returns as String pointer

	int Find(const String& findString); //returns the location of the start of the FIRST INSTANCE of the specific string
	int Find(int startIndex, const String& findString); //same as above but starts looking from specified index
	void Replace(const String& findString, const String& replaceString); //replaces all the occurances of specified string in the current string with new string
	void ReadFromConsole(); // get input from the console and store the result
	void WriteToConsole() const; // write the current string to the console
public:
	bool operator ==(const String& other) const; //returns true if lhs == rhs
	bool operator !=(const String& other); // returns true if lhs != rhs 
	void operator =(const String& str); //replaces the characters in teh lhs with the characters in rhs
	bool operator <(const String& other); //returns true if the lhs comes before rhs in the alphabet
	bool operator >(const String& other); //returns true if the lhs comes after rhs in the alphabet
	char operator [](int index); //returns the character located at pos provided
	char* operator +(const String& other); //return a pointer to the new concatantion of the two strings
	void operator +=(const String& other);  //sets the value before += to become the concatanation of two strings
	static bool alphabetComparison(const String& strLHS, const String& strRHS); // returns whether the LHS comes before the RHS is the alphabet
private:
	//I fixed it Julian :D
	void joinStrings(const String& strLHS, const String& strRHS); //function to add two strings together
	char* theStringArray; //pointer to the char array containing the class string
};

#endif
