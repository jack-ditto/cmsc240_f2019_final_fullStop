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

  int Vehicle::getLength();
  int Vehicle::getID();
  Tile* Vehicle::getHptr();
  Tile* Vehicle::getTptr();
  Turn Vehicle::getTurn();

}

#endif
