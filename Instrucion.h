#pragma once
#include "Register.h"
#include "Memory.h"
#include "ALU.h"
class Instruction
{
public:
	Instruction() = default;
	virtual void excute() = 0;
	virtual ~Instruction() {}
};

class LoadInstructionM : public Instruction // opcode 1
{
public:
	LoadInstructionM(Register& r, Memory& memory, int memoryadress);
	void excute() override;


private:
	Register& registers;
	Memory& memory;
	int memoryadress;
};

class LoadInstructiond : public Instruction // opcode 2
{
public:
	LoadInstructiond(string value, Register& registers);
	void excute();


private:
	string value;
	Register& registers;
};

class StoreatMemory : public Instruction // opcode 3
{
public:
	StoreatMemory(int memory_address, Register& registers, Memory& memory);
	void excute();


private:
	int memory_address;
	Register& registers;
	Memory& memory;
};

class MovetoRegister : public Instruction //op-code 4
{
public:
	MovetoRegister(Register& register1, Register& register2);
	void excute();
private:
	Register& register1;
	Register& register2;
};

class AddComopliments : public Instruction
{
public:
	AddComopliments(Register& r1, Register& r2, Register& r3, ALU res);
	void toTwosCompliment(Register& r1, Register& r2);
	void excute();
private:
	int value1 = 0;
	int value2 = 0;
	Register& r1;
	Register& r2;
	Register& r3;
	ALU res;
};
