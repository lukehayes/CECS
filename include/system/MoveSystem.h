#ifndef ECS_MOVE_SYSTEM_H
#define ECS_MOVE_SYSTEM_H

#include "entity/Entity.h"
#include <stdlib.h>

/**
 * Move an entity with velocity for example.
 *
 * @param Entity** ents.
 * @param int count.
 * @param float dt.
 *
 * @return void.
 */
void MoveSystem(Entity** ents, int count, float dt);


#endif //ECS_MOVE_SYSTEM_H
