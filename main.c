#include "raylib.h"
#include "logging.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int MAX = 5;
Color BGCOLOR = {250, 243, 221, 255};

typedef struct DrawComponent
{
    float x;
    float y;
    float w;
    float h;
    Color color;

} DrawComponent;


typedef struct Entity
{
    DrawComponent* drawComponent;

} Entity;

void freeEntity(Entity* e)
{
    free(e->drawComponent);
    free(e);

    e->drawComponent = NULL;
}

Entity* initEntity(float x, float y)
{
    Entity* e = malloc(sizeof(Entity));

    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = BLUE;
    e->drawComponent->x = x; 
    e->drawComponent->y = y; 
    e->drawComponent->w = 10; 
    e->drawComponent->h = 10; 

    return e;
}

void DrawEntity(Entity* e)
{

    if(e->drawComponent == NULL) return;


    BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(
            e->drawComponent->x,
            e->drawComponent->y,
            e->drawComponent->w,
            e->drawComponent->h,
            e->drawComponent->color
        );


    EndDrawing();

}




int main() {

    // BASE INITIALIZATION
    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");
    SetTargetFPS(60);
    // -------------------------------------------

    // ENTITY INITIALIZATION
    Entity* e1 = initEntity(
            GetRandomValue(10,500),
            GetRandomValue(10,500)
            );

    Entity* e2 = initEntity(
            GetRandomValue(10,500),
            GetRandomValue(10,500)
            );


    while (!WindowShouldClose()) {

        delta = GetFrameTime();
        c += 0.01;

        DrawEntity(e1);
        DrawEntity(e2);

        // BeginDrawing();
        //     ClearBackground(BLACK);
        // EndDrawing();
    }

    freeEntity(e1);

    CloseWindow();

    return 0;
}
