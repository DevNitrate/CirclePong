#include <iostream>
#include <raylib.h>
#include <string>

#include "../hdr/Player.h"
#include "../hdr/Button.h"
#include "../hdr/Ball.h"

int main () {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    enum Menu {
        Start,
        Game,
        End
    };

    Menu menu = Menu::Start;

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);

    Vector2 pos = { (screenWidth / 2), (screenHeight / 2) };
    Player player(pos, 180.0f);

    pos = { (screenWidth / 2), 300 };
    Vector2 vel = { 2.0f, 1.0f };
    Ball ball(pos, vel, 3.0);

    Color background = { 25, 38, 62, 255 };

    int nextCollide = 5; // this is so that you don't have infinite collisions when the ball clips so a collision can only happen every 5 frame
    bool canCollide = true;

    bool skipFirstFrame = true; // makes the first frame of the game not make the player instantly lose

    Button startBtn({ 400, 100 }, { ((screenWidth / 2) - 200), ((screenHeight / 2) - 50) }, "start", WHITE, BLACK, 80);
    Button closeBtn({ 400, 100 }, { ((screenWidth / 2) - 200), ((screenHeight / 2) + 150) }, "exit", WHITE, BLACK, 80);
    Button endBtn({ 400, 100 }, { ((screenWidth / 2) - 200), ((screenHeight / 2) - 50) }, "restart", WHITE, BLACK, 80);

    int score = 0;

    while (WindowShouldClose() == false){
        if (IsKeyDown(KEY_LEFT)) player.rotation += 4.0f;
        if (IsKeyDown(KEY_RIGHT)) player.rotation -= 4.0f;

        ball.movement();

        if (canCollide) {
            bool collide = player.collide(ball);
            if (collide) {
                canCollide = false;
                score++;
            }
        } else {
            if (nextCollide > 0) {
                nextCollide--;
            } else {
                canCollide = true;
                nextCollide = 5;
            }
        }

        if (!skipFirstFrame) {
            bool lost = player.lose(ball);
            if (lost) {
                menu = Menu::End;
                ball.pos = { (screenWidth / 2), 300 };
                ball.vel = vel;
                player.rotation = 180.0f;
                score = 0;
            }
        }

        BeginDrawing();
            ClearBackground(background);

            if (menu == Menu::Start) {
                bool start = startBtn.isClicked();
                bool close = closeBtn.isClicked();
                if (start) {
                    menu = Menu::Game;
                }

                if (close) {
                    exit(0);
                }
                startBtn.draw();
                closeBtn.draw();
            } else if (menu == Menu::Game) {
                DrawRing({(screenWidth / 2), (screenHeight / 2)}, player.cornerDist, player.cornerDist+5, 0.0f, 360.0f, 64, RED);
                player.draw({ 255, 255, 255, 255 });
                ball.draw();
                skipFirstFrame = false;

                std::string scoreStr = "Score: ";
                scoreStr.append(std::to_string(score));
                DrawText(scoreStr.c_str(), 10, 10, 40, GREEN);
            } else if (menu == Menu::End) {
                endBtn.draw();
                bool start = endBtn.isClicked();
                if (start) {
                    menu = Menu::Start;
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}