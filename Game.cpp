#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <iostream>
#include "Game.h"
#include "string"



/*
 * Typical use constructor. Takes a properly formatted text file of values as input
 */
Game::Game(std::string filePath) 
{
   // Do stuff to parse info from file in practice...
   std::cout << "Constructed using file!" << std::endl;
}

/*
 * Default constructor. Use default values for testing.
 */
Game::Game() 
{
   // This is the place to initialize all the values we need for the game...
   this->totalTime = 15;

   std::cout << "Constructed using default constructor!" << std::endl;
}


/*
 * Main run method, runs the game.
 */
void Game::run()
{
   std::cout << "The game is running..." << std::endl;
   
   
   int t = 0; // Counter for game
   while (t < this->totalTime)
   {
      // Game logic:
      moveTraffic(); 
      
      // Tell traffic light objects that time has passed
      // Something like...
      //
      // this->trafficLightOne.simSec()
      // this->trafficLightTwo.simSec()
      //
      // Open to suggestions about a better way to do this.

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