#include "component/util/TextureFactory.h"

#define BASE_IMAGE_TILE_SIZE 16
#define TILE_SCALE_FACTOR 1

/**
 * Initialize all of the textures in a single location.
 */
TextureFactory* initTextureFactory()
{
  LOG("Initializing Texture Factory");
  TextureFactory* factory = malloc(sizeof(TextureFactory));

  // TODO Need to add a better way to scale an image.
  Image spriteImage = LoadImage("../assets/debug_sprite.png");

  // Scale the image from its base size.
  ImageResize(&spriteImage, 
      BASE_IMAGE_TILE_SIZE * TILE_SCALE_FACTOR,
      BASE_IMAGE_TILE_SIZE * TILE_SCALE_FACTOR
  );


  factory->debug_sprite = LoadTextureFromImage(spriteImage);

  return factory;
}

void freeTextureFactory(TextureFactory* factory)
{

  LOG("Freeing Texture Debug Sprite");
  UnloadTexture(factory->debug_sprite);

  LOG("Freeing Texture Debug Player Sprite");
  UnloadTexture(factory->debug_player);
}
