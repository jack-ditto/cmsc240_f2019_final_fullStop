#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

TrafficLight::TrafficLight(Color col, int green, int yellow, int red)
{
  lightColor = col;
  timeGreen     = green;
  timeYellow    = yellow;
  timeRed       = red;
  if(col == GREEN)
  {
    timeTilChange = timeGreen;
  }
  /*else if(col == YELLOW)    //should never start yellow
  {
    timeTilChange = timeYellow;
  } */
  else
  {
    timeTilChange = timeRed;
  }
}

Color TrafficLight::getColor()
{
  return lightColor;
}

Color TrafficLight::setColor(Color c)
{
  Color old = lightColor;
  lightColor = c;
  return old;
}

int   TrafficLight::getTimeGreen()
{
  return timeGreen;
}

int   TrafficLight::getTimeYellow()
{
  return timeYellow;
}

int   TrafficLight::getTimeRed()
{
  return timeRed;
}

int TrafficLight::getTimeTilChange()
{
  return timeTilChange;
}

void  TrafficLight::decrement()
{
  timeTilChange--;

  if(timeTilChange == 0)
  {
    if(lightColor == GREEN)
    {
      lightColor == YELLOW;
      timeTilChange = timeYellow;
    }

    else if(lightColor == YELLOW)
    {
      lightColor == RED;
      timeTilChange = timeRed;
    }

  else
    {
      lightColor == GREEN;
      timeTilChange = timeGreen;
    }
  }
}


#endif
