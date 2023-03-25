// Declaring the Concept class
#pragma once
#include "main.h"

class Concept
{
public:
    Concept(string name = "NULL");                       // default constructor
    virtual ~Concept();                                  // destructor
    bool compare(const Concept *aConcept) const;         // compare the name
    bool ifEqualName(string name) const;                 // if names are equal
    bool ifGreater(string name) const;                   // if name is greater
    string getName() const;                              // get the name
    virtual void display() const;                        // virtual method
    virtual void readIn();                               // virtual method
    virtual bool ifMatch(const Concept *aConcept) const; // find out if there is a match
    virtual void edit() = 0;                             // edit an object
protected:
    string name; // data member
};
