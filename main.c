#include "raylib.h"
#include "Engine.h"

// Entity
#include "entity/Entity.h"

// Components

// Systems
#include "system/DrawSystem.h"
#include "system/MoveSystem.h"

#include "component/util/TextureFactory.h"
// --------------------------------------------------

float delta = 0.0;
float c = 0.0;

int main() {

    // ENGINE INITIALIZATION
    initEngine();
    // textureFactory = initTextureFactory();
    // ----------------------------------------------

    Entity* ents[ENTITY_COUNT];

    for(int i = 0; i <= ENTITY_COUNT - 1; i++)
    {
        Entity* e = initEntity();
        addTransformComponent(e, i * 10, i * 10,5,5);
        addSpriteComponent(e, "../assets/debug_sprite.png",10,10);
        ents[i] = e;
    }
    

    while (!WindowShouldClose()) {

        delta = GetFrameTime();

        MoveSystem(ents, ENTITY_COUNT, delta);
        DrawSystem(ents, ENTITY_COUNT, BLACK);
    }

    for(int i = 0; i<= ENTITY_COUNT-1; i++)
    {
        freeEntity(ents[i]);
    }

    CloseWindow();

    return 0;
}
