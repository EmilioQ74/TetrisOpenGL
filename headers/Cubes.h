#pragma once

#include "Game_Utils.h"
#include "Position.h"

class Cubes
{
protected:
    int id;
    int state;
    std::map<int, std::vector<Position>> pos;
    int offsetRow;
    int offsetColumn;
public:
    Cubes();
    ~Cubes();
    void setState(int state);
    void Move(int row,int column);
    void Rotate();
    void UndoRotate();
    void Draw();
    std::vector<Position> getPositions();

    int getID() const;
    int getCurrentState();
};
