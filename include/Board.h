#pragma once

#include "Location.h"
#include "Mouse.h"
#include "Cat.h"
#include "io.h"
#include "KeyDoor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Board
{
public:
	Board(std::string fileName);
	void ReadLevelGame(std::string fileName);
	void printCurrBoard(Mouse m, std::vector<Cat> c, std::vector<Location> cheeses,
		std::vector<Location> walls, KeyDoor keydoor, std::vector<Location> m_gift);	//function to print board;
	int GetRows();
	int GetCols();
	std::vector< std::string> GetBoard();
private:
	std::vector<std::string> m_currBoard;
	int m_rows;
	int m_cols;
};