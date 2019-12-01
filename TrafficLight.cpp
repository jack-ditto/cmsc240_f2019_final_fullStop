#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

class TrafficLight
{

  TrafficLight::TrafficLight(Color c, int green, int yellow, int red, int time)
  {
    lightColor = c;
    timeGreen = green;
    timeYellow = yellow;
    timeRed = red;
    timeTilChange = time; //maybe do not need
  }

}

#endif
