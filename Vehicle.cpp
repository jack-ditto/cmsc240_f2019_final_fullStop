#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"

class Vehicle
{
  Vehicle()
  {

  }

  ~Vehicle()
  {

  }

  int Vehicle::getLength()
  {
    return length;
  }

  int Vehicle::getID()
  {
    return id;
  }

  Tile* Vehicle::getHptr()
  {
    return hptr;
  }

  Tile* Vehicle::getTptr()
  {
    return tptr;
  }

  Turn Vehicle::getTurn()
  {
    return t;
  }

}

#endif
