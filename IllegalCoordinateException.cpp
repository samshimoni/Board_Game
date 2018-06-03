#include <string>
#include "Coordinate.h"
using namespace std;

class IllegalCoordinateException {

private:
    const Coordinate& c;

public:

   IllegalCoordinateException(const Coordinate& c): c(c){ }

    string theCoordinate() const
    {
        std::string s="";
        s=s + to_string(c.getX());
        s= s+", ";
        s= s +to_string(c.getY());
       return s;
    }

};
