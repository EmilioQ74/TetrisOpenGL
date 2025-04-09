#include "Gui.h"

#include "Gui.h"

#include <GL/freeglut.h> // or <GL/glut.h>

void Gui::renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y); // Set position (in 2D)
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
