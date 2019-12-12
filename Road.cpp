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
Road::Road(int num, IntersectionTile *intersectionTile1, IntersectionTile *intersectionTile2, Direction direction)
{
	this->roadLen = num * 2 + 2;
	Tile *prevTile = NULL;
	for (int i = 0; i < num + 4; i++)
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

	// Point the last Tile before intersection to IntersectionTile
	prevTile->setStraight(intersectionTile1);

	Tile *transition = new Tile; // Transition tile from 2nd intersection to rest of road

	// Point the first intersectionTile to 2nd, and 2nd to
	//rest of road by assigning correct direction
	switch (direction)
	{
	case Direction::north:
		intersectionTile1->setNorth(intersectionTile2);
		intersectionTile2->setNorth(transition);
		break;
	case Direction::east:
		intersectionTile1->setEast(intersectionTile2);
		intersectionTile2->setEast(transition);
		break;
	case Direction::south:
		intersectionTile1->setSouth(intersectionTile2);
		intersectionTile2->setSouth(transition);
		break;
	case Direction::west:
		intersectionTile1->setWest(intersectionTile2);
		intersectionTile2->setWest(transition);
	}

	// Add transition Tile to road and set it as previous tile
	road.push_back(transition);
	prevTile = transition;

	// Continue building the road of Tiles after intersection
	for (int i = 0; i < num + 3; i++)
	{
		Tile *t = new Tile;

		if (prevTile != NULL)
		{
			prevTile->setStraight(t);
		}

		prevTile = t;
		this->road.push_back(t);
	}
}

vector<VehicleBase *> Road::getRoadSnapshot()
{

	vector<VehicleBase *> snapshot(roadLen, nullptr);

	for (int i = 0; i < roadLen; i++)
	{
		if (road[i + 4]->isOccupied())
		{
			snapshot[i] = road[i + 4]->getOccupyingVehicle();
		}
	}

	return snapshot;
}

Tile *Road::getQueueHead()
{
	return this->queueHead;
}

#endif
