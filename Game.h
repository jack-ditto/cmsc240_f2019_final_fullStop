#ifndef __GAME_H__
#define __GAME_H__

#include "string"
#include "IntersectionTile.h"
#include "Road.h"
#include <random>


class Game
{
   private:
<<<<<<< HEAD
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
     

     
     

=======
      int    seed;                              // Seed for random number generator
      int    maxSimTime;                        // Maximum simulation time
      int    numSectionsBeforeIntersection;     // Number of tiles before intersection for each road
      int    greenNS;                           // Time that the north-south light is green
      int    yellowNS;                          // Time that the north-south light is yellow
      int    greenEW;                           // Time that the east-west light is green
      int    yellowEW;                          // Time that the east-west light is yellow
      double probNewVehicleN;                   // Probability a new vehicle is generated northbound
      double probNewVehicleS;                   // Probability a new vehicle is generated southbound
      double probNewVehicleE;                   // Probability a new vehicle is generated eastbound
      double probNewVehicleW;                   // Probability a new vehicle is generated westbound
      double proportionCars;                    // Proportion of generated vehicles that are cars
      double proportionSUVs;                    // Proportion of generated vehicles that are SUV
      double proprtionTrucks;                   // Proportion of generated vehicles that are trucks
      double probRightCars;                     // Probability a car turns right
      double probRightSUVs;                     // Probability a SUV turns right
      double probRightTrucks;                   // Probability a truck turns right
      double probLeftCars;                      // Probability a car turns left
      double probLeftSUVs;                      // Probability a SUV turns left
      double probLeftTrucks;                    // Probability a truck turns left
>>>>>>> eb1b14b71a4e46cbece2d6e8269c27991c204a86

   public:

      // Constructors
      Game();
      Game(std::string filePath);
<<<<<<< HEAD
      vector<Vehicle> generateDirections(Road *west, Road *east, Road *south, Road *north, vector<Vehicle> veh);
      vector<Vehicle> generateVehicles(Direction direction, vector<Vehicle> v);
=======
>>>>>>> eb1b14b71a4e46cbece2d6e8269c27991c204a86


<<<<<<< HEAD
      void moveTraffic(Road *north, Road *south, Road *west, Road *east, vector<Vehicle> a );
=======
      // Simulation running methods
      void run();
      void moveTraffic();

      // Methods to generate new vehicles
      void generateDirections(Road *west, Road *east, Road *south, Road *north);
      void generateVehicles(Direction direction);

>>>>>>> eb1b14b71a4e46cbece2d6e8269c27991c204a86
};
#endif
