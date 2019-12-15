#ifndef __GAME_H__
#define __GAME_H__

#include "string"
#include "IntersectionTile.h"
#include "Road.h"
#include <random>
#include <vector>

class Game
{
private:
   int seed;                          // Seed for random number generator
   int maxSimTime;                    // Maximum simulation time
   int numSectionsBeforeIntersection; // Number of tiles before intersection for each road
   int greenNS;                       // Time that the north-south light is green
   int yellowNS;                      // Time that the north-south light is yellow
   int greenEW;                       // Time that the east-west light is green
   int yellowEW;                      // Time that the east-west light is yellow
   double probNewVehicleN;            // Probability a new vehicle is generated northbound
   double probNewVehicleS;            // Probability a new vehicle is generated southbound
   double probNewVehicleE;            // Probability a new vehicle is generated eastbound
   double probNewVehicleW;            // Probability a new vehicle is generated westbound
   double proportionCars;             // Proportion of generated vehicles that are cars
   double proportionSUVs;             // Proportion of generated vehicles that are SUV
   double proprtionTrucks;            // Proportion of generated vehicles that are trucks
   double probRightCars;              // Probability a car turns right
   double probRightSUVs;              // Probability a SUV turns right
   double probRightTrucks;            // Probability a truck turns right
   double probLeftCars;               // Probability a car turns left
   double probLeftSUVs;               // Probability a SUV turns left
   double probLeftTrucks;             // Probability a truck turns left
   vector<Vehicle *> vehicles;
   char dummy;

public:
   // Constructors
   Game();
   Game(std::string filePath);
   ~Game();

   void generateVehicle(Road *r, vector<Vehicle *> *v, double directionProb, double probNewVehicle, double typeProb, double turnProb);
   void moveTraffic(vector<Vehicle *> &a);
   // Simulation running methods
   void run();
   void moveTraffic();
};
#endif
