#ifndef __SUV_H__
#define __SUV_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Suv : public Vehicle
{
  public:
    Suv(Direction direction, Tile *hptr);
    ~Suv();

}

#endif
