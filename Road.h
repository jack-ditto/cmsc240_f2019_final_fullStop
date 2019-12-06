#ifndef __ROAD_H__
#define __ROAD_H__

#include "IntersectionTile.h"
#include "Tile.h"
#include <vector>
using namespace std;

class Road
{
	private:
		vector<Tile> road;
	public:
		Road();
		Road(int num, Tile start,Intersection a, Intersection b);
};

#endif
