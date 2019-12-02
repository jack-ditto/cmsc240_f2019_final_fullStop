#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"

IntersectionTile::IntersectionTile(Tile n, Tile s, Tile e, Tile w, TrafficLight ns, TrafficLight ew)
{
  north = &n;
  south = &s;
  east  = &e;
  west  = &w;
  northSouth = ns;
  eastWest = ew;
}

IntersectionTile::IntersectionTile(const IntersectionTile& other)
{
  north = other.getNorth();
  south = other.getSouth();
  east  = other.getEast();
  west  = other.getWest();
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
