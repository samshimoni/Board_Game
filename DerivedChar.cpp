#include "DerivedChar.h"

DerivedChar::DerivedChar(){
}

DerivedChar::DerivedChar(char c){
    this->c = c;
}

void DerivedChar::operator= (const char c){
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
    }
}


void DerivedChar::operator= (const DerivedChar& dc){
    this->c = dc.c;
}

ostream& operator<< (ostream& os, const DerivedChar& dc){
    return os << dc.c;
}