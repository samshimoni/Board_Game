#include "Board.h"
using namespace std;

Board::Board(int n)
{
    _size = n;
    board = new Cell*[n];
    for (int i = 0; i < n; ++i)
    {
        board[i] = new Cell[n];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            board[i][j]='.';
        }
    }
}
Board::Board(const Board& b){
    _size = b.size();
    board = new Cell*[_size];
    int i, j;
    for(i = 0; i < _size; i++){
        board[i] = new Cell[_size];
        for(j = 0; j < _size; j++)
            board[i][j] = b.board[i][j];
    }
}

ostream& operator<<(ostream& os, const Board& b)
{

    for (int i=0;i<b.size();i++)
        {
            for (int j=0;j<b.size();j++)
            {
                os<<b.board[i][j];
            }
              os<<endl;
        }
      return os;
}
Board& Board::operator= (char s)
{
    if(s=='X' || s=='O' || s=='.')

    {
        Cell c(s);
        for (int i = 0; i < _size; ++i)
            {
                for (int j = 0; j < _size; ++j)
                {
                    board[i][j]=c;
                }
            }
    }



    return *this;
}

Board& Board::operator=(const Board& b){
    this->~Board();
    _size = b.size();
    board = new Cell*[_size];
    for(int i = 0; i < _size; i++){
        board[i] = new Cell[_size];
        for(int j = 0; j < _size; j++)
            board[i][j] = b.board[i][j];
    }
    return *this;
}


Cell& Board::operator[] (const Coordinate& p)const
{
    if (p.getX()<_size && p.getX()>-1 && p.getY()<_size && p.getY()>-1)
            return board[p.getX()][p.getY()];
    throw IllegalCoordinateException(p);
}

Board::~Board()
{
    for (int i = 0; i<_size ; i++)
        delete[] board[i];
    delete[] board;
}

int Board::size() const
 {
    return _size;
 }
