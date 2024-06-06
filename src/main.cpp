
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

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);

    Vector2 pos = { (screenWidth / 2), (screenHeight / 2) };
    Player player(pos, 180.0f);

    pos = { (screenWidth / 2), 300 };
    Vector2 vel = { 2.0f, 1.0f };
    Ball ball(pos, vel);

    while (WindowShouldClose() == false){
        if (IsKeyDown(KEY_LEFT)) player.rotation += 4.0f;
        if (IsKeyDown(KEY_RIGHT)) player.rotation -= 4.0f;

        player.collision(ball);   //changed the name to create a boolean for the if
        player.lose(ball);

        if (player.collide(ball)){      //checks if the player collides
           player.GetRotation( rotation,float last_rotation);  //gets rotation          FIX THIS PART
           player.DeterminePhysichs( rotation,  last_rotation,ball );//uses that to calculate where to send the ball
        }

        BeginDrawing();
            ClearBackground(BLACK);

            player.draw({ 255, 255, 255, 255 });
            ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}