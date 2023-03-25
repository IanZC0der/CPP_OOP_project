// Decalring the node class and BST class
#pragma once
#include "main.h"
#include "concept.h"
#include "introductory.h"
#include "intermediate.h"
#include "advanced.h"

class Node
{
public:
    Node();                                              // default constructor
    Node(const Concept *&source);                        // copy constructor
    unique_ptr<Node> &getLeft();                         // get the left pointer
    unique_ptr<Node> &getRight();                        // get the right pointer
    void setLeft(const unique_ptr<Node> &ptr);           // set the left pointer
    void setRight(const unique_ptr<Node> &ptr);          // set the right pointer
    bool lessThanOrEqual(const Concept *&newData) const; // compare newData and current node
    bool greaterThan(const Concept *&newData) const;     // compare newData and current one
    Concept *getData() const;                            // get the data
    bool findConcept(string name) const;                 // find out if the names match
    bool ifMatch(const Concept *aConcept) const;         // find out if two objects completely match
    void edit();                                         // edit the current node
    bool greaterThanName(string name) const;             // compare the name
    void display() const;                                // display the node
    void deallocate();                                   // deallocate the data in the node
    void changeData(const Concept *data);                // change the data in the node
    ~Node();                                             // destructor
private:
    Concept *data;          // pointer to a concept object
    unique_ptr<Node> left;  // left pointer
    unique_ptr<Node> right; // right pointer
};

class BST
{
public:
    BST();                                           // default constructor
    BST(string fileName);                            // load data from file
    void insert(const Concept *newData);             // insert new data
    void display() const;                            // display the BST
    bool removeAConcept(string name);                // remove the node if the names match
    bool findOut(string name) const;                 // find out if the names match
    void removeAll();                                // remove all the data
    void testRTTI() const;                           // test the RTTI
    bool find(const Concept *aConcept, char ifEdit); // find a match and edit
private:
    unique_ptr<Node> root;                                                   // the root
    unique_ptr<Node> &findInorderSuccessor(unique_ptr<Node> &root);          // find in-order successor
    void testRTTI(const unique_ptr<Node> &root) const;                       // test the RTTI
    void insert(unique_ptr<Node> &root, const Concept *newData);             // insert new data
    void display(const unique_ptr<Node> &root) const;                        // display the data
    void removeAll(unique_ptr<Node> &root);                                  // remove all the data
    void loadFromFile(string fileName);                                      // load from file
    bool removeAConcept(unique_ptr<Node> &root, string name);                // remove the node if the names match
    void removeAConcept(unique_ptr<Node> &root);                             // perform the actual removing if the names match
    bool find(unique_ptr<Node> &root, const Concept *aConcept, char ifEdit); // find a match and edit
    bool findOut(const unique_ptr<Node> &root, string name) const;           // find out if the names match
};

void splitString(list<string> &lanList, const string languages, char delim); // split the string
