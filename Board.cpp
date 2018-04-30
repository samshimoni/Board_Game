#include "Board.h"


Board::Board(int size){
    this->size = size;
    this->board = new DerivedChar*[size];
    int i;
    for(i = 0; i<size; i++)
        board[i] = new DerivedChar[size];
//             ^ ^    
    operator =('.'); //Initialize the board
}

void Board::operator= (const DerivedChar& dc){
    int i, j;
    for(i = 0; i<size; i++)
        for(j = 0; j<size; j++)
            this->board[i][j] = dc;
}

DerivedChar& Board::operator[] (const Coordinate& c) const{
    if(c.getX()<size && c.getX()>=0 && c.getY()<size && c.getY()>=0)
        return this->board[c.getX()][c.getY()];
    throw IllegalCoordinateException(c);
}

ostream& operator<< (ostream& os, const Board& b){
    int i, j;
    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++)
            os << b[i][j];
        os << endl;
    }
}

Board::~Board(){
    int i;
    for(i = 0; i<size; i++)
    	delete[] board[i]; //This part was allocated with new[], so we use delete[]
    delete[] board;
}