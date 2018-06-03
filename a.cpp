/** This file was taken from erel gitHUb */

#include <iostream>
#include <fstream>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};



int main() {
  const int dimx = 800, dimy = 800;
  ofstream imageFile("board.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[dimx*dimy];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      image[dimx*j+i].red = (0);
      image[dimx*j+i].green = (0);
      image[dimx*j+i].blue = (0);



    }
  }

  //drawing the columns

  for (int i=0 ;i<=800;i+=100){
      int xFrom = i;

      for (int r=0; r<dimy; r++){
          image[dimy*(r)+xFrom].red=(255);
          image[dimy*(r)+xFrom].green=(255);
          image[dimy*(r)+xFrom].blue=(255);
      }
  }

    //drawing the rows  
    for (int i=0; i<800; i+=100){
        int yFrom = i;
        for(int r=0; r<dimx; ++r){
            image[(r)+yFrom *dimy].red=(255);
            image[(r)+yFrom *dimy].green=(255);
            image[(r)+yFrom *dimy].blue=(255);
        } 
    }
    int yFrom = dimy-1;
    for(int r=0; r<dimx; ++r){
            image[(r)+yFrom *dimy].red=(255);
            image[(r)+yFrom *dimy].green=(255);
            image[(r)+yFrom *dimy].blue=(255);
        } 
    int xFrom = dimx-1;
    for (int c=0; c<dimy; ++c){
          image[dimy*(c)+xFrom].red=(255);
          image[dimy*(c)+xFrom].green=(255);
          image[dimy*(c)+xFrom].blue=(255);
    }

    //Drawing x 
    for (int r=0; r<99;++r){
        image[dimy*(r)+r].red=(150);
        image[dimy*(r)+r].green=(150);
        image[dimy*(r)+r].blue=(150);

        image[dimy*(r)+99-(r)].red=(150);
        image[dimy*(r)+99-(r)].blue=(15);
        image[dimy*(r)+89-(r)].green=(0);
    }
    
  

  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
  return 0;
}