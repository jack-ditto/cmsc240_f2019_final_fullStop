#ifndef __VEHICLE_H__
#define __VEHICLE_H__

class Vehicle
{

enum Turn {LEFT, RIGHT, STRAIGHT};

private:
  int length;
  int id;
  Tile* hptr;
  Tile* trptr;
  Turn t;

public:
  Vehicle();
  ~Vehicle();

  int getLength();
  int getID();
  Tile* getHptr();
  Tile* getTptr();
  Turn getTurn();

};

#endif
