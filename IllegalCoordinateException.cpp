#include <exception>
#include <string>

class IllegalCoordinateException:public exception{
  private:
    Coordinate c;
    
  public:
      IllegalCoordinateException(const Coordinate& c){
          this->c = c;
      }
      
      virtual string theCoordinate(){
          return string("Illegal coordinate: " + to_string(c.getX()) + "," + to_string(c.getY()));
      }  
};