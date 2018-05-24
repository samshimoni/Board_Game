#include "TicTacToe.h"

void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    _winner = &oPlayer;
    _board = '.';

    unsigned int whosTurn = 1;
    unsigned int maxTurns = _board.size()*_board.size();

    for (int i =0 ;i < maxTurns && !gameIsOver(xPlayer,oPlayer);i++)
    {
        if(whosTurn==1)
        {
            try
            {
                Coordinate c = xPlayer.play(_board);
                _board[c]=='.' ? _board[c] = oPlayer.getChar():throw IllegalCoordinateException(c);
            }

            catch (const IllegalCoordinateException ex)
            {
                break;
            }
            catch (const string& ex)
            {
                break;
            }
            whosTurn = 0;
        }
        else
        {
            try
                {
                    Coordinate c = oPlayer.play(_board);
                    _board[c]=='.' ? _board[c] = oPlayer.getChar(): throw IllegalCoordinateException(c);

                }
            catch (const IllegalCoordinateException ex)
            {
                _winner = &xPlayer;
                break;
            }
            catch(const string& ex)
            {
                _winner = &xPlayer;
                break;
            }
            whosTurn = 1;
        }
    }
}

bool TicTacToe::gameIsOver(Player &xPlayer, Player &oPlayer)
{
    int size = _board.size()-1;
    char c = _board[{0,size}];

    if(c!='.')
    {
        for (int i=1;i<=size;i++)
        {
            if(_board[{i,size-i}]!=c)
                break;
            if(i==size)
            {
                if(c==xPlayer.getChar())
                    _winner = &xPlayer;
                return true;
            }

        }
    }
    c=_board[{0,0}];
    if(c!='.')
    {
        for(int i=1; i<=size;i++)
        {
            if(_board[{i,i}]!= c)
                break;
            if(i==size){
                if(c==xPlayer.getChar())
                    _winner = &xPlayer;
                return true;
            }
        }
    }

    for (int i=0; i<=size;i++)
    {
        c= _board[{0,i}];
        if (c!='.')
        {
            for(int j=1;j<=size;i++)
            {
                if(_board[{i,j}]!=c)
                    break;
                if(i==size)
                {
                    if(xPlayer.getChar()==c)
                        _winner=&xPlayer;
                    return true;
                }
            }
        }
    }

    for(int i = 0; i<=size; i++ )
    {
        c= _board[{0,i}];
        if (c!='.')
        for(int j=1;j<=size;j++)
        {
            if(_board[{i,j}]!= c)
                break;
            if(j==size)
            {
                if(xPlayer.getChar()==c)
                    _winner=&xPlayer;
                return true;
            }
        }
    }
    return false;
}
