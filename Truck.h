#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Truck : public Vehicle
{

public:
  Truck(Direction direction, bool willTurnRight);
  ~Truck();
};

#endif
