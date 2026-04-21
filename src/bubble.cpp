#include "bubble.h"

Bubble::Bubble(float x, float y, float r, int s) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->score = s;
    alive = true;
}

void Bubble::draw() {
    if (alive) {
        DrawCircle((int)x, (int)y, r, SKYBLUE);
    }
}

bool Bubble::isClicked(int mx, int my) {
    if (!alive) return false;

    return CheckCollisionPointCircle(
        Vector2{ (float)mx, (float)my },
        Vector2{ x, y },
        r
    );
}

int Bubble::pop() {
    if (!alive) return 0;

    alive = false;
    return score;
}

bool Bubble::isAlive() {
    return alive;
}