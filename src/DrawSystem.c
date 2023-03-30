#include "system/DrawSystem.h"

void DrawSystem(Entity** ents, int count)
{

    BeginDrawing();
    for(int i = 0; i <= count - 1; i++)
    {
        Entity* e = ents[i];

        if(e->transformComponent == NULL) return;
        if(e->drawComponent == NULL) return;

        DrawRectangle(
            e->transformComponent->x,
            e->transformComponent->y,
            e->drawComponent->w,
            e->drawComponent->h,
            e->drawComponent->color
        );

    }

    EndDrawing();
}


