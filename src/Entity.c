#include "entity/Entity.h"
#include <stdlib.h>

#include "component/util/TextureFactory.h"

TextureFactory* textureFactory;

// XXX Using 10,000+ with textures is slow! 100,000 is slow with DrawRect.
int ENTITY_COUNT = 1;

//-----------------------------------------------------------------------------
// CONSTRUCTOR/DESTRUCTOR
//-----------------------------------------------------------------------------

Entity* initEntity()
{
    Entity* e = malloc(sizeof(Entity));
    return e;
}

void freeEntity(Entity* e)
{
    if(e->drawComponent)
        free(e->drawComponent);

    if(e->transformComponent)
        free(e->transformComponent);

    // if(e->spriteComponent)
    // {
    //     UnloadTexture(*e->spriteComponent->texture);
    //     free(e->spriteComponent);
    // }

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
    *ent->spriteComponent->texture = LoadTextureFromImage(img);
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
