#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class putSphere : public FiguraGeometrica {

int xc, yc, zc, rad;

public:
putSphere(int xc, int yc, int zc, int rad, float r, float g, float b, float a);

~putSphere(){};

void draw(Sculptor &t);

};

#endif // PUTSPHERE_H