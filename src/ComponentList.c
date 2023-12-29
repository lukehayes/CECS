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
    }


    TraceLog(LOG_DEBUG, "Component List Initialized");
    TraceLog(LOG_DEBUG, "Created Component List");

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
    }

    TraceLog(LOG_DEBUG, "Components Destroyed");

    free(components);

    TraceLog(LOG_DEBUG, "Component List Destroyed");
}

