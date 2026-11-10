#include "Game.hpp"

Game::Game(const unsigned screenWidth , const unsigned int screenHeight , const std::string gameTitle)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight; 
    this->gameTitle = gameTitle;
}

int Game::getScreenWidth()
{
    return this->screenWidth;
}

int Game::getScreenHeight()
{
    return this->screenHeight;
}

std::string Game::getGameTitle()
{
    return this->gameTitle;
}

void Game::Initializer()
{
    SetTargetFPS(60);
   InitWindow(getScreenWidth(),getScreenHeight(),getGameTitle().c_str());
    while(!WindowShouldClose())
    {
        BeginDrawing();
        DrawCircle(this->screenWidth/2 , this->screenHeight / 2, 40,RED );

        EndDrawing();
    }
    

}


