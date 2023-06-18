#ifndef LEITORARQUIVOS_H
#define LEITORARQUIVOS_H
#include <vector>
#include "Figurageometrica.h"
#include <string>
using namespace std;

class leitorarquivos {
int dimX, dimY, dimZ;
float r, g, b, a;

public:
leitorarquivos();
vector <FiguraGeometrica *> parse(string filename);
int getDx();
int getDy();
int getDz();

};

#endif // LEITORARQUIVOS_H