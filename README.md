# C++ OOP Prooject for RTTI Practicing

## Topics


- Virutal methods
- Abstract base class
- Dynamic casting
- Runtime type identification (RTTI)
- Inheritance in C++
- BST

## Introduction


This project was the third assignment of [CS302](http://web.cecs.pdx.edu/~karlaf/CS302%20Flyer.html) at [PSU](https://www.pdx.edu/), designed by [Karla Fant](http://web.cecs.pdx.edu/~karlaf/), a great instructor at PSU, for the course CS302, titled [Programming Methodologies and Software 
implementation](http://web.cecs.pdx.edu/~karlaf/CS302%20Flyer.html), in which we practiced OOP with CPP and Python. The program is used to track different concepts in C++. What sets this project different from my previous C++ projects is that here we implemmeted an abstract base class in which we added some virtual methods. 


## Details


In this project, six classes are created to fulfill the assigned tasks, including `Concept`, `Introductory`, `Intermediate`, `Advanced`, `Node` and `BST`. The base class is `Concept` class, which is an abstract base class. In the base class, `display`, `readIn()` and `ifMatch(const Concept* aConcept)` are major virtual functions in addition to the virtual destructor. Besides, the `edit()` method is a pure virtual method to be implemented by derived classes. This method is implemented in the derived classes to allow the client to edit the attributes of the derived class objects except for the `name`. `Introductory`, `Intermediate` and `Advanced` classes are derived from the base class and implement the virtual methods. Besides, each derived class has a unique method that is used to test the RTTI. `BST`, along with the `Node` class, is used to implement the binary search tree that save derived class objects. All the responsibilities of the classes are clearly assigned.


In the BST, the nodes are sorted based on the `name` attributes. There are some methods like `removeAll()` and `display()` that are designed to perform the binary search recursively, which is one of the key requirements for this project enforced by the instructor.



## RTTI?


The BST in this project could have different objects of different classes `Introductory`, `Intermediate` and `Advanced`, thanks to RTTI. They all have unique methods and attributes. In order to test the RTTI, one method `testRTTI()` is implements to identify of object type at each node and invoke their unique methods accordingly. 


