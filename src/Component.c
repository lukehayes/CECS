#include "ECS/Component.h"
#include <stdio.h>

void addTransform(int entity_id, int x, int y, Color color, ComponentList* components)
{
    TransformComponent* transform = malloc(sizeof(TransformComponent));

    transform->position.x = x;
    transform->position.y = y;
    transform->size = TILE_SIZE;
    transform->color = color;

    transform->dx = GetRandomValue(-1,1);
    transform->dy = GetRandomValue(-1,1);
    transform->speed = GetRandomValue(100,200);

    components->transforms[entity_id] = transform;
}

void addSound(int entity_id, const char* soundfile, ComponentList* components)
{
    SoundComponent* sound = malloc(sizeof(SoundComponent));

    sound->sound = LoadSound(soundfile);

    components->sounds[entity_id] = sound;
}

void addCollision(int entity_id, int size, ComponentList* components)
{
    TransformComponent* transform = components->transforms[entity_id];
    CollisionComponent* collision = malloc(sizeof(CollisionComponent));

    int scale = (collision->size + transform->size) / 2;

    int xCalc = (transform->position.x + collision->size) / 2;
    int yCalc = (transform->position.y + collision->size) / 2;

    collision->position = (Vector2){xCalc, yCalc};

    collision->color = (Color){90,100,140,190};
    collision->size = size;

    components->collisions[entity_id] = collision;
}
