#include <iostream>
using namespace std;

class remoteLampu
{
    private:
        string SaklarNo[10];

    public:
        void setSaklarNo(int i, string value)
        {
            SaklarNo[i] = value;
        }
        string getSaklarNo(int i)
        {
            return SaklarNo[i];
        }
};
