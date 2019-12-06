#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "TrafficLight.h"

class IntersectionTile : public Tile
{

private:
  Tile*        turn;
  Tile*        straight;
  TrafficLight northSouth;
  TrafficLight eastWest


public:
  IntersectionTile(Tile n, Tile s, Tile e, Tile w);
  IntersectionTile(const IntersectionTile other);
  ~IntersectionTile();

  Tile  getTurn();
  Tile  getStraight();
  Color getLightNS();
  Color getLightEW(); //to set up for traffic light enum color

};

#endif
