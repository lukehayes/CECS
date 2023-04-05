#include "system/TimerSystem.h"

void TimerSystem(Entity** ents, int count, float delta)
{
  for(int i = 0; i<= count - 1; i++)
  {
      Entity* e = ents[i];
      TimerComponent* t = e->timers[0];

      LOG(delta);

      // t->timeleft -= delta;
      //
      // LOG(delta);
      // LOG(t->timeleft);
      // LOG(t->duration);

  }
}


