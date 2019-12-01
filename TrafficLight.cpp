#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

class TrafficLight
{

  TrafficLight::TrafficLight(Color col) //, int green, int yellow, int red, int time)
  {
    lightColor = col;
    //timeGreen     = green;
    //timeYellow    = yellow;
    //timeRed       = red;
    //timeTilChange = time;
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

  /*void TrafficLight::increment()
  {
    timeTilChange--;
    if(timeTilChange == 0)
    {
      if(lightColor == GREEN)
      {
        lightColor = YELLOW;
        timeTilChange = timeYellow;
      }

      if(lightColor == YELLOW)
      {
        lightColor = RED;
        timeTilChange = timeRed;
      }

      if(lightColor == RED)
      {
        lightColor = GREEN;
        timeTilChange = timeGreen;
      }
    }
  } */

  /*int TrafficLight::getTimeTilChange()
  {
    return timeTilChange;
  } */

}

#endif
