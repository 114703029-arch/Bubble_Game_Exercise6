#include "raylib.h"
#include "bubble.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "EX06 - Click the Bubble");
    SetTargetFPS(60);

    srand((unsigned int)time(NULL));

    std::vector<Bubble> bubbles;
    int score = 0;
    int spawnTimer = 0;

    while (!WindowShouldClose()) {
        spawnTimer++;

        // create a new bubble every 30 frames
        if (spawnTimer >= 30) {
            float bubbleX = (float)(50 + rand() % 700);
            float bubbleY = (float)(50 + rand() % 350);
            float bubbleRadius = (float)(20 + rand() % 30);

            Bubble newBubble(bubbleX, bubbleY, bubbleRadius, 10);
            bubbles.push_back(newBubble);

            spawnTimer = 0;
        }

        // check if player clicks a bubble
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            for (size_t i = 0; i < bubbles.size(); i++) {
                if (bubbles[i].isClicked(mouseX, mouseY)) {
                    score += bubbles[i].pop();
                    break;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (size_t i = 0; i < bubbles.size(); i++) {
            if (bubbles[i].isAlive()) {
                bubbles[i].draw();
            }
        }

        DrawText("Click the bubble!", 20, 20, 30, DARKBLUE);
        DrawText(TextFormat("Score: %d", score), 20, 60, 30, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}