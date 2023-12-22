#include "raylib.h"
#include "Engine.h"
#include "Externs.h"

#include "ECS/Transform.h"

#include <stdio.h>

float delta = 0.0;

#define COMPONENT_COUNT 100

void colorConvert(const char* val)
{
    int c1 = (char)val[1];
    printf("Char %i \n", c1);
    int r = (int)val[1] + (int)val[2];
    printf("R %i \n", r);

    int c2 = (int)val[3];
    int g = c2 + (int)val[4];

    int c3 = (int)val[5];
    int b = c3 + (int)val[6];

    printf("Color: %s = r{%i}, g{%i}, b{%i} \n", val,r,g,b);

}

TransformComponent* transforms[COMPONENT_COUNT];

int main() {

    initEngine();

    colorConvert("#FFFFFF");
   colorConvert("#3a23aa");
    colorConvert("#110022");

    Color colors[3]= {
        {104,82,84, 255},
        {178,156,152, 255},
        {255,250,246,255},
    };

    for(int i = 0; i <= COMPONENT_COUNT; i++)
    {
        int rc = GetRandomValue(0,2);
        int rx = GetRandomValue(10,600);
        int ry = GetRandomValue(10,600);
        addTransform(i,rx,ry, colors[rc], transforms);
    }

    while (!WindowShouldClose()) {

        PollInputEvents();

        printf("FPS: %i \n", GetFPS());

        delta = GetFrameTime();

        UpdateSystem(transforms, GetFrameTime());
        DrawSystem(transforms);

    }

    DestroyTransforms(transforms);

    CloseWindow();

    return 0;
}
