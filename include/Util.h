#ifndef ECS_UTIL_H
#define ECS_UTIL_H

#include "raylib.h"
#include "ECS/Globals.h"
#include <stdio.h>

/**
* Draw debugging information like FPS.
*/
void drawDebug()
{
    char fps[100];
    char ent_count[100];

    sprintf(fps, "FPS: %i", GetFPS());
    sprintf(ent_count, "Entity Count: %i", COMPONENT_COUNT);

    BeginDrawing();
        DrawText(fps, 10,10, 26, WHITE);
        DrawText(ent_count, 10,50, 26, WHITE);
    EndDrawing();

}
#endif // DEBUG
