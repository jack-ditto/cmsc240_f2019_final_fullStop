#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "TrafficLight.h"

class IntersectionTile : public Tile
{

private:
  Tile *turn;
  TrafficLight northSouth;
  TrafficLight eastWest;

public:
  IntersectionTile();
  IntersectionTile(Tile n, Tile s, Tile e, Tile w);
  IntersectionTile(const IntersectionTile &other);
  ~IntersectionTile();

  Tile getTurn();
  Color getLightNS();
  Color getLightEW(); //to set up for traffic light enum color
};

#endif
