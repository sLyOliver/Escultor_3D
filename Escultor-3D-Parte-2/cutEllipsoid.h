#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "Figurageometrica.h"
#include "Sculptor.h"


class cutEllipsoid : public FiguraGeometrica {
int xc, yc, zc, rx, ry, rz;

public:

cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz);

~cutEllipsoid(){};

void draw(Sculptor &t);

};

#endif // CUTELLIPSOID_H