#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Truck : public Vehicle
{

public:
  //Constructors and destructors
  Truck(Direction direction, bool willTurnRight);
  ~Truck();
};

#endif
