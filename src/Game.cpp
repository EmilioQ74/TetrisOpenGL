#include "Game.h"
#include <random>

//constructor
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
//draw the game
void Game::Draw()
{
    
    board.drawBoard();
    currentBlock.Draw();
}
void Game::setSpeed(int speed)
{
    if(speed < 1)speed = 1;
    this->speed = speed;
}

int Game::getSpeed() const
{
    return speed;
}
// check if the tetrimino is outside the board
bool Game::isOutside()
{
    std::vector<Position> tetriminoPos = currentBlock.getPositions();
    for(Position item: tetriminoPos)
    {
        if(board.isOutside(item.row,item.column))return true;
    }
    return false;
}
//move the tetrimino down
void Game::MoveDown()
{
    currentBlock.Move(1, 0);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(-1, 0);
        LockCube();
    }
}
//move the tetrimino to the left
void Game::MoveLeft()
{
    currentBlock.Move(0, -1);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(0, 1);
    }
}
//move the tetrimino to the right
void Game::MoveRight()
{
    currentBlock.Move(0, 1);
    if (isOutside() || !CubesFit())
    {
        currentBlock.Move(0, -1);
    }
}


//rotate the tetrimino 
void Game::CubeRotate()
{
    currentBlock.Rotate();
    if (isOutside())
    {
        FixPosition();
    }
    if(!CubesFit())
    {
        currentBlock.UndoRotate();
    }
}
//lock the tetrimino and add it to the board by the id value 
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
//check if the tetimino collide with other tetrimino so it can't move
bool Game::CubesFit()
{
    std::vector<Position> tetriminosPos = currentBlock.getPositions();
    for(Position item:tetriminosPos)
    {
        if(!board.isCellEmpty(item.row,item.column)){
            return false;
        }
    }
    return true;
}
//check if the tetrimino is outside of the board and fix the position so it can rotate like tha game
void Game::FixPosition()
{
    std::vector<Position> tetriminosPos = currentBlock.getPositions();
    for(Position item:tetriminosPos)
    {
        if(isOutside())
        {
            if(item.column<=0)
            {
                currentBlock.setState(currentBlock.getCurrentState());
                currentBlock.Move(0,1);
                printf("Current State: %d\n",currentBlock.getCurrentState());
            }
            if(item.column>=COLUMN)
            {
                currentBlock.setState(currentBlock.getCurrentState());
                currentBlock.Move(0,-1);
                printf("Current State: %d\n",currentBlock.getCurrentState());
            }
        }
    }
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

Cubes Game::AddToTheList()
{
    srand(time(0));
    int index = rand() % nextBlocks.size();
    Cubes block = nextBlocks[index];
    nextBlocks.erase(nextBlocks.begin() + index);
    return block;
}

std::vector<Cubes> Game::GetAllBlocks()
{
    return {BlockI(), BlockJ(), BlockL(), BlockO(), BlockS(), BlockT(), BlockZ()};
}

void Game::reset()
{
   board.initialize();
   cubes = GetAllBlocks();
   nextBlocks = GetAllBlocks();
   currentBlock = AddRandomBlock();
}