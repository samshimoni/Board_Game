class Board{
    private:
        GameBoard* board;
    
    public:
        Board(int size);
        void operator= (const Symbol s);
        void operator= (const gameBoard& b);
        char& operator[] (const Coordinate& c);
        friend ostream& operator<< (ostream& os, const gameBoard& b);
};
