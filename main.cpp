#include <iostream>
#include <string>
#include "Menu.h"
#include "Machine.h"
using namespace std;

int main()
{
	Machine test;
	Machine* testptr = &test;
	Menu program(testptr);
	program.displayMenu();
}
