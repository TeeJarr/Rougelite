#include "raylib.h"
#pragma once

class Entity
{
  public:
    Entity();
    Rectangle GetEntityBounds() const;
    void SetEntityBounds(Rectangle newBounds);
    void SetEntityPos(Vector2 newPos);
    void SetEntitySize(Vector2 newSize);
    void Draw();
    Rectangle GetRect() const;
    bool Collisions(Rectangle player, Rectangle obstacle);

  protected:
    Rectangle EntityBounds;
    Vector2 EntityPos;
    Vector2 EntitySize;
};
