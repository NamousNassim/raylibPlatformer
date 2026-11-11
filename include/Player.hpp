#pragma once
#include "raylib.h"
#include<algorithm>
#include<iostream>

/*
velocityY = 0



gravity = 900



deltaTime = 0.02
*/


class Player
{
    public:
        Player(float positionX ,float positionY);
        void Render();
        void Update(unsigned int screenWidth,unsigned int screenHeight);
        void Initialize();
        void Unload();
    private:
    Rectangle GetHitbox() const;

    // position is the player's FEET (bottom-center), not the sprite center.
    // Sprite, hitbox and ground check are all measured from this point.
    float positionX;
    float positionY;
    float moveSpeed;
    float velocityY;
    float gravity;
    float jumpStrenght;
    float hitboxWidth;
    float hitboxHeight;
    bool isGrounded; // true - standing on the ground | false ; player on air

    // textures 

    Texture2D playerTexture{};

};