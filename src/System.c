#include "ECS/System.h"
#include "ECS/Component.h"
#include "ECS/ComponentList.h"
#include <stdlib.h>
#include <stdio.h>


void DrawSystem(ComponentList* components)
{
    struct TransformComponent** transforms = components->transforms;

    BeginDrawing();
    ClearBackground((Color){76,38,61, 255});

    for(int i = 0; i<= COMPONENT_COUNT -1; i++)
    {
        TransformComponent* transform = transforms[i];

        if(transform)
        {
            DrawRectangle(
                transform->position.x,
                transform->position.y,
                transform->size,
                transform->size,
                transform->color
            );
        }
    }

    EndDrawing();
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

