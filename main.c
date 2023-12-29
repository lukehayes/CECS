#include "raylib.h"
#include "Engine.h"
#include "ECS/System.h"
#include "ECS/Component.h"

#include <stdio.h>

float delta = 0.0;

int main() {

    initEngine();

    ComponentList* components = createComponentList();

    for(int x = 0; x <= COMPONENT_COUNT - 1; x++)
    {
        for(int y = 0; y <= COMPONENT_COUNT - 1; y++)
        {
            int N = 30;
            int rx = x;
            int ry = y;
            addTransform(x + y + 1, rx,ry, BLUE, components);
        }
    }

    /*addTransform(0,100,100, BLUE, components);*/
    /*addTransform(1,200,500, RED, components);*/
    /*addTransform(1,200,500, RED, components);*/

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();

        DrawSystem(components);
    }

    destroyComponentList(components);

    CloseWindow();

    return 0;
}
