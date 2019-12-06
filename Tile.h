#ifndef __TILE_H__
#define __TILE_H__

#include<string>

class Tile
{
private:
	bool isEmpty;
	Tile* straight;

public:
   std::string name;
   Tile();
	Tile(Tile* n);
	Tile(const Tile& other);
	~Tile();

	bool isOccupied();
	void setOccupied();
};

#endif
