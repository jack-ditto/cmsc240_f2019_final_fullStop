#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <fstream>
#include <iostream>
#include <random>
#include <iterator>

#include "Animator.h"
#include "Car.h"
#include "Game.h"
#include "IntersectionTile.h"
#include "Road.h"
#include "string"
#include "Suv.h"
#include "TrafficLight.h"
#include "Truck.h"
#include "Vehicle.h"
using namespace std;

/*
 * Typical use constructor. Takes a properly formatted text file of values as input
 */
Game::Game(std::string filePath)
{
   seed = 8675309;
   std::cout << "Constructed using file!" << std::endl;

   std::ifstream infile;
   infile.open(filePath);

   if (!infile.is_open())
   {
      std::cerr << "Error opening file: " << filePath << std::endl;
   }

   std::string temp;
   double d;
   int count = 0;

   while (infile.good())
   {
      infile >> temp;
      infile >> d;
      count++;

      if (infile.fail())
      {
         if (infile.eof())
         {
            break;
         }
         else
         {
            std::cerr << "Error reading the input." << std::endl;
         }
      }
      else
      {
         switch (count)
         {
         case 1:
            maxSimTime = static_cast<int>(d);
            break;
         case 2:
            numSectionsBeforeIntersection = static_cast<int>(d);
            break;
         case 3:
            greenNS = static_cast<int>(d);
            break;
         case 4:
            yellowNS = static_cast<int>(d);
            break;
         case 5:
            greenEW = static_cast<int>(d);
            break;
         case 6:
            yellowEW = static_cast<int>(d);
            break;
         case 7:
            probNewVehicleN = d;
            break;
         case 8:
            probNewVehicleS = d;
            break;
         case 9:
            probNewVehicleE = d;
            break;
         case 10:
            probNewVehicleW = d;
            break;
         case 11:
            proportionCars = d;
            break;
         case 12:
            proportionSUVs = d;
            break;
         case 13:
            probRightCars = d;
            break;
         case 14:
            probLeftCars = d;
            break;
         case 15:
            probRightSUVs = d;
            break;
         case 16:
            probLeftSUVs = d;
            break;
         case 17:
            probRightTrucks = d;
            break;
         case 18:
            probLeftTrucks = d;
            break;
         default: // code to be executed if n doesn't match any cases
            std::cerr << "Error executing cases." << std::endl;
            break;
         }
      }
   }

   infile.close();
}

/*
 * Default constructor. Use default values for testing.
 */
Game::Game()
{
   // This is the place to initialize all the values we need for the game...
   this->maxSimTime = 15;

   std::cout << "Constructed using default constructor!" << std::endl;
}

Game::~Game()
{
   for (int i = 0; i < this->vehicles.size(); i++)
   {
      delete this->vehicles[i];
   }
   this->vehicles.clear();
}

/*
 * Main run method, runs the game.
 */
void Game::run()
{
   std::cout << "The game is running..." << std::endl;

   Animator animator(numSectionsBeforeIntersection);

   // create two traffic lights
   TrafficLight lightNS(LightColor::green, greenNS, yellowNS, greenEW + yellowEW);
   TrafficLight lightEW(LightColor::red, greenEW, yellowEW, greenNS + yellowNS);

   // create four intersectionTiles
   IntersectionTile it1(&lightNS);
   IntersectionTile it2(&lightEW);
   IntersectionTile it3(&lightEW);
   IntersectionTile it4(&lightNS);

   // create roads
   Road northBoundRoad(numSectionsBeforeIntersection, &it4, &it2, Direction::north);
   Road southBoundRoad(numSectionsBeforeIntersection, &it1, &it3, Direction::south);
   Road eastBoundRoad(numSectionsBeforeIntersection, &it3, &it4, Direction::east);
   Road westBoundRoad(numSectionsBeforeIntersection, &it2, &it1, Direction::west);

   animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
   animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
   animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
   animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

   // to do create generate vehicle,add to road

   std::mt19937 rng(this->seed);
   double a = 0;
   double b = 1.0;
   std::uniform_real_distribution<double> rand_double(a, b);
   double directionProb;
   double vehicleProb;
   double turnOrNot;

   // Vector to store the vehicles on the road

   int t = 0; // Counter for game

   while (t <= this->maxSimTime)
   {

      // update vehicles
      directionProb = rand_double(rng);
      vehicleProb = rand_double(rng);
      turnOrNot = rand_double(rng);
      generateVehicle(&northBoundRoad, &vehicles, directionProb, probNewVehicleN, vehicleProb, turnOrNot); //north

      directionProb = rand_double(rng);
      vehicleProb = rand_double(rng);
      turnOrNot = rand_double(rng);
      generateVehicle(&southBoundRoad, &vehicles, directionProb, probNewVehicleS, vehicleProb, turnOrNot); //south

      directionProb = rand_double(rng);
      vehicleProb = rand_double(rng);
      turnOrNot = rand_double(rng);
      generateVehicle(&eastBoundRoad, &vehicles, directionProb, probNewVehicleE, vehicleProb, turnOrNot); //east

      directionProb = rand_double(rng);
      vehicleProb = rand_double(rng);
      turnOrNot = rand_double(rng);
      generateVehicle(&westBoundRoad, &vehicles, directionProb, probNewVehicleW, vehicleProb, turnOrNot); //west

      //Set up animation
      animator.setLightNorthSouth(lightNS.getColor());
      animator.setLightEastWest(lightEW.getColor());

      animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
      animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
      animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
      animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

      animator.draw(t);
      std::cin.get(dummy);

      moveTraffic(vehicles); //updated

      //Increment time: traffic light and for game
      lightNS.decrement();
      lightEW.decrement();

      t++;
   }
}

/*
 * Handles the movements by traffic done in one 'second' of time.
 */
void Game::moveTraffic(vector<Vehicle *> &a)
{

   if (a.size() != 0)
   {

      for (int i = 0; i < a.size(); i++)
      {
         if (a[i]->hasReachedEndOfRoad())
         {
            a.erase(a.begin() + i);
         }
      }

      for (int i = 0; i < a.size(); i++)
      {
         a[i]->move();
      }
   }
}

void Game::generateVehicle(Road *r, vector<Vehicle *> *v, double directionProb, double probNewVehicle, double typeProb, double turnProb)
{

   // The direction of the road
   Direction direction = r->getDirection();

   // Make sure there is space to spawn a vehicle
   if (r->canSpawnVehicle())
   {
      if (directionProb <= probNewVehicle)
      {
         if (typeProb <= proportionCars)
         {
            if (turnProb <= probRightCars)
            {
               Car *a = new Car(direction, true);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }

            else
            {
               Car *a = new Car(direction, false);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }
         }

         else if ((typeProb > proportionCars) && (typeProb <= proportionCars + proportionSUVs))
         {

            if (turnProb <= probRightSUVs)
            {
               Suv *a = new Suv(direction, true);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }

            else
            {
               Suv *a = new Suv(direction, false);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }
         }

         else
         {
            if (turnProb <= probRightTrucks)
            {
               Truck *a = new Truck(direction, true);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }

            else
            {
               Truck *a = new Truck(direction, false);
               a->enterRoad(r->getQueueHead());
               v->push_back(a);
            }
         }
      }
   }
}
#endif
