#include "raylib.h"
#include "logging.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int MAX = 5;
Color BGCOLOR = {250, 243, 221, 255};

int main() {

    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
