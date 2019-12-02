#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

enum Color {GREEN, YELLOW, RED};

class TrafficLight
{
	private:
		Color lightColor;
  	int timeGreen;
  	int timeYellow;
  	int timeRed;
  	int timeTilChange;

	public:
		TrafficLight(Color light, int green, int yellow, int red);
		TrafficLight(const TrafficLight& other);
		~TrafficLight();

  	Color getColor();
  	Color setColor(Color c);
		int   getTimeGreen();
		int   getTimeYellow();
		int   getTimeRed();
  	int   getTimeTilChange();
		void  decrement();

};

#endif
