#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <fstream>
#include <iostream>
#include <random>

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

   Animator animator(numSectionsBeforeIntersection);

   // create two traffic lights
   TrafficLight lightNS(LightColor::green,greenNS,yellowNS,greenEW+yellowEW);
   TrafficLight lightEW(LightColor::red,greenEW,yellowEW,greenNS+yellowNS);

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

   // TODO: vehicle vector

   int t = 0; // Counter for game
   while (t < this->maxSimTime)
   {
     //Set up animation
     animator.setLightNorthSouth(lightNS.getColor());
     animator.setLightEastWest(lightEW.getColor());

     animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
     animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
     animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
     animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

     animator.draw(t);

     //Update vehicles:
     generateDirections(&westBoundRoad ,&eastBoundRoad , &southBoundRoad, &northBoundRoad);
     moveTraffic();

     //Increment time: traffic light and for game
     lightNS.decrement();
     lightEW.decrement();

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


void Game:: generateDirections(Road *west, Road *east, Road *south, Road *north)
{

      Direction direction;

      std::mt19937 rng(this->seed);
      double a = 0;  double b = 1.0;
      std::uniform_real_distribution<double> rand_double(a, b);

      double directionProb = rand_double(rng);

      cout << "The number of diretion probability for north should be " << directionProb << endl;
      if(directionProb<=probNewVehicleN)
     {

        generateVehicles(Direction::north);
        cout << "It havs generated a vehicle in the north lane " << endl;


     }
      directionProb = rand_double(rng);

       cout << "The number of diretion probability for south should be " << directionProb << endl;



     if (directionProb <=probNewVehicleN+probNewVehicleS && directionProb >= probNewVehicleN)
     {

        generateVehicles(Direction::south);
          cout << "It havs generated a vehicle in the south lane " << endl;
     }

      directionProb = rand_double(rng);

      cout << "The number of diretion probability for east should be " << directionProb << endl;

     if(directionProb <=probNewVehicleN+probNewVehicleS + probNewVehicleE && directionProb >= probNewVehicleN+probNewVehicleS)
     {

        generateVehicles (Direction::east);
        cout << "It havs generated a vehicle in the east lane " << endl;
     }

     directionProb = rand_double(rng);

   cout << "The number of diretion probability for west should be " << directionProb << endl;

     if(directionProb <=1 && directionProb >= probNewVehicleN+probNewVehicleS+probNewVehicleE)
     {

        generateVehicles (Direction::west);
        cout << "It havs generated a vehicle in the west lane " << endl;
     }
}


void Game:: generateVehicles(Direction direction)
{

      std::mt19937 rng(this->seed);
      double a = 0;  double b = 1.0;
      std::uniform_real_distribution<double> rand_double(a, b); //Generator randomnumber from 0-1
      double vehicletype = rand_double(rng);
      double directionProb = rand_double(rng);




      bool turnright;




      if(vehicletype<=proportionCars)
      {

         double turnornot = rand_double(rng);

         cout << "The probability of turn to the right or not should be " << turnornot << endl;
         if(turnornot<=probRightCars)
         {
           Car a (direction,true);

           cout << "Test" << "It's car with right turn" << endl;
         }
         else
         {
            Car a (direction, false);
            cout << "Test" << "It's a car with straight road" <<endl;

         }
      }
      else if ((vehicletype > proportionCars) && (vehicletype<=proportionCars+proportionSUVs))
      {

         double turnornot = rand_double(rng);

         if (turnornot <= probLeftSUVs )
         {

            cout << "Test" << "It's SUV with right turn" << endl;
            Suv a(direction,true);
         }
         else
         {
            cout << "Test" << "It's a SUV with straight road" <<endl;
            Suv a(direction,false);
         }
      }
      else
      {

         double turnornot = rand_double(rng);

         if (turnornot <= probRightTrucks)
         {
            cout << "Test" << "It's a truck with right turn" << endl;
            Truck a (direction,true);
         }
         else
         {
            cout << "Test" << "It's a truck with straight road" <<endl;

            Truck a (direction,false);
         }

      }




}

#endif
