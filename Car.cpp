#ifndef __CAR_CPP__
#define __CAR_CPP__

#include "Car.h"
#include "Vehicle.h"
#include <iostream>

/**
 * Typical use constructor for car
 */
Car::Car(Direction direction, bool willTurnRight) : Vehicle(VehicleType::car, direction, 2, willTurnRight)
{
}

/**
 * Destructor for car
 */
Car::~Car()
{
}

#endif
