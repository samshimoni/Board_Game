#include "DerivedChar.h"

DerivedChar::DerivedChar(char c){
    operator= (c);
}

void DerivedChar::operator= (const char c){
    switch c:
        case Symbol::X:
            this->c = c;
            break;
        case Symbol::O:
            this->c = c;
            break;
        case Symbol::.:
            this->c = c;
            break;
        default:
            throw IllegalCharException(c);
}

void DerivedChar::operator= (const DerivedChar& dc){
    this->c = dc.c;
}

ostream& operator<< (ostream& os, const DerivedChar& dc){
    return os << dc.c;
}