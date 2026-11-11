#pragma once
#include "raylib.h"
class Renderer
{
    private:
    public:
    void DrawSprite(const Texture2D & texture , Vector2 position);
    void DrawHitBox(const Rectangle& rectangle);

};