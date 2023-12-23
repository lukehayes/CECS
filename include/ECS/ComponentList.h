#pragma once

#include <stdlib.h>
#include "Globals.h"

typedef struct ComponentList
{
    struct TransformComponent* transforms[COMPONENT_COUNT];
} ComponentList;

ComponentList* createComponentList();

void destroyComponentList(ComponentList* list);

