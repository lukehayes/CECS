#ifndef COMP_SPRITE_COMP_H
#define COMP_SPRITE_COMP_H

#include "raylib.h"

/**
 * A static sprite component that is designed to use a single image.
 */
typedef struct SpriteComponent
{

  Texture2D texture;
  Color tint;

} SpriteComponent;

#endif //COMP_SPRITE_COMP_H
