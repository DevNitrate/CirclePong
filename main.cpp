#include <iostream>
#include <raylib.h>

#include "Player.h"
#include "Button.h"
#include "Ball.h"

int main () {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);

    Vector2 pos = { (screenWidth / 2), (screenHeight / 2) };
    Player player(pos, 180.0f);

    pos = { (screenWidth / 2), 300 };
    Vector2 vel = { 2.0f, 0.0f };
    Ball ball(pos, vel);

    while (WindowShouldClose() == false){
        if (IsKeyDown(KEY_LEFT)) player.rotation += 4.0f;
        if (IsKeyDown(KEY_RIGHT)) player.rotation -= 4.0f;

        player.collide(ball);
        BeginDrawing();
            ClearBackground(BLACK);

            player.draw({ 255, 255, 255, 255 });
            ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}