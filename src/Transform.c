#include "ECS/Transform.h"
#include <stdlib.h>


void addTransform(int entity_id, int x, int y, Color color, TransformComponent** transforms)
{
    int counter = 0;
    TransformComponent* comp = malloc(sizeof(TransformComponent));
    comp->position.x = x;
    comp->position.y = y;
    comp->size = 20;
    comp->color = color;

    while(transforms[counter])
    {
        counter++;
    }

    transforms[counter] = comp;
}

void DrawSystem(TransformComponent** transforms)
{
    int counter = 0;

    BeginDrawing();
    ClearBackground(BLACK);

    while(transforms[counter])
    {
        TransformComponent* transform = transforms[counter];

        DrawRectangle(
            transform->position.x,
            transform->position.y,
            transform->size,
            transform->size,
            transform->color
        );

        counter++;
    }

    EndDrawing();

    if(counter >= COMPONENT_COUNT)
    {
        counter = 0;
    }

}

void UpdateSystem(TransformComponent** transforms, float delta)
{
    int counter = 0;

    while(transforms[counter])
    {
        TransformComponent* transform = transforms[counter];

        transform->position.x += 10 * delta;
        transform->position.y += 10 * delta;

        counter++;
    }

    if(counter >= COMPONENT_COUNT)
    {
        counter = 0;
    }

}

void DestroyTransforms(TransformComponent** transforms)
{
    for(int i = 0; i <= COMPONENT_COUNT; i++)
    {
        TransformComponent* transform = transforms[i];
        free(transform);
    }

    TraceLog(LOG_DEBUG, "Tranform Components Destroyed.");
}

