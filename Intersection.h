#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Tile.h"

class Intersection
{

private:
  Tile* north;
  Tile* south;
  Tile* east;
  Tile* west;

public:
  Intersection(Tile n, Tile s, Tile e, Tile w);
  Intersection(const Intersection other);
  ~Intersection();

  Tile getNorth();
  Tile getSouth();
  Tile getEast();
  Tile getWest();

};

#endif
