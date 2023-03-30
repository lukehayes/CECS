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
Entity* initEntity(float x, float y);

/**
 * Destroy an allocated entity and all of its components.
 *
 * @param Entity*
 *
 * @retrun void
 */
void freeEntity(Entity* e);

#endif //ECS_ENTITY_H
