#include "system/TimerSystem.h"
#include "Externs.h"

void TimerSystem(Entity** ents, int count, float delta)
{
  for(int i = 0; i<= count - 1; i++)
  {
      Entity* e = ents[i];
      TimerComponent* t = e->timers[0];

      t->timeleft -= delta;

      if(t->timeleft < 0 && ! t->oneshot)
      {
        // TODO Need to create header/source file implementation.
        t->callback(e);
        t->timeleft = t->duration;
        LOG("Callback called");
      }
  }
}


