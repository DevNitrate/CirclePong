#include "../hdr/Ball.h"

Ball::Ball(Vector2 pos, Vector2 vel) {
    this->pos = pos;
    this->vel = vel;
}

void Ball::draw() {
    this->pos.x += this->vel.x;
    this->pos.y += this->vel.y;
    DrawCircle(pos.x, pos.y, 10.0f, WHITE);
}
