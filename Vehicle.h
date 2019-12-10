#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Tile.h"
#include "VehicleBase.h"

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

  bool isTurningRight;
  int movesLeftInTurn;
  void setOccupiedTiles();
  void moveForward();

public:
  Vehicle(Tile *hptr, Tile *tptr);

  // Typical use: hptr here is a the queueHead in Road. tptr calculated in constructor based on length
  Vehicle(VehicleType vehicleType, Direction direction, Tile *hptr);

  Vehicle(VehicleType type, Direction originalDirection);
  ~Vehicle();

  int getLength();
  int getID();
  Tile *getHptr();
  Tile *getTptr();
  Turn getTurn();
  void move();
  void turnRight();
};

#endif
