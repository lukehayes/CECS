#ifndef UTIL_TEXTURE_FACTORY_H
#define UTIL_TEXTURE_FACTORY_H

#include "raylib.h"
#include "logging.h"
#include <stdlib.h>

/**
 * Texture factory represents a single location to load textures
 * so it is only loaded onto the GPU once.
 */
typedef struct TextureFactory
{
  Texture debug_sprite;
  Texture debug_player;

} TextureFactory;


/**
 * Initialize all of the textures in a single location.
 */
TextureFactory* initTextureFactory();

void freeTextureFactory(TextureFactory* factory);

extern TextureFactory* textureFactory;



#endif  //UTIL_TEXTURE_FACTORY_H
