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
    Player player(pos, 0.0f);

    pos = { (screenWidth / 2), 600 };
    Vector2 vel = { 0, 0 };
    Ball ball(pos, vel);

    while (WindowShouldClose() == false){
        if (IsKeyDown(KEY_LEFT)) player.rotation += 4.0f;
        if (IsKeyDown(KEY_RIGHT)) player.rotation -= 4.0f;

        bool collide = player.collide(ball);
        BeginDrawing();
            ClearBackground(BLACK);

            if (collide) {
                player.draw({ 255, 0, 0, 255 });
            } else {
                player.draw({ 255, 255, 255, 255 });
            }
            ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}