#include <exception>
#include <string>

class IllegalCharException:public exception{
    private:
        char c;
        
    public:
        IllegalCharException(const char c){
            this->c = c;  
        }
        
        virtual string theChar() const{
            return string("Illegal char: " + to_string(c));
        }
}