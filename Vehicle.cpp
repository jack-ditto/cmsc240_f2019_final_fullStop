#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "VehicleBase.h"
#include <iostream>
#include "IntersectionTile.h"

// Default constructor for Vehicle
Vehicle::Vehicle() : VehicleBase(VehicleType::car, Direction::north) {}

// Typical use constructor for Vehicle
Vehicle::Vehicle(VehicleType vehicleType, Direction direction, Tile *tptr) : VehicleBase(VehicleType::car, Direction::east)
{
   this->length = 3;

   this->tptr = tptr;
   this->hptr = tptr;

   for (int i = 0; i < this->length - 1; i++)
   {
      this->hptr = this->hptr->getStraight();
   }

   this->setOccupiedTiles();
}

Vehicle::~Vehicle()
{
}

int Vehicle::getLength()
{
   return length;
}

int Vehicle::getID()
{
   return id;
}

Tile *Vehicle::getHptr()
{
   return this->hptr;
}

Tile *Vehicle::getTptr()
{
   return this->tptr;
}

Vehicle::Turn Vehicle::getTurn()
{
   return t;
}

void Vehicle::setOccupiedTiles()
{
   this->hptr->setOccupied(this);

   Tile *currTile = this->tptr;
   while (currTile != this->hptr)
   {
      if (this->isTurningRight && currTile->getName() == "IntersectionTile")
      {
         // This is how this should look, but not yet implemented in IntersecitonTile
         // Also, may need to downcast currTile to get getRight() method access
         // currTile = currTile->getRight();
      }
      else
      {
         currTile->setOccupied(this);
         currTile = currTile->getStraight();
      }
   }
}

/**
 *   Moves the vehicle forward regardless. This is a private method, and should only be called
 *   from move() to avoid errors.
 * 
 */
void Vehicle::moveForward()
{
   // Set the previous tile to unoccupied
   this->tptr->setUnoccupied();
   this->hptr->setUnoccupied();

   // Move each pointer forward
   this->hptr = this->hptr->getStraight();
   this->tptr = this->tptr->getStraight();

   // Set the tiles between head and tail to occupied (may remove later, not sure if nescessary here)
   this->setOccupiedTiles();
}

/**
 *  Called for every 'click' of time. Moves the vehicle one Tile and handles turning 
 *  by calling external method when the Vehicle reaches an intersection. 
 *
 */
void Vehicle::move()
{
   Tile *next = this->hptr->getStraight();
   bool turningRight = false; // Determine if we are turning here

   // Check if next Tile 1) exists and 2) is unoccupied
   if (next != nullptr && !next->isOccupied())
   {
      // If we are turning right, let turnRight() handle the move logic
      if (this->isTurningRight)
      {
         turnRight();
         return;
      }

      // If next is an IntersectionTile and we're turning right, set turningRight to true
      if (next->getName() == "IntersectionTile" && turningRight)
      {
         // Logic for turning right
         this->isTurningRight = true;
         this->movesLeftInTurn = this->length - 1;
      }

      // Move forward regardless
      this->moveForward();
   }
}

/*
 *  When the Vehicle is turning, effectively takes the place of move(); should only be called
 *  by move(). Also, will be called when the head is already on the IntersectionTile
 *
 */
void Vehicle::turnRight()
{
   if (this->movesLeftInTurn != 0)
   {
      // Set previous tiles to unoccupied
      this->tptr->setUnoccupied();
      this->hptr->setUnoccupied();

      // TODO: may need to set all tiles in between head and tail to occupied
      // (like in moveForward()), which would be some interesting logic

      // If head is on IntersectionTile, turn the head right
      if (this->hptr->getName() == "IntersectionTile")
      {
         // Downcast to IntersectionTile
         IntersectionTile *headIntersectionTile = dynamic_cast<IntersectionTile *>(this->hptr);

         // This is how this should look, but not yet implemented in IntersectionTile
         // this->hptr = headIntersectionTile->getRight();
      }
      else if (this->tptr->getName() == "IntersectionTile")
      {
         // Downcast to IntersectionTile
         IntersectionTile *tailIntersectionTile = dynamic_cast<IntersectionTile *>(this->tptr);

         // This is how this should look, but not yet implemented in IntersectionTile
         // this->hptr = tailIntersectionTile->getRight();
      }
      else
      {
         moveForward();
      }
      movesLeftInTurn--;
   }
   else
   {
      this->isTurningRight = false;
   }
}

#endif
