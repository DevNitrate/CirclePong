#pragma once

#include <raylib.h>

class Ball {
public:
    Ball(Vector2 pos, Vector2 vel, float maxSpeed);

    Vector2 pos;
    Vector2 vel;
    float maxSpeed;

    void draw();
    void movement();
};