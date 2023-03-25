// Implementing the client functions
#include "client.h"

void displayMenu()
{
    cout << "\tWelcome to CPPConcepts 1.0." << endl
         << "\t\ta. display all the concepts" << endl
         << "\t\tb. test RTTI" << endl
         << "\t\tc. find out if a concept is in the list" << endl
         << "\t\td. remove one concept" << endl
         << "\t\te. find a match and edit" << endl
         << "\t\tf. remove all concepts" << endl
         << "\t\tg. insert a new concept" << endl
         << "\t\tq. quit" << endl
         << endl;
} // display the menu

char readCmd()
{
    char cmd;
    cout << "\tPlease enter a command:" << endl;
    cin >> cmd;
    cin.ignore(MAX_CHAR, '\n');
    return tolower(cmd);
} // read in the command

void findOut(const BST &aList)
{
    string name;
    cout << "Please enter the concept you want to find out:" << endl;
    getline(cin, name);
    cout << "In process..." << endl
         << endl;
    bool ifFound = aList.findOut(name);
    if (ifFound)
        cout << "The concept is in the list!" << endl
             << endl;
    else
        cout << "Not found!" << endl
             << endl;
} // find out a match according to the name

void removeOne(BST &aList)
{
    string name;
    cout << "Please enter the concept you want to delete:" << endl;
    getline(cin, name);
    bool ifFound = aList.findOut(name);
    if (ifFound)
    {
        bool removed = aList.removeAConcept(name);
        if (removed)
            cout << "The concept is removed!" << endl
                 << endl;
    }
    else
        cout << "Not found!" << endl
             << endl;
} // remove a match if the names match

void findMatchAndEdit(BST &aList)
{
    cout << "Please be noted that the data you would be entering must match the data in the list." << endl
         << endl;
    string conceptType;
    Introductory anIntro;
    Intermediate anInter;
    Advanced anAdv;
    Concept *ptr = nullptr;

    cout << "Please enter the type of the concept (intro/inter/adv)" << endl;
    getline(cin, conceptType);
    if (conceptType == "intro")
    {
        anIntro.readIn(); // read in the object
        ptr = &anIntro;   // upcasting
    }
    else if (conceptType == "inter")
    {
        anInter.readIn();
        ptr = &anInter; // upcasting
    }
    else if (conceptType == "adv")
    {
        anAdv.readIn();
        ptr = &anAdv; // upcasting
    }
    if (!ptr)
        cout << "Please check your input and retry." << endl
             << endl;
    if (ptr)
    {
        bool find = aList.find(ptr, 'n');
        if (find)
        {
            char cmd;
            cout << "Match found. Please confirm if you want to edit: y/Y/n/N" << endl;
            cin >> cmd;
            cin.ignore(MAX_CHAR, '\n');
            bool edit = aList.find(ptr, cmd);
            if (edit)
                cout << "The concept is updated." << endl
                     << endl;
        }
        else
            cout << "No match." << endl
                 << endl;
    }
} // find out a match and edit

void insert(BST &aList)
{
    string conceptType;
    Introductory anIntro;
    Intermediate anInter;
    Advanced anAdv;
    Concept *ptr = nullptr;

    cout << "Please enter the type of the concept (intro/inter/adv)" << endl;
    getline(cin, conceptType);
    if (conceptType == "intro")
    {
        anIntro.readIn(); // read in the object
        ptr = &anIntro;   // upcasting
    }
    else if (conceptType == "inter")
    {
        anInter.readIn();
        ptr = &anInter;
    }
    else if (conceptType == "adv")
    {
        anAdv.readIn();
        ptr = &anAdv;
    }
    if (!ptr)
        cout << "Please retry. Make sure your input is intro/inter/adv." << endl;
    else
    {
        bool alreadyExist = aList.findOut(ptr->getName()); // find out if this concept already exists
        if (!alreadyExist)
            aList.insert(ptr);
        else
            cout << "The concept is already in the list. Please retry." << endl;
    }
} // insert new data

void executeCmd(BST &aList, char cmd)
{
    switch (cmd)
    {
    case 'a':
        aList.display();
        break;
    case 'b':
        aList.testRTTI();
        break;
    case 'c':
        findOut(aList);
        break;
    case 'd':
        removeOne(aList);
        break;
    case 'e':
        findMatchAndEdit(aList);
        break;
    case 'f':
        aList.removeAll();
        break;
    case 'g':
        insert(aList);
        break;
    default:
        cout << "Invalid commond!" << endl;
        break;
    }
} // execute the command
