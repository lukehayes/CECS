#include "entity/Entity.h"
#include <stdlib.h>

Entity* initEntity(float x, float y)
{
    Entity* e = malloc(sizeof(Entity));

    Color colors[3] = {RED, GREEN, BLUE};

    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = colors[GetRandomValue(0,2)];
    e->drawComponent->x = x; 
    e->drawComponent->y = y; 
    e->drawComponent->w = 5; 
    e->drawComponent->h = 5; 

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
