#include "Animator.h"
#include "VehicleBase.h"
#include "Tile.h"
#include "Vehicle.h"
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Road.h"
#include "Car.h"
#include "Truck.h"
#include "Suv.h"

int main()
{
    int NUM_BEFORE_INTERSECTION = 7;

    // Create Animator object
    Animator animator(NUM_BEFORE_INTERSECTION);
    animator.setLightNorthSouth(LightColor::red);
    animator.setLightEastWest(LightColor::green);

    // Create traffic lights
    TrafficLight trafficLightNS(LightColor::red, 7, 3, 10);
    TrafficLight trafficLightEW(LightColor::green, 7, 3, 10);

    // Create 4 intersection tiles, labeled like this:
    //
    //      |----|----|
    //      |  1 | 2  |
    //      |---------|
    //      |  3 | 4  |
    //      |---------|

    // Create intersection tiles
    IntersectionTile it1(&trafficLightNS);
    IntersectionTile it2(&trafficLightEW);
    IntersectionTile it3(&trafficLightEW);
    IntersectionTile it4(&trafficLightNS);

    // Create Roads
    Road northBoundRoad(NUM_BEFORE_INTERSECTION, &it4, &it2, Direction::north);
    Road southBoundRoad(NUM_BEFORE_INTERSECTION, &it1, &it3, Direction::south);
    Road eastBoundRoad(NUM_BEFORE_INTERSECTION, &it3, &it4, Direction::east);
    Road westBoundRoad(NUM_BEFORE_INTERSECTION, &it2, &it1, Direction::west);

    // Set roads initially for animator
    animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
    animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
    animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
    animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

    // Manually create Vehicles
    Truck v1(Direction::east, false);
    Car v2(Direction::north, true);
    Suv v3(Direction::south, false);
    Truck v4(Direction::west, true);

    // Add vehicles to a vector
    vector<Vehicle *> vehiclesVector;
    vehiclesVector.push_back(&v1);
    vehiclesVector.push_back(&v2);
    vehiclesVector.push_back(&v3);
    vehiclesVector.push_back(&v4);

    v1.enterRoad(eastBoundRoad.getQueueHead());
    v2.enterRoad(northBoundRoad.getQueueHead());
    v3.enterRoad(southBoundRoad.getQueueHead());
    v4.enterRoad(westBoundRoad.getQueueHead());

    for (int i = 0; i < 100; i++)
    {

        // Update roads for animator
        animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
        animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
        animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
        animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

        // Update trafficlights for animator
        animator.setLightEastWest(trafficLightEW.getColor());
        animator.setLightNorthSouth(trafficLightNS.getColor());

        // draw the board
        animator.draw(i);

        // wait for user to press enter
        std::cin.ignore();

        for (int i = 0; i < vehiclesVector.size(); i++)
        {
            vehiclesVector[i]->move();
        }

        // Tell traffic lights that time has passed
        trafficLightEW.decrement();
        trafficLightNS.decrement();
    };
}