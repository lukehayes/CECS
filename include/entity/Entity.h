#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H

#include "component/DrawComponent.h"
#include "component/TransformComponent.h"
#include "component/SpriteComponent.h"


extern int ENTITY_COUNT;


typedef struct Entity
{
    DrawComponent* drawComponent;
    TransformComponent* transformComponent;
    SpriteComponent* spriteComponent;

} Entity;

//-----------------------------------------------------------------------------
// CONSTRUCTOR/DESTRUCTOR
//-----------------------------------------------------------------------------

/**
 * Create an instance of an entity. Basically a constructor.
 *
 * Calls malloc so return value needs to be freed.
 *
 * @param float x.
 * @param float y.
 *
 * @retrun Entity*
 */
Entity* initEntity();

/**
 * Destroy an allocated entity and all of its components.
 *
 * @param Entity*
 *
 * @retrun void
 */
void freeEntity(Entity* e);


//-----------------------------------------------------------------------------
// COMPONENT FUNCTIONS
//-----------------------------------------------------------------------------

/**
 * Set the transform component of this entity.
 *
 * Calls malloc so return value needs to be freed.
 *
 * @param Entity* ent.
 * @param float x.
 * @param float y.
 * @param float w.
 * @param float h.
 *
 * @retrun void*
 */
void addTransformComponent(Entity* e, int x, int y, int w, int h);

/**
 * Set the sprite component of this entity.
 *
 * Calls malloc so return value needs to be freed.
 *
 * @param Entity* ent.
 * @param const char* imagePath.
 * @param int sx.
 * @param int sy.
 *
 * @retrun void*
 */
void addSpriteComponent(Entity* e, const char* imagePath, int sx, int sy);

/**
 * Set a timer component on this entity
 *
 * @param Entity* e.
 *
 * @return void.
 */
void addTimerCompnent(Entity* e);

/**
 * Set the draw component of this entity.
 *
 * Calls malloc so return value needs to be freed.
 *
 * @param Entity* ent.
 * @param int size.
 *
 * @retrun void*
 */
void addDrawComponent(Entity* e, int size);

#endif //ECS_ENTITY_H
