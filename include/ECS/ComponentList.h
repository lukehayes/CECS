#pragma once

#include <stdlib.h>
#include "Globals.h"

typedef struct ComponentList
{
    struct TransformComponent* transforms[COMPONENT_COUNT];
    struct SoundComponent*     sounds[COMPONENT_COUNT];
    struct CollisionComponent* collisions[COMPONENT_COUNT];
} ComponentList;


/**
* Create an empty component list.
* @return ComponentList*
*/
ComponentList* createComponentList();

/**
* Create a ComponentList and fill it with test entities.
* @return ComponentList*
*/
ComponentList* fillComponentList();

/**
* Destroy a ComponentList.
* @return void
*/
void destroyComponentList(ComponentList* list);

