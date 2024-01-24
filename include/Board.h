#pragma once

#include "Location.h"
#include "Mouse.h"
#include "Cat.h"
#include "io.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board
{
public:
	void ReadLevelGame(std::string fileName);
	void printCurrBoard(Mouse mouse, std::vector<Cat> cat, std::vector<Location> cheeses,
		std::vector<Location> walls, std::vector<Location> keys,
		std::vector<Location> doors, std::vector<Location> gift);
	int GetRows();
	int GetCols();
	std::vector< std::string> GetBoard();
private:
	std::vector<std::string> m_currBoard;
	int m_rows;
	int m_cols;
};