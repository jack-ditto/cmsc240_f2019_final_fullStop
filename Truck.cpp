#ifndef __TRUCK_CPP__
#define __TRUCK_CPP__

#include "Tile.h"
#include "Truck.h"
#include "Vehicle.h"
#include <iostream>

Truck::Truck(Direction direction, bool willTurnRight) : Vehicle(VehicleType::truck, direction, 4, willTurnRight)
{
}

Truck::~Truck()
{
}

#endif
