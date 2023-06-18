#include <iostream>
#include <vector>
#include "Figurageometrica.h"
#include "Sculptor.h"
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"
#include "Leitorarquivos.h"

using namespace std;

int main() {

Sculptor *t1;

leitorarquivos dg;

vector <FiguraGeometrica *> figs;

figs = dg.parse("entrada.txt");

t1 = new Sculptor(dg.getDx(), dg.getDy(), dg.getDz());

for(int i=0; (int) i < figs.size(); i++){
  cout << "Desenhando..." << endl;
  figs[i] -> draw(*t1);
}


t1->writeOFF("Desenho.off");


for(int i=0; (int) i < figs.size(); i++){
 delete figs[i];
}

delete t1;

return 0;
}