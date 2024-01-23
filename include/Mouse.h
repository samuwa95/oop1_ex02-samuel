#pragma once

#include "Location.h"
#include "io.h"

class Mouse
{
public:
	Mouse();
	Mouse(Location loc);
	int getLife(); // getter function to return amount of life
	Location getMouseLocation();
	void moveObject(int key); // move mouse according to key press
	void decreasedLife();
private:
	Location m_Mouselocation;
	int m_life; // amount of hearts
};