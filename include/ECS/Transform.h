#pragma once

#include "raylib.h"
#include "ECS/Globals.h"
#include "ECS/ComponentList.h"


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
void addTransform(int entity_id, int x, int y, Color color, ComponentList* components);

/**
* Transform Component draw system.
*
* @param TransformComponent** color
*
* @return void
*/
void DrawSystem(struct ComponentList* components);

/**
* Transform Component update system.
*
* @param TransformComponent** color
* @param float delta
*
* @return void
*/
void UpdateSystem(struct ComponentList* components, float delta);

/**
* Free all allocated Transform Components.
*
* @param TransformComponent** color
*
* @return void
*/
void DestroyTransforms(struct ComponentList* components);
