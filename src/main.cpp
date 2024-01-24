#pragma once
#include "Board.h"
#include "Location.h"
#include "GameController.h"
#include "Mouse.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	GameController game;
	game.StartGame();
	return EXIT_SUCCESS;
}