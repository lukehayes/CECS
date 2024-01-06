#include "ECS/System.h"
#include "ECS/Component.h"
#include "ECS/ComponentList.h"
#include <stdlib.h>
#include <stdio.h>


void DrawSystem(ComponentList* components)
{
    struct TransformComponent** transforms = components->transforms;
    struct CollisionComponent** collisions = components->collisions;

    BeginDrawing();
    ClearBackground((Color){76,38,61, 255});

    for(int i = 0; i<= COMPONENT_COUNT -1; i++)
    {
        TransformComponent* transform = (struct TransformComponent*)transforms[i];
        CollisionComponent* collision = (struct CollisionComponent*)collisions[i];

        if(transform)
        {
            DrawRectangle(
                transform->position.x,
                transform->position.y,
                transform->size,
                transform->size,
                transform->color
            );

            if(collision)
            {
                DrawRectangle(
                    collision->position.x,
                    collision->position.y,
                    collision->size,
                    collision->size,
                    collision->color
                );
            }
        }
    }

    EndDrawing();
}

void UpdateSystem(ComponentList* components, float delta)
{
    TransformComponent** transforms = components->transforms;
    CollisionComponent** collisions = components->collisions;

    for(int i = 0; i < COMPONENT_COUNT; i++)
    {
        TransformComponent* transform = transforms[i];
        CollisionComponent* collision = collisions[i];

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

            /*collision->position.x = transform->position.x / 2;*/
            /*collision->position.y = transform->position.y / 2;*/
        }
    }
}

void CollisionSystem(ComponentList* components, float delta)
{
    TransformComponent** transforms = components->transforms;
    CollisionComponent** collisions = components->collisions;

    for(int i = 0; i < COMPONENT_COUNT; i++)
    {
        TransformComponent* transform = transforms[i];
        CollisionComponent* collision = collisions[i];

        if(transform && collision)
        {
            /*collision->position = transform->position;*/
        }
    }
}
