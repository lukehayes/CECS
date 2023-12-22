#ifndef ECS_TRANSFORM_H
#define ECS_TRANSFORM_H

#include "raylib.h"

#define COMPONENT_COUNT 100

typedef struct TransfromComponent
{
    Vector2 position;
    int size;
    Color color;
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
void addTransform(int entity_id, int x, int y, Color color, TransformComponent** transforms);

/**
* Transform Component draw system.
*
* @param TransformComponent** color
*
* @return void
*/
void DrawSystem(TransformComponent** transforms);

/**
* Transform Component update system.
*
* @param TransformComponent** color
* @param float delta
*
* @return void
*/
void UpdateSystem(TransformComponent** transforms, float delta);

/**
* Free all allocated Transform Components.
*
* @param TransformComponent** color
*
* @return void
*/
void DestroyTransforms(TransformComponent** transforms);

#endif // DEBUG
