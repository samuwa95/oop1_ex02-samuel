#pragma once
#include "Board.h"

Board::Board(std::string fileName)
{
	auto file = std::ifstream(fileName);

	if (!file)		        //if cant find file
		exit(EXIT_FAILURE);

	auto line = std::string(); // arr dinamc
	std::getline(file, line);	//Read a line

	while (!line.empty())
	{
		m_currBoard.push_back(line);	//each line is kept in the vector
		std::getline(file, line);
	}
}

int Board::getBoardSize()
{
	return m_currBoard.size();
}

void Board::printCurrBoard()
{
	for (int i = 0; i < m_currBoard.size(); i++)
	{
		std::cout << m_currBoard[i];
		std::cout << std::endl;
	}
}
