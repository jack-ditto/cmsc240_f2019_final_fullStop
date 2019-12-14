#ifndef __CAR_H__
#define __CAR_H__

#include "Tile.h"
#include "Vehicle.h"
#include "VehicleBase.h"

class Car : public Vehicle
{

public:
  //Constructors and destructors
  Car(Direction direction, bool willTurnRight);
  ~Car();
};

#endif
