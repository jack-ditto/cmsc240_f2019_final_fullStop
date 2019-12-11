#ifndef __CAR_CPP__
#define __CAR_CPP__

#include "Car.h"
#include <iostream>

Car::Car(Direction direction, Tile *hptr) : Vehicle (car, direction, hptr, 2)
{
}

Car::~Car()
{
}

#endif
