#pragma once


#include <raylib.h>
#include <rlgl.h>
#include <math.h>
#include <iostream>
#include <cmath>

#include "Button.h"
#include "Ball.h"

class Player {
public:
    Player(Vector2 pos, float rotation);

    float rotation;
    float lastRotation;
    Vector2 corners[4] = {(Vector2){0, 0}, (Vector2){0, 0}};
    Rectangle rect;
    float cornerDist;

    void draw(Color col);
    bool lose(Ball& ball);
    void DrawRect(Rectangle rec, Vector2 origin, float rotation, Color color);
    bool collide(Ball& ball);
};