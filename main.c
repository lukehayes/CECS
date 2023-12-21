#include "raylib.h"
#include "Engine.h"
#include "Externs.h"

float delta = 0.0;

int main() {

    initEngine();

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();
    }

    CloseWindow();

    return 0;
}
