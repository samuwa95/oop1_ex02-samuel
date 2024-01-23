#pragma once
#include "Cat.h"

Cat::Cat(Location loc) :m_location(loc), m_direction(SpecialKeys::UP) {}

Location Cat::getCatLocation()
{
	return m_location;
}

int Cat::getDirection()
{
	return m_direction;
}

void Cat::setDirection(int direction)
{
	m_direction = direction;
}

void Cat::moveObject()
{
	switch (m_direction)
	{
	case SpecialKeys::UP:
		m_location.row--;
		break;
	case SpecialKeys::DOWN:
		m_location.row++;
		break;
	case SpecialKeys::LEFT:
		m_location.col--;
		break;
	case SpecialKeys::RIGHT:
		m_location.col++;
		break;
	}
}