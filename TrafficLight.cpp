#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include <iostream>
#include "TrafficLight.h"

//Typical Use Constructor
TrafficLight::TrafficLight(Color light, int green, int yellow, int red)
{
  lightColor = light;
  timeGreen = green;
  timeYellow = yellow;
  timeRed = red;

  if (light == GREEN)
  {
    timeTilChange = timeGreen;
  }
  else if (light == YELLOW) //should never start yellow
  {
    timeTilChange = timeYellow;
  }
  else
  {
    timeTilChange = timeRed;
  }
}

//Copy constructor
TrafficLight::TrafficLight(const TrafficLight &other)
{
  lightColor = other.lightColor;
  timeGreen = other.timeGreen;
  timeYellow = other.timeYellow;
  timeRed = other.timeRed;
  timeTilChange = other.timeTilChange;
}

//Destructor
TrafficLight::~TrafficLight() {}

Color TrafficLight::getColor()
{
  return lightColor;
}

Color TrafficLight::setColor(Color col)
{
  if (col == GREEN)
  {
    timeTilChange = timeGreen;
  }
  else if (col == YELLOW)
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

  if (timeTilChange == 0)
  {
    if (lightColor == GREEN)
    {
      lightColor = YELLOW;
      timeTilChange = timeYellow;
    }

    else if (lightColor == YELLOW)
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

#endif
