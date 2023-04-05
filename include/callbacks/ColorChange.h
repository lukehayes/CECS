#ifndef CB_COLOR_CHANGE_H
#define CB_COLOR_CHANGE_H

#include "raylib.h"
#include "entity/Entity.h"

void CB_ChangeColor(Entity* e)
{
  Color color = {
    GetRandomValue(150,105),
    GetRandomValue(150,165),
    GetRandomValue(160,255),
    GetRandomValue(200,255)
  };

  e->transformComponent->color = color;
}

#endif // CB_COLOR_CHANGE_H
