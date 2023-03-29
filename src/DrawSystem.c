#include "system/DrawSystem.h"

void DrawSystem(Entity* e)
{
    if(e->drawComponent == NULL) return;

        DrawRectangle(
            e->drawComponent->x,
            e->drawComponent->y,
            e->drawComponent->w,
            e->drawComponent->h,
            e->drawComponent->color
        );
}


