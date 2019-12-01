#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Tile.h"
#include "Intersection.h"
#include "TrafficLight.h"

class Intersection : public Tile
{
  Intersection::Intersection(Tile n, Tile s, Tile e, Tile w, TrafficLight ns, TrafficLight ew)
  {
    north = n;
    south = s;
    east  = e;
    west  = w;
    northSouth = ns;
    eastWest = ew;
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

  Color Intersection::getLightNS()
  {
    return northSouth.getColor();
  }

  Color Intersection::getLightEW()
  {
    return eastWest.getColor();
  }

}

#endif
