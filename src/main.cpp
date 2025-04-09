#include "Game_Utils.h"
#include "Game.h"
#include "Gui.h"

static Game game;
Gui gui;
double lastUpdateTime = 0;

bool SlowUpdate(double speed)
{
    double currentTime = glutGet(GLUT_ELAPSED_TIME);
    if(currentTime - lastUpdateTime >= 500-(speed*10))
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


void keyboard(unsigned char key, int x, int y) {
    game.KeyHandler(key, x, y);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0.027, 0.278, 1);
    game.Draw();
    const char* scoreText = ("Score: " + std::to_string(50)).c_str();
    gui.renderText(30, 80, scoreText);
    glutSwapBuffers();
}

void update(int value) {
    glutTimerFunc(16, update, 0);
    if(SlowUpdate(game.getSpeed())) game.MoveDown();
    glutPostRedisplay();
}
void init() {
    lastUpdateTime = glutGet(GLUT_ELAPSED_TIME);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)WINDOW_WIDTH, (GLdouble)WINDOW_HEIGHT, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, (GLdouble)h, 0.0);
    glutReshapeWindow(WINDOW_WIDTH,WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //Display mode and smoothing animation using swap buffers

    int x = glutGet(GLUT_SCREEN_WIDTH);   //Gets the width of the screen
    int y = glutGet(GLUT_SCREEN_HEIGHT);   //Gets the height of the screen
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); //Sets the window size
    glutInitWindowPosition((x-WINDOW_WIDTH)/2,(y-WINDOW_HEIGHT)/2); //Centers the window
    // Τιτλος παραθύρου
    init();
    glutCreateWindow("Tetris");
    glutTimerFunc(16,update, 0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
