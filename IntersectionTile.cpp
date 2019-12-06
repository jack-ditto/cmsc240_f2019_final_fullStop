#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"

IntersectionTile::IntersectionTile(Tile t, Tile s, TrafficLight ns, TrafficLight ew)
{
  turn = &t;
  straight = &s;
  northSouth = ns;
  eastWest = ew;
}

IntersectionTile::IntersectionTile(const IntersectionTile& other)
{
  turn = other.turn;
  straight = other.straight;
}

IntersectionTile::~IntersectionTile() {}

Tile IntsectionTile::getTurn()
{
  return turn;
}

Tile IntersectionTile::getStraight()
{
  return stright;
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
