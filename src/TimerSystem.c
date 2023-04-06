#include "system/TimerSystem.h"
#include "Externs.h"
#include <stdio.h>

void TimerSystem(Entity** ents, int count, float delta)
{
  for(int i = 0; i<= count - 1; i++)
  {
      Entity* e = ents[i];
  
      // Loop through all of the timers and check if they are set.
      for(int j = 0; j<= MAX_TIMER_COUNT - 1; ++j)
      {

        TimerComponent* t = e->timers[j];

        if(!t) break;

        t->timeleft -= delta;

        LOG(t->timeleft);

        if(t->timeleft <= 0)
        {
          t->callback(e);
          t->timeleft = t->duration;
        }
      }


  }
}


