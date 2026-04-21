#ifndef BUBBLE_H
#define BUBBLE_H

#include "raylib.h"

class Bubble {
private:
    float x;
    float y;
    float r;
    int score;
    bool alive;

public:
    Bubble(float x, float y, float r, int s);

    void draw();
    bool isClicked(int mx, int my);
    int pop();
    bool isAlive();
};

#endif