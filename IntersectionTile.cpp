#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"
#include <iostream>

IntersectionTile::IntersectionTile(TrafficLight *trafficLight) : Tile()
{
  this->name = "IntersectionTile";
  this->trafficLight = trafficLight;
}

IntersectionTile::~IntersectionTile()
{
}

Tile *IntersectionTile::getStraight()
{
  switch (this->getOccupyingVehicle()->getVehicleOriginalDirection())
  {
  case Direction::north:
    return this->north;
    break;
  case Direction::east:
    return this->east;
    break;
  case Direction::south:
    return this->south;
    break;
  case Direction::west:
    return this->west;
    break;
  default:
    return Tile::getStraight();
  }
}

Tile *IntersectionTile::getRight()
{
  switch (this->getOccupyingVehicle()->getVehicleOriginalDirection())
  {
  case Direction::north:
    return this->east;
    break;
  case Direction::east:
    return this->south;
    break;
  case Direction::south:
    return this->west;
    break;
  case Direction::west:
    return this->north;
    break;
  }
}

void IntersectionTile::setNorth(Tile *north)
{
  this->north = north;
}
void IntersectionTile::setEast(Tile *east)
{
  this->east = east;
}
void IntersectionTile::setSouth(Tile *south)
{
  this->south = south;
}
void IntersectionTile::setWest(Tile *west)
{
  this->west = west;
}

TrafficLight *IntersectionTile::getTrafficLight()
{
  return this->trafficLight;
}

#endif
