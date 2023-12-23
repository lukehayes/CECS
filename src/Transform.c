#include "ECS/Transform.h"
#include "ECS/ComponentList.h"
#include <stdlib.h>


void addTransform(int entity_id, int x, int y, Color color, ComponentList* components)
{
    int counter = 0;
    TransformComponent* transform = malloc(sizeof(TransformComponent));
    transform->position.x = x;
    transform->position.y = y;
    transform->size = 10;
    transform->color = color;

    TransformComponent* comp = components->transforms[counter];

    components->transforms[counter] = comp;

}

void DrawSystem(ComponentList* components)
{
    int counter = 0;

    TransformComponent** transforms = components->transforms;

    BeginDrawing();
    ClearBackground((Color){76,38,61, 255});

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

void UpdateSystem(ComponentList* components, float delta)
{
    int counter = 0;

    TransformComponent** transforms = components->transforms;

    while(transforms[counter])
    {
        TransformComponent* transform = transforms[counter];

        counter++;
    }

    if(counter >= COMPONENT_COUNT)
    {
        counter = 0;
    }

}

void DestroyTransforms(ComponentList* components)
{
    for(int i = 0; i <= COMPONENT_COUNT; i++)
    {
        TransformComponent* transform = components->transforms[i];
        free(transform);
    }

    TraceLog(LOG_DEBUG, "Tranform Components Destroyed.");
}

