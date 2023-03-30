#include "system/DrawSystem.h"

void DrawSystem(Entity** ents, int count)
{

    BeginDrawing();
    for(int i = 0; i <= count - 1; i++)
    {
        Entity* e = ents[i];

        if(e->transformComponent == NULL) return;


        if(e->spriteComponent)
        {
            DrawTexture(
                    e->spriteComponent->texture,
                    e->transformComponent->x,
                    e->transformComponent->y,
                    e->spriteComponent->tint
            );

        }else if(e->drawComponent)
        {
            DrawRectangle(
                e->transformComponent->x,
                e->transformComponent->y,
                e->transformComponent->w,
                e->transformComponent->h,
                ORANGE
            );

        }else
        {
            return;
        }
    }

    EndDrawing();
}


