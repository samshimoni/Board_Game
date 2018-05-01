#include <exception>
// #include <string>

class IllegalCharException : public exception{
    private:
        char c;
        
    public:
        IllegalCharException(const char c){
            this->c = c;  
        }
        
        // virtual const char* theChar() const{
        //     return "Illegal char: " + c;
        // }
        virtual const char theChar() const{
            return this->c;
        }
};