#include "Gui.h"

void drawCorner(float x, float y, float radius, const char* corner);


void Gui::NextBlock(Cubes block)
{
    int SQUARE_TOP = BORDER_TOP+10, SQUARE_BOTTOM = BORDER_TOP+ 250, SQUARE_LEFT = BORDER_RIGHT + 50 , SQUARE_RIGHT = WINDOW_WIDTH-50;
    DrawRoundedRect(SQUARE_LEFT, SQUARE_TOP, SQUARE_RIGHT, SQUARE_BOTTOM, 10);
    glColor3fv(colors[COLOR_WHITE]);
    renderText(SQUARE_LEFT+20, SQUARE_TOP+20, "NEXT\t\tBLOCK");
    block.Move(4,9);
    block.Draw();
}

void Gui::HowToPlay()
{
    int SQUARE_TOP = BORDER_TOP + 300, SQUARE_BOTTOM = WINDOW_HEIGHT-50, SQUARE_LEFT = BORDER_RIGHT + 50 , SQUARE_RIGHT = WINDOW_WIDTH-50;
    DrawRoundedRect(SQUARE_LEFT, SQUARE_TOP, SQUARE_RIGHT, SQUARE_BOTTOM, 10);
    glColor3fv(colors[COLOR_WHITE]);
    renderText(SQUARE_LEFT+20, SQUARE_TOP+20, "HOW TO PLAY");
    renderText(SQUARE_LEFT+20, SQUARE_TOP+60, "Use a or left arrow for left");
    renderText(SQUARE_LEFT+20, SQUARE_TOP+80, "Use d or right arrow for right");
    renderText(SQUARE_LEFT+20, SQUARE_TOP+100, "Use w or up arrow for rotate");
    renderText(SQUARE_LEFT+20, SQUARE_TOP+120, "Use s or down arrow for down");
    renderText(SQUARE_LEFT+20, SQUARE_TOP+140, "Use space for drop dorwn");
    renderText(SQUARE_LEFT + 20, SQUARE_TOP + 180, "Use r for Reset");
}

void Gui::Score(int score)
{
    int SQUARE_TOP =  15, SQUARE_BOTTOM = BORDER_TOP - 10, SQUARE_LEFT = 10 , SQUARE_RIGHT = BORDER_RIGHT;
    DrawRoundedRect(SQUARE_LEFT, SQUARE_TOP, SQUARE_RIGHT, SQUARE_BOTTOM, 10);
    glColor3fv(colors[COLOR_WHITE]);
    char* scoreText = new char[1000];
    sprintf(scoreText, "%d", score);
    renderText(SQUARE_LEFT+10, SQUARE_TOP+40, scoreText);
    renderText(SQUARE_LEFT+10, SQUARE_TOP+10, "Score:");
}

void Gui::DrawRoundedRect(int x, int y, int width, int height, float radius)
{
    glColor4fv(colors[COLOR_LIGHT_BLUE]);
    glRectd(x, y, width, height); //draws the rectangle
    drawCorner(x, y, radius, "top-left");
    drawCorner(width, y, radius, "top-right");
    glRectd(x-radius, y, x, height); //draws the rectangle from the left top to the bottom
    glRectd(width, y, width+radius, height); // draws the rectangle from the right top to the bottom
    glRectd(x, y-radius, width, y); //draws the rectangle from the left bottom to the right
}

void drawCorner(float x, float y, float radius, const char* corner) {
    const int segments = 20;
    float startAngle = 0.0f;

    // Determine start angle based on corner name
    if (strcmp(corner, "top-right") == 0) {
        startAngle = 1.5f * M_PI; // 270°
    } else if (strcmp(corner, "top-left") == 0) {
        startAngle = M_PI; // 180°
    } else if (strcmp(corner, "bottom-left") == 0) {
        startAngle = 0.5f * M_PI; // 90°
    } else if (strcmp(corner, "bottom-right") == 0) {
        startAngle = 0.0f; // 0°
    } else {
        return; // Invalid corner
    }

    // Draw quarter circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center

    for (int i = 0; i <= segments; ++i) {
        float angle = startAngle + (M_PI / 2.0f) * (i / (float)segments);
        float cx = x + cos(angle) * radius;
        float cy = y + sin(angle) * radius;
        glVertex2f(cx, cy);
    }

    glEnd();
}


Gui::Gui()
{

}

void Gui::renderText(float x, float y, const char *text)
{
    glRasterPos2f(x, y); // Set position (in 2D)
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void Gui::Draw(Cubes block, int score)
{
    HowToPlay();
    NextBlock(block);
    Score(score);
}
