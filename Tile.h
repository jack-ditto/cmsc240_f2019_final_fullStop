#ifndef __TILE_H__
#define __TILE_H__

#include<string>

class Tile
{
private:
	bool isEmpty;
	Tile* straight;
   std::string name;

public:
   Tile();
	Tile(Tile* n);
	Tile(const Tile& other);
	~Tile();

	Tile* getStraight();
	bool isOccupied();
	void setOccupied();
   virtual std::string getName();
};

#endif
