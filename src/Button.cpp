#include "../hdr/Button.h"

Button::Button(Vector2 size, Vector2 pos, const char* text, Color col, Color textCol) {
    this->btn = { pos.x, pos.y, size.x, size.y };
    this->col = col;
    this->size = size;
    this->pos = pos;
    this->text = text;
    this->textCol = textCol;       //sets color and size and other things

    int xySize = size.x + size.y;
    int avgSize = xySize / 2;

    this->avgSize = avgSize;
}

void Button::draw() {
    int fontSize = this->avgSize/5;
    int x = ((this->pos.x + this->size.x/2) - (this->text.size()) * (fontSize/4));
    int y = ((this->pos.y + this->size.y/2) - (fontSize/2));
    DrawRectangleRec(this->btn, this->col);
    DrawText(this->text.c_str(), x, y, fontSize, this->textCol);
}

bool Button::isHovering() {
    Vector2 mousePos = GetMousePosition();
    if (mousePos.x > this->pos.x && mousePos.x < this->pos.x + this->size.x && mousePos.y > this->pos.y && mousePos.y < this->pos.y + this->size.y) {
        return true;
    }
    return false;
}

bool Button::isClicked() {
    bool isHovering = Button::isHovering();
    if (isHovering) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            return true;
        }
    }

    return false;
}

void Button::updateColor(Color newCol) {
    this->col = newCol;
}