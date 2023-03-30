#include "entity/Entity.h"
#include <stdlib.h>

// XXX Using 10,000+ with textures is slow! 100,000 is slow with DrawRect.
int ENTITY_COUNT = 100;

Entity* initEntity(float x, float y)
{
    Entity* e = malloc(sizeof(Entity));

    Color colors[3] = {
        {130,0,250,255},
        {0,180,250,255},
        {80,0,200,255},
    };

    int size = GetRandomValue(2,10);

    // DrawComponent
    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = colors[GetRandomValue(0,2)];
    e->drawComponent->w = size;
    e->drawComponent->h = size; 

    // TransformComponent
    e->transformComponent = malloc(sizeof(TransformComponent));
    e->transformComponent->x = x;
    e->transformComponent->y = y;
    e->transformComponent->w = 8;
    e->transformComponent->h = 8;
    e->transformComponent->dx = GetRandomValue(-1,1);
    e->transformComponent->dy = GetRandomValue(-1,1);
    e->transformComponent->vx = GetRandomValue(-1,1);
    e->transformComponent->vy = GetRandomValue(-1,1);
    e->transformComponent->speed = GetRandomValue(10,400);


    Image img = LoadImage("../assets/debug_player.png");
    ImageResize(&img, 16 * 10, 16 * 10);

    // SpriteComponent
    e->spriteComponent = malloc(sizeof(TransformComponent));
    e->spriteComponent->texture = LoadTextureFromImage(img);
    e->spriteComponent->tint = colors[GetRandomValue(0,2)];

    UnloadImage(img);

    return e;
}

void freeEntity(Entity* e)
{
    if(e->drawComponent)
        free(e->drawComponent);

    if(e->transformComponent)
        free(e->transformComponent);

    if(e->spriteComponent)
    {
        UnloadTexture(e->spriteComponent->texture);
        free(e->spriteComponent);
    }

    free(e);

    e->drawComponent = NULL;
}
