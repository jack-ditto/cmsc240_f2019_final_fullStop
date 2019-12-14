EXECS = test
OBJS =  test.o Animator.o Vehicle.o VehicleBase.o Tile.o Road.o IntersectionTile.o Car.o Game.o  Suv.o TrafficLight.o Truck.o 

#### use next two lines for Mac
CC = clang++
CCFLAGS = -std=c++11 -stdlib=libc++ 

#### use next two lines for mathcs* machines:
#CC = g++
#CCFLAGS = -std=c++11

all: $(EXECS)

test: $(OBJS)
	$(CC)  $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
