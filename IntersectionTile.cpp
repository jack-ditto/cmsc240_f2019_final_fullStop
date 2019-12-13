#ifndef __INTERSECTIONTILE_CPP__
#define __INTERSECTIONTILE_CPP__

#include "Tile.h"
#include "IntersectionTile.h"
#include "TrafficLight.h"
#include <iostream>

/*
 *  Typical use: IntersectionTile should have a traffic light
 */
IntersectionTile::IntersectionTile(TrafficLight *trafficLight) : Tile()
{
  this->name = "IntersectionTile";
  this->trafficLight = trafficLight;
}

IntersectionTile::~IntersectionTile()
{
}

/*
 * Override of Tile's getStraight(), determines what direction the vehicle occupying it 
 * is going in and returns "straight" for that Vehicle
 */
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

/**
 * Similair to IntersectionTile::getStraight(), returns pointer to the "right" Tiles based on
 * the current direction of the Vehicle occupying it. 
 */
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

// Set each of the 4 directions, used on construction in Road
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

/*
 * Returns reference to TrafficLight to be used in Vehicle
 */
TrafficLight *IntersectionTile::getTrafficLight()
{
  return this->trafficLight;
}

#endif
