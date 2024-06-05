#include "Player.h"
#include "Ball.h"
#include <iostream>
#include <cmath>

Player::Player(Vector2 pos, float rotation) {
    this->rect = { pos.x, pos.y, 200, 50 };
    this->rotation = rotation;
}

void Player::draw(Color col) {
    DrawRect(rect, { 100, 25 + 250}, rotation, col);
}

//bool CalcDist(corners[0],this->pos,float Checkcollide ){
//   Checkcollide = corners[0] - Ball.pos;
//}

void Player::collide(Ball& ball) {
    // make the collisions work, the DrawRect function is the same as the raylib one but updates the corners array so every corner position is stored in it: corners[0] = topLeft corner, corners[1] = topRight corner, corners[2] = bottomRight corner, corners[3] = bottomLeft corner. So if you're good at math make something with it and make it work
    
    int lengthX = corners[2].x - corners[3].x; // get the horizontal between the two points of the line
    int lengthY = corners[2].y - corners[3].y; // same as above but for vertical distance
    int length = sqrt((lengthX * lengthX) + (lengthY * lengthY)); // now get the actual distance using pythagorean theorem: sqrt(A^2 + B^2) = hypothenus

    float dot = (((ball.pos.x - corners[2].x) * (corners[3].x - corners[2].x) + (ball.pos.y - corners[2].y) * (corners[3].y - corners[2].y))) / pow(length, 2);

    float closestX = corners[2].x + (dot * (corners[3].x - corners[2].x));
    float closestY = corners[2].y + (dot * (corners[3].y - corners[2].y));

    float distX = closestX - ball.pos.x;
    float distY = closestY - ball.pos.y;
    float dist = sqrt((distX * distX) + (distY * distY));

    if (dist <= 10.0f) { // is the distance of the ball to the closest point on the line is less than or equal to the radius it means we are colliding
        ball.vel.x *= -1; // invert the x speed
        ball.vel.y *= -1; // invert the y speed
    }

    if (ball.pos.x > (GetScreenWidth() / 2) + 225) {
       exit(0);
    }
}

void Player::DrawRect(Rectangle rec, Vector2 origin, float rotation, Color color)
{
    Vector2 topLeft = { 0 };
    Vector2 topRight = { 0 };
    Vector2 bottomLeft = { 0 };
    Vector2 bottomRight = { 0 };

    // Only calculate rotation if needed
    if (rotation == 0.0f)
    {
        float x = rec.x - origin.x;
        float y = rec.y - origin.y;
        topLeft = (Vector2){ x, y };
        topRight = (Vector2){ x + rec.width, y };
        bottomLeft = (Vector2){ x, y + rec.height };
        bottomRight = (Vector2){ x + rec.width, y + rec.height };
    }
    else
    {
        float sinRotation = sinf(rotation*DEG2RAD);
        float cosRotation = cosf(rotation*DEG2RAD);
        float x = rec.x;
        float y = rec.y;
        float dx = -origin.x;
        float dy = -origin.y;

        topLeft.x = x + dx*cosRotation - dy*sinRotation;
        topLeft.y = y + dx*sinRotation + dy*cosRotation;

        topRight.x = x + (dx + rec.width)*cosRotation - dy*sinRotation;
        topRight.y = y + (dx + rec.width)*sinRotation + dy*cosRotation;

        bottomLeft.x = x + dx*cosRotation - (dy + rec.height)*sinRotation;
        bottomLeft.y = y + dx*sinRotation + (dy + rec.height)*cosRotation;

        bottomRight.x = x + (dx + rec.width)*cosRotation - (dy + rec.height)*sinRotation;
        bottomRight.y = y + (dx + rec.width)*sinRotation + (dy + rec.height)*cosRotation;

    }
    corners[0] = topLeft;
    corners[1] = topRight;
    corners[2] = bottomRight;
    corners[3] = bottomLeft;


#if defined(SUPPORT_QUADS_DRAW_MODE)
    rlSetTexture(texShapes.id);

    rlBegin(RL_QUADS);

        rlNormal3f(0.0f, 0.0f, 1.0f);
        rlColor4ub(color.r, color.g, color.b, color.a);

        rlTexCoord2f(texShapesRec.x/texShapes.width, texShapesRec.y/texShapes.height);
        rlVertex2f(topLeft.x, topLeft.y);

        rlTexCoord2f(texShapesRec.x/texShapes.width, (texShapesRec.y + texShapesRec.height)/texShapes.height);
        rlVertex2f(bottomLeft.x, bottomLeft.y);

        rlTexCoord2f((texShapesRec.x + texShapesRec.width)/texShapes.width, (texShapesRec.y + texShapesRec.height)/texShapes.height);
        rlVertex2f(bottomRight.x, bottomRight.y);

        rlTexCoord2f((texShapesRec.x + texShapesRec.width)/texShapes.width, texShapesRec.y/texShapes.height);
        rlVertex2f(topRight.x, topRight.y);

    rlEnd();

    rlSetTexture(0);
#else
    rlBegin(RL_TRIANGLES);

        rlColor4ub(color.r, color.g, color.b, color.a);

        rlVertex2f(topLeft.x, topLeft.y);
        rlVertex2f(bottomLeft.x, bottomLeft.y);
        rlVertex2f(topRight.x, topRight.y);

        rlVertex2f(topRight.x, topRight.y);
        rlVertex2f(bottomLeft.x, bottomLeft.y);
        rlVertex2f(bottomRight.x, bottomRight.y);

    rlEnd();
#endif
}