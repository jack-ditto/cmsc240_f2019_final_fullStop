#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Tile.h"
#include "Intersection.h"
#include "TrafficLight.h"

class Intersection : public Tile
{
  Intersection::Intersection(Tile n, Tile s, Tile e, Tile w)
  {
    north = n;
    south = s;
    east  = e;
    west  = w;
  }

  Intersection::Intersection(const Intersection other)
  {
    north = other.getNorth();
    south = other.getSouth();
    east  = other.getEast();
    west  = other.getWest();
  }

  Intersection::~Intersection() {}

  Tile Intsection::getNorth()
  {
    return north;
  }

  Tile Intersection::getSouth()
  {
    return south;
  }

  Tile Intersection::getEast()
  {
    return east;
  }

  Tile Intersection::getWest()
  {
    return west;
  }


}

#endif
