#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class putVoxel : public FiguraGeometrica{
  int x, y, z;

public:

  putVoxel(int x, int y, int z, float r, float g, float b, float a);
  ~putVoxel(){};

  void draw(Sculptor &t);
};

#endif // PUTVOXEL_H