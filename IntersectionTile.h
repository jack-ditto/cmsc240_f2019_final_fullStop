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
  ~IntersectionTile();                             // Destructor

  // Getter methods
  Tile *getStraight() override;
  Tile *getBack() override;
  Tile *getRight();
  TrafficLight *getTrafficLight();
  inline Tile *getNorth() { return this->north; }
  inline Tile *getEast() { return this->east; }
  inline Tile *getSouth() { return this->south; }
  inline Tile *getWest() { return this->west; }

  // Setter methods
  inline void setNorth(Tile *north) { this->north = north; }
  inline void setEast(Tile *east) { this->east = east; }
  inline void setSouth(Tile *south) { this->south = south; }
  inline void setWest(Tile *west) { this->west = west; }
};

#endif
