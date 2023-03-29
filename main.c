#include "raylib.h"
#include "logging.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float delta = 0.0;
float c = 0.0;
int MAX = 1000;
Color BGCOLOR = {250, 243, 221, 255};

typedef struct DrawComponent
{
    float x;
    float y;
    float w;
    float h;
    Color color;

} DrawComponent;

typedef struct VelocityComponent
{
    float vx;
    float vy;
    float speed;

} VelocityComponent;


typedef struct Entity
{
    DrawComponent* drawComponent;
    VelocityComponent* velocityComponent;

} Entity;

void freeEntity(Entity* e)
{
    free(e->drawComponent);
    free(e->velocityComponent);
    free(e);

    e->drawComponent = NULL;
}

Entity* initEntity(float x, float y)
{
    Entity* e = malloc(sizeof(Entity));

    Color colors[3] = {RED, GREEN, BLUE};

    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = colors[GetRandomValue(0,2)];
    e->drawComponent->x = x; 
    e->drawComponent->y = y; 
    e->drawComponent->w = 10; 
    e->drawComponent->h = 10; 

    e->velocityComponent = malloc(sizeof(VelocityComponent));
    e->velocityComponent->vx = GetRandomValue(-1,1);
    e->velocityComponent->vy = GetRandomValue(-1,1);
    e->velocityComponent->speed = GetRandomValue(10,400);

    return e;
}

void DrawEntity(Entity* e)
{
    if(e->drawComponent == NULL) return;

        DrawRectangle(
            e->drawComponent->x,
            e->drawComponent->y,
            e->drawComponent->w,
            e->drawComponent->h,
            e->drawComponent->color
        );
}

void MoveEntity(Entity* e, float dt)
{
    if(e->drawComponent == NULL) return;
    if(e->velocityComponent == NULL) return;

    e->drawComponent->x += e->velocityComponent->vx *
                          e->velocityComponent->speed * dt;

    e->drawComponent->y += e->velocityComponent->vy *
                          e->velocityComponent->speed * dt;
}


int main() {

    // BASE INITIALIZATION
    SetTraceLogLevel(LOG_ALL);
    InitWindow(1280, 720, "RLPong");
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
            MoveEntity(ents[i], delta);
        }


        ClearBackground(BLACK);
        BeginDrawing();
            DrawEntity(e1);

            for(int i = 0; i<= MAX-1; i++)
            {
                DrawEntity(ents[i]);
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
