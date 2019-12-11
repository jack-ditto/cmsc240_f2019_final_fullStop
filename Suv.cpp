#ifndef __SUV_CPP__
#define __SUV_CPP__

#include "Suv.h"
#include "VehicleBase.h"
#include <iostream>

Suv::Suv(Direction direction, Tile *hptr) : Vehicle (suv, direction, hptr, 3)
{
}

Suv::~Suv()
{
}

#endif
