#include "Memory.h"
#include <iostream>

using namespace std;

//Constructor
Memory::Memory() : cells(256, "00") {}
//Function to store value at specific memory adress
void Memory::store(int adress, string value)
{
	if (adress >= 0 && adress <= 255)
	{
		cells[adress] = value;
	}
	else {
		cout << "Invalid Address" << endl;
	}
}
//Function to load value at specific memory adress
string Memory::load(int adress)
{
	if (adress >= 0 && adress <= 255)
	{
		return cells[adress];
	}
	else {
		cout << "Invalid Address" << endl;
		return "00";
	}
}
