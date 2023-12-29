#ifndef CECS_ENGINE_H

#define CECS_ENGINE_H

#include "raylib.h"
#include "ECS/Globals.h"

/**
 * General engine configurtion is stored in this file mostly in the
 * form of extern variables, defines and init functions.
 */


/**
 * Initialize raylib and all other necessary things.
 */
void initEngine()
{
    SetTraceLogLevel(LOG_DEBUG);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
    InitAudioDevice();
    SetTargetFPS(60);
}

#endif // !CECS_ENGINE_H
