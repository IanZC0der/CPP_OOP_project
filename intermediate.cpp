// Implementing the Intermediate class

#include "intermediate.h"

Intermediate::Intermediate(string name, string definition, string example) : Concept(name), definition(definition), example(example) {} // default construcdtor

Intermediate::~Intermediate() {} // destructor

void Intermediate::display() const
{
    Concept::display();
    cout << "The definition:" << endl;
    cout << this->definition << endl;
    cout << "For example:" << endl;
    cout << this->example << endl
         << endl;
} // display the object

void Intermediate::readIn()
{
    Concept::readIn(); // invoke the readIn method in base class
    this->definition.clear();
    this->example.clear();
    cout << "Please enter the definition:" << endl;
    getline(cin, this->definition);

    cout << "Please enter an example:" << endl;
    getline(cin, this->example);
} // read in the data from the client

bool Intermediate::ifMatch(const Concept *aConcept) const
{
    const Intermediate *ptr = dynamic_cast<const Intermediate *>(aConcept); // ensure that two objects are of same type
    if (!ptr)
        return false;
    return this->definition == ptr->definition && this->example == ptr->example && Concept::ifMatch(aConcept); // all the attributes must match
} // find out if there is a match

void Intermediate::edit()
{
    this->definition.clear();
    this->example.clear();
    cout << "Please enter the definition:" << endl;
    getline(cin, this->definition);

    cout << "Please enter an example:" << endl;
    getline(cin, this->example);
} // edit the object. The name cannot be changed as the name is used for sorting and the BST is sorted

void Intermediate::showTheExample() const
{
    cout << "An example:" << endl;
    cout << this->example << endl
         << endl;
} // show the example only, this method is for testing the RTTI
