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

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();

        UpdateSystem(components, delta);
        DrawSystem(components);
    }

    destroyComponentList(components);

    CloseWindow();

    return 0;
}
