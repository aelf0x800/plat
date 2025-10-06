#include <raylib.h>
#include "World/Tokeniser.hpp"

int main() 
{
    Tokeniser t;

    InitWindow(600, 600, "test");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();
}
