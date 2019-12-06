#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Tile.h"

class Vehicle
{

enum Turn {LEFT, RIGHT, STRAIGHT};

private:
  int length;
  int id;
  Tile* hptr;
  Tile* tptr;
  Turn t;

  bool isTurningRight;
  int movesLeftInTurn;

public:
  Vehicle();
  ~Vehicle();

  int getLength();
  int getID();
  Tile* getHptr();
  Tile* getTptr();
  Turn getTurn();
  void move();
  void turnRight();

};

#endif
