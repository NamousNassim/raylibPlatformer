#include "Player.hpp"

Player::Player(float positionX, float positionY)
    : positionX(positionX),
      positionY(positionY),
      moveSpeed(300.0f),
      circleRadius(50.0f),
      velocityY(0.0f),
      gravity(900.0f),
      isGrounded(false),
      jumpStrenght(400.0f)
{
}

void Player::Render()
{
  if (!IsTextureValid(playerTexture))
    {
        return;
    }

     Vector2 drawPosition = {
        positionX - playerTexture.width / 2.0f,
        positionY - playerTexture.height / 2.0f
    };

    DrawTextureV(playerTexture, drawPosition, WHITE);

}

void Player::Update(unsigned int screenWidth,unsigned int screenHeight)
{
  float deltaTime = GetFrameTime();
  
  float minX = this->circleRadius;
  float maxX = screenWidth- this->circleRadius;

  float maxY = screenHeight - this->circleRadius;
  
  this->velocityY += this->gravity * deltaTime;
  this->positionY += this->velocityY * deltaTime;
  //grounding logic 
  

  if(positionY >= maxY)
  {
      this->positionY = maxY;
      this->velocityY = 0.0f;
      this->isGrounded = true;
  }
  else{
    this->isGrounded = false;
  }

    if(IsKeyDown(KEY_RIGHT))
    {
        this->positionX += this->moveSpeed * deltaTime;
    }
    if(IsKeyDown(KEY_LEFT))
    {
        this->positionX -= this->moveSpeed * deltaTime;
    }

    // jump 

    if(isGrounded && IsKeyPressed(KEY_SPACE))
      {
        this->velocityY =- this->jumpStrenght;
        this->isGrounded = false;
      }


     this->positionX = std::clamp(this->positionX,minX,maxX);
}

void Player::Initialize()
{
  this->playerTexture = LoadTexture("assets/textures/Player/player_idle.png");
  if(!IsTextureValid(this->playerTexture))
  {
    std::cerr << "Failed to load player texture!\n";

    return;
  }

}


void Player::Unload()
{
  if(IsTextureValid(this->playerTexture))
  {
      UnloadTexture(this->playerTexture);
      this->playerTexture = {};
  }
}