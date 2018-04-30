#include <iostream>

class GameBoard{
    private:
        char* gb[];
        int size;
        
        GameBoard(const gameBoard& gb);
        
    public:
        gameBoard(int size);
        
        ~gameBoard();
};