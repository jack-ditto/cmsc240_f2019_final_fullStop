#ifndef __SUV_H__
#define __SUV_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Suv : public Vehicle
{

private:
  int length = 3;

public:
  Suv(Direction direction, Tile *hptr, bool willTurnRight);
  ~Suv();
};

#endif
