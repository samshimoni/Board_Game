#include "Board.h"

Board(int size){
    GameBoard gb(size);
    this->board = &gb;
}