#ifndef __TILE_H__
#define __TILE_H__

#include <string>
#include "VehicleBase.h"

class Tile
{
private:
	bool isEmpty;
	Tile *straight;
	std::string name;
	Vehicle *occupyingVehicle;

public:
	Tile();
	Tile(Tile *n);
	Tile(const Tile &other);
	~Tile();

	Tile *getStraight();
	bool isOccupied();
	void setOccupied(Vehicle *);
	void setUnoccupied();
	void setStraight(Tile &t);
	virtual std::string getName();
	Vehicle *getOccupyingVehicle();
};

#endif
