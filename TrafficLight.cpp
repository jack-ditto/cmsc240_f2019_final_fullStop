#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

class TrafficLight
{

  TrafficLight::TrafficLight(Color col, int green, int yellow, int red)
  {
    lightColor = col;
    timeGreen     = green;
    timeYellow    = yellow;
    timeRed       = red;
    timeTilChange = 0;
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

      if(lightColor == YELLOW)
      {
        lightColor == RED;
        timeTilChange = timeRed;
      }

      if(lightColor == RED)
      {
        lightColor == GREEN;
        timeTilChange = timeGreen;
      }
    }
  }


}

#endif
