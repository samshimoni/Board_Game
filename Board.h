#include "DerivedChar.h"
#include "IllegalCoordinateException.cpp"

class Board{
    private:
        DerivedChar** board;
        int size;
    
    public:
        Board(int size);
        Board(const Board& b);
        //Board& operator=(const Board&);
        Board& operator= (const char c);
        //Board& operator= (const DerivedChar& dc);
        DerivedChar& operator[] (const Coordinate& c) const;
        //char operator[] (const Coordinate& c) const;
        friend ostream& operator<< (ostream& os, const Board& b);
        ~Board();
};
