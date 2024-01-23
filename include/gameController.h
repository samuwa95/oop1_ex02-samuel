#pragma once
#include "Board.h"
#include "Location.h"
#include "Mouse.h"
#include "Cat.h"
#include "KeyDoor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <io.h>

class GameController
{
public:
    GameController(std::string fileName);
    void SaveObjectsLocations(std::string fileName);
    void StartGame();

    int CheckFinish(); // check if the mouse got all cheeses or the cats killed the mouse
    void MoveMouse();
    void MoveCat(int index);
    void CheckMove();
    void ClearScreen();

    bool CheckWallDoor(int row, int col);
    
private:
    Board m_board;
    Mouse m_mouse;
    KeyDoor m_keyDoor;

    std::vector<Location> m_cheeses;
    std::vector<Location> m_walls;
    std::vector<Cat> m_cats;
    std::vector<Location> m_gift;

   //std::vector<KeyDoor> m_KeyDoor;
};