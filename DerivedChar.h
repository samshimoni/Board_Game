#include <iostream>
#include "Symbol.h"
#include "IllegalCharException.cpp"

using namespace std;

class DerivedChar{
    private:
        char c;
        
    public:
        DerivedChar();
        DerivedChar(char c);
        DerivedChar(const DerivedChar& dc);
        DerivedChar& operator= (const char c);
        DerivedChar& operator= (const DerivedChar& dc);
        friend ostream& operator<< (ostream& os, const DerivedChar& dc);
        
        operator char() const;
};