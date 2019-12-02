#ifndef __TILE_H__
#define __TILE_H__

#include "Vehicle.h"
class Tile
{

private:
	Vehicle* v;

public:
	Tile();
	Tile(Vehicle* v1);
	~Tile();
	Vehicle* getVehicle();

};

#endif
