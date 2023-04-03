#ifndef CB_COLOR_CHANGE_H
#define CB_COLOR_CHANGE_H

#include "raylib.h"
#include "entity/Entity.h"

void CB_ChangeColor(Entity* e)
{
  Color colors[3] = {RED, GREEN, BLUE};
  e->transformComponent->color = colors[GetRandomValue(0,3)];
}

#endif // CB_COLOR_CHANGE_H
