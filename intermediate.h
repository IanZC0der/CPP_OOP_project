// Declaring the Intermediate class
#pragma once
#include "main.h"
#include "concept.h"

class Intermediate : public Concept
{
public:
    Intermediate(string name = "NULL", string definition = "NULL", string example = "NULL"); // default constructor
    ~Intermediate();                                                                         // destructor
    void display() const;                                                                    // display method
    void readIn();                                                                           // virtual method
    bool ifMatch(const Concept *aConcept) const;                                             // find out if there is a match
    void edit();                                                                             // edit an object
    void showTheExample() const;                                                             // show the example
private:
    string definition; // data member
    string example;    // data member
};
