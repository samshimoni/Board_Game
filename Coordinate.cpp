#include "Coordinate.h"

Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
}

Coordinate& Coordinate::operator= (const Coordinate& c){
  this->x = c.getX();
  this->y = c.getY();
  return *this;
}

int Coordinate::getX() const{
    return this->x;
}

int Coordinate::getY() const{
    return this->y;
}

Coordinate::~Coordinate() { }