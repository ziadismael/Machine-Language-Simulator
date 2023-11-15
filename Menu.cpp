#include "Menu.h"
#include "Machine.h"
using namespace std;

Menu::Menu() : simulator(nullptr) {}
Menu::Menu(Machine* machine) : simulator(machine) {} // Constructor initialization


void Menu::displayMenu()
{
    cout << "                          +---------------------------------------------+\n";
    cout << "                          |       VOLE Machine Language Simulator       |\n";
    cout << "                          +---------------------------------------------+\n";
    cout << "                          | 1. Run Program                              |\n";
    cout << "                          | 2. Single Step                              |\n";
    cout << "                          | 3. Display Status                           |\n";
    cout << "                          | 4. Clear Memory                             |\n";
    cout << "                          | 5. Clear Registers                          |\n";
    cout << "                          | 6. Reset                                    |\n";
    cout << "                          | 7. Load Program                             |\n";
    cout << "                          | 8. Help                                     |\n";
    cout << "                          | 0. Exit                                     |\n";
    cout << "                          +---------------------------------------------+\n";
    cout << endl;

    int choice = 8;

    simulator->loadtoMemory();
    cout << endl;
    while (choice != 0)
    {
        cout << "Enter your choice (1-8) or (0) to exit: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Running Program...\n";
            simulator->runMachine();
            break;

        case 2:
            cout << "Single Step...\n";
            simulator->runMachine(1);
            break;

        case 3:
            displayStatus();
            break;

        case 4:
            cout << "Clearing Memory...\n";
            simulator->clearMemory();
            break;

        case 5:
            cout << "Clearing Registers...\n";
            simulator->clearRegister();
            break;

        case 6:
            cout << "Resetting Program...\n";
            simulator->clearMemory();
            simulator->clearRegister();
            break;

        case 7:
            simulator->loadtoMemory();
            break;

        case 0:
            cout << "Thank You !" << endl;
            break;

        case 8:
            cout << "Help:\n";
            cout << "1. LOAD MEMORY (Op-code 1):\n";
            cout << "Format: 1RXY\n";
            cout << "Description: Load the register R with the bit pattern found in the memory cell whose address is XY.\n";
            //cout << "\n";
            cout << "2. LOAD IMMEDIATE (Op-code 2):\n";
            cout << "Format: 2RXY\n";
            cout << "Description: Load the register R with the bit pattern XY.\n";
            //cout << "\n";
            cout << "3. STORE (Op-code 3):\n";
            cout << "Format: 3RXY\n";
            cout << "Description: Store the bit pattern found in register R in the memory cell whose address is XY.\n";
            //cout << "\n";
            cout << "4. STORE TO SCREEN (Op-code 3 R00):\n";
            cout << "Format: 3R00\n";
            cout << "Description: Store the contents of register R in memory location 00, which is a memory mapping for the screen.\n";
            //cout << "\n";
            cout << "5. MOVE (Op-code 4):\n";
            cout << "Format: 40RS\n";
            cout << "Description: Move the bit pattern found in register R to register S.\n";
            //cout << "\n";
            cout << "6. ADD (Op-code 5):\n";
            cout << "Format: 5RST\n";
            cout << "Description: Add the bit patterns in registers S and T as two’s complement representations, and leave the result in register R.\n";
            cout << "7. JUMP (Op-code B):\n";
            cout << "Format: BRXY\n";
            cout << "Description: Jump to the instruction located in the memory cell at address XY if the bit pattern in register R\n";
            cout << "is equal to the bit pattern in register number 0. Otherwise, continue with the normal sequence of execution.\n";
            //cout << "\n";
            cout << "8. HALT (Op-code C):\n";
            cout << "Format: C000\n";
            cout << "Description: Halt execution. This instruction causes program execution to stop.\n";
            cout << "\n";
            break;

        default:
            cout << "Invalid choice. Please choose a number between 1 and 8 or 0 to exit.\n";
            break;
        }
        cout << endl;

    }

}

void Menu::displayStatus()
{
    simulator->displayBgad();
}