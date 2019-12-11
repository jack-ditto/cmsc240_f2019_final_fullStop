#ifndef __CAR_H__
#define __CAR_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Car : public Vehicle
{
  private:
    int length = 2;

  public:
    Car(Direction direction, Tile *hptr);
    ~Car();
};

#endif
