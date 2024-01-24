#pragma once
#include "Board.h"

Board::Board(std::string fileName)
{
	ReadLevelGame(fileName);
}

void Board::ReadLevelGame(std::string fileName)
{
	m_rows = 0;
	auto file = std::ifstream(fileName);

	if (!file)	//if cant find file
	{
		exit(EXIT_FAILURE);
	}

	auto line = std::string(); // arr dinamc
	std::getline(file, line);	//Read a line

	while (!line.empty())
	{
		m_currBoard.push_back(line);	//each line is kept in the vector
		std::getline(file, line);
		m_rows++;
	}
	m_cols = (int)m_currBoard[0].size();
}
void Board::printCurrBoard(Mouse mouse, std::vector<Cat> cat, std::vector<Location> cheeses,
	std::vector<Location> walls, std::vector<Location> keys,
	std::vector<Location> doors, std::vector<Location> gift)
{
	bool print = false;
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			print = false;
			//print the wals of board
			for (size_t k = 0; !print && k < walls.size(); k++)
			{
				if (i == walls[k].row && j == walls[k].col)
				{
					std::cout << (char)Characters::WALL;
					print = true;
				}
			}
			// print the cats 
			for (size_t k = 0; !print && k < cat.size(); k++)
			{
				if (i == cat[k].getCatLocation().row && j == cat[k].getCatLocation().col)
				{
					std::cout << (char)Characters::CAT;
					print = true;
					break;
				}
			}
			// print the cheeses
			for (size_t l = 0; !print && l < cheeses.size(); l++)
			{
				if (i == cheeses[l].row && j == cheeses[l].col)
				{
					std::cout << (char)Characters::CHEESE;
					print = true;
					break;
				}
			}

			// print the gifts
			for (size_t l = 0; !print && l < gift.size(); l++)
			{
				if (i == gift[l].row && j == gift[l].col)
				{
					std::cout << (char)Characters::GIFT;
					print = true;
					break;
				}
			}

			// print the mouse
			if (!print && i == mouse.getMouseLocation().row && j == mouse.getMouseLocation().col)
			{
				std::cout << (char)Characters::MOUSE;
				print = true;
			}

			// print the keys
			for (size_t k = 0; k < keys.size(); k++)
			{
				if (!print && i == keys[k].row
					&& j == keys[k].col)
				{
					std::cout << (char)Characters::KEY;
					print = true;
				}
			}

			// print the door
			for (size_t k = 0; k < doors.size(); k++)
			{
				if (!print && i == doors[k].row
					&& j == doors[k].col)
				{
					std::cout << (char)Characters::DOOR;
					print = true;
				}
			}

			if (!print)
				std::cout << (char)Characters::SPACE;
		}
		std::cout << std::endl;
	}
}

int Board::GetRows()
{
	return m_rows;
}

int Board::GetCols()
{
	return m_cols;
}

std::vector<std::string> Board::GetBoard()
{
	return m_currBoard;
}