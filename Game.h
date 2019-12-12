#ifndef __GAME_H__
#define __GAME_H__

#include "string"
#include "IntersectionTile.h"
#include "Road.h"
#include <random>


class Game
{
   private:
      int    seed;
      int    maxSimTime;
      int    numSectionsBeforeIntersection;
      int    greenNS;
      int    yellowNS;
      int    greenEW;
      int    yellowEW;
      double probNewVehicleN;
      double probNewVehicleS;
      double probNewVehicleE;
      double probNewVehicleW;
      double proportionCars;
      double proportionSUVs;
      double proprtionTrucks;
      double probRightCars;
      double probRightSUVs;
      double probRightTrucks;
      double probLeftCars;
      double probLeftSUVs;
      double probLeftTrucks; 

      Road westRoad;
      Road northRoad;
      Road southRoad;
      Road eastRoad;
     


   public:

      // Constructors
      Game();
      Game(std::string filePath);
      void generateVehicles(Road *start);

      // Initial run method
      void run();

      void moveTraffic();
};
#endif
