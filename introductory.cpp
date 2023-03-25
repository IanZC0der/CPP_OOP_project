// Implementing the Introductory class
#include "introductory.h"

Introductory::Introductory(string name, string context) : Concept(name), context(context) {} // constructor

Introductory::~Introductory() {} // destructor

void Introductory::display() const
{
    Concept::display(); // kick start the display method in the base class
    cout << "The context:" << endl;
    cout << this->context << endl
         << endl;
} // display the object

void Introductory::readIn()
{
    Concept::readIn(); // kick start the method in the base class
    cout << "Please enter the context:" << endl;
    getline(cin, this->context); // read in the context
} // read the data from client

bool Introductory::ifMatch(const Concept *aConcept) const
{
    const Introductory *ptr = dynamic_cast<const Introductory *>(aConcept); // ensure that we are comparing two objects of the same type
    if (ptr)
        return this->context == ptr->context && Concept::ifMatch(aConcept); // names and contexts must match
    else
        return false;
} // find out if there is a match

void Introductory::edit()
{
    this->context.clear();
    cout << "Please enter the context:" << endl;
    getline(cin, this->context);
    cout << "The updated concept is:" << endl;
    this->display();
} // edit the object. The name cannot be changed as the name is used for sorting and the BST is sorted

void Introductory::printContext() const
{
    cout << "Context:" << endl;
    cout << this->context << endl
         << endl;
} // print the context only, this method is for testing the RTTI
