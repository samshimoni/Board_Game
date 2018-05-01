class Coordinate{
    private:
        int x, y;  
    
    public:
        Coordinate(int x, int y);
        Coordinate& operator= (const Coordinate& c);
        int getX() const;
        int getY() const;
        ~Coordinate();
};