#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Film {
public:
    string name;
    Film(const string& name) : name(name) {}

    void display() const {
        cout << name << endl;
    }
};