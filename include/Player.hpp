#pragma once
#include "raylib.h"
#include<algorithm>

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
    private:
    float positionX;
    float positionY;
    float moveSpeed;
    float circleRadius;
    float velocityY;
    float gravity;
    float jumpStrenght;

    bool isGrounded; // true - standing on the ground | false ; player on air
};