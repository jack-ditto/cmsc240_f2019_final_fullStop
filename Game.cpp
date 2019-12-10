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
   // Do stuff to parse info from file in practice...
   std::cout << "Constructed using file!" << std::endl;

   std::ifstream infile;
   infile.open(fillePath);

   if(!infile.is_open())
   {
     std::cerr << "Error opening file: " << filePath << std::endl;
   }

   int count = 0;

   while (infile.good())
   {
     infile >> str;
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
            maxSimTime = str;
            break;
         case 2:
            numSectionsBeforeIntersection = str;
            break;
         case 3:
            greenNS = str;
            break;
         case 4:
            yellowNS = str;
            break;
         case 5:
            greenEW = str;
            break;
         case 6:
            yellowEW = str;
            break;
         case 7:
            probNewVehicleN = str;
            break;
         case 8:
            probNewVehicleS = str;
            break;
         case 9:
            probNewVehicleE = str;
            break;
         case 10:
            probNewVehicleW = str;
            break;
         case 11:
            proportionCars = str;
            break;
         case 12:
            proportionSUVs = str;
            break;
         case 13:
            proprtionTrucks = str;
            break;
         case 14:
            probRightCars = str;
            break;
         case 15:
            probRightSUVs = str;
            break;
         case 16:
            probRightTrucks = str;
            break;
         case 17:
            probLeftCars = str;
            break;
         case 18:
            probLeftSUVs = str;
            break;
         case 19:
            probLeftTrucks = str;
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
