#pragma once

#include "Location.h"
#include "io.h"

class Mouse
{
public:
	Mouse();
	Mouse(Location loc, int life = 3, int point = 0);
	void setLocationMouse(Location loc);
	int getLife(); // getter function to return amount of life
	Location getMouseLocation();
	void moveObject(int key); // move mouse according to key press
	void decreasedLife();
	int getPoints();
	void addPoints(int point);
private:
	Location m_Mouselocation;
	int m_life;// amount of hearts
	int m_points;
};