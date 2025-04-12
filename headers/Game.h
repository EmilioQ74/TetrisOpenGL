#pragma once 
#include "Board.h"
#include "Blocks.h"
#include "Cubes.h"
#include "Gui.h"
#include "Music.h"
#include "Game_Utils.h"


class Game
{
private:
    std::vector<Cubes> cubes;
    Cubes currentBlock;
    Cubes nextBlock;
    Gui gui;
    int score;
    int speed;
    bool GameOver;
    bool dropDown;
    std::thread musicThread;
    bool isOutside();
    void CubeRotate();
    void LockCube();
    bool CubesFit();
    void FixPosition();
    Cubes AddRandomBlock();
    
public:
    Board board;
    Game(/* args */);
    void Draw();
    int getScore() const;
    void setSpeed();
    int getSpeed() const;
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void KeyHandler(unsigned char key, int x, int y);
    void SpecialKeyHandler(int key, int x, int y);
    std::vector<Cubes> GetAllBlocks();
    void reset();
    ~Game();
};
