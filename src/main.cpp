#pragma once
#include "Board.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	auto filename1= std::string("Board.txt");
	Board b(filename1);
	b.printCurrBoard();

}
