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

    animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
    animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
    animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
    animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

   // to do create generate vehicle,add to road 

   std::mt19937 rng(this->seed);
   double a = 0;  double b = 1.0;
   std::uniform_real_distribution<double> rand_double(a, b);
   double directionProb;
   double vehicleProb;
   double turnOrNot;

   vector<Vehicle*> vehicles;

   // Vector to store the vehicles on the road 


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
     std::cin.ignore();
 


   // update vehicles 
   directionProb = rand_double(rng);
   vehicleProb = rand_double(rng);
   turnOrNot = rand_double(rng);
 
   generateDirections(&northBoundRoad,vehicles, directionProb,probNewVehicleN,vehicleProb,turnOrNot); //north

   directionProb = rand_double(rng);
   vehicleProb = rand_double(rng);
   turnOrNot = rand_double(rng);
  generateDirections(&southBoundRoad,vehicles, directionProb,probNewVehicleS,vehicleProb,turnOrNot);//south
   
   directionProb = rand_double(rng);
   vehicleProb = rand_double(rng);
   turnOrNot = rand_double(rng);

   generateDirections(&eastBoundRoad, vehicles, directionProb,probNewVehicleE,vehicleProb,turnOrNot); //east

   directionProb = rand_double(rng);
   vehicleProb = rand_double(rng);
   turnOrNot = rand_double(rng);
  
   generateDirections(&westBoundRoad, vehicles, directionProb, probNewVehicleW, vehicleProb,turnOrNot); //west

  
   
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
void Game::moveTraffic(vector<Vehicle*> &a)
{
  
   for (int i =0; i<a.size(); i++)
   { 
      
      
      Vehicle* temp = a[i];
     
   
      if (temp->isOutOfBound())  
      {  
         
          delete a[i];
      }

      else
      {
         
       
         temp->move(); // problem 
        
       
      }
      

   }

}


void Game:: generateDirections(Road *r, vector<Vehicle*> &v, double directionprob, double probNewVehicle, double vehicletype, double turnornot)
{
   Road temp = *r;
   Direction direction =temp.getDirection();
  
   
   if (temp.canSpawnVehicle()){
   if(direction == Direction::north){
   cout << "the direction now should be " << "north" << endl;
   }
   else if (direction == Direction::south)
   {
      cout << "direction now should be " << "south" << endl;
   }
   else if (direction == Direction::east)
   {
      cout << "direction now should be " << "east" << endl;
   }
   else
   {
      cout << "direction now should be " << "west" << endl;
   }
   
   
   
      

     
      if(directionprob<=probNewVehicle)
     {

         bool turnright = false;




      if(vehicletype<=proportionCars)
      {

      
         cout << "The probability of turn to the right or not should be " << turnornot << endl;
         if(turnornot<=probRightCars)
         {
           Car a (direction,true);
           a.enterRoad(r->getQueueHead());
           v.push_back(&a);
         

           cout << "Test" << "It's car with right turn" << endl;
         }
         else
         {
            Car a (direction, false);
            a.enterRoad(r->getQueueHead());
            v.push_back(&a);
            cout << "Test" << "It's a car with straight road" <<endl;

         }
      }
      else if ((vehicletype > proportionCars) && (vehicletype<=proportionCars+proportionSUVs))
      {

         //double turnornot = rand_double(rng);

         if (turnornot <= probLeftSUVs )
         {

            cout << "Test" << "It's SUV with right turn" << endl;
            Suv a(direction,true);
            Suv* addy = &a;
            a.enterRoad(r->getQueueHead());
            v.push_back(&a);
         }
         else
         {
            cout << "Test" << "It's a SUV with straight road" <<endl;
            Suv a(direction,false);
            a.enterRoad(r->getQueueHead());
             v.push_back(&a);
         }
      }
      else
      {

        

         if (turnornot <= probRightTrucks)
         {
            cout << "Test" << "It's a truck with right turn" << endl;
            Truck a (direction,true);
             a.enterRoad(r->getQueueHead());
             v.push_back(&a);
         }
         else
         {
            cout << "Test" << "It's a truck with straight road" <<endl;

            Truck a (direction,false);
             a.enterRoad(r->getQueueHead());
             v.push_back(&a);
         }

        
         
      }


       

    

         
      }

     }
   
}
#endif
