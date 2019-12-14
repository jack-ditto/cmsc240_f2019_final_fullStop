#ifndef __TILE_H__
#define __TILE_H__

#include <string>
#include "VehicleBase.h"

class Tile
{
private:
	bool isEmpty;				   // Tile has a Vehicle on it
	VehicleBase *occupyingVehicle = nullptr; // VehicleBase pointer to Vehicle occupying Tile

	// NOTE: It would have been better here to use Vehicle instead of VehicleBase, but since Vehicle include Tile,
	// Including Vehicle here would have caused a circular depenency. VehicleBase works just fine.

protected:
	Tile *straight;   // Next tile
	Tile *back;		  // Previous tile
	std::string name; // Name of tile (see Tile::getName() for explanation)

public:
	Tile();
	~Tile();

	// Getters
	virtual Tile *getStraight();		// getStraight, overrwritten in IntersectionTile
	virtual Tile *getBack();			// getBack, overwritten in IntersectionTile
	bool isOccupied();					// Tile has a Vehicle on it
	VehicleBase *getOccupyingVehicle(); // Get VehicleBase reference to occupying vehicle
	std::string getName();				// Return name ("Tile")

	// Setters
	void setOccupied(VehicleBase *); // Tell Tile that there is a Vehicle on it
	void setUnoccupied();			 // Tell Tile there is not longer a Vehicle on it
	void setStraight(Tile *t);		 // Set the next Tile
	void setBack(Tile *t);
};

#endif
