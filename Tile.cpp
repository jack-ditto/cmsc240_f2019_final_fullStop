#include"Tile.h"


Tile::Tile()
{
    isEmpty = false;
}
bool Tile::isOccupied()
{
    return isEmpty;
}

void Tile::setOccupied()
{
    isEmpty=false;
}