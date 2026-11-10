#pragma once
#include "raylib.h"
#include <string>
class Game
{
    public: 
    Game(const unsigned int screenWidth , const unsigned int screenHeight , const std::string gameTitle);
    void Initializer();
    int getScreenWidth();
    int getScreenHeight();
    std::string getGameTitle();
    private:
    //1280 × 720 pixels
    int screenWidth;
    int screenHeight;
    std::string gameTitle;


};