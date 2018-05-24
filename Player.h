#pragma once
#include "Board.h"

class Player
{
    public :

    char myChar;

    char getChar() const
    {
        return myChar;
    }

    void setChar(const char otherChar)
    {
        myChar = otherChar;
    }

    virtual const string name() const { return ""; };
    virtual const Coordinate play(const Board& board){ };
};