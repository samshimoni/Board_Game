#include "Board.h"
#include "math.h"
using namespace std;

Board::Board(int n)
{
    size = n;
    board = new Cell*[n];
    for (int i = 0; i < n; ++i)
    {
        board[i] = new Cell[n];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            board[i][j]='.';
        }
    }
}
Board::Board(const Board& b){
    size = b.size;
    board = new Cell*[size];
    int i, j;
    for(i = 0; i < size; i++){
        board[i] = new Cell[size];
        for(j = 0; j < size; j++)
            board[i][j] = b.board[i][j];
    }
}

ostream& operator<<(ostream& os, const Board& b)
{

    for (int i=0;i<b.size;i++)
        {
            for (int j=0;j<b.size;j++)
            {
                os<<b.board[i][j];
            }
              os<<endl;
        }
      return os;
}
istream& operator >> (istream& in, Board& b)
{
    string line;
    getline(in,line);
    int len = line.length();
    Board temp{len};
    for (int i=0;i<len;i++)
    {
        temp[{0,i}]=line.at(i);
    }
    for (int i=1;i<len;i++)
    {
        getline(in,line);
        for (int j=0;j<len;j++)
        {
            temp[{i,j}]=line.at(j);
        }
    }
    b = temp;
    return in;
}

string Board::draw(int pixelSize){

    int num = 0;
	std::string fileName = "board"+to_string(num)+".ppm";

	while(true){
		ifstream f("board"+to_string(num)+".ppm");
		if(!f.good())
			break;
		else{
			num++;
		}
	}

    const int dimx = pixelSize,dimy = pixelSize;
    ofstream imageFile(fileName, ios::out | ios::binary);
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
    RGB image[dimx*dimy];

    for (int j = 0; j < dimy; ++j)  {  // row
		for (int i = 0; i < dimx; ++i) { // column
			image[dimx*j+i].red = (20);
			image[dimx*j+i].green = (200);
			image[dimx*j+i].blue = (200);
		}
	}



    //thats procesdure draws the columns 
    
    for (int i=0;i<pixelSize;i++){
        int xStart =i*(dimx/size);

        //we need to draw the lines in proportion to the original Board
        //so each time we draw (in the dimx- the owl size div by how many clumns we have)

        for (int row= 10; row < dimy - 10 ; row++) {

			image[dimy * (row) + xStart].red = (0);
			image[dimy * (row) + xStart].green = (0);
			image[dimy * (row) + xStart].blue = (0);
		}
    }

    for (int i=0 ;i<pixelSize;i++){

        int yStart = i*(dimy/size);
        for ( int row =10 ;row<dimx-10;row++){

            image[(row) + yStart*dimy].red=(0);
            image[(row) + yStart*dimy].green=(0);
            image[(row) + yStart*dimy].blue=(0);


        }
    }
    
    //now we'll draw the 'x' and 'o's 

    for (int row =0; row<pixelSize;row++){
        for (int column = 0;column<pixelSize;column++){
            int xStart = column *(dimx/pixelSize);
            int xEnd = (column+1)*(dimx/pixelSize);
            int yStart = row*(dimy/pixelSize);
            int yEnd = (row+1)*(dimy/pixelSize);

            if (board[row][column]=='X'){
                //drawing the symbol 'X'
            
            for (int row =20; row<yEnd-yStart;row++){
                //alahson 

                image[dimy * (yStart + row ) + xStart + row].red = (0);
                image[dimy * (yStart + row ) + xStart + row].green = (0);
                image[dimy * (yStart + row ) + xStart + row].blue = (0);
                //second alahson

                image[dimy * (yStart+ row ) + xEnd - (row)].red = (0);
                image[dimy * (yStart+ row ) + xEnd - (row)].green = (0);
                image[dimy * (yStart+ row ) + xEnd - (row)].blue = (0);


            }

            }
            else if(board[row][column] == 'O'){
                //drawing the symbol 'O'
            
            int Radius = (xEnd-xStart)/2;
            int xEfez = (xEnd-xStart)/2;
            int yEfez = (yEnd-yStart)/2;

            for (int x=10; x<yEnd-yStart-10;x++){
                int sqrtC = sqrt((Radius*Radius)-(x-xEfez)*(x-xEfez))+yEfez;

                image[dimy * (sqrtC + yStart - 20) +xStart + x].red = (0);
				image[dimy * (sqrtC + yStart - 20) +xStart + x].blue = (0);
				image[dimy * (sqrtC + yStart - 20) +xStart + x].green = (0);

                image[dimy * (yEnd - sqrtC + 20) + xStart + x].red = (0);
                image[dimy * (yEnd - sqrtC + 20) + xStart + x].blue = (0);
                image[dimy * (yEnd - sqrtC + 20) + xStart + x].green = (0);

            } 

        }
    }
}
    imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
    imageFile.close();
    return fileName;
}



Board& Board::operator= (char s)
{
    if(s=='X' || s=='O' || s=='.')

    {
        Cell c(s);
        for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    board[i][j]=c;
                }
            }
    }



    return *this;
}

Board& Board::operator=(const Board& b){
    this->~Board();
    size = b.size;
    board = new Cell*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Cell[size];
        for(int j = 0; j < size; j++)
            board[i][j] = b.board[i][j];
    }
    return *this;
}


Cell& Board::operator[] (const Coordinate& p)const
{
    if (p.getX()<size && p.getX()>-1 && p.getY()<size && p.getY()>-1)
            return board[p.getX()][p.getY()];
    throw IllegalCoordinateException(p);
}




Board::~Board()
{
    for (int i = 0; i<size ; i++)
        delete[] board[i];
    delete[] board;
}

int Board::getSize()
 {
    return size;
 }
//returns all points that are in thev exact distance from the center
bool distance(Coordinate c1,Coordinate c2,int r){
    
    return (pow(c1.getX()+c2.getX(),2)+pow(c1.getY()+c2.getY(),2)==pow(r,2));
} 
string draw(int n){
    Board b(n);

}
