// Entry point
#include "raylib.h"
const int screenWidth = 800;
const int screenHeight = 450;


int main()
{
    InitWindow(screenWidth,screenHeight,"Hello Traingle");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        Vector2 v1 = {400.0f,100.0f};
        Vector2 v2 = {250.0f , 320.0f};
        Vector2 v3 = {550.0f , 320.0f};
        
        DrawTriangle(v1,v2,v3,RED);
        DrawText("Hello Traingle!" , 10,10,20,LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
