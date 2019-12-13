#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <fstream>
#include <iostream>
#include "Animator.h"
#include "Game.h"
#include "string"
#include <random>
#include "IntersectionTile.h"
#include "Road.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Suv.h"



/*
 * Typical use constructor. Takes a properly formatted text file of values as input
 */
Game::Game(std::string filePath)
{
   seed = 8675309;
   std::cout << "Constructed using file!" << std::endl;

        std::ifstream infile;
        infile.open(filePath);

        if(!infile.is_open())
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
                 std::cout << maxSimTime << std::endl;
                 break;
              case 2:
                 numSectionsBeforeIntersection = static_cast<int>(d);
                 std::cout << numSectionsBeforeIntersection << std::endl;
                 break;
              case 3:
                 greenNS = static_cast<int>(d);
                 std::cout << greenNS << std::endl;
                 break;
              case 4:
                 yellowNS = static_cast<int>(d);
                 std::cout << yellowNS << std::endl;
                 break;
              case 5:
                 greenEW = static_cast<int>(d);
                 std::cout << greenEW << std::endl;
                 break;
              case 6:
                 yellowEW = static_cast<int>(d);
                 std::cout << yellowEW << std::endl;
                 break;
              case 7:
                 probNewVehicleN = d;
                 std::cout << probNewVehicleN << std::endl;
                 break;
              case 8:
                 probNewVehicleS = d;
                 std::cout << probNewVehicleS << std::endl;
                 break;
              case 9:
                 probNewVehicleE = d;
                 std::cout << probNewVehicleE << std::endl;
                 break;
              case 10:
                 probNewVehicleW = d;
                 std::cout << probNewVehicleW << std::endl;
                 break;
              case 11:
                 proportionCars = d;
                 std::cout << proportionCars << std::endl;
                 break;
              case 12:
                 proportionSUVs = d;
                 std::cout << proportionSUVs << std::endl;
                 break;
              case 13:
                 proprtionTrucks = d;
                 std::cout << proprtionTrucks << std::endl;
                 break;
              case 14:
                 probRightCars = d;
                 std::cout << probRightCars << std::endl;
                 break;
              case 15:
                 probRightSUVs = d;
                 std::cout << probRightSUVs << std::endl;
                 break;
              case 16:
                 probRightTrucks = d;
                 std::cout << probRightTrucks << std::endl;
                 break;
              case 17:
                 probLeftCars = d;
                 std::cout << probLeftCars << std::endl;
                 break;
              case 18:
                 probLeftSUVs = d;
                 std::cout << probLeftSUVs << std::endl;
                 break;
              case 19:
                 probLeftTrucks = d;
                 std::cout << probLeftTrucks << std::endl;
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

/*
 * Main run method, runs the game.
 */
void Game::run()
{
   std::cout << "The game is running..." << std::endl;

   // TODO: Construct instance of animator here

   Animator animator(numSectionsBeforeIntersection);

    // create four intersectionTile
   IntersectionTile it1;
   IntersectionTile it2;
   IntersectionTile it3;
   IntersectionTile it4;

   // creat roads
   Road northBoundRoad(numSectionsBeforeIntersection, &it4, &it2);
   Road southBoundRoad(numSectionsBeforeIntersection, &it1, &it3);
   Road eastBoundRoad(numSectionsBeforeIntersection, &it3, &it4);
   Road westBoundRoad(numSectionsBeforeIntersection, &it2, &it1);

   // Road *north = &northBoundRoad;
   // Road *south = &southBoundRoad;
   // Road *east = &eastBoundRoad;
   // Road *west = &westBoundRoad;


   // random number for dirction probability
   std::mt19937 rng(this->seed);
   double a = 0;  double b = 1.0;
   std::uniform_real_distribution<double> rand_double(a, b);
   double directionProb = rand_double(rng);
   generateDirections(directionProb,&westBoundRoad ,&eastBoundRoad , &southBoundRoad, &northBoundRoad);

   vector<VehicleBase *> westbound(numSectionsBeforeIntersection * 2 + 2, nullptr);
   vector<VehicleBase *> eastbound(numSectionsBeforeIntersection * 2 + 2, nullptr);
   vector<VehicleBase *> southbound(numSectionsBeforeIntersection * 2 + 2, nullptr);
   vector<VehicleBase *> northbound(numSectionsBeforeIntersection * 2 + 2, nullptr);

   animator.setLightNorthSouth(LightColor::red);
   animator.setLightEastWest(LightColor::green);

   animator.setVehiclesNorthbound(northbound);
   animator.setVehiclesSouthbound(southbound);
   animator.setVehiclesEastbound(easbound);
   animator.setVehiclesWestbound(westbound);

   int t = 0; // Counter for game
   while (t < this->maxSimTime)
   {
      animator.draw(t);

      //Update vehicles:
      moveTraffic();

      // TODO: Tell traffic light objects that time has passed

      // TODO: Handles operations for animator code.
      //       This includes setting the traffic light color
      //       and calling draw()

      animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
      animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
      animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
      animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

      t++;
   }
}

/*
 * Handles the movements by traffic done in one 'second' of time.
 */
void Game::moveTraffic()
{
   // Going to iterate through something here
   // What I'm thinking: something like...
   //
   // for each Vehicle v in for each Road:
   //    v.move()
   //
}


void Game:: generateDirections (double directionProb, Road *west, Road *east, Road *south, Road *north)
{
      Direction direction;

      if(directionProb<=probNewVehicleN)
     {
        direction = Direction::north;
        generateVehicles(north);


     }
     else if (directionProb <=probNewVehicleN+probNewVehicleS && directionProb >= probNewVehicleN)
     {
        direction = Direction::south;
        generateVehicles(south);
     }
     else if (directionProb <=probNewVehicleN+probNewVehicleS+ probNewVehicleE && directionProb >= probNewVehicleN+probNewVehicleS)
     {
        direction = Direction::east;
        generateVehicles (east);
     }
     else
     {
        direction = Direction::west;
        generateVehicles (west);
     }
}


void Game:: generateVehicles(Road *start)
{

      std::mt19937 rng(this->seed);
      double a = 0;  double b = 1.0;
      std::uniform_real_distribution<double> rand_double(a, b); //Generator randomnumber from 0-1
      double vehicletype = rand_double(rng);
      double directionProb = rand_double(rng);

      Direction direction;


      bool turnright;




      if(vehicletype<=proportionCars)
      {

         double turnornot = rand_double(rng);
         if(turnornot<=probRightCars)
         {
           Car a (direction,start->getQueueHead(),true);
         }
         else
         {
            Car a (direction, start->getQueueHead(), false);
         }
      }
      else if ((vehicletype > proportionCars) && (vehicletype<=proportionCars+proportionSUVs))
      {

         double turnornot = rand_double(rng);

         if (turnornot <= probLeftSUVs )
         {
            Suv a(direction,start->getQueueHead(), true);
         }
         else
         {
            Suv a(direction,start->getQueueHead(), false);
         }
      }
      else
      {

         double turnornot = rand_double(rng);

         if (turnornot <= probRightTrucks)
         {
            Truck a (direction,start->getQueueHead(),true);
         }
         else
         {
            Truck a (direction,start->getQueueHead(),false);
         }

      }




}

#endif
