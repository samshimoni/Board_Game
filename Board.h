#include <iostream>
#include "Coordinate.h"
#include <fstream>
#include "Cell.h"
#include <stdlib.h>
#include "RGB.h"
#include "IllegalCoordinateException.cpp"
using namespace std;

class Board
{
    public:
        int getSize();
        Board(int n);
        Board():size(0){};
        Board(const Board& b);
        Board& operator= (char c);
        Cell& operator[] (const Coordinate& p)const;
        Board& operator= (const Board& b);
        void switchSol(char sol, int x, int y);
        friend ostream& operator<<(ostream& os, const Board& b);
        friend istream& operator >> (istream& is  ,Board& c);
        string draw(int size);
        ~Board();
        void setBoard(const int sizeOfBoard);
        void setMat(const int sizeOfBoard);
        void setSize(const int oSize);

    private:
            Cell** board;
            int size;

};
