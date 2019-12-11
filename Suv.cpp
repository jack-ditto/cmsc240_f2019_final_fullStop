#ifndef __SUV_CPP__
#define __SUV_CPP__

#include "Suv.h"
#include "Tile.h"
#include "Vehicle.h"
#include <iostream>

Suv::Suv(Direction direction, Tile *tptr, bool willTurnRight) : Vehicle(VehicleType::suv, direction, tptr, 3, willTurnRight)
{
}

Suv::~Suv()
{
}

#endif
