#include "Machine.h"
#include "Menu.h"

Machine::Machine() : menu(nullptr) {} // Constructor initialization

void Machine::setMenu(Menu* menuPtr)
{
	menu = menuPtr;
}

void Machine::loadtoMemory()
{
	cout << "Enter the file name that contains the Vole program instructions: ";
	string filename;
	cin >> filename;

	filename += ".txt";
	cout << endl << "Enter Address to start storing from, or (1) for default: ";

	string address_hex;
	cin >> address_hex;
	starting_address = stoi(address_hex, nullptr, 16);
	resetting_adress = starting_address;
	int iter = starting_address;
	cout << "Loading Program...\n";

	ifstream file;
	file.open(filename);

	if (!file.is_open()) {
		cout << "Error in openeing the file.";
		return;
	}
	// 0x1 0x2 0xFF -> cell1 = 0x12 || cell2 = 0xFF
	string line;
	while (getline(file, line)) {
		string cell1, cell2;
		cell1 = cell1 + line[2] + line[6];
		cell2 = line.substr(10);


		memory.cells[iter++] = cell1;
		memory.cells[iter++] = cell2;
	}


	file.close();
	cout << "Program loaded in memory starting from the address: " << hex << starting_address << endl;
}
