#include "Game.h"
#include <random>

//constructor
Game::Game()
{
    PlaySound(MUSIC_PLAY, NULL, SND_ASYNC | SND_LOOP);
    GameOver = false;
    dropDown = false;
    score = 0;
    speed = 20;
    board = Board();
    gui = Gui();
    cubes = GetAllBlocks();
    currentBlock = AddRandomBlock();
    nextBlock = AddRandomBlock();
}

Game::~Game()
{

}
//draw the game
void Game::Draw()
{
    board.drawBoard();
    currentBlock.Draw();
    gui.Draw(nextBlock, score);
}
// set the speed of the game
void Game::setSpeed()
{
    if (score > 1000) speed = 25;
    if (score > 2000) speed = 30;
    if (score > 3000) speed = 35;
    if (score > 5000) speed = 40;
    if (score > 10000) speed = 45;
}
//get the speed
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
    if(GameOver)
    {
        return;
    }
    if (!GameOver)
    {
        while (dropDown)
        {
            currentBlock.Move(1, 0);
            score++;
            if (isOutside() || !CubesFit())
            {
                currentBlock.Move(-1, 0);
                LockCube();
            }
        }
        currentBlock.Move(1, 0);
        score++;
        if (isOutside() || !CubesFit())
        {
            currentBlock.Move(-1, 0);
            LockCube();
        }
    }
}
//move the tetrimino to the left
void Game::MoveLeft()
{
    if (!GameOver)
    {
        currentBlock.Move(0, -1);
        if (isOutside() || !CubesFit())
        {
            currentBlock.Move(0, 1);
        }

    }
    
    
}
//move the tetrimino to the right
void Game::MoveRight()
{
    if (!GameOver)
    {
        currentBlock.Move(0, 1);
        if (isOutside() || !CubesFit())
        {
            currentBlock.Move(0, -1);
        }
    }
}



//rotate the tetrimino 
void Game::CubeRotate()
{
    if (!GameOver)
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
}

//lock the tetrimino and add it to the board by the id value 
void Game::LockCube()
{
    std::vector<Position> tetriminoPos = currentBlock.getPositions();
    for(Position item: tetriminoPos)
    {
    board.insetBlock(item.row, item.column, currentBlock.getID());
    }
    dropDown = false;
    currentBlock = nextBlock;
    setSpeed();
    int rowCleared = board.ClearFullRow();
    if(rowCleared > 0)
    {
        score += rowCleared*100;
    }
    nextBlock = AddRandomBlock();
    if(!CubesFit()) GameOver = true;

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
            }
            if(item.column>=COLUMN)
            {
                currentBlock.setState(currentBlock.getCurrentState());
                currentBlock.Move(0,-1);
            }
        }
    }
}

void Game::KeyHandler(unsigned char key, int x, int y)
{
    if(GameOver && key == 'r') {
        GameOver = false;
        reset();
    }
    if(GameOver) return;
    switch(key)
    {
        case 'w':
        case 'W':
            CubeRotate();
            break;
        case 's':
        case 'S':
            MoveDown();
            break;
        case 'a':
        case 'A':
            MoveLeft();
            break;
        case 'd':
        case 'D':
            MoveRight();
            break;
        case ' ':
            dropDown = true;
            MoveDown();
            break;
    }
   
}

void Game::SpecialKeyHandler(int key, int x, int y)
{
    if(GameOver) return;
    switch(key)
    {
        case GLUT_KEY_UP:
            CubeRotate();
            break;
        case GLUT_KEY_DOWN:
            MoveDown();
            break;
        case GLUT_KEY_LEFT:
            MoveLeft();
            break;
        case GLUT_KEY_RIGHT:
            MoveRight();
            break;
    }
}

Cubes Game::AddRandomBlock()
{
    if(cubes.size() == 1)
    {
        Cubes lastBlock = cubes[0];
        cubes.clear();
        cubes = GetAllBlocks();
        return lastBlock;
    }
    srand(time(0));
    int index = rand() % cubes.size();
    Cubes block = cubes[index];
    cubes.erase(cubes.begin() + index);
    return block;
}
std::vector<Cubes> Game::GetAllBlocks()
{
    return {BlockI(), BlockJ(), BlockL(), BlockO(), BlockS(), BlockT(), BlockZ(),BlockI(), BlockJ(), BlockL(), BlockO(), BlockS(), BlockT(), BlockZ()};
}

void Game::reset()
{
   board.initialize();
   cubes = GetAllBlocks();
   currentBlock = AddRandomBlock();
   score = 0;
   speed = 20;
}