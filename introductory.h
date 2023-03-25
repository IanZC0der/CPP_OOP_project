// declaring the Introductory class
#pragma once
#include "main.h"
#include "concept.h"

class Introductory : public Concept
{
public:
    Introductory(string name = "NULL", string context = "NULL"); // default constructor
    ~Introductory();                                             // destructor
    void display() const;                                        // display method
    void readIn();                                               // virtual method
    bool ifMatch(const Concept *aConcept) const;                 // find out if there is a match
    void edit();                                                 // edit an object
    void printContext() const;                                   // show if there is already a context set
private:
    string context; // data member
};
