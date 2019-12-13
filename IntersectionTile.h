#ifndef __INTERSECTIONTILE_H__
#define __INTERSECTIONTILE_H__

#include "Tile.h"
#include "TrafficLight.h"

class IntersectionTile : public Tile
{

private:
  Tile *north;                // North pointer
  Tile *south;                // South pointer
  Tile *east;                 // East pointer
  Tile *west;                 // West pointer
  TrafficLight *trafficLight; // Reference to TrafficLight

public:
  IntersectionTile(TrafficLight *TrafficLight);    // Typical use constructor
  IntersectionTile(const IntersectionTile &other); // Copy constructor
  ~IntersectionTile();                             // Deconstructor

  // Getter methods
  Tile *getStraight() override;
  Tile *getRight();
  TrafficLight *getTrafficLight();

  // Setter methods
  void setNorth(Tile *north);
  void setEast(Tile *east);
  void setSouth(Tile *south);
  void setWest(Tile *west);
};

#endif
