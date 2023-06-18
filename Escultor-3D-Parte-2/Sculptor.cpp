#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include "Sculptor.h"


using namespace std;

// CONSTRUTOR

Sculptor :: Sculptor(int _nx, int _ny, int _nz){
 nx = _nx;
 ny = _ny;
 nz = _nz;
r = g = b = a = 0.5;

// Alocacao da Matriz 3D

v = new Voxel**[nx];

for(int i=0; i<nx; i++){
  v[i] = new Voxel*[ny];
}

for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    v[i][j] = new Voxel[nz];
  }
}

for(int i=0; i<nx; i++){
  for(int j=0; j<ny; j++){
    for(int k=0; k<nz; k++){

      v[i][j][k].isOn = false;

      v[i][j][k].r = r;
      v[i][j][k].g = g;
      v[i][j][k].b = b;
      v[i][j][k].a = a;
    }
  }
}
}

// DESTRUTOR (LIBERACAO DA MEMORIA)

Sculptor :: ~Sculptor(){

// Liberacao da memoria alocada para a Matriz
   for(int i=0; i < nx; i++){
    for(int j=0; j<ny; j++){
      delete[] v[i][j];
    }
  }

  for(int i=0; i<nx; i++){
    delete[] v[i];
  }

  delete[] v;
  nx = ny = nz = 0;
}


// Escolha das cores
void Sculptor :: setColor(float mr, float mg, float mb, float ma){
r = mr;
g = mg;
b = mb;
a = ma;
}


// Ativa o voxel da posicao (mx, my, mz)
void Sculptor :: putVoxel(int mx, int my, int mz){
  v[mx][my][mz].isOn = true;
  v[mx][my][mz].r = r;
  v[mx][my][mz].g = g;
  v[mx][my][mz].b = b;
  v[mx][my][mz].a = a;
}


// Desativa voxel da posicao (mx, my, mz)
void Sculptor :: cutVoxel(int mx, int my, int mz){
  v[mx][my][mz].isOn = false;
}


// Criacao do arquivo .OFF
void Sculptor :: writeOFF(const char *filename){
        ofstream fout;

    fixed(fout); // para corrigir precisão de casas decimais no arquivo .OFF

    int Nvertices=0;
    int Nfaces=0;
    int aux=0;
    fout.open(filename);

    if(fout.is_open()){
        cout << "Aguarde...Salvando o arquivo OFF.\n";
    }
    else{
        cout << "Arquivo OFF nao foi aberto\n";
        exit(1);
    }

    fout<<"OFF"<<endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn == true){
                    Nvertices=Nvertices+8;
                    Nfaces=Nfaces+6;
                }
            }
        }
    }

    fout<<Nvertices<<" "<<Nfaces<<" "<<0<<endl;


    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn == true){


                        fout<< i-0.5 << " " << j+0.5 << " " << k-0.5 <<endl;
                        fout<< i-0.5 << " " << j-0.5 << " " << k-0.5 <<endl;
                        fout<< i+0.5 << " " << j-0.5 << " " << k-0.5 <<endl;
                        fout<< i+0.5 << " " << j+0.5 << " " << k-0.5 <<endl;
                        fout<< i-0.5 << " " << j+0.5 << " " << k+0.5 <<endl;
                        fout<< i-0.5 << " " << j-0.5 << " " << k+0.5 <<endl;
                        fout<< i+0.5 << " " << j-0.5 << " " << k+0.5 <<endl;
                        fout<< i+0.5 << " " << j+0.5 << " " << k+0.5 <<endl;

                }
            }
        }
    }

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn == true){
                    fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<< v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;

                    
                    aux=aux+8;
                }
            }
        }
    }

    if(fout.is_open()){
        cout << "Arquivo.OFF salvo!"<<endl;
    }
  fout.close();
}



