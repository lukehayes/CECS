#include "entity/Entity.h"
#include <stdlib.h>

int ENTITY_COUNT = 10000;

Entity* initEntity(float x, float y)
{
    Entity* e = malloc(sizeof(Entity));

    Color colors[3] = {
        {130,0,250,255},
        {0,180,250,255},
        {80,0,200,255},
    };

    int size = GetRandomValue(2,10);

    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = colors[GetRandomValue(0,2)];
    e->drawComponent->x = x; 
    e->drawComponent->y = y; 
    e->drawComponent->w = size;
    e->drawComponent->h = size; 

    e->velocityComponent = malloc(sizeof(VelocityComponent));
    e->velocityComponent->vx = GetRandomValue(-1,1);
    e->velocityComponent->vy = GetRandomValue(-1,1);
    e->velocityComponent->speed = GetRandomValue(10,400);

    return e;
}

void freeEntity(Entity* e)
{
    free(e->drawComponent);
    free(e->velocityComponent);
    free(e);

    e->drawComponent = NULL;
}
