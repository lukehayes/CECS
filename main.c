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
    textureFactory = initTextureFactory();
    // ----------------------------------------------

    Entity* ents[ENTITY_COUNT];

    // ENTITY INITIALIZATION
    Entity* e1 = initEntity();

    addTransformComponent(e1, 10,10,30,30);
    // addSpriteComponent(e1, "../assets/debug_player.png", 10,10);
    
    ents[0] = e1;

    while (!WindowShouldClose()) {

        delta = GetFrameTime();

        MoveSystem(ents, ENTITY_COUNT, delta);
        DrawSystem(ents, ENTITY_COUNT, BLACK);
    }

    freeEntity(e1);

    // for(int i = 0; i<= ENTITY_COUNT-1; i++)
    // {
    //     freeEntity(ents[i]);
    // }

    CloseWindow();

    return 0;
}
