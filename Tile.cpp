#ifndef __TILE_CPP__
#define __TILE_CPP__

#include "Tile.h"

Tile::Tile()
{
   this->name = "Tile";
   delete straight;
   isEmpty = true;
}

Tile::Tile(Tile* n)
{
   this->name = "Tile";
   straight = n;
   isEmpty = true;
}

Tile::Tile(const Tile& other)
{
   this->name = other.name;
   straight = other.straight;
   isEmpty = other.isEmpty;
}

Tile::~Tile() {}

bool Tile::isOccupied()
{
   return isEmpty;
}

void Tile::setOccupied()
{
   isEmpty = false;
}

#endif
