#include "Symbol.h"
#include <iostream>
using namespace std;

class DerivedChar{
    private:
        char c;
        
    public:
        DerivedChar();
        DerivedChar(char c);
        void operator= (const char c);
        void operator= (const DerivedChar& dc);
        friend ostream& operator<< (ostream& os, const DerivedChar& dc);
};