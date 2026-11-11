#include "Player.hpp"
#include "Renderer.hpp"
Player::Player(float positionX, float positionY)
    : positionX(positionX),
      positionY(positionY),
      moveSpeed(300.0f),
      velocityY(0.0f),
      gravity(900.0f),
      isGrounded(false),
      jumpStrenght(400.0f),
      // player_idle.png is 80x110; visible pixels span x 9-71, y 14-109.
      // The body (without the arms sticking out) is ~50px wide, and the
      // character is 96px tall from the top of the hair to the feet.
      hitboxWidth(50.0f),
      hitboxHeight(96.0f)
{
}

Rectangle Player::GetHitbox() const
{
  // bottom-center anchored: the hitbox stands on the feet
  return Rectangle{
      positionX - hitboxWidth / 2.0f,
      positionY - hitboxHeight,
      hitboxWidth,
      hitboxHeight};
}

void Player::Render()
{
  if (!IsTextureValid(playerTexture))
    {
        return;
    }

    // bottom-center anchored: the sprite's bottom row (the feet) sits on positionY
    Vector2 drawPosition = {
        positionX - playerTexture.width / 2.0f,
        positionY - playerTexture.height
    };

    DrawTextureV(playerTexture, drawPosition, WHITE);
    DrawRectangleLinesEx(GetHitbox(), 2.0f, GREEN);
}

void Player::Update(unsigned int screenWidth,unsigned int screenHeight)
{
  float deltaTime = GetFrameTime();
  
  float minX = this->hitboxWidth / 2.0f;
  float maxX = screenWidth- (this->hitboxWidth / 2.0f);

  // positionY is the feet, so the ground is simply the bottom of the screen
  float maxY = static_cast<float>(screenHeight);
  
  float previousY = positionY;

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