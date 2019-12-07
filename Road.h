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
		vector<Tile> road;
    vector<vehicle> vehicles;
	public:
		Road();
		Road(int num, Tile start,Intersection a, Intersection b);
    void addVehicle(Vehicle a){
        vehicles.push_back(a);
    }
};

#endif
