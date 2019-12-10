#ifndef __TILE_CPP__
#define __TILE_CPP__

#include "Tile.h"

Tile::Tile()
{
    this->name = "Tile";
    // delete straight;
    isEmpty = true;
}

Tile::Tile(Tile *n)
{
    this->name = "Tile";
    straight = n;
    isEmpty = true;
}

Tile::Tile(const Tile &other)
{
    this->name = other.name;
    straight = other.straight;
    isEmpty = other.isEmpty;
}

Tile::~Tile() {}

Tile *Tile::getStraight()
{
    return straight;
}

bool Tile::isOccupied()
{
    return !isEmpty;
}

void Tile::setStraight(Tile &t)
{
    this->straight = &t;
}

void Tile::setOccupied()
{
    isEmpty = false;
}

void Tile::setUnoccupied()
{
    isEmpty = true;
}

std::string Tile::getName()
{
    return this->name;
}

#endif
