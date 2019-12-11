#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"

IntersectionTile::IntersectionTile() : Tile()
{
  // Temporary default traffic lights
  this->northSouth = TrafficLight(Color::GREEN, 0, 0, 0);
  this->eastWest = TrafficLight(Color::GREEN, 0, 0, 0);

  this->name = "IntersectionTile";
}

IntersectionTile::~IntersectionTile()
{
}

Tile IntersectionTile::getTurn()
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

#endif
