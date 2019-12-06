#ifndef __TILE_H__
#define __TILE_H__

class Tile
{
private:
	bool isEmpty;
	Tile* next;

public:
	Tile();
	Tile(Tile* n);
	Tile(const Tile& other);
	~Tile();

	bool isOccupied();
	void setOccupied();
};

#endif
