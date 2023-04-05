#include "raylib.h"
#include "Engine.h"

// Entity
#include "entity/Entity.h"

// Components

// Systems
#include "system/DrawSystem.h"
#include "system/MoveSystem.h"
#include "system/TimerSystem.h"

#include "component/util/TextureFactory.h"

#include "callbacks/ColorChange.h"

// --------------------------------------------------

float delta = 0.0;
float c = 0.0;

int main() {

    // ENGINE INITIALIZATION
    initEngine();
    textureFactory = initTextureFactory();
    // ----------------------------------------------

    Entity* ents[ENTITY_COUNT];

    for(int i = 0; i <= ENTITY_COUNT - 1; i++)
    {
        int n = 400;
        Entity* e = initEntity();
        addTransformComponent(e, GetRandomValue(0,n), GetRandomValue(0,n),5,5);
        addSpriteComponent(e, "../assets/debug_sprite.png",10,10);
        addTimerCompnent(e, 0, 3, false, CB_ChangeColor);
        ents[i] = e;
    }
    

    while (!WindowShouldClose()) {

        delta = GetFrameTime();

        TimerSystem(ents, ENTITY_COUNT, delta);

        MoveSystem(ents, ENTITY_COUNT, delta);
        DrawSystem(ents, ENTITY_COUNT, BLACK);
    }

    for(int i = 0; i<= ENTITY_COUNT-1; i++)
    {
        freeEntity(ents[i]);
    }

    freeTextureFactory(textureFactory);

    CloseWindow();

    return 0;
}
