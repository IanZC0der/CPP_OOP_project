#include "main.h"
#include "concept.h"
#include "introductory.h"
#include "intermediate.h"
#include "advanced.h"
#include "node.h"
#include "client.h"

int main()
{
    BST list{"data.txt"}; // load data from file
    char cmd;

    displayMenu();   // display the menu
    cmd = readCmd(); // read in the command
    while (cmd != 'q')
    {
        executeCmd(list, cmd); // execute the command
        displayMenu();         // display the menu
        cmd = readCmd();       // read in the command
    }
    return 0;
}
