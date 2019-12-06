#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"

Vehicle::Vehicle()
{}

Vehicle::~Vehicle()
{}

int Vehicle::getLength()
{
   return length;
}

int Vehicle::getID()
{
   return id;
}

Tile* Vehicle::getHptr()
{
   return this->hptr;
}

Tile* Vehicle::getTptr()
{
   return this->tptr;
}

Vehicle::Turn Vehicle::getTurn()
{
   return t;
}

/**
 *  Called for every 'click' of time. Moves the vehicle one Tile and handles turning 
 *  by calling external method when the Vehicle reaches an intersection. 
 *
 */
void Vehicle::move() 
{
   // Tile has not been implemented yet, so psuedocode so it will compile
   //
   // if this->isTurning:
   //    
   //    turn();
   //
   // else if *hptr.next typeof IntersectionTile:
   //    
   //    check the light color (through method in the IntersectionTile)
   //
   //    decide whether or not to turn right
   //
   //    if the light is green:
   //       
   //       if we are turning right:
   //          
   //          this->isTurning = true;
   //          this->movesLeftInTurn = this->length+1; // for right turns, takes len+1 moves
   //          this->turnRight();
   //          return;
   //       
   // this->hptr = (*hptr).next
   // this->tptr = (*tptr).next
   //
   //if(this->isTurningRight)
   //{
   //   this->turnRight();
   //} 
   //else if(*hptr.next typeof 
   //{

   //}



}

/*
 *  When the Vehicle is turning, effectively takes the place of move(); should only be called
 *  by move()
 *
 */
void Vehicle::turnRight()
{
   // if movesLeftInTurn != 0:
   //    
   //    // If the head is on an Itersection Tile, turn it right
   //    if *(hptr) instanceof IntersectionTile:
   //       
   //       this->hptr = *(hptr).right;
   //    
   //    // If the tail is on an Intersection Tile, turn it right
   //    else if *(tptr) instanceof IntersectionTile:
   //       
   //       this->tptr = *(tptr).right;
   //    
   //    // Handles move when head or tail are not on intersection tile 
   //    else:
   //
   //       this->hptr = (*hptr).next;
   //       this->tptr = (*hptr).next;
   //
   //    movesLeftInTurn--;
   // 
   // else:
   //    
   //    this->isTurning = false;
   //
}


#endif
