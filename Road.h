#ifndef __ROAD_H__
#define __ROAD_H__

#include "IntersectionTile.h"
#include "Tile.h"
#include <vector>
#include "Vehicle.h"
using namespace std;

class Road
{
private:
	vector<Tile *> road;	  // Store Tiles in road as pointer to tiles
	vector<Vehicle> vehicles; // Store Vehicles on road

public:
	Road();
	Road(int num, Tile start, IntersectionTile a, IntersectionTile b);
	void addVehicle(Vehicle a)
	{
		vehicles.push_back(a);
	}
};

#endif
