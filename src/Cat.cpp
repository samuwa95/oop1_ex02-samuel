#pragma once
#include "Cat.h"

Cat::Cat(Location loc) :m_catlocation(loc), m_direction(SpecialKeys::UP) {}

Location Cat::getCatLocation()
{
	return m_catlocation;
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
		m_catlocation.row--;
		break;
	case SpecialKeys::DOWN:
		m_catlocation.row++;
		break;
	case SpecialKeys::LEFT:
		m_catlocation.col--;
		break;
	case SpecialKeys::RIGHT:
		m_catlocation.col++;
		break;
	}
}