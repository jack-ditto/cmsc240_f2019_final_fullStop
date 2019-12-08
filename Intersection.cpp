#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "Intersection.h"
#include "TrafficLight.h"

Intersection::IntersectionTile(Tile n, Tile s, Tile e, Tile w, TrafficLight ns, TrafficLight ew)
{
  north = n;
  south = s;
  east = e;
  west = w;
  northSouth = ns;
  eastWest = ew;
}

Intersection::IntersectionTile(const Intersection other)
{
  north = other.getNorth();
  south = other.getSouth();
  east = other.getEast();
  west = other.getWest();
}

IntersectionTile::~IntersectionTile() {}

Tile IntsectionTile::getNorth()
{
  return north;
}

Tile IntersectionTile::getSouth()
{
  return south;
}

Tile IntersectionTile::getEast()
{
  return east;
}

Tile IntersectionTile::getWest()
{
  return west;
}

Color IntersectionTile::getLightNS()
{
  return northSouth.getColor();
}

Color IntersectionTile::getLightEW()
{
  return eastWest.getColor();
}

#endif
