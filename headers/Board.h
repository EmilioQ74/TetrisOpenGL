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
    void DrawCell(int row, int column);
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row,int numRows);
public:
    Board();
    ~Board();
    void initialize();
    void drawBoard();
    void insetBlock(int row, int column,int value);
    bool isCellEmpty(int row,int column);
    bool isOutside(int row, int column);
    int ClearFullRow();
    void Reset();

    void printBoard();
};
