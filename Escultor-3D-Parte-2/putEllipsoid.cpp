#include "putEllipsoid.h"
#include <iostream>


putEllipsoid :: putEllipsoid (int xc, int yc, int zc, int rx, int ry, int rz, float r, float g, float b, float a){

  this -> xc = xc; this -> rx = rx;
  this -> yc = yc; this -> ry = ry;
  this -> zc = zc; this -> rz = rz;

  this -> r = r; this -> g = g; this -> b = b; this -> a=a;
}


void putEllipsoid :: draw(Sculptor &t){
  double x2, y2, z2;
  t.setColor(r,g,b,a);
  for(int i = xc-rx; i<xc+rx; i++){
    for(int j= yc-ry; j<yc+ry; j++){
      for(int k=zc-rz; k<zc+rz; k++){

     x2 = ((double)(i-xc)*(double)(i-xc))/(rx*rx);
     y2 = ((double)(j-yc)*(double)(j-yc))/(ry*ry);
     z2 = ((double)(k-zc)*(double)(k-zc))/(rz*rz);

        if((x2 + y2 + z2) < 1){
        t.putVoxel(i, j, k);
        }
      }
    }
  }
}