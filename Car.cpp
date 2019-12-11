#ifndef __CAR_CPP__
#define __CAR_CPP__

#include "Car.h"
#include "Tile.h"
#include "Vehicle.h"
#include <iostream>

Car::Car(Direction direction, Tile *hptr) : Vehicle (VehicleType::car, direction, hptr, 2)
{
}

Car::~Car()
{
}

/*
int main()
{
  Tile t;
  Tile* tilePtr = &t;
  Direction d = Direction::east;
  Car c(d, tilePtr);
  return 0;
}*/

#endif
