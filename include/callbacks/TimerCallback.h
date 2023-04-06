#ifndef CB_TIMER_CALLBACK_H
#define CB_TIMER_CALLBACK_H

#include "raylib.h"
#include "entity/Entity.h"

/**
 * All timer callbacks are defined in this file.
 * The TMCB prefix means Timer Callback.
 */

/**
 * Change the color of a specific Entity.
 *
 * @param Entity* e.
 *
 * @return void.
 */
void TMCB_ChangeColor(Entity* e);

void TMCB_ChangeSize(Entity* e);

#endif // CB_COLOR_CHANGE_H
