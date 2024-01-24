#pragma once
#include "Mouse.h"


Mouse::Mouse()
{
}

Mouse::Mouse(Location loc, int life, int point)
	:m_Mouselocation(loc), m_life(life), m_points(point)
{
}

int Mouse::getLife()
{
	return  m_life;
}

Location Mouse::getMouseLocation()
{
	return m_Mouselocation;
}

void Mouse::moveObject(int key)
{
	switch (key)
	{
	case SpecialKeys::UP:
		m_Mouselocation.row--;
		break;
	case SpecialKeys::DOWN:
		m_Mouselocation.row++;
		break;
	case SpecialKeys::LEFT:
		m_Mouselocation.col--;
		break;
	case SpecialKeys::RIGHT:
		m_Mouselocation.col++;
		break;
	}
}

void Mouse::decreasedLife()
{
	m_life--;
}

int Mouse::getPoints()
{
	return m_points;
}

void Mouse::addPoints(int point)
{
	m_points += point;
}
