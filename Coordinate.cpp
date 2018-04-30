#include "Coordinate.h"

Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
}

int Coordinate::getX() const{
    return this->x;
}

int Coordinate::getY() const{
    return this->y;
}