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
