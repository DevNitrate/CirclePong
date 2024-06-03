#include <iostream>
#include <raylib.h>

int main () {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}