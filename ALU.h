#pragma once
#include "Register.h"
class ALU
{
public:
	ALU() = default;
	void adddingFunction(Register& r1, Register& r2, Register& r3);
	int add(int num1, int num2);
};

