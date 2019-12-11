#ifndef __TILE_H__
#define __TILE_H__

#include <string>
#include "Vehicle.h"

class Tile
{
private:
	bool isEmpty;
	VehicleBase *occupyingVehicle;

protected:
	Tile *straight;
	std::string name;

public:
	Tile();
	Tile(Tile *n);
	Tile(const Tile &other);
	~Tile();

	Tile *getStraight();
	bool isOccupied();
	void setOccupied(VehicleBase *);
	void setUnoccupied();
	virtual void setStraight(Tile *t);
	VehicleBase *getOccupyingVehicle();
	std::string getName();
};

#endif
