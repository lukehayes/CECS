#include "ECS/ComponentList.h"
#include <stdlib.h>
#include "ECS/Globals.h"
#include "ECS/Component.h"

ComponentList* createComponentList()
{
    ComponentList* components = malloc(sizeof(ComponentList));
    *components->transforms = malloc(sizeof(TransformComponent) * COMPONENT_COUNT - 1);

   /* Initialze all of the component spaces to NULL. */
    for(int i = 0; i<= COMPONENT_COUNT -1; i++)
    {
        components->transforms[i] = NULL;
        components->sounds[i] = NULL;
        components->collisions[i] = NULL;
    }

    TraceLog(LOG_DEBUG, "Component Transforms Initialized");
    TraceLog(LOG_DEBUG, "Component Sounds Initialized");
    TraceLog(LOG_DEBUG, "Component Collisions Initialized");
    TraceLog(LOG_DEBUG, "Component List Initialization Finished");

    return components;
}

ComponentList* fillComponentList()
{
    ComponentList* components = createComponentList();

    for(int i = 0; i < COMPONENT_COUNT; i++)
   {
        int rx = GetRandomValue(10,WINDOW_WIDTH);
        int ry = GetRandomValue(10,WINDOW_HEIGHT);
        Color color[2] = {DARK, LIGHT, WHITE};

        addTransform(i, rx,ry, color[GetRandomValue(0,2)], components);

        addCollision(i,TILE_SIZE, components);
    }

    return components;
}

void destroyComponentList(ComponentList* components)
{
    for(int i = 0; i <= COMPONENT_COUNT - 1; i++)
    {
        if(components->transforms[i])
        {
            free(components->transforms[i]);
        }

        if(components->sounds[i])
        {
            UnloadSound(components->sounds[i]->sound);
            free(components->sounds[i]);
        }

        if(components->collisions[i])
        {
            free(components->collisions[i]);
        }
    }

    TraceLog(LOG_DEBUG, "Components Destroyed");

    free(components);

    TraceLog(LOG_DEBUG, "Component List Destroyed");
}

