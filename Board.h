#include "DerivedChar.h"
#include "IllegalCoordinateException.cpp"

class Board{
    private:
        DerivedChar** board;
        int size;
    
    public:
        Board(int size);
        void operator= (const DerivedChar& dc);
        DerivedChar& operator[] (const Coordinate& c) const;
        friend ostream& operator<< (ostream& os, const Board& b);
        ~Board();
};
