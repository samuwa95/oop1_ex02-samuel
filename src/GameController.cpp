#pragma once
#include "GameController.h"

GameController::GameController()
{
}

void GameController::SaveObjectsLocations(std::string fileName)
{
	m_board.ReadLevelGame(fileName);
	for (int i = 0; i < m_board.GetRows(); i++)
	{
		for (int j = 0; j < m_board.GetCols(); j++)
		{
			switch (m_board.GetBoard()[i][j])
			{
			case Characters::CAT: // keeps all cats and their locations in vector
				m_cats.push_back(Cat(Location(i, j)));
				break;
			case Characters::MOUSE: // keeps the location of the mouse in the board
				//m_mouse = Mouse(Location(i, j));
				m_mouse.setLocationMouse(Location(i, j));
				break;
			case Characters::CHEESE: // keeps all the cheeses and their location in vector
				m_cheeses.push_back(Location(i, j));
				break;
			case Characters::GIFT://keeps all gift and their locations in vector
				m_gift.push_back(Location(i, j));
				break;
			case Characters::WALL://keeps all wall(hagshtag) and their locations in vector
				m_walls.push_back(Location(i, j));
				break;
			case Characters::KEY: ////keeps all key and their locations in vector
				m_keylocations.push_back(Location(i, j));
				break;
			case Characters::DOOR: ////keeps all door and their locations in vector
				m_doorlocations.push_back(Location(i, j));
			}
		}
	}

	m_numofcats = int(m_cats.size());// count the namber of cats
	
}

void GameController::StartGame()
{
	std::vector<std::string> fileNames = { "Board1.txt", "Board2.txt" , "Board3.txt" };
	size_t  level = 0; // count how many levels we finish
	int status = -1;

	m_mouse = Mouse(Location(0, 0));
	while (level < fileNames.size())
	{
		ClearVectors();
		SaveObjectsLocations(fileNames[level]);
		bool game = true;
		while (game)
		{
			Screen::resetLocation();
			ClearScreen();
			Screen::resetLocation();
			status = CheckFinish();
			switch (status)
			{
			case 1: // the mouse caught all the cheeses
				game = false;
				break;
			case 2: // the cats got the mouse to lose his lifes
				game = false;
				break;
			case 0:
				m_board.printCurrBoard(m_mouse, m_cats, m_cheeses, m_walls, m_keylocations,
					m_doorlocations, m_gift);
				std::cout << "\nPoints: " << m_mouse.getPoints() << "    Life : " << m_mouse.getLife() << std::endl;
				MoveMouse();
				for (size_t i = 0; i < m_cats.size(); i++)
				{
					MoveCat((int)i);
				}
				break;
				//
			}
		}
		if (status == 1)
		{
			level++;
			m_mouse.addPoints(25 + m_numofcats * 5);
		}
		else
			break;
	}

	if (status == 1)
		std::cout << "You've finish all levels, Well done!" << std::endl;
	else
		std::cout << "The mouse lost all lifes, Good luck next time!" << std::endl;
}

int GameController::CheckFinish() // 0 - continue to play, 1 - Mouse ate all cheeses, 2 - Mouse has lost all lifes
{
	if (m_cheeses.empty())
		return 1; // win situation
	if (m_mouse.getLife() == 0)
		return 2; // lose situation
	return 0; // contiue the game
}

void GameController::MoveMouse()
{
	int tav = _getch();
	if (tav == Keys::SPECIAL_KEY || tav == 0)
	{
		tav = _getch();
		Location locate = m_mouse.getMouseLocation();
		switch (tav)
		{
		case SpecialKeys::UP:
			if (CheckWall(locate.row - 1, locate.col))
			{
				m_mouse.moveObject(tav);
			}
			break;
		case SpecialKeys::DOWN:
			if (CheckWall(locate.row + 1, locate.col))
			{
				m_mouse.moveObject(tav);
			}
			break;
		case SpecialKeys::RIGHT:
			if (CheckWall(locate.row, locate.col + 1))
			{
				m_mouse.moveObject(tav);
			}
			break;
		case SpecialKeys::LEFT:
			if (CheckWall(locate.row, locate.col - 1))
			{
				m_mouse.moveObject(tav);
			}
			break;
		}
		CheckMove();
	}
}

void GameController::MoveCat(int index)
{
	Location mouselocation = m_mouse.getMouseLocation();
	Location catlocation = m_cats[index].getCatLocation();

	int direction = m_cats[index].getDirection();
	bool checkDirection = true;

	//m_cats[index].moveObject(direction);
	switch (direction)
	{
	case SpecialKeys::UP:
		if (!CheckWall(catlocation.row - 1, catlocation.col))
		{
			checkDirection = false;
		}
		break;
	case SpecialKeys::DOWN:
		if (!CheckWall(catlocation.row + 1, catlocation.col))
		{
			checkDirection = false;
		}
		break;
	case SpecialKeys::RIGHT:
		if (!CheckWall(catlocation.row, catlocation.col + 1))
		{
			checkDirection = false;
		}
		break;
	case SpecialKeys::LEFT:
		if (!CheckWall(catlocation.row, catlocation.col - 1))
		{
			checkDirection = false;
		}
		break;
	}

	if (!checkDirection) // == false we get in this case if we cant
	{
		switch (direction)
		{
		case SpecialKeys::UP:
		case SpecialKeys::DOWN:
			if (mouselocation.col < catlocation.col)
			{
				m_cats[index].setDirection(SpecialKeys::LEFT);
			}	
			else
			{
				m_cats[index].setDirection(SpecialKeys::RIGHT);
			}	
			break;
		case SpecialKeys::RIGHT:
		case SpecialKeys::LEFT:
			if (mouselocation.row < catlocation.row)
			{
				m_cats[index].setDirection(SpecialKeys::UP);
			}
			else
			{
				m_cats[index].setDirection(SpecialKeys::DOWN);
			}
			break;
		}
	}
	m_cats[index].moveObject();
}

void GameController::CheckMove()
{
	Location locate = m_mouse.getMouseLocation();

	// decrase the amount of cheese
	for (size_t i = 0; i < m_cheeses.size(); i++)
	{
		if (locate.row == m_cheeses[i].row && locate.col == m_cheeses[i].col)
		{
			m_cheeses.erase(m_cheeses.begin() + i);
			m_mouse.addPoints(10);
			break;
		}
	}
	
	//deacrese the amount heart of mouse
	for (size_t i = 0; i < m_cats.size(); i++)
	{
		if (locate.row == m_cats[i].getCatLocation().row && 
			locate.col == m_cats[i].getCatLocation().col)
		{
			m_mouse.decreasedLife();
			break;
		}
	}
	// if we found the gift we decrese the amount of cats
	for (size_t i = 0; i < m_gift.size(); i++)
	{
		if (locate.row == m_gift[i].row && locate.col == m_gift[i].col)
		{
			if (m_cats.size() > 0)
			{
				m_cats.erase(m_cats.end() - 1);
				m_gift.erase(m_gift.begin() + i);
				m_mouse.addPoints(5);
			}	
			break;
		}
	}
	// if we found the key we decrese the amount of dor
	for (size_t i = 0; i < m_keylocations.size(); i++)
	{
		if (locate.row == m_keylocations[i].row && locate.col == m_keylocations[i].col)
		{
			m_keylocations.erase(m_keylocations.begin() + i);
			break;
		}
	}	
}

void GameController::ClearScreen()
{
	system("cls");
}

void GameController::ClearVectors()
{
	m_cheeses.clear();
	m_walls.clear();
	m_cats.clear();
	m_gift.clear();
	m_keylocations.clear();
	m_doorlocations.clear();
}

bool GameController::CheckWall(int row, int col)
{
	//check if there's a wll in mouse's way
	for (size_t i = 0; i < m_walls.size(); i++)
	{
		if (row == m_walls[i].row && col == m_walls[i].col)
		{
			return false;
		}
	}

	//check if the cat in the same location on door
	for (size_t i = 0; i < m_doorlocations.size(); i++)
	{
		if (row == m_doorlocations[i].row && col == m_doorlocations[i].col)
		{
			if (m_keylocations.size() == m_doorlocations.size())
			{
				return false;
			}
			else
			{
				m_doorlocations.erase(m_doorlocations.begin() + i);
				m_mouse.addPoints(2);
				break;
			}
		}
	}
	return true;
}