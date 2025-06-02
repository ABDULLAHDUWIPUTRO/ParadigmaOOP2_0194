#include <iostream>
using namespace std;

class remotelampu {
    private :
    string saklarno[10];
    public:
    void setsaklarno(int i, string value) {
        saklarno[i] = value;
    }
    string getsaklarno(int i) {
        return saklarno[i];
    }
};