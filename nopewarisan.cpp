#include <iostream>
using namespace std;

class baseclass final{
    public:
    virtual void perkenalan() {
        cout << "hallo saya function dari base class";
    }
};

class derivedclass : public baseclass {
    public:
    void perkenalan() {
        cout << "hallo saya function dari derived class";
    }
};