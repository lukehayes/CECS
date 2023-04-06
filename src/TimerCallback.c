#ifndef CB_TIMER_CALLBACK_H
#define CB_TIMER_CALLBACK_H

#include "raylib.h"
#include "entity/Entity.h"
#include "logging.h"

/**
 * All timer callbacks are defined in this file.
 * The TMCB prefix means Timer Callback.
 */

void TMCB_ChangeColor(Entity* e)
{
  Color color = {
    GetRandomValue(150,105),
    GetRandomValue(150,165),
    GetRandomValue(60,255),
    GetRandomValue(200,255)
  };
  e->transformComponent->color = color;
}

void TMCB_ChangeSize(Entity* e)
{
  e->transformComponent->w = GetRandomValue(1,30);
  e->transformComponent->h = GetRandomValue(1,30);
}

#endif // CB_COLOR_CHANGE_H
