#include "Player.hpp"

Player::Player(float positionX, float positionY)
    : positionX(positionX),
      positionY(positionY),
      moveSpeed(300.0f),
      circleRadius(50.0f),
      velocityY(0.0f),
      gravity(900.0f),
      isGrounded(false)
{
}

void Player::Render()
{
      DrawCircle(this->positionX , this->positionY,this->circleRadius,RED);

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
    if(this->positionY == maxY)
    {
      this->isGrounded == true;
    }

  if(positionY > maxY)
  {
      this->positionY = maxY;
      this->velocityY = 0.0f;
  }

    if(IsKeyDown(KEY_RIGHT))
    {
        this->positionX += this->moveSpeed * deltaTime;
    }
    if(IsKeyDown(KEY_LEFT))
    {
        this->positionX -= this->moveSpeed * deltaTime;
    }


  

     this->positionX = std::clamp(this->positionX,minX,maxX);


}