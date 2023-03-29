#ifndef ECS_DRAW_SYSTEM_H
#define ECS_DRAW_SYSTEM_H

#include "entity/Entity.h"
#include <stdlib.h>

/**
 * Draw an entity.
 *
 * @param Entity** ents.
 *
 * @param int count.
 *
 * @return void.
 */
void DrawSystem(Entity** ents, int count);


#endif //ECS_DRAW_SYSTEM_H
