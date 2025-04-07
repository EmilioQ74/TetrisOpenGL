#include "Game.h"
#include <random>


Game::Game()
{
    speed = 1;
    cubeState = 0;
    board = Board();
    cubes = GetAllBlocks();
    nextBlocks = GetAllBlocks();
    currentBlock = AddRandomBlock();
}

Game::~Game()
{

}

void Game::Draw()
{
    
    board.drawBoard();
    currentBlock.Draw();
}
bool Game::isOutside()
{
    std::vector<Position> tetriminoPos = currentBlock.getPositions();
    for(Position item: tetriminoPos)
    {
        if(board.isOutside(item.row,item.column))return true;
    }
    return false;
}
void Game::MoveDown()
{
    currentBlock.Move(1, 0);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(-1, 0);
        LockCube();
    }
}

void Game::MoveLeft()
{
    currentBlock.Move(0, -1);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveRight()
{
    currentBlock.Move(0, 1);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(0, -1);
    }
}



void Game::CubeRotate()
{
    currentBlock.Rotate();
    if (isOutside() || !CubesFit())
    {
        currentBlock.UndoRotate();
    }
}

void Game::LockCube()
{
    std::vector<Position> tetriminoPos = currentBlock.getPositions();
    for(Position item: tetriminoPos)
    {
    board.insetBlock(item.row, item.column, currentBlock.getID());
    }
    currentBlock = AddRandomBlock();
    if(!CubesFit())board.Reset();
    board.ClearFullRow();

}

bool Game::CubesFit()
{
    std::vector<Position> tetriminosPos = currentBlock.getPositions();
    for(Position item:tetriminosPos)
    {
        if(board.isCellEmpty(item.row,item.column)==false){
            return false;
        }
    }
    return true;
}

void Game::KeyHandler(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            CubeRotate();
            break;
        case 's':
            MoveDown();
            break;
        case 'a':
            MoveLeft();
            break;
        case 'd':
            MoveRight();
            break;
    }
}

Cubes Game::AddRandomBlock()
{
    //old system with only random blocks
    srand(time(0));
    int index = rand() % nextBlocks.size();
    Cubes block = nextBlocks[index];
    return block;
}

std::vector<Cubes> Game::GetAllBlocks()
{
    return {BlockI(), BlockJ(), BlockL(), BlockO(), BlockS(), BlockT(), BlockZ()};
}
