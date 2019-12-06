#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"

IntersectionTile::IntersectionTile(Tile t, TrafficLight ns, TrafficLight ew)
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
  northSouth = other.northSouth;
  eastWest = other.eastWest;
}

IntersectionTile::~IntersectionTile() {}

Tile IntsectionTile::getTurn()
{
  return turn;
}

Color IntersectionTile::getLightNS()
{
  return northSouth.getColor();
}

Color IntersectionTile::getLightEW()
{
  return eastWest.getColor();
}

int main()
{
    IntersectionTile inter;
}

#endif
