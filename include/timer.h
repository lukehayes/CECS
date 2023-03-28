#pragma once

#include <stdbool.h>

typedef struct Timer
{
    float time;
    float elapsed;
    bool finished;
    bool repeat;

} Timer;

/**
 * Create a timer.
 *
 * @param float time    Amount of time until timer stops.
 * @param bool  repeat  Is the timer a one-shot?
 *
 * @return Timer.
 */
Timer createTimer(float time, int repeat);

/**
 * Update a timer per frame.
 *
 * @param Timer* timer    Instance of Timer struct.
 * @param float  delta    Delta time.
 *
 * @return Timer.
 */
void updateTimer(Timer* timer, float delta);
