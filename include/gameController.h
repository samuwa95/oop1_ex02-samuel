#pragma once
#include "Board.h"
#include "Location.h"
#include "Mouse.h"
#include "Cat.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <io.h>

class GameController
{
public:
    GameController();
    void SaveObjectsLocations(std::string fileName);
    void StartGame();

    int CheckFinish(); // check if the mouse got all cheeses or the cats killed the mouse
    void MoveMouse();
    void MoveCat(int index);
    void CheckMove();
    void ClearScreen();
    void ClearVectors();
    bool CheckWall(int row, int col);
    
private:
    Board m_board;
    Mouse m_mouse;
    int m_numofcats;

    std::vector<Location> m_cheeses;
    std::vector<Location> m_walls;
    std::vector<Cat> m_cats;
    std::vector<Location> m_gift;
    std::vector<Location> m_keylocations;
    std::vector<Location> m_doorlocations;
};