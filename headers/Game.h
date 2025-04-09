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
    void FixPosition();
    Cubes AddRandomBlock();
    Cubes AddToTheList();
public:
    Board board;
    Game(/* args */);
    void Draw();
    void setSpeed(int speed);
    int getSpeed() const;
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void KeyHandler(unsigned char key, int x, int y);
    std::vector<Cubes> GetAllBlocks();
    void reset();
    ~Game();
};
