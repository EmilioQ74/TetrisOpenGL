#pragma once 
#include "Board.h"
#include "Blocks.h"
#include "Cubes.h"
#include "Game_Utils.h"


class Game
{
private:
    std::vector<Cubes> cubes;
    Cubes currentBlock;
    std::vector<Cubes> nextBlocks;
    int cubeState;
    int score;
    int speed;
    int CubePosX;
    int CubePosY;
public:
    Board board;
    Game(/* args */);
    void Draw();
    bool isOutside();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void CubeRotate();
    void LockCube();
    void KeyHandler(unsigned char key, int x, int y);
    Cubes AddRandomBlock();
    std::vector<Cubes> GetAllBlocks();
    ~Game();
};
