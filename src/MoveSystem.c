#include "system/MoveSystem.h"


void MoveSystem(Entity** ents, int count, float dt)
{
    for(int i = 0; i <= count - 1; i++)
    {
        Entity* e = ents[i];

        if(e->drawComponent == NULL) return;
        if(e->velocityComponent == NULL) return;

        e->drawComponent->x += e->velocityComponent->vx *
                              e->velocityComponent->speed * dt;

        e->drawComponent->y += e->velocityComponent->vy *
                              e->velocityComponent->speed * dt;
    }


}


