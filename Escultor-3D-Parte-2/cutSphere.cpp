#include "cutSphere.h"
#include <iostream>


cutSphere :: cutSphere (int xc, int yc, int zc, int rad){
  this -> xc = xc;
  this -> yc = yc;
  this -> zc = zc;
}

void cutSphere :: draw(Sculptor &t){
  double x2, y2, z2;
  t.setColor(r,g,b,a);
  for(int i = xc-rad; i<xc+rad; i++){
    for(int j= yc-rad; j<yc+rad; j++){
      for(int k=zc-rad; k<zc+rad; k++){

        x2 = (double)(i-xc)*(double)(i-xc);
        y2 = (double)(j-yc)*(double)(j-yc);
        z2 = (double)(k-zc)*(double)(k-zc);

        if((x2 + y2 + z2) < (rad*rad)){
        t.cutVoxel(i, j, k);
        }
      }
    }
  }
}