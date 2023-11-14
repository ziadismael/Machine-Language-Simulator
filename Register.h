#pragma once
#include<vector>
#include <string>
using namespace std;
class Register
{
public:
	Register();
	void setValue(string newValue);
	string getValue();

private:
	string value;
};
