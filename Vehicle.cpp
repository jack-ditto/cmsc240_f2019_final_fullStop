#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "VehicleBase.h"
#include <iostream>
#include "IntersectionTile.h"
using namespace std;

// Typical use constructor for Vehicle
Vehicle::Vehicle(VehicleType vehicleType, Direction direction, int vehicleLength, bool willTurnRight) : VehicleBase(vehicleType, direction)
{
   this->length = vehicleLength;        // Set the vehicle length
   this->willTurnRight = willTurnRight; // Whether Vehicle will turn right or now
}

Vehicle::~Vehicle()
{
}

// Getter methods

/*
 *  Return the length of the Vehicle
 */
int Vehicle::getLength()
{
   return length;
}

/*
 *  Return the current direction of the Vehicle
 */
Direction Vehicle::getCurrDirection()
{
   return this->currDirection;
}

/*
 * Private method, sets all the tiles between head and tail to occupied. Also accounts
 * for turns. 
 */
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

/*
 *  Called when vehicle should "drive" itself on to the road. Passed a pointer to  
 *  the first available tile on a Road, as retrieved by Road.getQueueHead()
 */
void Vehicle::enterRoad(Tile *hptr)
{
   this->hptr = hptr; // Set head pointer
   this->tptr = hptr; // Tail is initially same as head

   // Move the tail backward the length of the car to "drive" on to the Road
   for (int i = 0; i < this->length - 1; i++)
   {
      this->tptr = this->tptr->getBack();
   }

   // Set all the Tiles between head and tail to occupied
   this->setOccupiedTiles();
}

/*
 *   Moves the vehicle forward regardless. This is a private method, and should only be called
 *   from move() to avoid errors.
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

/*
 *  Called for every 'click' of time. Moves the vehicle one Tile and handles turning
 *  by calling external method when the Vehicle reaches an intersection.
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

      // The next tile is an IntersectionTile and we don't already have a green light
      if (next->getName() == "IntersectionTile" && !this->hasGreen)
      {
         // Cast Tile to IntersectionTile
         IntersectionTile *it = dynamic_cast<IntersectionTile *>(next);

         // Get the light color from IntersectionTile
         LightColor lightColor = it->getTrafficLight()->getColor();

         // If the light is red, don't go forward but can turn
         if (lightColor == LightColor::red)
         {
            // Check if you can turn and turn
            if (this->willTurnRight && this->canTurnRight(it))
            {
               turnRight();
            }
            return;
         }
         // If the light is yellow, only Vehicle can make it
         else if (lightColor == LightColor::yellow)
         {
            if (it->getTrafficLight()->getTimeTilChange() >= this->length + 1 && this->willTurnRight)
            {
               turnRight();
               return;
            }

            if (it->getTrafficLight()->getTimeTilChange() >= this->length + 2)
            {
               this->hasGreen = true;
               this->moveForward();
            }
         }
         else if (lightColor == LightColor::green)
         {
            this->hasGreen = true;

            // If the light is green and Vehicle is turning right, just do it
            if (this->willTurnRight)
            {
               turnRight();
               return;
            }

            this->moveForward();
         }
      }
      else
      {
         // Move forward to the next Tile
         this->moveForward();
      }
   }
   else if (next == NULL)
   {
      this->reachedEndOfRoad = true;

      Tile *tail = this->tptr;

      while (tail != hptr)
      {
         tail->setUnoccupied();
         tail = tail->getStraight();
      }

      this->hptr->setUnoccupied();
   }
}

/*
 *  When the Vehicle is turning, effectively takes the place of move(); should only be called
 *  by move(). Also, will be called when the head is already on the IntersectionTile
 */
void Vehicle::turnRight()
{

   std::cout << this->getVehicleID() << " turning right..." << std::endl;

   // Set turning right to true if it isn't already
   if (!this->isTurningRight)
   {
      this->isTurningRight = true;
      this->movesLeftInTurn = this->length + 1;
   }

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

/*
 * Not currently used, but for left turns might be important.
 */
void Vehicle::setCurrDirection(Direction direction)
{
   this->currDirection = direction;
}

/*
 * Check if a Vehicle can turn right on a red light
 */
bool Vehicle::canTurnRight(IntersectionTile *it)
{

   if (it->getTrafficLight()->getColor() == LightColor::green)
   {
      return true;
   }

   IntersectionTile *it2;
   switch (this->getVehicleOriginalDirection())
   {
   case Direction::north:
      it2 = dynamic_cast<IntersectionTile *>(it->getWest());
      break;
   case Direction::east:
      it2 = dynamic_cast<IntersectionTile *>(it->getNorth());
      break;
   case Direction::south:
      it2 = dynamic_cast<IntersectionTile *>(it->getEast());
   case Direction::west:
      it2 = dynamic_cast<IntersectionTile *>(it->getSouth());
   }

   if (it2->isOccupied())
   {
      return false;
   }

   Tile *checkTile = it2->getBack();
   for (int i = 0; i < this->length - 1; i++)
   {
      if (checkTile->isOccupied())
      {
         return false;
      }
      checkTile = checkTile->getBack();
   }

   return true;
}

#endif
