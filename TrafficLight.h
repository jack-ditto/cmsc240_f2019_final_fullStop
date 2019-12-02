#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__


class TrafficLight
{

enum Color {GREEN, YELLOW, RED};

private:
	Color lightColor;
  int timeGreen;
  int timeYellow;
  int timeRed;
  int timeTilChange; 

public:
  Color getColor();
  Color setColor(Color c);
	int   getTimeGreen();
	int   getTimeYellow();
	int   getTimeRed();
  int   getTimeTilChange();
	void  decrement();

};

#endif
