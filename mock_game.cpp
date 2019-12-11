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

int main()
{
    int NUM_BEFORE_INTERSECTION = 7;

    // westbound, easbound, southbound, and northbound
    vector<VehicleBase *> westbound(NUM_BEFORE_INTERSECTION * 2 + 2, nullptr);
    vector<VehicleBase *> eastbound(NUM_BEFORE_INTERSECTION * 2 + 2, nullptr);
    vector<VehicleBase *> southbound(NUM_BEFORE_INTERSECTION * 2 + 2, nullptr);
    vector<VehicleBase *> northbound(NUM_BEFORE_INTERSECTION * 2 + 2, nullptr);

    // Create Animator object
    Animator animator(NUM_BEFORE_INTERSECTION);
    animator.setLightNorthSouth(LightColor::red);
    animator.setLightEastWest(LightColor::green);

    animator.setVehiclesEastbound(eastbound);
    animator.setVehiclesWestbound(westbound);
    animator.setVehiclesSouthbound(southbound);
    animator.setVehiclesNorthbound(northbound);

    // Create 4 intersection tiles, labeled like this:
    //
    //      |----|----|
    //      |  1 | 2  |
    //      |---------|
    //      |  3 | 4  |
    //      |---------|

    IntersectionTile it1;
    IntersectionTile it2;
    IntersectionTile it3;
    IntersectionTile it4;

    // Create Road object, 5 tiles before Intersection and 5 after
    Road northBoundRoad(NUM_BEFORE_INTERSECTION, &it4, &it2);
    Road southBoundRoad(NUM_BEFORE_INTERSECTION, &it1, &it3);
    Road eastBoundRoad(NUM_BEFORE_INTERSECTION, &it3, &it4);
    Road westBoundRoad(NUM_BEFORE_INTERSECTION, &it2, &it1);

    // Decide whether to spawn a Vehicle on a road, put it in the 'invisible' part of Road
    Car v1(Direction::north, northBoundRoad.getQueueHead(), false);
    Truck v2(Direction::west, westBoundRoad.getQueueHead(), false);

    // std::cout << v1.getLength() << std::endl;

    for (int i = 0; i < 100; i++)
    {
        std::cin.ignore();
        // system("clear");
        v1.move();
        v2.move();

        animator.setVehiclesEastbound(eastBoundRoad.getRoadSnapshot());
        animator.setVehiclesWestbound(westBoundRoad.getRoadSnapshot());
        animator.setVehiclesSouthbound(southBoundRoad.getRoadSnapshot());
        animator.setVehiclesNorthbound(northBoundRoad.getRoadSnapshot());

        animator.draw(i);
    };
}