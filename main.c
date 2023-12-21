#include "raylib.h"
#include "Engine.h"
#include "Externs.h"
#include <stdlib.h>
#include <stdio.h>

float delta = 0.0;

typedef struct Component
{
    int entity_id;
} Component;

typedef struct RenderComponent {
    int entity_id;
    int x;
    int y;
    int size;
} RenderComponent;


typedef struct Entity
{
    int entity_id;
    RenderComponent* renderComponent;
} Entity;

Entity* entities[ENTITY_COUNT];

void addRenderComponent(int entity_id, int x, int y)
{
    Entity* entity = entities[entity_id];
    RenderComponent* comp = malloc(sizeof(RenderComponent));

    comp->entity_id = entity_id;
    comp->x = x;
    comp->y = y;
    comp->size = 100;

    entity->renderComponent = comp;
}

void destroy_components(Entity** entites)
{
    for(int i = 0; i <= ENTITY_COUNT - 1; i++)
    {
        Entity* entity = entities[i];

        if(entity->renderComponent)
        {
            free(entity->renderComponent);
        }
    }
}


int main() {

    initEngine();


    addRenderComponent(0, 100,100);

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();

        BeginDrawing();

        EndDrawing();
    }

    destroy_components(entities);

    CloseWindow();

    return 0;
}
