
//---------------------------------------------------------------------------------------------------------------------------------------
//  TO-DO:
//    prob physics Haven't tested mine
//    point system
//    restart when lose
//    give better looks to the game 
//-------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <raylib.h>

#include "../hdr/Player.h"
#include "../hdr/Button.h"
#include "../hdr/Ball.h"

int main () {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);

    Vector2 pos = { (screenWidth / 2), (screenHeight / 2) };
    Player player(pos, 180.0f);

    pos = { (screenWidth / 2), 300 };
    Vector2 vel = { 2.0f, 1.0f };
    Ball ball(pos, vel);

    Color background = { 25, 38, 62, 255 };

    int nextCollide = 5; // this is so that you don't have infinite collisions when the ball clips so a collision can only happen every 5 frame
    bool canCollide = true;

    while (WindowShouldClose() == false){
        if (IsKeyDown(KEY_LEFT)) player.rotation += 4.0f;
        if (IsKeyDown(KEY_RIGHT)) player.rotation -= 4.0f;

        //ball.movement();

        if (canCollide) {
            bool collide = player.collide(ball);
            if (collide) canCollide = false;
        } else {
            if (nextCollide > 0) {
                nextCollide--;
            } else {
                canCollide = true;
                nextCollide = 5;
            }
        }

        player.lose(ball);

        BeginDrawing();
            ClearBackground(background);

            player.draw({ 255, 255, 255, 60 });
            ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}