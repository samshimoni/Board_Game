#include "Champion.h"

/*this Player allways wins;
____
|O**O|
|*OO*|
|*OO*|
|O**O|
*/

const Coordinate Champion::play(const Board& board)
{
    unsigned int size = board.size();


    //**STRATEGI**

    if (board[{size,0}]=='.') // means still empty
        return  Coordinate{size,0};

    if (board[{0,size}]=='.')
        return Coordinate{0,size};

    for (unsigned int i=1; i<size; i++)
    {
        if (board[{i,size}]=='.')
            return Coordinate{i,size-i};
    }

    for (unsigned i=0;i<=size;i++)
    {
        if (board[{i,i}]=='.')
            return Coordinate{i,i};
    }

}