# cmsc240_f2019_final_fullStop
CMSC 240 F2019 Traffic Simulation Project
Group Members: Jack Ditto, Jing Dong, Rachel Morris

Design Decisions:
  Vehicles: (Primary Classes: VehicleBase, Vehicle, Car, SUV, Truck)
    VehicleBase:

    Vehicle: (Inherits from VehicleBase)

    Car: (Inherits from Vehicle and by extension VehicleBase)
      Cars are vehicles that have length 2.

    SUV: (Inherits from Vehicle and by extension VehicleBase)
      SUVs are vehicles that have length 3.

    Truck: (Inherits from Vehicle and by extension VehicleBase)
      Trucks are vehicles that have length 4.

  Road Construction: (Primary Classes: Tile, IntersectionTile, Road, TrafficLight)
    Tile:
      Tiles have references to both the previous and the next tile (like in a double-linked list). Additionally, all tiles know if there is a vehicle occupying it and store a pointer to that vehicle. Methods allow for both the boolean isOccupied to be returned as for the reference to the vehicle itself.

    IntersectionTile: (Inherits from Tile)
      IntersectionTiles contain pointers to four tiles (north, south, east, west) instead of just the previous and the next. Additionally, IntersectionTiles store a reference to the appropriate TrafficLight so that Vehicles can determine whether they can move via the IntersectionTile.

    Road:

    TrafficLight:

    Constructing roads depends on tiles.  Additionally, IntersectionTile which inherits from Tile has references to four tiles (north, south, east, west).

  Game: (Combines all Vehicle and Road related classes to perform the simulation)
