#include "Board.h"

 

Board::Board()
{
    this->rows = ROW;
    this->columns = COLUMN;
    initialize();
}

Board::~Board()
{

}

void Board::initialize()
{
    for(int i = 0; i <= ROW; i++)
    {
        for(int j = 0; j <= COLUMN; j++)
        {
            this->board[i][j] = 0;
        }
    }
}
void Board::drawBoard()
{
    for(int i = 0; i < ROW ; i++)
        {
            for(int j = 0; j<COLUMN; j++)
            {
                DrawCell(i,j);
            }
        }
}

void Board::insetBlock(int row, int column,int value)
{
    this->board[row][column] = value;
}

bool Board::isCellEmpty(int row, int column)
{
    if(board[row][column]==0)return true;
    return false;
}

bool Board::isOutside(int row, int column)
{
    if(row>= 0 && row < ROW && column>= 0 && column < COLUMN)
        return false;
    return true;
}

int Board::ClearFullRow()
{
    int completedRow = 0;
    for(int row = ROW-1;row >= 0;row--)
    {
        if(isRowFull(row))
        {
             ClearRow(row);
             completedRow++;
        }else if(completedRow>0)
        {
            MoveRowDown(row,completedRow);
        }
    }
    return completedRow;
}

void Board::Reset()
{
    for(int row = 0;row<ROW;row++)
    {
        for(int column = 0;column<COLUMN;column++)
        {
            this->board[row][column] = 0;
        }
    }
}

void Board::DrawCell(int row,int column)
{
    glColor4fv(colors[board[row][column]]);
    glRectd(column*CELL_SIZE_WIDTH + CELL_POS_X + LINE_WIDTH, row*CELL_SIZE_HEIGHT + CELL_POS_Y+LINE_WIDTH, column*CELL_SIZE_WIDTH + BORDER_LEFT + CELL_SIZE_WIDTH-LINE_WIDTH, row*CELL_SIZE_HEIGHT + BORDER_TOP + CELL_SIZE_HEIGHT-LINE_WIDTH);
}

bool Board::isRowFull(int row)
{
    for(int column = 0; column < COLUMN; column++)
    {
        if(board[row][column]== 0)return false;
    }
    return true;
}

void Board::ClearRow(int row)
{
    for(int columns = 0;columns<COLUMN;columns++)
    {
        board[row][columns] = 0;
    }
}

void Board::MoveRowDown(int row, int numRows)
{
    for(int column=0;column<ROW;column++)
    {
        board[row+numRows][column] = board[row][column];
        board[row][column]=0;
    }
}

void Board::printBoard()
{
    for(int i = 0; i <= ROW; i++)
    {
        for(int j = 0; j <= COLUMN; j++)
        {
            printf("%d ",this->board[i][j]);
        }
        printf("\n");
   }
}

