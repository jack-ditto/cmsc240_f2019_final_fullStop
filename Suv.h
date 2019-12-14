#ifndef __SUV_H__
#define __SUV_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Suv : public Vehicle
{

public:
  //Constructors and destructors
  Suv(Direction direction, bool willTurnRight);
  ~Suv();
};

#endif
