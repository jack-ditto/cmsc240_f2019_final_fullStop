#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "TrafficLight.h"

class IntersectionTile : public Tile
{

private:
  Tile *turn;
  Tile *north;
  Tile *south;
  Tile *east;
  Tile *west;
  TrafficLight *trafficLight;

public:
  IntersectionTile(TrafficLight *TrafficLight);
  IntersectionTile(Tile n, Tile s, Tile e, Tile w);
  IntersectionTile(const IntersectionTile &other);
  ~IntersectionTile();

  Tile *getStraight() override;
  Tile *getRight();
  void setNorth(Tile *north);
  void setEast(Tile *east);
  void setSouth(Tile *south);
  void setWest(Tile *west);
  TrafficLight *getTrafficLight();

  Tile getTurn();
};

#endif
