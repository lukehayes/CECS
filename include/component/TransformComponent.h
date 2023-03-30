#ifndef COMP_TRANSFORM_H
#define COMP_TRANSFORM_H

/**
 * Transform component that holds positional data.
 */
typedef struct TransformComponent
{
  float x;  // X Position
  float y;  // Y Position
  float vx; // Velocity X
  float vy; // Velocity Y
  float dx; // Direction X (-1 or -)
  float dy; // Direction Y ( -1 or 1)
  float speed; // Speed of entity movement
  float w;
  float h;

} TransformComponent;



#endif //COMP_TRANSFORM_H
