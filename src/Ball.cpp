#include "../hdr/Ball.h"

Ball::Ball(Vector2 pos, Vector2 vel, float maxSpeed) {
    this->pos = pos;
    this->vel = vel;
    this->maxSpeed = maxSpeed;
}

void Ball::draw() {
    this->pos.x += this->vel.x;
    this->pos.y += this->vel.y;
    DrawCircle(pos.x, pos.y, 10.0f, WHITE);
}

void Ball::movement() {
    if (this->vel.y < 3.0f) {
        //vel.y += 0.1f;
    }
}