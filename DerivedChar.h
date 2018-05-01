#include <iostream>
#include "Symbol.h"
#include "IllegalCharException.cpp"

using namespace std;

class DerivedChar{
    private:
        char c;
        
    public:
        DerivedChar(char c);
        DerivedChar& operator= (const char c);
        void operator= (const DerivedChar& dc);
        friend ostream& operator<< (ostream& os, const DerivedChar& dc);
};