#include "entity/Entity.h"
#include <stdlib.h>

int ENTITY_COUNT = 10;

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
    e->transformComponent->dx = GetRandomValue(-1,1);
    e->transformComponent->dy = GetRandomValue(-1,1);
    e->transformComponent->vx = GetRandomValue(-1,1);
    e->transformComponent->vy = GetRandomValue(-1,1);
    e->transformComponent->speed = GetRandomValue(10,400);

    return e;
}

void freeEntity(Entity* e)
{
    free(e->drawComponent);
    free(e->transformComponent);
    free(e);

    e->drawComponent = NULL;
}
