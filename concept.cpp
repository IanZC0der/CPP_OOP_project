// Implementing the concept class
#include "concept.h"

Concept::Concept(string name)
{
    this->name = name;
} // constructor

Concept::~Concept() {} // destructor

bool Concept::compare(const Concept *aConcept) const
{
    if (this->name <= aConcept->name)
        return true;
    return false;
} // compare the name

string Concept::getName() const
{
    return this->name;
} // get the name

void Concept::display() const
{
    cout << "The name of the concept: " << endl;
    cout << this->name << endl;
} // display the name

void Concept::readIn()
{
    this->name.clear();
    cout << "Please enter the name of the concept:" << endl;
    getline(cin, this->name);
} // enter the name

bool Concept::ifMatch(const Concept *aConcept) const
{
    if (this->name == aConcept->name)
        return true;
    return false;
} // find out if the name matches or not

bool Concept::ifEqualName(string name) const
{
    return this->name == name; // find out if the names are equal
}

bool Concept::ifGreater(string name) const
{
    return this->name > name;
} // find if name is greater
