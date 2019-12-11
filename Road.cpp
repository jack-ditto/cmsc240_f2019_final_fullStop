#ifndef __ROAD_CPP__
#define __ROAD_CPP__

#include "Road.h"
#include <iostream>

Road::Road()
{
	// for (int i = 0; i < 3; i++)
	// {
	// 	Tile beginning(); // how to make the pointer to the next ?? Do we need this??
	// 	Road1.push_back(beginning);
	// }
}
Road::Road(int num, IntersectionTile *intersectionTile1, IntersectionTile *intersectionTile2)
{
	this->roadLen = num * 2 + 2;
	Tile *prevTile = NULL;
	for (int i = 0; i < roadLen + 4; i++)
	{
		Tile *t = new Tile;

		// Store queueHead
		if (i == 0)
		{
			this->queueHead = t;
		}

		if (prevTile != NULL)
		{
			prevTile->setStraight(t);
		}

		prevTile = t;
		this->road.push_back(t);
	}

	road.push_back(intersectionTile1);
	road.push_back(intersectionTile2);

	for (int i = 0; i < num; i++)
	{
		Tile *t;
		this->road.push_back(t);
	}

	// for (int i = 0; i < 2 * num + 2; i++)
	// {

	// 	if (i == num + 1)
	// 	{

	// 		Road1.push_back(a);
	// 	}

	// 	else if (i == num + 2)
	// 	{
	// 		Road1.push_back(b);
	// 	}

	// 	else
	// 	{
	// 		Tile temp();

	// 		Road1.push_back(temp);

	// 		Road.push_back(temp);
	// 	}
	// }
}

vector<VehicleBase *> Road::getRoadSnapshot()
{

	Tile *currTile = this->road[4];

	vector<VehicleBase *> snapshot(roadLen, nullptr);

	for (int i = 0; i < roadLen; i++)
	{
		if (currTile->isOccupied())
		{
			snapshot[i] = currTile->getOccupyingVehicle();
		}

		currTile = currTile->getStraight();
	}

	return snapshot;
}

Tile *Road::getQueueHead()
{
	return this->queueHead;
}

#endif
