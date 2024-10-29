#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string name;
    Book(const string& name) : name(name) {}

    void display() const {
        cout << name << endl;
    }
};