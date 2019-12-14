#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Tile.h"

class Vehicle : public VehicleBase
{

  enum Turn
  {
    LEFT,
    RIGHT,
    STRAIGHT
  };

private:
  int length;              // Vehicle length
  Tile *hptr;              // Pointer to Tile where head of Vehicle is
  Tile *tptr;              // Pointer to Tile where tail of Vehicle is
  bool willTurnRight;      // Vehicle is destined to turn right
  bool isTurningRight;     // Vehicle is currently turning right
  int movesLeftInTurn;     // Number of moves left in a turn
  Direction currDirection; // Current direction of the Vehicle

  void setOccupiedTiles(); // Set all Tiles between head and tail to occupied
  void moveForward();      // Move the vehicle forward a Tile

public:
  // Typical use: hptr here is a the queueHead in Road. tptr calculated in constructor based on length
  Vehicle(VehicleType vehicleType, Direction direction, int vehicleLength, bool willTurnRight);

  // Destructor
  ~Vehicle();

  // Getter methods
  int getLength();
  Direction getCurrDirection();
  Tile *getHptr();
  Tile *getTptr();
  Turn getTurn();

  // Setter methods
  void setCurrDirection(Direction direction);

  // Actions
  void move();                // Tell the Vehicle to move
  void turnRight();           // Takes place of move() when turning
  void enterRoad(Tile *tptr); // Called after construction, point Vehicle to Road
};

#endif
