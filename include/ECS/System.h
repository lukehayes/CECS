#pragma once

#include "raylib.h"
#include "ECS/Globals.h"
#include "ECS/ComponentList.h"


/**
* Transform Component draw system.
*
* @param TransformComponent** color
*
* @return void
*/
void DrawSystem(ComponentList* components);

/**
* General sytem to try new components etc.
* More specific systems should be defined.
*
* @param ComponentList** components.
* @param float delta.
*
* @return void.
*/
void UpdateSystem(ComponentList* components, float delta);

/**
* Collision detection for entities.
*
* @param ComponentList** components.
* @param float delta.
*
* @return void.
*/
void CollisionSystem(ComponentList* components, float delta);
