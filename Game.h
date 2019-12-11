#ifndef __GAME_H__
#define __GAME_H__

#include "string"

class Game
{
   private:
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

   public:

      // Constructors
      Game();
      Game(std::string filePath);
      void generateVehicles();

      // Initial run method
      void run();

      void moveTraffic();
};
#endif
