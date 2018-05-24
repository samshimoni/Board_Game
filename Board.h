#include <iostream>
#include "Coordinate.h"
#include "Cell.h"
#include "IllegalCoordinateException.cpp"
using namespace std;

class Board
{
    public:
        int size()  const;
        Board(int n);
        Board(const Board& b);
        Board& operator= (char c);
        Cell& operator[] (const Coordinate& p)const;
        Board& operator= (const Board& b);
        void switchSol(char sol, int x, int y);
        friend ostream& operator<<(ostream& os, const Board& b);
        ~Board();
        void setBoard(const int sizeOfBoard);
        void setMat(const int sizeOfBoard);
        void setSize(const int oSize);

    private:
            Cell** board;
            int _size;

};
