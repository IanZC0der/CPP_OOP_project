// Implementing the node class and the BST class
#include "node.h"

Node::Node() : data(nullptr), left(nullptr), right(nullptr) {} // default constructor

Node::Node(const Concept *&source) : data(nullptr), left(nullptr), right(nullptr)
{
    const Introductory *ptr1 = dynamic_cast<const Introductory *>(source);
    const Intermediate *ptr2 = dynamic_cast<const Intermediate *>(source);
    const Advanced *ptr3 = dynamic_cast<const Advanced *>(source); // perform RTTI to decide what kind of object to allocate
    if (ptr1)
        this->data = new Introductory(*ptr1); // allocate the memory
    else if (ptr2)
        this->data = new Intermediate(*ptr2);
    else if (ptr3)
        this->data = new Advanced(*ptr3);
} // copy constructor

unique_ptr<Node> &Node::getLeft()
{
    return this->left;
} // get the left pointer

unique_ptr<Node> &Node::getRight()
{
    return this->right;
} // get the right pointer

bool Node::lessThanOrEqual(const Concept *&newData) const
{
    return this->data->compare(newData);
} // compare newData and current node

bool Node::greaterThan(const Concept *&newData) const
{
    return !this->data->compare(newData);
} // compare newData and current node

void Node::changeData(const Concept *data)
{
    if (this->data)
        delete this->data; // delete the data if the data pointer is not nullptr
    const Introductory *ptr1 = dynamic_cast<const Introductory *>(data);
    const Intermediate *ptr2 = dynamic_cast<const Intermediate *>(data);
    const Advanced *ptr3 = dynamic_cast<const Advanced *>(data); // perform RTTI to decide what kind of data to allocate
    if (ptr1)
        this->data = new Introductory(*ptr1);
    else if (ptr2)
        this->data = new Intermediate(*ptr2);
    else if (ptr3)
        this->data = new Advanced(*ptr3); // allocate the memory
} // change the data in the node

Concept *Node::getData() const
{
    return this->data;
} // get the data

bool Node::findConcept(string name) const
{
    return this->data->ifEqualName(name);
} // find out if the names match

void Node::display() const
{
    this->data->display();
} // display the node

bool Node::greaterThanName(string name) const
{
    return this->data->ifGreater(name);
} // compare the name

void Node::deallocate()
{
    if (this->data)
    {
        delete this->data;
        this->data = nullptr;
    }
} // deallocate the data in the node

bool Node::ifMatch(const Concept *aConcept) const
{
    return this->data->ifMatch(aConcept);
} // find out if two objects completely match

void Node::edit()
{
    this->data->edit();
} // edit the current node

Node::~Node()
{
    this->deallocate();
} // destructor

BST::BST() : root(nullptr) {} // default contructor

BST::BST(string fileName) : root(nullptr)
{
    loadFromFile(fileName);
} // load data from file

void BST::testRTTI() const
{
    try
    {
        if (!root)
        {
            throw invalid_argument("EMPTY!");
        } // if the root is nullptr, throw exception
        testRTTI(this->root);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

void BST::testRTTI(const unique_ptr<Node> &root) const
{
    if (root)
    {
        const Introductory *ptr1 = dynamic_cast<const Introductory *>(root->getData());
        const Intermediate *ptr2 = dynamic_cast<const Intermediate *>(root->getData());
        const Advanced *ptr3 = dynamic_cast<const Advanced *>(root->getData()); // perform RTTI to decide the actual data type
        if (ptr1)
            ptr1->printContext();
        else if (ptr2)
            ptr2->showTheExample();
        else if (ptr3)
            ptr3->printLanguageList();
        testRTTI(root->getLeft());
        testRTTI(root->getRight());
    }
} // test the RTTI

bool BST::find(const Concept *aConcept, char ifEdit)
{
    return find(this->root, aConcept, ifEdit);
} // find a match and edit

bool BST::find(unique_ptr<Node> &root, const Concept *aConcept, char ifEdit)
{
    if (!root)
        return false;
    if (root->ifMatch(aConcept))
    {
        if (ifEdit == 'y' || ifEdit == 'Y')
            root->edit(); // edit the data
        return true;
    }
    if (root->greaterThan(aConcept))
        return find(root->getLeft(), aConcept, ifEdit);
    return find(root->getRight(), aConcept, ifEdit);
} // find a match and edit

void splitString(list<string> &lanList, const string languages, char delim)
{
    stringstream ss(languages);
    string item;
    while (getline(ss, item, delim))
    {
        lanList.push_back(item);
    }
} // split the string

void BST::loadFromFile(string fileName)
{
    ifstream in;
    in.open(fileName);
    if (!in)
    {
        cerr << "Fail to open the file: " << fileName << endl;
        exit(1);
    }

    string conceptType;
    string name;
    string context;
    string definition;
    string example;
    string languages;

    getline(in, conceptType);

    while (!in.eof())
    {
        if (conceptType == "intro")
        {
            getline(in, name);
            getline(in, context);
            Introductory anIntro{name, context};
            Concept *ptr = &anIntro; // upcasting
            this->insert(ptr);       // insert the data
        }
        else if (conceptType == "inter")
        {
            getline(in, name);
            getline(in, definition);
            getline(in, example);
            Intermediate anInter{name, definition, example};
            Concept *ptr = &anInter; // upcasting
            this->insert(ptr);       // insert the data
        }
        else if (conceptType == "adv")
        {
            getline(in, name);
            getline(in, example);
            getline(in, languages);
            list<string> lanList;
            char delim = ';';
            splitString(lanList, languages, delim); // split the string and update the lanList
            Advanced anAdv{name, example, lanList};
            Concept *ptr = &anAdv; // upcasting
            this->insert(ptr);     // insert the data
        }
        getline(in, conceptType);
    }
} // load data from file

void BST::insert(const Concept *newData)
{
    insert(root, newData);
} // insert new data

void BST::insert(unique_ptr<Node> &root, const Concept *newData)
{
    if (!root)
    {
        unique_ptr<Node> temp(new Node(newData)); // allocate memory
        root = move(temp);
        return;
    }
    if (root->greaterThan(newData))
        insert(root->getLeft(), newData);
    else
        insert(root->getRight(), newData);
} // insert new data

void BST::display() const
{
    try
    {
        if (!root)
        {
            throw invalid_argument("EMPTY!");
        } // if the root is nullptr, throw an exception
        display(root);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
} // display the BST

void BST::display(const unique_ptr<Node> &root) const
{
    if (root)
    {
        display(root->getLeft());
        root->display();
        display(root->getRight());
    }
} // perform in-order traversal

bool BST::findOut(string name) const
{
    return findOut(root, name);
} // find out if the names match

bool BST::findOut(const unique_ptr<Node> &root, string name) const
{
    if (!root)
        return false;
    if (root->findConcept(name))
    {
        root->display(); // display the data if the names match
        return true;
    }
    if (root->greaterThanName(name))
        return findOut(root->getLeft(), name);
    return findOut(root->getRight(), name);
} // find out if the names match

bool BST::removeAConcept(string name)
{
    return removeAConcept(root, name);
} // remove the node if the names match

bool BST::removeAConcept(unique_ptr<Node> &root, string name)
{
    if (!root)
        return false;
    if (root->findConcept(name))
    {
        removeAConcept(root); // if a match if found, delete the node and return true
        return true;
    }
    if (root->greaterThanName(name))
        return removeAConcept(root->getLeft(), name);
    return removeAConcept(root->getRight(), name);
} // remove the node if the names match

unique_ptr<Node> &BST::findInorderSuccessor(unique_ptr<Node> &root)
{
    if (!root->getLeft())
        return root;
    return findInorderSuccessor(root->getLeft());
} // find in-order successor

void BST::removeAConcept(unique_ptr<Node> &root)
{
    if (!root->getLeft() && !root->getRight())
    {
        root->deallocate();
        root.reset();
        return;
    } // delete the node if it's a leaf
    if (root->getLeft() && root->getRight())
    {
        root->changeData(findInorderSuccessor(root->getRight())->getData()); // change the data in the current node to the data in the in-order successor node
        findInorderSuccessor(root->getRight())->deallocate();                // deallocate the in-order successor
        findInorderSuccessor(root->getRight()).reset();                      // deallocate he in-order successor
        return;
    }
    if (root->getLeft())
    {
        root->changeData(root->getLeft()->getData()); // change the data in the current node to the data in the left child node
        root->getLeft()->deallocate();                // deallocate the left child node
        root->getLeft().reset();                      // deallocate the lef child node
        return;
    }
    root->changeData(root->getRight()->getData()); // change the data in the current node to the data in the right child node

    root->getRight()->deallocate(); // deallocate the left child node
    root->getRight().reset();       // deallocate the left child node
    return;
}

void BST::removeAll()
{
    if (!this->root)
        return;
    removeAll(this->root);
} // remove all the data

void BST::removeAll(unique_ptr<Node> &root)
{
    if (root)
    {
        removeAll(root->getLeft());
        removeAll(root->getRight());
        root->deallocate();
        root.reset();
    }
} // perform post-order removal
