#include "Game.hpp"

Game::Game(const unsigned screenWidth , const unsigned int screenHeight , const std::string gameTitle)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight; 
    this->gameTitle = gameTitle;
    this->positionX = this->screenWidth / 2.0f;
    this->moveSpeed = 300.0f;
}

Game::~Game()
{
    if (windowInitialized)
    {
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

void Game::Render()
{   
    ClearBackground(RAYWHITE);
    DrawCircle(this->positionX , getScreenHeight()/2,this->circleRadius,RED);
}

void Game::Update()
{
    float deltaTime = GetFrameTime();


    float minX = this->circleRadius;
    float maxX = this->screenWidth - this->circleRadius;

 


    if(IsKeyDown(KEY_RIGHT))
    {
        this->positionX += this->moveSpeed * deltaTime;
    }
    if(IsKeyDown(KEY_LEFT))
    {
        this->positionX -= this->moveSpeed * deltaTime;
    }


    // position clamp (boundries)
     this->positionX = std::clamp(
    this->positionX,
    minX,
    maxX
);
}