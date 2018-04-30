class Coordinate{
    private:
        int x, y;  
    
    public:
        Coordinate(int x, int y);
        int getX() const;
        int getY() const;
        ~Coordinate();
};