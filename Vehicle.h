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
  int length;
  int id;
  Tile *hptr;
  Tile *tptr;
  Turn t;
  bool willTurnRight;

  bool isTurningRight;
  int movesLeftInTurn;
  void setOccupiedTiles();
  void moveForward();
  Direction currDirection;

public:
  // Default constructor
  Vehicle();

  // Typical use: hptr here is a the queueHead in Road. tptr calculated in constructor based on length
  Vehicle(VehicleType vehicleType, Direction direction, Tile *tptr, int vehicleLength, bool willTurnRight);

  Vehicle(VehicleType type, Direction originalDirection);

  // Destructor
  ~Vehicle();

  int getLength();
  Direction getCurrDirection();
  void setCurrDirection(Direction direction);
  int getID();
  Tile *getHptr();
  Tile *getTptr();
  Turn getTurn();
  void move();
  void turnRight();
};

#endif
