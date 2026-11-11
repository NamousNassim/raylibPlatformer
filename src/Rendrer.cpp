#include "Renderer.hpp"

void Renderer::DrawSprite(const Texture2D & texture , Vector2 position)
{
    DrawTexture(texture , position.x,position.y , WHITE);
}

void Renderer::DrawHitBox(const Rectangle& rectangle)
{
    DrawRectangleLinesEx(rectangle,2.0f,GREEN);
}