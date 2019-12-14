#ifndef __TILE_CPP__
#define __TILE_CPP__

#include "Tile.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;
/*
 * Default constructor
 */
Tile::Tile()
{
    this->name = "Tile";
    this->isEmpty = true;
}

/*
 * Destructor
 */
Tile::~Tile() 
{
    // std::cout << "Tile deconstructed!" << std::endl;
}

/*
 * Return pointer to next Tile as set by setStraight()
 */
Tile *Tile::getStraight()
{
    return this->straight;
}

Tile *Tile::getBack()
{
    return this->back;
}

/*
 * Boolean of if a Vehicle is occupying the tile
 */
bool Tile::isOccupied()
{
    return !isEmpty;
}

/*
 * Set pointer to the next Tile
 */
void Tile::setStraight(Tile *t)
{
    this->straight = t;
}

void Tile::setBack(Tile *t)
{
    this->back = t;
}

/*
 * Usually called by Vehicle, sets the Tile as occupied with a VehicleBase reference
 */
void Tile::setOccupied(VehicleBase *occupyingVehicle)
{
    this->occupyingVehicle = occupyingVehicle;
    isEmpty = false;
}

/*
 *  Opposite of setOccupied, removes VehicleBase reference and sets the Tile to empty.
 */
void Tile::setUnoccupied()
{
    this->occupyingVehicle = nullptr;
    isEmpty = true;
}

/*
 *  Returns the "name" of the Tile. This method exists for ease of type identification when
 *  casting from Tile to IntersectionTile. Name will be "Tile" or "IntersectionTile"
 */
std::string Tile::getName()
{
    return this->name;
}

/*
 *  Returns VehicleBase pointer of Vehicle occupying the Tile
 */
VehicleBase *Tile::getOccupyingVehicle()
{
    return this->occupyingVehicle;
}

#endif
