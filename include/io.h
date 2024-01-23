#pragma once

#include "Location.h"

namespace Characters
{
	constexpr int CAT = 94; // ^
	constexpr int MOUSE = 37; // %
	constexpr int CHEESE = 42; // *
	constexpr int SPACE = 32; // ' '
	constexpr int WALL = 35; // #
	constexpr int KEY = 70; // F
	constexpr int DOOR = 68; // D
	constexpr int GIFT = 36; // $
}

namespace Keys
{
	constexpr int ESCAPE = 27;
	constexpr int SPECIAL_KEY = 224;
}

namespace SpecialKeys
{
	constexpr int UP = 72;
	constexpr int DOWN = 80;
	constexpr int LEFT = 75;
	constexpr int RIGHT = 77;
}

namespace Screen
{
	// Reset terminal cursor location to start of the screen (0,0)
	void resetLocation();
	// Set terminal cursor location to the desired location
	void setLocation(const Location& location);
}
