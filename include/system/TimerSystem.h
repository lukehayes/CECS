#ifndef SYS_TIMER_SYS_H
#define SYS_TIMER_SYS_H

#include "entity/Entity.h"
#include "component/TimerComponent.h"
#include "logging.h"

void TimerSystem(Entity** ents, int count, float delta);

#endif //SYS_TIMER_SYS_H

