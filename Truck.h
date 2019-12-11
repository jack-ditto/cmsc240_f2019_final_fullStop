#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Truck : public Vehicle
{

private:
  int length = 4;

public:
  Truck(Direction direction, Tile *hptr, bool willTurnRight);
  ~Truck();
};

#endif
