
#include "Cubes.h"
#include "Colors.h"
 

Cubes::Cubes()
{
    id = 0;
    state = 0;
    offsetRow = 0;
    offsetColumn = 0;
}

Cubes::~Cubes()
{
    
}

void Cubes::setState(int state)
{
    this->state = state;
}

void Cubes::Move(int row, int column)
{
    offsetRow += row;
    offsetColumn += column;
}

void Cubes::Rotate()
{
    state++;
    if(state > 3)state = 0;
}

void Cubes::UndoRotate()
{
    state--;
    if(state < 0)state = 3;
}

void Cubes::Draw()
{
    std::vector<Position> tetriminoPos = getPositions();
    for(Position item: tetriminoPos)
    {
        glColor4fv(colors[id]);
        glRectd(item.column*CELL_SIZE_WIDTH + CELL_POS_X, item.row*CELL_SIZE_HEIGHT + CELL_POS_Y+1, item.column*CELL_SIZE_WIDTH + BORDER_LEFT + CELL_SIZE_WIDTH-1, item.row*CELL_SIZE_HEIGHT + BORDER_TOP + CELL_SIZE_HEIGHT);
    }
}

std::vector<Position> Cubes::getPositions()
{
    std::vector<Position> tetriminoPos = pos[state];
    std::vector<Position> movedPos;
    for(Position item: tetriminoPos)
    {
        Position newPos = Position(item.row+offsetRow, item.column+offsetColumn);
        movedPos.push_back(newPos);
    }
    return movedPos;
}

int Cubes::getID() const
{
    return id;    
}

int Cubes::getCurrentState()
{
    return this->state;
}
