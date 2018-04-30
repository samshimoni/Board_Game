#include "Symbol.h"
#include <iostream>

class DerivedChar{
    private:
        char c;
        
    public:
        DerivedChar(char c);
        void operator= (const char c);
        void operator= (const DerivedChar& dc);
        friend ostream& operator<< (ostream& os, const DerivedChar& dc);
};