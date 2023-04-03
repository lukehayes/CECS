#include "entity/Entity.h"
#include <stdlib.h>

#include "component/util/TextureFactory.h"

TextureFactory* textureFactory;

// XXX Using 10,000+ with textures is slow! 100,000 is slow with DrawRect.
int ENTITY_COUNT = 10;

//-----------------------------------------------------------------------------
// CONSTRUCTOR/DESTRUCTOR
//-----------------------------------------------------------------------------

Entity* initEntity()
{
    Entity* e = malloc(sizeof(Entity));

    e->drawComponent      = NULL;
    e->transformComponent = NULL;
    e->spriteComponent    = NULL;

    return e;
}

void freeEntity(Entity* e)
{
    if(e->drawComponent)
        free(e->drawComponent);

    if(e->transformComponent)
        free(e->transformComponent);

    if(e->spriteComponent)
    {
        // XXX SpriteComponent->texture lives on the GPU and is freed
        // at a later time when freeTextureFactory() is called
        // at the end of the program.
        LOG("Freeing Allocated Texture Space");
        free(e->spriteComponent->texture);

        LOG("Freeing Sprite Component");
        free(e->spriteComponent);
    }

    free(e);

    e->drawComponent = NULL;
}
//-----------------------------------------------------------------------------
// COMPONENT FUNCTIONS
//-----------------------------------------------------------------------------

void addTransformComponent(Entity* ent, int x, int y, int w, int h)
{
    // TransformComponent
    ent->transformComponent = malloc(sizeof(TransformComponent));
    ent->transformComponent->x = x;
    ent->transformComponent->y = y;
    ent->transformComponent->w = w;
    ent->transformComponent->h = h;
    ent->transformComponent->dx = GetRandomValue(-1,1);
    ent->transformComponent->dy = GetRandomValue(-1,1);
    ent->transformComponent->vx = GetRandomValue(-1,1);
    ent->transformComponent->vy = GetRandomValue(-1,1);
    ent->transformComponent->speed = GetRandomValue(10,400);
}


void addSpriteComponent(Entity* ent, const char* imagePath, int sx, int sy)
{
    // TODO Need some kind of hashmap for this. Will
    // implement something later when I learn
    // how it should be done.
    
    Image img = LoadImage(imagePath);
    ImageResize(&img, 16 * sx, 16 * sy);

    ent->spriteComponent = malloc(sizeof(SpriteComponent));

    // This is needed otherwise a segfault happens.
    ent->spriteComponent->texture = malloc(sizeof(Texture2D));
    *ent->spriteComponent->texture = textureFactory->debug_sprite;

    ent->spriteComponent->tint = WHITE;
}

void addDrawComponent(Entity* e, int size)
{
    // DrawComponent
    e->drawComponent = malloc(sizeof(DrawComponent));
    e->drawComponent->color = LIGHTGRAY;
    e->drawComponent->w = size;
    e->drawComponent->h = size; 
}
