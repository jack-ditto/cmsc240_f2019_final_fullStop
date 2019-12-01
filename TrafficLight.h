#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__


class TrafficLight
{

enum Color {GREEN, YELLOW, RED};

private:
	Color lightColor;
  //int timeGreen;
  //int timeYellow;
  //int timeRed;
  //int timeTilChange; //maybe do not need

public:
  Color getColor();
  Color setColor(Color c);
  //void  increment(); //will need either set color of increment, depends on whether light keeps track of time or game keeps track of time
  //int   getTimeTilChange();

};

#endif
