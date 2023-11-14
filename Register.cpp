#include "Register.h"

//Constructor
Register::Register() :value("0") {}


//Setter
void Register::setValue(string newValue)
{
	value = newValue;
}

// Getter
string Register::getValue()
{
	return value;
}
