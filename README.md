# cmsc240_f2019_final_fullStop
CMSC 240 F2019 Traffic Simulation Project

Group Members: Jack Ditto, Jing Dong, Rachel Morris

**Directions for Compiling:** Classes required: Animator.* Vehicle.* VehicleBase.* Tile.* Road.* IntersectionTile.* Car.* Game.* Suv.* TrafficLight.* Truck.*

If compiling on a Mac, call make. If compiling on a Windows system, use the appropriate lines which are commented out in the Makefile, comment out Mac lines, and then call make. The resulting executable is called test, so call ./test to run the traffic simulation. Then to step through the simulation, press enter.

**Design Decisions:**
  * Vehicles: (Primary Classes: Vehicle, Car, SUV, Truck)
    1. Vehicle: (Inherits from VehicleBase)

         Vehicles store their length, their type, their direction, whether they turn right, and pointers to the first and last Tile they occupy.

         Methods:

            1. Getters for length and the current direction

            2. Setters for current direction and occupied (which makes Tiles in the Road as occupied)

            3. EnterRoad: lets the Vehicle enter the road with the head on the road and the tail on the invisible Tiles.

            4. MoveForward: moves the pointers for the head and tail up one and updates which Tiles are occupied

            5. Move: handles logic for whether a Vehicle can move (i.e. stop if TrafficLight is red and next Tile is and IntersectionTile) and then appropriately calls the moveForward or turnRight method. Finally, when the Vehicle is at the end of the Road, move sets the Tiles it currently occupies to unoccupied.

            6. TurnRight: the head or tail is moved right if it is on an IntersectionTile or both the head and the tail are moved forward. A boolean isTurningRight keeps track of whether the Vehicle is currently in the process of a right turn.

            7. CanTurnRight: Implements the logic for whether a Vehicle can turn right. If green it is always true. If red, the Vehicle can only turn right if there is enough space.

    2. Car: (Inherits from Vehicle and by extension VehicleBase)

         Cars are Vehicles that have length 2.

    3. SUV: (Inherits from Vehicle and by extension VehicleBase)

         SUVs are Vehicles that have length 3.

    4. Truck: (Inherits from Vehicle and by extension VehicleBase)

         Trucks are Vehicles that have length 4.

  * Road Construction: (Primary Classes: Tile, IntersectionTile, Road, TrafficLight)
    1. Tile:

         Tiles have references to both the previous and the next Tile (like in a double-linked list). Additionally, all Tiles know if there is a vehicle occupying it and store a pointer to that vehicle. Methods allow for both the boolean isOccupied to be returned as for the reference to the Vehicle itself.

    2. IntersectionTile: (Inherits from Tile)

         IntersectionTiles contain pointers to four Tiles (north, south, east, west) instead of just the previous and the next. Additionally, IntersectionTiles store a reference to the appropriate TrafficLight so that Vehicles can determine whether they can move via the IntersectionTile.

    3. Road:

         Road is constructed via a vector if Tiles and IntersectionTiles that are linked together as described above for a single direction. The snapshot method returns a vector of VehicleBase pointers describing which Tiles are occupied.

    4. TrafficLight:

         TrafficLight stores its current color and length of time that the light is green, yellow, and red as well as how much time is left until the light changes. The methods for TrafficLight allow the color to be set and for all data members to be accessed. Additionally, there is a method decrement that updates the time until the light changes color and changes the color if necessary.

  * Game: (Combines all Vehicle and Road related classes to perform the simulation)

    * Constructor: Constructing an instance of Game requires a string of the path of the input file. Then, using that file, the initial values of the instance variables are read and then assigned. Additionally, the seed is set to 8675309.

    * Destructor: Vehicles are dynamically allocated when they are generated, so all remaining vehicles in the simulation must be deleted.

    * Run: This is the primary method for our simulation. Instances of Animator, TrafficLight, IntersectionTile, and Road are generated. Additionally, our random number generator is created. Then, we have a while loop that first updates the animation, then generates new vehicles, and moves traffic, and finally updates the traffic light and game "clock." This while loop runs until the simulation time has reached the maximum simulation time.

    * MoveTraffic: For our vector of Vehicle pointers, every Vehicle is either deleted if its tail pointer has reached the end of the road or it is moved by the Vehicle move method.

    * GenerateVehicles: For a given road, generateVehicles determines whether a new Vehicle is to be spawned in that direction, if so what type of Vehicle, and finally if it turns right. These decisions are made by comparing a randomly generated in [0,1] to the proportions defined by the input file.
