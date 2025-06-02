#include <iostream>
using namespace std;

class baseclass {
    public:
        virtual void perkenalan() {
            cout << "Hallo, saya function dari base class\n";
        }
    };

class derivedclass : public baseclass {
    public:
        void perkenalan() override {
            cout << "Hallo, saya function dari derived class\n";
        }
    };

