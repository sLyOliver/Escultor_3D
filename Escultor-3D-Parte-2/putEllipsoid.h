#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "Figurageometrica.h"
#include "Sculptor.h"


class putEllipsoid : public FiguraGeometrica {
int xc, yc, zc, rx, ry, rz;

public:

putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz, float r, float g, float b, float a);

~putEllipsoid(){};

void draw(Sculptor &t);

};

#endif // PUTELLIPSOID_H