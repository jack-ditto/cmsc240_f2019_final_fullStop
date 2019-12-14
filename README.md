# cmsc240_f2019_final_fullStop
CMSC 240 F2019 Traffic Simulation Project
Group Members: Jack Ditto, Jing Dong, Rachel Morris

Directions for Compiling: [TODO: when it compiles]

Design Decisions:
  * Vehicles: (Primary Classes: VehicleBase, Vehicle, Car, SUV, Truck)
    1. VehicleBase: [INSERT EDITS TO VEHICLEBASE OR DELETE HERE AND VEHICLEBASE ON LINE ABOVE]

    2. Vehicle: (Inherits from VehicleBase)
         Vehicles store their length, pointers to the first and last tile they occupy. The set of "action" methods in Vehicle handle the Vehicle's movement (moving forward, turning right, and entering the road). These methods update whether a Tile isOccupied in order to connect with the Road.

    3. Car: (Inherits from Vehicle and by extension VehicleBase)
         Cars are vehicles that have length 2.

    4. SUV: (Inherits from Vehicle and by extension VehicleBase)
         SUVs are vehicles that have length 3.

    5. Truck: (Inherits from Vehicle and by extension VehicleBase)
         Trucks are vehicles that have length 4.

  * Road Construction: (Primary Classes: Tile, IntersectionTile, Road, TrafficLight)
    1. Tile:
         Tiles have references to both the previous and the next tile (like in a double-linked list). Additionally, all tiles know if there is a vehicle occupying it and store a pointer to that vehicle. Methods allow for both the boolean isOccupied to be returned as for the reference to the vehicle itself.

    2. IntersectionTile: (Inherits from Tile)
         IntersectionTiles contain pointers to four tiles (north, south, east, west) instead of just the previous and the next. Additionally, IntersectionTiles store a reference to the appropriate TrafficLight so that Vehicles can determine whether they can move via the IntersectionTile.

    3. Road:
         Road is constructed via a vector if Tiles and IntersectionTiles that are linked together as described above for a single direction. The snapshot method returns a vector of VehicleBase pointers describing which tiles are occupied.

    4. TrafficLight:
         TrafficLight stores its current color and length of time that the light is green, yellow, and red as well as how much time is left until the light changes. The methods for TrafficLight allow the color to be set and for all data members to be accessed. Additionally, there is a method decrement that updates the time until the light changes color and changes the color if necessary.

  * Game: (Combines all Vehicle and Road related classes to perform the simulation)
    [TODO: when it compiles]
