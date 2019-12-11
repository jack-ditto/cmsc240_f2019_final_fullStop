#ifndef __SUV_CPP__
#define __SUV_CPP__

#include "Suv.h"
#include "Tile.h"
#include "Vehicle.h"
#include <iostream>

Suv::Suv(Direction direction, Tile *tptr) : Vehicle(VehicleType::suv, direction, tptr)
{
}

Suv::~Suv()
{
}

#endif
