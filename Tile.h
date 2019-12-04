#ifndef __TILE_H__
#define __TILE_H__

#include "Vehicle.h"

class Tile
{

private:
	bool isEmpty;
	Tile* next;
public: 
   Tile();
   bool isOccupied();
   void setOccupied();
};

#endif
