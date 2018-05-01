#include "Board.h"


Board::Board(int size){
    this->size = size;
    this->board = new DerivedChar*[size];
    int i, j;
    for(i = 0; i < size; i++){
        this->board[i] = new DerivedChar[size];
        for(j = 0; j < size; j++)
            this->board[i][j] = '.'; 
    }
//             ^ ^    
    // operator= ('.'); //Initialize the board

    
    
}

DerivedChar& Board::operator= (const DerivedChar& dc){
    int i, j;
    for(i = 0; i < this->size; i++)
        for(j = 0; j < this->size; j++)
            this->board[i][j] = dc;
}

DerivedChar& Board::operator[] (const Coordinate& c) const{
    if(c.getX() < size && c.getX() >= 0 && c.getY() < size && c.getY() >= 0)
        return board[c.getX()][c.getY()];
    throw IllegalCoordinateException(c);
}

ostream& operator<< (ostream& os, const Board& b){
    int i, j;
    for(i = 0; i < b.size; i++){
        for(j = 0; j < b.size; j++)
            os << b.board[i][j];
        os << endl;
    }
}

Board::~Board(){
    int i;
    for(i = 0; i< this->size; i++)
    	delete[] board[i]; //This part was allocated with new[], so we use delete[]
    delete[] board;
}