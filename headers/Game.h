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
    bool isOutside();
    void CubeRotate();
    void LockCube();
    bool CubesFit();
public:
    Board board;
    Game(/* args */);
    void Draw();
    
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void KeyHandler(unsigned char key, int x, int y);
    Cubes AddRandomBlock();
    std::vector<Cubes> GetAllBlocks();
    ~Game();
};
