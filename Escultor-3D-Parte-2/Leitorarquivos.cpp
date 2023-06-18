#include "Leitorarquivos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"

using namespace std;

// Construtor padrao
leitorarquivos :: leitorarquivos(){

}

vector <FiguraGeometrica *> leitorarquivos :: parse(string filename){
  vector <FiguraGeometrica *> figs;
  ifstream entrada;
  stringstream ss;
  string s, token;


  entrada.open(filename.c_str());

  cout << "Abrindo o arquivo " << filename << "..." << endl;
  if(!entrada.is_open()){
    cout << "Erro na abertura do arquivo!\n";
    exit(0);
  }

  while(entrada.good()){
    getline(entrada, s);
    if(entrada.good()){
      ss.clear();
      ss.str(s);
      ss >> token;

      if(ss.good()){

        if(token.compare("dim") == 0){
          ss >> dimX >> dimY >> dimZ;
        }

        else if(token.compare("putVoxel") == 0){
          int x, y, z;
          ss >> x >> y >> z >> r >> g >> b >> a;
          figs.push_back(new putVoxel(x,y,z,r,g,b,a));
        }

        else if(token.compare("cutVoxel") == 0){
          int x, y, z;
          ss >> x >> y >> z;
          figs.push_back(new cutVoxel(x,y,z));
        }

        else if(token.compare("putBox") == 0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }

          else if(token.compare("cutBox") == 0){
          int x0, x1, y0, y1, z0, z1;
          ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
          figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }

          else if(token.compare("putSphere") == 0){
          int xc, yc, zc, rad;
          ss >> xc >> yc >> zc >> rad >> r >> g >> b >> a;
          figs.push_back(new putSphere(xc,yc,zc,rad,r,g,b,a));
        }

          else if(token.compare("cutSphere") == 0){
          int xc, yc, zc, rad;
          ss >> xc >> yc >> zc >> rad;
          figs.push_back(new cutSphere(xc,yc,zc,rad));
        }

          else if(token.compare("putEllipsoid") == 0){
          int xc, yc, zc, rx, ry, rz;
          ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
          figs.push_back(new putEllipsoid(xc,yc,zc,rx,ry,rz,r,g,b,a));
        }

          else if(token.compare("cutEllipsoid") == 0){
          int xc, yc, zc, rx, ry, rz;
          ss >> xc >> yc >> zc >> rx >> ry >> rz;
          figs.push_back(new cutEllipsoid(xc,yc,zc,rx,ry,rz));
        }
        else{
          entrada.close();
          exit(1);
        }

      }

    }
  }

entrada.close();
return (figs);
}

int leitorarquivos :: getDx(){
  return dimX;
}

int leitorarquivos :: getDy(){
  return dimY;
}

int leitorarquivos :: getDz(){
  return dimZ;
}