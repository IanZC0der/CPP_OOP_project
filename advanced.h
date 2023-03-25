// Declaring the Advanced class
#pragma once
#include "main.h"
#include "concept.h"

class Advanced : public Concept
{
public:
    Advanced(string name = "NULL", string example = "NULL", list<string> languages = {}); // default constructor
    ~Advanced();                                                                          // destructor
    void display() const;                                                                 // display method
    void readIn();                                                                        // virtual method
    bool ifMatch(const Concept *aConcept) const;                                          // find out if there is a match
    void edit();                                                                          // edit an object
    /*
bool findOut(string aLang) const;//find out if a language is already in the list
                         */
    void printLanguageList() const; // print the language list only. This method is for testing the RTTI
private:
    void readInHelper();    // read in the language list
    string example;         // data member
    list<string> languages; // data member
};
