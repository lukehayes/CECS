#include "ECS/Component.h"

void addTransform(int entity_id, int x, int y, Color color, ComponentList* components)
{
    TransformComponent* transform = malloc(sizeof(TransformComponent));

    transform->position.x = x;
    transform->position.y = y;
    transform->size = 10;
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

void addCollision(int entity_id, int x, int y, int size, ComponentList* components)
{
    CollisionComponent* collision = malloc(sizeof(CollisionComponent));
    collision->position = (Vector2){x,y};
    collision->color = (Color){50,100,100,190};
    collision->size = size;

    components->collisions[entity_id] = collision;
}
