#include "Game.hpp"

Game::Game(
    unsigned int screenWidth,
    unsigned int screenHeight,
    const std::string& gameTitle
): screenWidth(screenWidth),
      screenHeight(screenHeight),
      gameTitle(gameTitle),
      player(100.0f, 300.0f)
{
}

Game::~Game()
{
    if (windowInitialized)
    {
        player.Unload();
        CloseWindow();
        windowInitialized = false;
    }
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
    if (windowInitialized)
    {
        
        return;
    }
   InitWindow(getScreenWidth(),getScreenHeight(),getGameTitle().c_str());
    windowInitialized = IsWindowReady();
    if(windowInitialized)
    {
    SetTargetFPS(60);
     player.Initialize();
    }
   
 }


void Game::Run()
{
    if (!this->windowInitialized)
    {
        return;
    }
while(!WindowShouldClose())
    {
        Update();
        BeginDrawing();
        Render();
        EndDrawing();
    }  
       
}


void Game::Update()
{
         player.Update(this->screenWidth,this->screenHeight);

}
void Game::Render()
{
        ClearBackground(RAYWHITE);
            player.Render();

}