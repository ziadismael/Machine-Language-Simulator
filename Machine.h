#pragma once
#include "ALU.h"
#include "Memory.h"
#include "Instruction.h"
#include "Register.h"

class Menu; // Forward declaration

class Machine
{
public:
    Machine(); // Constructor
    void setMenu(Menu* menu); // Setter for Menu
    void loadtoMemory();
    void runMachine();
    void runMachine(int x);
    void clearMemory();
    void clearRegister();
    void displayBgad();

private:
    Memory memory;
    ALU alu;
    Register registers[16];
    Instruction* instructions;
    int PC{};
    string IR = "0000";
    int starting_address = 1;
    int resetting_adress = 1;
    Menu* menu; // Pointer to Menu
};