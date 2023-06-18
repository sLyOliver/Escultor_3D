#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class cutVoxel : public FiguraGeometrica {
 int x, y, z;

public:

  cutVoxel(int x, int y, int z);
  ~cutVoxel(){};

  void draw(Sculptor &t);
};

#endif // CUTVOXEL_H