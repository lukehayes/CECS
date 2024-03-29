#pragma once

#include "raylib.h"
#include "ECS/ComponentList.h"


/**----------------------------------------------------------------------------
 * Transform
----------------------------------------------------------------------------**/

typedef struct TransformComponent
{
    Vector2 position;
    int size;
    Color color;

    int dx;
    int dy;
    int speed;

} TransformComponent;

/**
* Add a transform component to an entity.
*
* @param int entity_id
* @param int x
* @param int y
* @param Color color
* @param TransformComponent** color
*
* @return void
*/
void addTransform(int entity_id, int x, int y, Color color, ComponentList* components);

/**----------------------------------------------------------------------------
 * Sound
----------------------------------------------------------------------------**/

typedef struct SoundComponent
{
    Sound sound;

} SoundComponent;

void addSound(int entity_id, const char* soundfile, ComponentList* components);

/**----------------------------------------------------------------------------
 * Collision
----------------------------------------------------------------------------**/

typedef struct CollisionComponent
{
    Vector2 position;
    int size;
    Color color;

} CollisionComponent;

void addCollision(int entity_id, int size, ComponentList* components);
