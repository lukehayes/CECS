#include "raylib.h"
#include "Engine.h"
#include "ECS/System.h"
#include "ECS/Component.h"
#include "ECS/Globals.h"

#include "Util.h"

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

        #ifdef DEV_DEBUG
        drawDebug();
        #endif

    }

    destroyComponentList(components);

    CloseWindow();

    return 0;
}
