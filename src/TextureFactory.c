#include "component/util/TextureFactory.h"

/**
 * Initialize all of the textures in a single location.
 */
TextureFactory* initTextureFactory()
{
  LOG("Initializing Texture Factory");
  TextureFactory* factory = malloc(sizeof(TextureFactory));

  Image spriteImage = LoadImage("../assets/debug_sprite.png");
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
