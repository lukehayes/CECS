#include "ECS/Component.h"

void addTransform(int entity_id, int x, int y, Color color, ComponentList* components)
{
    TransformComponent* transform = malloc(sizeof(TransformComponent));

    transform->position.x = x;
    transform->position.y = y;
    transform->size = 10;
    transform->color = color;
    
    components->transforms[entity_id] = transform;
}
