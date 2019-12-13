#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include "VehicleBase.h"

class TrafficLight
{
private:
	LightColor lightColor;
	int timeGreen;
	int timeYellow;
	int timeRed;
	int timeTilChange;

public:
	//TrafficLight();
	TrafficLight(LightColor light, int g, int y, int r);
	TrafficLight(const TrafficLight &other);
	~TrafficLight();

	LightColor getColor();
	LightColor setColor(LightColor c);
	int getTimeGreen();
	int getTimeYellow();
	int getTimeRed();
	int getTimeTilChange();
	void decrement();
};

#endif
