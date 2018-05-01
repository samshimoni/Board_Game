#include "DerivedChar.h"

DerivedChar::DerivedChar(const char c) : c(c) { }

DerivedChar& DerivedChar::operator= (const char c){
    switch (c){
        case Symbol::X:
            this->c = c;
            break;
        case Symbol::O:
            this->c = c;
            break;
        case Symbol::P:
            this->c = c;
            break;
        default:
            throw IllegalCharException(c);
            break;
    }
    return *this;
}


void DerivedChar::operator= (const DerivedChar& dc){
    this->c = dc.c;
}

ostream& operator<< (ostream& os, const DerivedChar& dc){
    return os << dc.c;
}