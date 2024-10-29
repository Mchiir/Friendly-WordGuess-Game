#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team {
public:
    string name;
    Team(const string& name) : name(name) {}

    void display() const {
        cout << name << endl;
    }
};