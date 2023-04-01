#ifndef CECS_ENGINE_H
#define CECS_ENGINE_H

#include "raylib.h"

/**
 * General engine configurtion is stored in this file mostly in the
 * form of extern variables, defines and init functions.
 */

// DEFINES
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define GAME_TITLE    "ECS"

/**
 * Initialize raylib and all other necessary things.
 */
void initEngine()
{
    SetTraceLogLevel(LOG_ALL);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
    SetTargetFPS(60);
}

#endif // !CECS_ENGINE_H
