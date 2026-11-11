#pragma once
#include"Player.hpp"
#include "raylib.h"
#include <string>
#include<algorithm>
class Game
{
    public: 
    Game(const unsigned int screenWidth , const unsigned int screenHeight , const std::string &gameTitle);
    ~Game();
    void Initializer();
    int getScreenWidth();
    int getScreenHeight();
    std::string getGameTitle();

    void Run();
    void Render();   
    void Update();
    
    private:
    //1280 × 720 pixels
    int screenWidth;
    int screenHeight;
    std::string gameTitle;
    bool windowInitialized = false;

    Player player;

};