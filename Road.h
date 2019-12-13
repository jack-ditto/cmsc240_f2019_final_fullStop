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
		vector<Tile *> road; // Store Tiles in road as pointer to tiles
		Tile *queueHead;	 // Stores pointer to last 'invisible' tile on the road
		int roadLen;		 // Total length of road NOT including invisible tiles (+8)
		Direction direction;

	public:
		Road(int num, IntersectionTile *intersectionTile1, IntersectionTile *intersectionTile2, Direction direction);
		Tile *getQueueHead();
		vector<VehicleBase *> getRoadSnapshot();
		Direction getDirection(); // Should be needed by generate vehicle
};

#endif
