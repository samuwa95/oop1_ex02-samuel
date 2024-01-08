#pragma once

#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Board
{
public:
	Board(std::string fileName);				//defaut constructor
	int getBoardSize();							//fuction to get board size
	void printCurrBoard();						//function to print board
	//Location getLocations(int searchedPlayer);	//return the location of the searched player

private:
	int m_col;
	int m_row;

	std::vector<std::string> m_currBoard;

};