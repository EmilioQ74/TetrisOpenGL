#pragma once 
#include "Game.h"


class Gui
{
private:
    int score;
    std::string text;
    std::string welcomeText;
public:
    void renderText(float x, float y, const char *text);
};