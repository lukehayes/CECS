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
* Transform Component update system.
*
* @param TransformComponent** color
* @param float delta
*
* @return void
*/
void UpdateSystem(ComponentList* components, float delta);

/**
* Free all allocated Transform Components.
*
* @param TransformComponent** color
*
* @return void
*/
void DestroyTransforms(ComponentList* components);
