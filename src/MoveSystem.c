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

        int x = e->drawComponent->x; 
        int y = e->drawComponent->y; 

        if(x <= 0 || x > 1260)
        {
            e->velocityComponent->vx = -e->velocityComponent->vx;

        }

        if(y <= 0 || y > 700)
        {
            e->velocityComponent->vy = -e->velocityComponent->vy;

        }


    }


}


