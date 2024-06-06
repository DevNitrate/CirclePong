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
    Vector2 corners[4] = {(Vector2){0, 0}, (Vector2){0, 0}};
    Rectangle rect;

    void draw(Color col);
    void collision(Ball& ball);
    void lose(Ball& ball);
    void DrawRect(Rectangle rec, Vector2 origin, float rotation, Color color);
    void DeterminePhysichs(float rotation, float last_rotation,Ball& ball );
    void GetRotation(float rotation,float last_rotation);
    bool collide(Ball& ball);
};