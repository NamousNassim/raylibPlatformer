#include "raylib.h"

int main()
{
    InitWindow(800, 450, "raylib Platformer");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("raylib is working!", 280, 200, 30, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
