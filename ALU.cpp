#include "ALU.h"
#include <sstream>
#include <string>

void ALU::adddingFunction(Register& r1, Register& r2, Register& r3)
{
	int val1, val2;
	std::istringstream(r1.getValue()) >> val1;
	std::istringstream(r2.getValue()) >> val2;
	int result = add(val1, val2);
	string res = std::to_string(result);
	r3.setValue(res);
}

int ALU::add(int num1, int num2)
{
	return num1 + num2;
}