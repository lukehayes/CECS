
#ifndef COMP_TIMER_COMP_H
#define COMP_TIMER_COMP_H

#include <stdbool.h>

typedef struct TimerComponent
{
  float duration;
  float timeleft;
  bool  oneshot;
  
  // Callback to run on timer ending.
  void (*callback)();

} TimerComponent;

#endif //COMP_SPRITE_COMP_H
