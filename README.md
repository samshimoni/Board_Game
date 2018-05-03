**Date: 30/4/2018**  
**Last Edit: 3/5/2018**

Board Game  
===  

Assignment 6 in a C++ course  

Authors:
--
Dvir Barzilay  
Kineret Ruth Nahary  

**Introduction**
==

About the assignment:
-- 
Create a class called Board that represent the game tic-tac-toe.  
The class is built by inputing it the board's size N * N.  
Every square has to have only: '.' \ 'X' \ 'O' - the dot char represents an empty square.  
The class has to support the operators: output, =, [].  
The class has to deal with exceptions: 
inputing an illegal char or trying to exceed the board's limits throws an exception according to the case.  
    
**File list:** (In development)
--  

```  
.: 
.gitignore 
Board.cpp  
Board.hpp  
DerivedChar.cpp  
DerivedChar.h    
Coordinate.cpp  
Coordinate.h    
README.md  
main.cpp  
IllegalCoordinateException.cpp  
IllegalCharException.cpp 
Symbol.h  
```  
Further look into the classes:  (In development)    
--  
1. **main.cpp** - This class has some examples to run and check the code with it.  
2. **Board.hpp** -      
*board* -        
3. **Board.cpp** -   
4. **Coordinate.hpp** -  
5. **Coordinate.cpp** -  
6. **DerivedChar.hpp** -   
7. **DerivedChar.cpp** -   
8. **IllegalCoordinateException.cpp** - 
9. **IllegalCharException.cpp** - 
10. **Symbol.h** -  

Compile Command:  
--  
g++ -std=c++11 *.cpp  
