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
        TransformComponent* transform = (struct TransformComponent*)transforms[i];

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

    TransformComponent** transforms = components->transforms;


    for(int i = 0; i < COMPONENT_COUNT; i++)
    {
        TransformComponent* transform = transforms[i];


        if(transform)
        {
            // BOUNDS CHECKING ----------------
            bool xBound = transform->position.x < 5 || transform->position.x > WINDOW_WIDTH;
            bool yBound = transform->position.y < 5 || transform->position.y > WINDOW_HEIGHT;

            if(xBound)
            {
                transform->dx = -transform->dx;
            }

            if(yBound)
            {
                transform->dy = -transform->dy;
            }

            // MOVEMENT ----------------
            transform->position.x += transform->dx * transform->speed * delta;
            transform->position.y += transform->dx * transform->speed * delta;
        }
    }
}
