#include "raylib.h"

// Entity
#include "entity/Entity.h"

// Components
#include "component/DrawComponent.h"
#include "component/VelocityComponent.h"
#include "entity/Entity.h"

// Systems
#include "system/DrawSystem.h"
#include "system/MoveSystem.h"

// --------------------------------------------------

float delta = 0.0;
float c = 0.0;
int MAX = 100;
Color BGCOLOR = {250, 243, 221, 255};

int main() {

    // BASE INITIALIZATION
    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "ECS");
    SetTargetFPS(60);
    // -------------------------------------------

    Entity* ents[MAX];

    for(int i = 0; i<= MAX-1; i++)
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

        for(int i = 0; i<= MAX-1; i++)
        {
            MoveSystem(ents[i], delta);
             
        }


        ClearBackground(BLACK);
        BeginDrawing();
            DrawSystem(e1);

            for(int i = 0; i<= MAX-1; i++)
            {
                DrawSystem(ents[i]);
            }

        EndDrawing();

        // BeginDrawing();
        //     ClearBackground(BLACK);
        // EndDrawing();
    }

    freeEntity(e1);

    for(int i = 0; i<= MAX-1; i++)
    {
        freeEntity(ents[i]);
    }

    CloseWindow();

    return 0;
}
