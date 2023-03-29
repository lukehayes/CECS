#include "system/MoveSystem.h"


void MoveSystem(Entity* e, float dt)
{
    if(e->drawComponent == NULL) return;
    if(e->velocityComponent == NULL) return;

    e->drawComponent->x += e->velocityComponent->vx *
                          e->velocityComponent->speed * dt;

    e->drawComponent->y += e->velocityComponent->vy *
                          e->velocityComponent->speed * dt;
}


