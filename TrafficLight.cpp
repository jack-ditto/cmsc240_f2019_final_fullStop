#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include <iostream>
#include "TrafficLight.h"
#include "VehicleBase.h"

//Typical Use Constructor
TrafficLight::TrafficLight(LightColor light, int g, int y, int r)
{
  lightColor = light;
  timeGreen = g;
  timeYellow = y;
  timeRed = r;

  if (light == LightColor::green)
  {
    timeTilChange = timeGreen;
  }
  else if (light == LightColor::yellow) //should never start yellow
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

LightColor TrafficLight::getColor()
{
  return lightColor;
}

LightColor TrafficLight::setColor(LightColor col)
{
  if (col == LightColor::green)
  {
    timeTilChange = timeGreen;
  }
  else if (col == LightColor::yellow)
  {
    timeTilChange = timeYellow;
  }
  else
  {
    timeTilChange = timeRed;
  }

  LightColor old = lightColor;
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
    if (lightColor == LightColor::green)
    {
      lightColor = LightColor::yellow;
      timeTilChange = timeYellow;
    }

    else if (lightColor == LightColor::yellow)
    {
      lightColor = LightColor::red;
      timeTilChange = timeRed;
    }

    else
    {
      lightColor = LightColor::green;
      timeTilChange = timeGreen;
    }
  }
}

#endif
