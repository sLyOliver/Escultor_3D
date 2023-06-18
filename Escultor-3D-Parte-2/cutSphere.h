#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class cutSphere : public FiguraGeometrica {
  int xc, yc, zc, rad;

public:

  cutSphere(int xc, int yc, int zc, int rad);
  ~cutSphere(){};

  void draw(Sculptor &t);
};

#endif // CUTSPHERE_H