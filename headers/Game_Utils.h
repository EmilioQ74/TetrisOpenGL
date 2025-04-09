#ifndef GAME_UTILS_H
#define GAME_UTILS_H
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <map>
#include <vector>
#include <iostream>
// Define the width and height of the window
#define WINDOW_WIDTH 800   // Set the width of the window to 1920 pixels
#define WINDOW_HEIGHT 700  // Set the height of the window to 1080 pixels

// Define the number of rows and columns for the grid
#define ROW 20      // Set the number of rows to 20
#define COLUMN 10   // Set the number of columns to 10

#define LINE_WIDTH 1

// Define the position of the first cell
#define CELL_POS_X BORDER_LEFT  // Set the x position of the first cell to the left border
#define CELL_POS_Y BORDER_TOP   // Set the y position of the first cell to the top border

// Calculate the size of each cell based on the border dimensions and number of rows/columns
#define CELL_SIZE_HEIGHT (BORDER_HEIGHT/ROW)  // Calculate the height of each cell
#define CELL_SIZE_WIDTH (BORDER_WIDTH/COLUMN) // Calculate the width of each cell

// Define the border dimensions and positions
#define BORDER_WIDTH 400 // Set the width of the border to 400 pixels
#define BORDER_HEIGHT 600 // Set the height of the border to 600 pixels

// Calculate the positions of the borders based on the window dimensions and border dimensions
#define BORDER_LEFT (CELL_SIZE_WIDTH)  // Calculate the x position of the left border to center it horizontally
#define BORDER_TOP (BORDER_BOTTOM-BORDER_HEIGHT)  // Calculate the y position of the top border to center it vertically

// Calculate the positions of the right and bottom borders based on the left and top borders
#define BORDER_RIGHT (BORDER_LEFT+BORDER_WIDTH)  // Calculate the x position of the right border
#define BORDER_BOTTOM (WINDOW_HEIGHT-CELL_SIZE_HEIGHT)  // Calculate the y position of the bottom border

#endif // GAME_UTILS_H



//need fixing rotate when is on wall 
//add score just for dispalying
//and random nextBlock