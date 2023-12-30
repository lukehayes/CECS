#include "raylib.h"
#include "Engine.h"
#include "ECS/System.h"
#include "ECS/Component.h"
#include "ECS/Globals.h"

#include <stdio.h>

float delta = 0.0;

int main() {

    initEngine();
    ComponentList* components = fillComponentList();

    addTransform(0, 100,100, LIGHT, components);
    addCollision(0, 100,100, 20, components);

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();

        UpdateSystem(components, delta);
        CollisionSystem(components, delta);
        DrawSystem(components);

        char fps[100];
        char ent_count[100];

        sprintf(fps, "FPS: %i", GetFPS());
        sprintf(ent_count, "Entity Count: %i", COMPONENT_COUNT);

        BeginDrawing();
            DrawText(fps, 10,10, 26, WHITE);
            DrawText(ent_count, 10,50, 26, WHITE);
        EndDrawing();

    }

    destroyComponentList(components);

    CloseWindow();

    return 0;
}
