#include "system/MoveSystem.h"


void MoveSystem(Entity** ents, int count, float dt)
{
    for(int i = 0; i <= count - 1; i++)
    {
        Entity* e = ents[i];

        if(e->drawComponent == NULL) return;
        if(e->transformComponent == NULL) return;

        e->transformComponent->x += e->transformComponent->vx *
                              e->transformComponent->speed * dt;

        e->transformComponent->y += e->transformComponent->vy *
                              e->transformComponent->speed * dt;

        int x = e->transformComponent->x; 
        int y = e->transformComponent->y; 

        if(x <= 0 || x > 1260)
        {
            e->transformComponent->vx = -e->transformComponent->vx;

        }

        if(y <= 0 || y > 700)
        {
            e->transformComponent->vy = -e->transformComponent->vy;

        }


    }


}


