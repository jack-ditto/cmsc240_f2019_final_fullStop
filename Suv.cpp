#ifndef __SUV_CPP__
#define __SUV_CPP__

#include "Suv.h"
#include "Tile.h"
#include "Vehicle.h"
#include <iostream>


// Typical use constructor for SUV
Suv::Suv(Direction direction, bool willTurnRight) : Vehicle(VehicleType::suv, direction, 3, willTurnRight)
{
}

// Destructor
Suv::~Suv()
{
}

#endif
