#ifndef ECS_MOVE_SYSTEM_H
#define ECS_MOVE_SYSTEM_H

#include "entity/Entity.h"
#include <stdlib.h>

/**
 * Move an entity with velocity for example.
 *
 * @param Entity* e.
 * @param float dt.
 *
 * @return void.
 */
void MoveSystem(Entity* e, float dt);


#endif //ECS_MOVE_SYSTEM_H
