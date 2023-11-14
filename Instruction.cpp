#include "Instruction.h"
#include "Memory.h"
#include <sstream>
#include <cctype>
#include <algorithm>

LoadInstructionM::LoadInstructionM(Register& r, Memory& memory, int memoryadress) :registers(r), memory(memory), memoryadress(memoryadress) {}

void LoadInstructionM::excute()
{
	string value = memory.load(memoryadress);
	registers.setValue(value);
}

LoadInstructiond::LoadInstructiond(string value, Register& registers) :value(value), registers(registers) {}

void LoadInstructiond::excute()
{
	registers.setValue(value);
}
AddComopliments::AddComopliments(Register& r1, Register& r2, Register& r3, ALU res) : r1(r1), r2(r2), r3(r3), res(res)
{
	value1 = 0;
	value2 = 0;

}

void AddComopliments::toTwosCompliment(Register& r1, Register& r2)
{
	string num1 = r1.getValue(), num2 = r2.getValue();
	int integer1, integer2;
	integer1 = stoi(num1, nullptr, 16);
	integer2 = stoi(num2, nullptr, 16);
	if (integer1 > 128)
		value1 = integer1 - 256;
	else
		value1 = integer1;
	if (integer2 > 128)
		value2 = integer2 - 256;
	else
		value2 = integer2;
}

void AddComopliments::excute()
{
	string val3;

	toTwosCompliment(r1, r2);

	int value3 = res.add(value1, value2);

	if (value3 < 0)
	{
		value3 = -1 * (value3);
		value3 = 256 - value3;

		std::stringstream ss;
		ss << hex << value3;

		val3 = ss.str();
		
	}
	else
	{
		std::stringstream ss;
		ss << hex << value3;

		val3 = ss.str();

	}
	transform(val3.begin(), val3.end(), val3.begin(), ::toupper);
	if (val3.size() == 1)
	{
		val3 = "0" + val3;
	}
	r3.setValue(val3);
}
