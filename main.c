#include "raylib.h"

// Entity
#include "entity/Entity.h"

// Components

// Systems
#include "system/DrawSystem.h"
#include "system/MoveSystem.h"

// --------------------------------------------------

float delta = 0.0;
float c = 0.0;
Color BGCOLOR = {250, 243, 221, 255};

int main() {

    // BASE INITIALIZATION
    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "ECS");
    SetTargetFPS(60);
    // -------------------------------------------

    Entity* ents[ENTITY_COUNT];

    for(int i = 0; i<= ENTITY_COUNT-1; i++)
    {
        Entity* e = initEntity(
                GetRandomValue(10,500),
                GetRandomValue(10,500)
                );
        ents[i] = e;
    }


    // ENTITY INITIALIZATION
    Entity* e1 = initEntity(
            GetRandomValue(10,500),
            GetRandomValue(10,500)
            );

    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        MoveSystem(ents, ENTITY_COUNT, delta);

        ClearBackground(BLACK);
        DrawSystem(ents, ENTITY_COUNT);
    }

    freeEntity(e1);

    for(int i = 0; i<= ENTITY_COUNT-1; i++)
    {
        freeEntity(ents[i]);
    }

    CloseWindow();

    return 0;
}
