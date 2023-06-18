#include "putSphere.h"
#include "Sculptor.h"
#include <iostream>

putSphere :: putSphere(int xc, int yc, int zc, int rad, float r, float g, float b, float a){
  this -> xc = xc;
  this -> yc = yc;
  this -> zc = zc;
  this -> rad = rad;
  this -> r=r; this -> g=g; this-> a=a; this -> b=b;
}

void putSphere :: draw(Sculptor &t){
  
double x2, y2, z2;
t.setColor(r,g,b,a);
  for(int i = (xc-rad); i<(xc+rad); i++){
    for(int j= (yc-rad); j<(yc+rad); j++){
      for(int k= (zc-rad); k<(zc+rad); k++){

        x2 = (double)(i-xc)*(double)(i-xc);
        y2 = (double)(j-yc)*(double)(j-yc);
        z2 = (double)(k-zc)*(double)(k-zc);

        if((x2 + y2 + z2) < (rad*rad)){
        t.putVoxel(i, j, k);
        }
      }
    }
  }
}