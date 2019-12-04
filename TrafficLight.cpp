#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include <iostream>
#include "TrafficLight.h"

//Typical Use Constructor
TrafficLight::TrafficLight(Color light, int green, int yellow, int red)
{
  std::cout << "in typical use constructor" << std::endl;
  lightColor = light;
  timeGreen  = green;
  timeYellow = yellow;
  timeRed    = red;

  if(light == GREEN)
  {
    timeTilChange = timeGreen;
  }
  else if(light == YELLOW)    //should never start yellow
  {
    timeTilChange = timeYellow;
  }
  else
  {
    timeTilChange = timeRed;
  }
}

//Copy constructor
TrafficLight::TrafficLight(const TrafficLight& other)
{
  std::cout << "in copy constructor" << std::endl;
  lightColor = other.lightColor;
  timeGreen = other.timeGreen;
  timeYellow = other.timeYellow;
  timeRed = other.timeRed;
  timeTilChange = other.timeTilChange;
}

//Destructor
TrafficLight::~TrafficLight(){}

Color TrafficLight::getColor()
{
  return lightColor;
}

Color TrafficLight::setColor(Color col)
{
  if(col == GREEN)
  {
    timeTilChange = timeGreen;
  }
  else if(col == YELLOW)
  {
    timeTilChange = timeYellow;
  }
  else
  {
    timeTilChange = timeRed;
  }

  Color old = lightColor;
  lightColor = col;
  return old;
}

int TrafficLight::getTimeGreen()
{
  return timeGreen;
}

int TrafficLight::getTimeYellow()
{
  return timeYellow;
}

int TrafficLight::getTimeRed()
{
  return timeRed;
}

int TrafficLight::getTimeTilChange()
{
  return timeTilChange;
}
void TrafficLight::decrement()
{
  timeTilChange--;

  if(timeTilChange == 0)
  {
    if(lightColor == GREEN)
    {
      lightColor = YELLOW;
      timeTilChange = timeYellow;
    }

    else if(lightColor == YELLOW)
    {
      lightColor = RED;
      timeTilChange = timeRed;
    }

  else
    {
      lightColor = GREEN;
      timeTilChange = timeGreen;
    }
  }
}

/*
int main()
{
  TrafficLight t1(RED,1,2,3);
  TrafficLight t2(t1);

  std::cout << t1.setColor(GREEN) << std::endl;
  std::cout << t1.getColor() << std::endl;
  std::cout << t2.getColor() << std::endl;

  std::cout << t1.getTimeRed() << std::endl;
  std::cout << t1.getTimeTilChange() << std::endl;

  t1.decrement();

  std::cout << t1.getColor() << std::endl;
  std::cout << t1.getTimeTilChange() << std::endl << std::endl;

  t1.decrement();
  t1.decrement();

  std::cout << t1.getColor() << std::endl;
  std::cout << t1.getTimeTilChange() << std::endl << std::endl;

  t1.decrement();
  t1.decrement();
  t1.decrement();

  std::cout << t1.getColor() << std::endl;
  std::cout << t1.getTimeTilChange() << std::endl;

  return 0;
}
*/

#endif
