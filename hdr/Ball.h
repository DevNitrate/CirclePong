#pragma once

#include <raylib.h>

class Ball {
public:
    Ball(Vector2 pos, Vector2 vel);

    Vector2 pos;
    Vector2 vel;

    void draw();
};