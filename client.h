// declaring the client functions
#pragma once
#include "main.h"
#include "concept.h"
#include "introductory.h"
#include "intermediate.h"
#include "advanced.h"
#include "node.h"

void displayMenu(); // display the menu

char readCmd(); // read in the command

void findOut(const BST &aList); // find out a mathc according the name

void removeOne(BST &aList); // remove the match if names match

void findMatchAndEdit(BST &aList); // find out a match and edit

void executeCmd(BST &aList, char cmd); // execute the command

void insert(BST &aList); // insert new data
