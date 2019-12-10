#include "VehicleBase.h"
#include "Tile.h"
#include "Vehicle.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>

void drawRoad(std::vector<Tile *> road);
std::vector<Tile *> createRoad(int numTiles);

int main()
{

   int ROAD_SIZE = 30;

   std::vector<Tile *> r1 = createRoad(30);
   std::cout << r1.at(0) << std::endl;

   Vehicle v1(r1.at(0), r1.at(4));
   drawRoad(r1);

   for (int i = 0; i < ROAD_SIZE; i++)
   {
      std::cin.ignore();
      system("clear");

      v1.move();
      drawRoad(r1);
   };
}

void drawRoad(std::vector<Tile *> road)
{
   std::string sideRoad = "";
   std::string middleRoad = "";
   for (int i = 0; i < road.size(); i++)
   {
      sideRoad += "---";
      if (road.at(i)->isOccupied())
      {
         middleRoad += "|o|";
      }
      else
      {
         middleRoad += "| |";
      }
   }
   std::cout << sideRoad << std::endl;
   std::cout << middleRoad << std::endl;
   std::cout << sideRoad << std::endl;
}

std::vector<Tile *> createRoad(int numTiles)
{

   // Road isn't working, so let's pretend this is Road:

   // Create a "Road", aka a vector of Tile pointers
   std::vector<Tile *> road;

   // Add 10 tiles to the road
   Tile *prevTilePtr; // Store pointer to previously added Tile
   for (int i = 0; i < numTiles; i++)
   {
      // Store a pointer to a new tile object
      Tile *currTilePtr = new Tile;

      // If not first Tile, point the previous tile to this tile
      if (prevTilePtr != NULL)
      {
         // std::cout << prevTilePtr << " points to " << currTilePtr << std::endl;
         prevTilePtr->setStraight(*currTilePtr);
      }

      // Add the pointer to the current tile to the road
      road.push_back(currTilePtr);

      prevTilePtr = currTilePtr;
   }

   return road;

   // retrieve the pointer to the first tile
   // Tile *currTile = road.at(0);
   // // std::cout << currTile << std::endl;

   // // Walk through every Tile in the Road by using "next"
   // while (currTile->getStraight() != NULL)
   // {
   //    std::cout << currTile->getStraight() << std::endl;
   //    // std::cout << "Moving forward a tile..." << std::endl;
   //    currTile = currTile->getStraight();
   // }
};
