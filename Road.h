#ifndef __ROAD_H__
#define __ROAD_H__
#include "Intersection.h"
#include <vector>
using namespace std;

#include "Tile.h"
class Road
{
private:
vector<Tile> Road;
public: 
	Road();
	Road(int num, Tile start,Intersection a, Intersection b);
};
#endif 
