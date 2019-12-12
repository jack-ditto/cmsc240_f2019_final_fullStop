#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "VehicleBase.h"
#include <iostream>
#include "IntersectionTile.h"

// Default constructor for Vehicle
Vehicle::Vehicle() : VehicleBase(VehicleType::car, Direction::north) {}

// Typical use constructor for Vehicle
Vehicle::Vehicle(VehicleType vehicleType, Direction direction, Tile *tptr, int vehicleLength, bool willTurnRight) : VehicleBase(VehicleType::car, direction)
{
   this->length = vehicleLength;
   this->willTurnRight = willTurnRight;

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

void Vehicle::setOccupiedTiles()
{
   // Set the Tile where head is to occupied
   this->hptr->setOccupied(this);

   // Start from tail, setting all Tiles in between to occupied
   Tile *currTile = this->tptr;
   while (currTile != this->hptr)
   {
      // Set the tile to occupied
      currTile->setOccupied(this);

      // Check the current tile is an IntersectionTile to account for turns
      if (this->isTurningRight && currTile->getName() == "IntersectionTile")
      {
         currTile = dynamic_cast<IntersectionTile *>(currTile)->getRight();
      }
      // If the next is not IntersectionTile, keep going straight
      else
      {
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
   Tile *prevt = this->tptr;
   Tile *prevh = this->hptr;

   // Move each pointer forward
   this->hptr = this->hptr->getStraight();
   this->tptr = this->tptr->getStraight();

   // Unassign last position
   prevh->setUnoccupied();
   prevt->setUnoccupied();

   // Set the tiles between head and tail to occupied
   this->setOccupiedTiles();
}

/**
 *  Called for every 'click' of time. Moves the vehicle one Tile and handles turning
 *  by calling external method when the Vehicle reaches an intersection.
 *
 */
void Vehicle::move()
{

   // If we are turning right, let turnRight() handle the move logic
   if (this->isTurningRight)
   {
      turnRight();
      return;
   }

   // Get the next Tile
   Tile *next = this->hptr->getStraight();

   // Check if next Tile 1) exists and 2) is unoccupied
   if (next != nullptr && !next->isOccupied())
   {

      // If next is an IntersectionTile and we're turning right, set turningRight to true
      if (next->getName() == "IntersectionTile" && this->willTurnRight)
      {
         this->isTurningRight = true;
         this->movesLeftInTurn = this->length;
      }

      // Move forward to the next Tile
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
      // Set prev tiles
      Tile *prevt = this->tptr;
      Tile *prevh = this->hptr;

      // Check if the head is on an IntersectionTile (it should be initally)
      if (this->hptr->getName() == "IntersectionTile")
      {
         // Downcast to IntersectionTile
         IntersectionTile *headIntersectionTile = dynamic_cast<IntersectionTile *>(this->hptr);

         // Set the head to the right of the IntersectionTile
         this->hptr = headIntersectionTile->getRight();

         // Manually move tail pointer
         this->tptr->setUnoccupied();
         this->tptr = this->tptr->getStraight();

         // Set the spot where the head was to unoccupied (unescessary but for consistency)
         prevh->setUnoccupied();
      }
      // Check if the tail is on an IntersectionTile
      else if (this->tptr->getName() == "IntersectionTile")
      {
         // Downcast to IntersectionTile
         IntersectionTile *tailIntersectionTile = dynamic_cast<IntersectionTile *>(this->tptr);

         // Set the tail to the right of the IntersectionTile
         this->tptr = tailIntersectionTile->getRight();

         // Manually move head pointer
         this->hptr->setUnoccupied();
         this->hptr = this->hptr->getStraight();

         // Set the spot where the tail was to unoccupied (unescessary but for consistency)
         prevt->setUnoccupied();
      }
      else
      {
         // If the head and tail are not on IntersectionTiles, move head and tail forward
         moveForward();
      }
      this->setOccupiedTiles();
      movesLeftInTurn--;
   }

   // If the movesLeftInTurn are used up, set isTurningRight to false
   if (movesLeftInTurn == 0)
   {
      this->isTurningRight = false;
   }
}

Direction Vehicle::getCurrDirection()
{
   return this->currDirection;
}

void Vehicle::setCurrDirection(Direction direction)
{
   this->currDirection = direction;
}

#endif
