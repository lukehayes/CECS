#include "raylib.h"
#include "Engine.h"
#include "ECS/ComponentList.h"
#include "ECS/Transform.h"

float delta = 0.0;

int main() {

    initEngine();
    
    ComponentList* components = createComponentList();

    while (!WindowShouldClose()) {

        PollInputEvents();

        delta = GetFrameTime();
    }


    CloseWindow();

    return 0;
}
    /*Color colors[3]= {*/
        /*{104,82,84, 255},*/
        /*{178,156,152, 255},*/
        /*{255,250,246,255},*/
    /*};*/

    /*for(int i = 0; i <= COMPONENT_COUNT; i++)*/
    /*{*/
        /*int rc = GetRandomValue(0,2);*/
        /*int rx = GetRandomValue(10,600);*/
        /*int ry = GetRandomValue(10,600);*/

        /*addTransform(i,rx,ry, colors[rc], components->transforms);*/
    /*}*/
