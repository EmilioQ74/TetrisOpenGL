#pragma once 
#include "Game_Utils.h"
#include "Colors.h"
#include "Cubes.h"
#include "cmath"
class Gui
{
private:
    int score;
    std::string text;
    std::string welcomeText;
    void NextBlock(Cubes block);
    void HowToPlay();
    void Score(int score);
    void DrawRoundedRect(int x, int y, int width, int height, float radius);
    
public:
    Gui(/* args */);
    void renderText(float x, float y, const char *text);
    void Draw(Cubes block, int score);
};