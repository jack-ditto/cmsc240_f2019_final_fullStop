#ifndef __TILE_H__
#define __TILE_H__


class Tile
{

private:
	bool isEmpty;
	Tile* next;
public:
	Tile();
	bool isOccupied();
	void setOccupied();

public:
	Tile();
	Tile(Vehicle* v1);
	~Tile();
	Vehicle* getVehicle();

};

#endif
