#pragma once 
#include "Game_Utils.h"
#include "Colors.h"
#include "Cubes.h"
#include "Position.h"
class Board
{
private:
    int rows;
    int columns;
    int board[ROW][COLUMN];
public:
    Board();
    ~Board();
    void initialize();
    void drawBoard();
    void insetBlock(int row, int column,int value);
    bool isOutside(int row, int column);
    void printBoard();
};
