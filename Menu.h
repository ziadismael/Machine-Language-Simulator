#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Machine; // Forward declaration

class Menu
{
public:
    Menu();
    Menu(Machine* machine); // Constructor that takes a pointer to Machine
    void displayMenu();
    void displayStatus();

private:
    Machine* simulator; // Pointer to Machine
};