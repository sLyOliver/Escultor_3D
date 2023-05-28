#include "Sculptor.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <iomanip>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
  this->nx = _nx;
  this->ny = _ny;
  this->nz = _nz;
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->a = 0;

  v = new Voxel **[_nx];
    for(int i=0; i<_nx; i++){
    v[i] = new Voxel *[_ny];
    for(int j=0; j<_ny; j++){
    v[i][j] = new Voxel[_nz];
    for(int k=0; k<_nz; k++){

      this-> v[i][j][k].r = 0;
      this-> v[i][j][k].g = 0;       
      this-> v[i][j][k].b = 0;
      this-> v[i][j][k].a = 0;
      this-> v[i][j][k].isOn = false;
        
  }
  }
  }
}

Sculptor::~Sculptor(){
  for(int i=0; i<nx ; i++){
  for(int j=0; j<ny; j++){
      delete [] v [i][j];
  }
      delete [] v [i];
}     delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
  this-> r = r;
  this-> g = g;
  this-> b = b;
  this-> a = alpha;
  
}

void Sculptor::putVoxel(int x, int y, int z){
  this-> v[x][y][z].isOn = true;
  this-> v[x][y][z].r = this-> r;
  this-> v[x][y][z].g = this-> g;
  this-> v[x][y][z].b = this-> b;
  this-> v[x][y][z].a = this-> a;

}

void Sculptor::cutVoxel(int x, int y, int z){
  this-> v[x][y][z].isOn = false;
  
}

void Sculptor::putbox(int x0, int x1, int y0, int y1, int z0, int z1){
for(int i=x0; i<x1; i++){
  for(int j=y0; j<y1; j++){
    for(int k=z0; k<z1; k++){

this-> v[i][j][k].isOn = true;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;
}
    }
  }
}

void Sculptor::cutbox(int x0, int x1, int y0, int y1, int z0, int z1){
for(int i=x0; i<x1; i++){
  for(int j=y0; j<y1; j++){
    for(int k=z0; k<z1; k++){

this-> v[i][j][k].isOn = false;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;
}
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    for(int k=0; k<nz; k++){

if((pow(i-xcenter, 2)) + (pow(j-ycenter, 2)) + (pow(k-zcenter, 2)) == (pow(radius, 2))){

this-> v[i][j][k].isOn = true;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;

}
}
}
}
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    for(int k=0; k<nz; k++){

if((pow(i-xcenter, 2)) + (pow(j-ycenter, 2)) + (pow(k-zcenter, 2)) == (pow(radius, 2))){

this-> v[i][j][k].isOn = false;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;

}
}
}
}
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    for(int k=0; k<nz; k++){

if((pow(i-xcenter, 2)/pow(rx, 2)) + (pow(j-ycenter, 2)/pow(ry, 2)) + (pow(k-zcenter, 2)/pow(rz, 2)) == 1){

this-> v[i][j][k].isOn = true;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;

}
}
}
}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    for(int k=0; k<nz; k++){

if((pow(i-xcenter, 2)/pow(rx, 2)) + (pow(j-ycenter, 2)/pow(ry, 2)) + (pow(k-zcenter, 2)/pow(rz, 2)) == 1){

this-> v[i][j][k].isOn = false;
this-> v[i][j][k].r = this-> r;
this-> v[i][j][k].g = this-> g;
this-> v[i][j][k].b = this-> b;
this-> v[i][j][k].a = this-> a;

}
}
}
}
}

void Sculptor::writeOFF(char *filename){
  ofstream outFile;
  outFile.open(filename);

  int Nvoxel = 0;

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          Nvoxel++;
        }
      }
    }
  }

  outFile << "OFF" << endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << endl;

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
          outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
          outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
          outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
          outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
          outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
          outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
          outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
        }
      }
    }
  }

  int vertice = 0;
  outFile << setiosflags(ios::fixed);

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for(int k=0; k<nz; k++){
        if(v[i][j][k].isOn){
          outFile << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          outFile << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          outFile << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          outFile << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          outFile << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          outFile << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          vertice = vertice + 8;
          
        }
      }
    }
  }
  outFile.close();

}
