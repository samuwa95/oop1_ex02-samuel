#pragma once
#include "Location.h"
#include "io.h"

class Cat
{
public:
	Cat(Location loc);
	Location getCatLocation();
	int getDirection();
	void setDirection(int direction);
	void moveObject(); // move mouse according to key press
private:
	Location m_location;
	int m_direction;
};