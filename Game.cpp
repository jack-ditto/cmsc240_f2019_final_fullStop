#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <iostream>
#include <fstream>
#include "Game.h"
#include "string"

/*
 * Typical use constructor. Takes a properly formatted text file of values as input
 */
Game::Game(std::string filePath)
{
   std::cout << "Constructed using file!" << std::endl;

        std::ifstream infile;
        infile.open(filePath);

        if(!infile.is_open())
        {
          std::cerr << "Error opening file: " << filePath << std::endl;
        }

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

   int t = 0; // Counter for game
   while (t < this->maxSimTime)
   {
      // Game logic:
      moveTraffic();

      // TODO: Tell traffic light objects that time has passed

      // TODO: Handles operations for animator code.
      //       This includes setting the traffic light color
      //       and calling draw()

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

#endif
