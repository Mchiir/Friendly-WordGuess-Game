#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {
public:
    string name;
    Animal(const string& name) : name(name) {}

    void display() const {
        cout << name << endl;
    }
};