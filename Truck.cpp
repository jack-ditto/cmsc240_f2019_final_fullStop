#ifndef __TRUCK_CPP__
#define __TRUCK_CPP__

#include "Truck.h"
#include "VehicleBase.h"
#include <iostream>

Truck::Truck(Direction direction, Tile *hptr) : Vehicle (truck, direction, hptr, 4)
{
}

Truck::~Truck()
{
}

#endif
