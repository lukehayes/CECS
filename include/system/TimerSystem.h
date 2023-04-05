#ifndef SYS_TIMER_SYS_H
#define SYS_TIMER_SYS_H

#include "entity/Entity.h"
#include "component/TimerComponent.h"
#include "logging.h"

void TimerSystem(Entity** ents, int count, float delta)
{
  for(int i = 0; i<= count - 1; i++)
  {
      Entity* e = ents[i];
      TimerComponent* t = e->timers[0];

      t->timeleft -= delta;

      LOG(t->timeleft);

  }
}


#endif //SYS_TIMER_SYS_H

