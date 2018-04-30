#include "GameBoard.h"

GameBoard::GameBoard(int size){
    this->gb = new char*[size];
    int i,j;
    for(i =0; i<size; i++){
        this->gb[i] = new char[size];
        for(j=0; j<size; i++){
            this->gb[i][j] = '.';
        }
    }
}