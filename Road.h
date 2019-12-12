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
	Tile *queueHead;		  // Stores pointer to last 'invisible' tile on the road
	int roadLen;

public:
	Road();
	Road(int num, IntersectionTile *intersectionTile1, IntersectionTile *intersectionTile2, Direction direction);
	void addVehicle(Vehicle a)
	{
		vehicles.push_back(a);
	}
	Tile *getQueueHead();
	vector<VehicleBase *> getRoadSnapshot();
};

#endif
