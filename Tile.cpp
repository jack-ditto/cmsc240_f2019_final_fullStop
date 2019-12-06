#ifndef __TILE_CPP__
#define __TILE_CPP__

#include "Tile.h"

Tile::Tile()
{
    delete next;
    isEmpty = true;
}

Tile::Tile(Tile* n)
{
    next = n;
    isEmpty = true;
}

Tile::Tile(const Tile& other)
{
    next = other.next;
    isEmpty = other.isEmpty;
}

Tile::~Tile() {}

Tile* Tile::getNext()
{
    return next;
}

bool Tile::isOccupied()
{
    return isEmpty;
}

void Tile::setOccupied()
{
    isEmpty = false;
}

#endif
