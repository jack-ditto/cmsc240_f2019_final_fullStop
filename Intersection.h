#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "TrafficLight.h"

class IntersectionTile : public Tile
{

private:
  Tile *north;
  Tile *south;
  Tile *east;
  Tile *west;
  TrafficLight northSouth;
  TrafficLight eastWest

      public : Intersection(Tile n, Tile s, Tile e, Tile w);
  Intersection(const Intersection other);
  ~Intersection();

  Tile getNorth();
  Tile getSouth();
  Tile getEast();
  Tile getWest();
  Color getLightNS();
  Color getLightEW(); //to set up for traffic light enum color
};

#endif
