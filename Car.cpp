#ifndef __CAR_CPP__
#define __CAR_CPP__

#include "Car.h"
#include "Vehicle.h"
#include <iostream>

 // Vehicle needs to take VehicleType, Direction, and a pointer to the back of the 'invisible' part of
 // the road. As for length, we can just make it an instance variable of Car which overrides the length
 // variable in Vehicle. Since length is a constant for each object, I just made it inline in the .h file - Jack
 Car::Car(Direction direction, Tile *tptr) : Vehicle(VehicleType::car, direction, tptr)
 {
 }

#endif
