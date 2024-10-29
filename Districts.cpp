#include <iostream>
#include <vector>
#include <string>

using namespace std;

class District {
public:
    string name;
    District(const string& name) : name(name) {}

    void display() const {
        cout << name << endl;
    }
};