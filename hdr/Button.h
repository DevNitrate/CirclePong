#pragma once

#include <raylib.h>
#include <iostream>
#include <string>

enum class Event {
    Hovered,
    Clicked
};

class Button {
public:
    Button(Vector2 size, Vector2 pos, const char* text, Color col, Color textCol, int fontSize);

    Rectangle btn;
    Color col;
    Color textCol;
    Vector2 size;
    Vector2 pos;
    std::string text;
    int fontSize;

    void draw();
    bool isHovering();
    bool isClicked();
    void updateColor(Color newCol);
};