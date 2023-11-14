#pragma once
#include <vector>
#include <string>
using namespace std;
class Memory
{
public:
	//Constructor
	Memory();
	//methods
	void store(int adress, string value);
	string load(int adress);
	//memory cells
	vector<string>cells;

};
