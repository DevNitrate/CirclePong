#pragma once

#include <raylib.h>
#include <rlgl.h>
#include <math.h>

#include "Button.h"
#include "Ball.h"

class Player {
public:
    Player(Vector2 pos, float rotation);

    float rotation;
    Vector2 corners[4] = {(Vector2){0, 0}, (Vector2){0, 0}};
    Rectangle rect;

    void draw(Color col);
    bool collide(Ball& ball);
    void DrawRect(Rectangle rec, Vector2 origin, float rotation, Color color);
    
};