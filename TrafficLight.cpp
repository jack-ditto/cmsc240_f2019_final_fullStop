#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include <iostream>
#include "TrafficLight.h"
#include "VehicleBase.h"

/**
 * Typical use constructor
 */
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
  else if (light == LightColor::yellow)
  {
    timeTilChange = timeYellow;
  }
  else
  {
    timeTilChange = timeRed;
  }
}

/**
 * Copy constructor
 */
TrafficLight::TrafficLight(const TrafficLight &other)
{
  lightColor = other.lightColor;
  timeGreen = other.timeGreen;
  timeYellow = other.timeYellow;
  timeRed = other.timeRed;
  timeTilChange = other.timeTilChange;
}

/**
 * Destructor
 */
TrafficLight::~TrafficLight() {}

/**
 * Returns the current color of the light
 */
LightColor TrafficLight::getColor()
{
  return lightColor;
}

/**
 * Changes the color of the light, updates timeTilChange, and returns its previous color
 */
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

/**
 * Returns the length of time the light is green
 */
int TrafficLight::getTimeGreen()
{
  return timeGreen;
}

/**
 * Returns the length of time the light is yellow
 */
int TrafficLight::getTimeYellow()
{
  return timeYellow;
}

/**
 * Returns the length of time the light is red
 */
int TrafficLight::getTimeRed()
{
  return timeRed;
}

/**
 * Returns the length of time until the light changes
 */
int TrafficLight::getTimeTilChange()
{
  return timeTilChange;
}

/**
 * Decrements timeTilChange and changes the light color when timeTilChange reaches 0
 */
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
