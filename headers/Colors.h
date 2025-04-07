#pragma once

// Define total number of colors
#define TOTAL_COLORS 9

// Define color indexes
#define COLOR_BLACK   0
#define COLOR_CYAN    1
#define COLOR_BLUE    2
#define COLOR_ORANGE  3
#define COLOR_YELLOW  4
#define COLOR_GREEN   5
#define COLOR_PURPLE  6
#define COLOR_RED     7
#define COLOR_WHITE   8

// Define the colors array using macros
#define COLORS { \
    {0.0f, 0.0f, 0.0f, 1.0f}, /* BLACK */   \
    {0.0f, 1.0f, 1.0f, 1.0f}, /* CYAN */    \
    {0.0f, 0.0f, 1.0f, 1.0f}, /* BLUE */    \
    {1.0f, 0.5f, 0.0f, 1.0f}, /* ORANGE */  \
    {1.0f, 1.0f, 0.0f, 1.0f}, /* YELLOW */  \
    {0.0f, 1.0f, 0.0f, 1.0f}, /* GREEN */   \
    {1.0f, 0.0f, 1.0f, 1.0f}, /* PURPLE */  \
    {1.0f, 0.0f, 0.0f, 1.0f}, /* RED */     \
    {1.0f, 1.0f, 1.0f, 1.0f}  /* WHITE */   \
}

const float colors[TOTAL_COLORS][4] = COLORS;