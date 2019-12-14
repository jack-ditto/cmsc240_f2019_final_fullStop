#ifndef __ROAD_CPP__
#define __ROAD_CPP__

#include "Road.h"
#include <iostream>

/**
 * Typical use constructor: constructs the road by linking Tiles and IntersectionTiles and setting the correct
 * direction pointers in the IntersecitonTiles
 */
Road::Road(int num, IntersectionTile *intersectionTile1, IntersectionTile *intersectionTile2, Direction dir)
{
	this->direction = dir;
	this->roadLen = num * 2 + 2; // Tiles before intersection + 2 intersection tiles
	Tile *prevTile = NULL;		 // Initial null value

	// Construct, add, and link first section of Tiles before intersection
	for (int i = 0; i < num + 4; i++)
	{
		Tile *t = new Tile;

		// Store the first Tile for Vehicle to enter on
		if (i == 3)
		{
			this->queueHead = t;
		}

		// Link the previous Tile to current
		if (prevTile != NULL)
		{
			t->setBack(prevTile);
			prevTile->setStraight(t);
		}

		// Assign new Prev tile and push Tile to road
		prevTile = t;
		this->road.push_back(t);
	}

	// Push both intersection tiles to the road
	road.push_back(intersectionTile1);
	road.push_back(intersectionTile2);

	// Point the last Tile before intersection to IntersectionTile
	prevTile->setStraight(intersectionTile1);
	intersectionTile1->setBack(prevTile);

	Tile *transition = new Tile; // Transition tile from 2nd intersection to rest of road

	// Point 1) first IntersectionTile to prev tile
	//		 2) first IntersectionTile to secton IntersectionTile
	//		 3) second IntersectionTile to first IntersectionTile
	//       4) second IntersectionTile to next Tile (rest of road)
	switch (direction)
	{
	case Direction::north:
		intersectionTile1->setSouth(prevTile);
		intersectionTile1->setNorth(intersectionTile2);
		intersectionTile2->setSouth(intersectionTile1);
		intersectionTile2->setNorth(transition);
		break;
	case Direction::east:
		intersectionTile1->setWest(prevTile);
		intersectionTile1->setEast(intersectionTile2);
		intersectionTile2->setWest(intersectionTile1);
		intersectionTile2->setEast(transition);
		break;
	case Direction::south:
		intersectionTile1->setNorth(prevTile);
		intersectionTile1->setSouth(intersectionTile2);
		intersectionTile2->setNorth(intersectionTile1);
		intersectionTile2->setSouth(transition);
		break;
	case Direction::west:
		intersectionTile1->setEast(prevTile);
		intersectionTile1->setWest(intersectionTile2);
		intersectionTile2->setEast(intersectionTile1);
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
			t->setBack(prevTile);
			prevTile->setStraight(t);
		}

		prevTile = t;
		this->road.push_back(t);
	}
}

/**
 * Returns a "snapshot" of Vehicles on the road, as needed by Animator. Returns a Vector of VehicleBase pointers of size
 * roadLen, with a reference in ever occupied spot and a nullpointer where there is not a Vehicle.
 */
vector<VehicleBase *> Road::getRoadSnapshot()
{
	// Initialize vector
	vector<VehicleBase *> snapshot(roadLen, nullptr);

	// Loop through Tiles and add Vehicle if it is on a Tile
	for (int i = 0; i < roadLen; i++)
	{
		if (road[i + 4]->isOccupied())
		{
			snapshot[i] = road[i + 4]->getOccupyingVehicle();
		}
	}

	return snapshot;
}

/**
 * Returns pointer to the furthest back Tile on a road (aka the first of the invisible Tiles)
 */
Tile *Road::getQueueHead()
{
	return this->queueHead;
}

/**
 * Returns the direction in which the road is constructed
 */
Direction Road::getDirection()
{
	return this->direction;
}

#endif
