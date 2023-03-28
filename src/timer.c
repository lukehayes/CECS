#include "timer.h"
#include <stdio.h>

/**
 * Create a timer.
 *
 * @param float time    Amount of time until timer stops.
 * @param bool  repeat  Is the timer a one-shot?
 *
 * @return Timer.
 */
Timer createTimer(float time, int repeat)
{
    Timer timer = {.time = time, .elapsed = 0.0, .finished = false, repeat = repeat};
    return timer;
}

/**
 * Update a timer per frame.
 *
 * @param Timer* timer    Instance of Timer struct.
 * @param float  delta    Delta time.
 *
 * @return Timer.
 */
void updateTimer(Timer* timer, float delta)
{
    if(!timer->finished)
    {
        timer->elapsed += delta;
        printf("Elapsed: %i\n", timer->elapsed);

        if(timer->elapsed >= timer->time)
        {
            timer->finished = true;
            timer->elapsed = 0;
        }
    }else
    {
        if(timer->repeat)
        {
            timer->finished = false;
            timer->elapsed = 0;
        }
    }

    //if(timer->elapsed > timer->time)
    //{

        //if(timer->repeat && !timer->finished)
        //{
            //timer->elapsed = 0.0;
            //timer->finished = true;

        //}else
        //{
            //timer->elapsed = 0.0;
            //timer->finished = false;
        //}
    //}
}
