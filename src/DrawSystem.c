#include "system/DrawSystem.h"
#include "logging.h"

void DrawSystem(Entity** ents, int count, Color clearColor)
{
    ClearBackground(clearColor);
    BeginDrawing();
    for(int i = 0; i <= count - 1; i++)
    {
        Entity* e = ents[i];

        // XXX Removed check for SpriteComponent for now.

        if(e->transformComponent == NULL)
        {
            LOG("NO TRANSFORM COMPONENT");
            return;
        }

        if(e->spriteComponent)
        {
            LOG("HAS SPRITE COMPONENT");
            DrawTexture(
                    *e->spriteComponent->texture,
                    e->transformComponent->x,
                    e->transformComponent->y,
                    e->spriteComponent->tint
            );

        }else
        {
            LOG("DRAW FROM TRANSFORM COMPONENT");
            DrawRectangle(
                e->transformComponent->x,
                e->transformComponent->y,
                e->transformComponent->w,
                e->transformComponent->h,
                e->transformComponent->color
            );

        }
    }

    EndDrawing();
}


