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
    glPointSize(LINE_WIDTH);;
    int lines = BORDER_LEFT;
    //COLUMNS
    for(int i = 0; i <= COLUMN; i++)
    {
        glBegin(GL_LINES);
        glColor4fv(colors[COLOR_WHITE]);
        glVertex2f(lines, BORDER_TOP);
        glVertex2f(lines, BORDER_TOP + ROW*CELL_SIZE_HEIGHT);
        lines += CELL_SIZE_WIDTH;
        glEnd();
    }
    //ROWS
    lines = BORDER_TOP;
    for(int i = 0; i <= ROW; i++)
    {
        glBegin(GL_LINES);
        glVertex2f(BORDER_LEFT, lines);
        glVertex2f(BORDER_LEFT + COLUMN*CELL_SIZE_WIDTH, lines);
        lines += CELL_SIZE_HEIGHT;
        glEnd();
    }
}

void Board::insetBlock(int row, int column,int value)
{
    this->board[row][column] = value;
}

bool Board::isOutside(int row, int column)
{
    if(row < 0 || row > ROW || column < 0 || column > COLUMN)
        return true;
    return false;
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

