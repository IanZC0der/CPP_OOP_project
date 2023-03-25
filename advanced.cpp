// Implementing the Advanced class
#include "advanced.h"

Advanced::Advanced(string name, string example, list<string> languages) : Concept(name), example(example), languages(languages) // constructor
{
}

Advanced::~Advanced() {} // destructor

void Advanced::display() const
{
    Concept::display(); // invoke the base class method
    cout << "For example:" << endl;
    cout << this->example << endl;
    cout << "The list of languages that support this concept:" << endl;
    if (this->languages.empty())
    {
        cout << "The language list is empty." << endl
             << endl;
        return;
    }

    for (auto i : languages)
        cout << i << endl;
    cout << endl;
} // display the object

void Advanced::readIn()
{
    Concept::readIn();
    this->example.clear();
    cout << "Please enter an example:" << endl;
    getline(cin, this->example);
    this->readInHelper(); // read in the language list
} // read in the data from client

void Advanced::readInHelper()
{
    string aLanguage;
    bool flag = true;
    while (flag)
    {
        cout << "Add a language? y/n" << endl;
        char aChar;
        cin >> aChar;
        cin.ignore(MAX_CHAR, '\n');
        if (aChar == 'y' || aChar == 'Y')
        {
            cout << "Please enter a language:" << endl;
            getline(cin, aLanguage); // add a language if the client wants to add one
            this->languages.push_back(aLanguage);
            aLanguage.clear();
        }
        else
            flag = false;
    }
} // read in the language list from the client

bool Advanced::ifMatch(const Concept *aConcept) const
{
    const Advanced *ptr = dynamic_cast<const Advanced *>(aConcept); // ensure that two objects are of the same type
    if (!ptr)
        return false;
    return this->example == ptr->example && Concept::ifMatch(aConcept); // the language lists don't need to match to simplify the comparison
} // find out it two objects match

void Advanced::edit()
{
    this->example.clear();
    cout << "Please enter an example:" << endl;
    getline(cin, this->example); // edit the example

    int numberOfLangs = 0;
    cout << "Please enter the number of languages you want to add:" << endl;
    cin >> numberOfLangs;
    cin.ignore(MAX_CHAR, '\n');
    for (int i = 0; i < numberOfLangs; ++i)
    {
        string aLang;
        cout << "Enter a programming language(e.g., Java):" << endl;
        getline(cin, aLang);
        this->languages.push_back(aLang);
        cout << "The language you just added is:" << endl;
        cout << aLang << endl;
    } // edit the language list
} // edit the object. The name cannot be changed as the name is used for sorting and the BST is sorted

void Advanced::printLanguageList() const
{
    for (auto i : languages)
        cout << i << endl;
} // print the language list only. This method is for testing the RTTI

/*
bool Advanced::findOut(string aLang) const
{
    if(this->languages.empty())
        return false;
    auto it = find(this->languages.begin(), this->languages.end(), aLang);
    if(it == this->languages.end())
        return false;
    return true;
}
*/
