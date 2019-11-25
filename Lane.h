#include "Tile.h"
#include "Intersection.h"

class Lane : public Tile
{
	 private: 
	 Tile* next;
	
	 
	 Lane(Tile a){*next = a};
	
}
