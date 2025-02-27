#include "Entity.hpp"
#include "raylib.h"

Entity::Entity() {}

void Entity::SetEntityBounds(Rectangle newBounds)
{
    EntityPos.x = newBounds.x;
    EntityPos.y = newBounds.y;
    EntitySize.x = newBounds.width;
    EntitySize.y = newBounds.height;
    EntityBounds.x = EntityPos.x;
    EntityBounds.y = EntityPos.y;
    EntityBounds.width = EntitySize.x;
    EntityBounds.height = EntitySize.y;
}

void Entity::SetEntityPos(Vector2 newPos)
{
    EntityPos.x = newPos.x;
    EntityPos.y = newPos.y;
}

void Entity::SetEntitySize(Vector2 newSize)
{
    EntitySize.x = newSize.x;
    EntitySize.y = newSize.y;
}

void Entity::Draw() { DrawRectangle(EntityPos.x, EntityPos.y, EntitySize.x, EntitySize.y, WHITE); }

Rectangle Entity::GetRect() const { return Rectangle{EntityPos.x, EntityPos.y, EntitySize.x, EntitySize.y}; }

bool Entity::Collisions(Rectangle player, Rectangle obstacle) { return CheckCollisionRecs(player, obstacle); }
