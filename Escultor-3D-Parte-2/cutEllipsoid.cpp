#include "cutEllipsoid.h"
#include <iostream>


cutEllipsoid :: cutEllipsoid (int xc, int yc, int zc, int rx, int ry, int rz){

  this -> xc = xc; this -> rx = rx;
  this -> yc = yc; this -> ry = ry;
  this -> zc = zc; this -> rz = rz;
}


void cutEllipsoid :: draw(Sculptor &t){
  double x2, y2, z2;
  for(int i = xc-rx; i<xc+rx; i++){
    for(int j= yc-ry; j<yc+ry; j++){
      for(int k=zc-rz; k<zc+rz; k++){

     x2 = ((double)(i-xc)*(double)(i-xc))/(rx*rx);
     y2 = ((double)(j-yc)*(double)(j-yc))/(ry*ry);
     z2 = ((double)(k-zc)*(double)(k-zc))/(rz*rz);

        if((x2 + y2 + z2) < 1){
        t.cutVoxel(i, j, k);
        }
      }
    }
  }
}