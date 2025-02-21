#include "Player.hpp"
#include "Config.hpp"
#include "raylib.h"

Player::Player()
{
    SetEntityPos(playerSpawnLocation);
    SetEntitySize(playerSize);
}
void Player::Move()
{
    if (IsKeyDown(KEY_LEFT))
    {
        EntityPos.x -= playerSpeed;
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        EntityPos.x += playerSpeed;
    }

    if (IsKeyDown(KEY_UP))
    {
        EntityPos.y -= playerSpeed;
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        EntityPos.y += playerSpeed;
    }
    CollisionCheck();
}

void Player::CollisionCheck()
{
    // Screen Bounds
    if (EntityPos.x <= 0)
    {
        SetEntityPos({0, EntityPos.y});
    }
    if (EntityPos.x + playerSize.x >= config::ScreenWidth)
    {
        SetEntityPos({config::ScreenWidth - playerSize.x, EntityPos.y});
    }
    if (EntityPos.y <= 0)
    {
        SetEntityPos({EntityPos.x, 0});
    }
    if (EntityPos.y + playerSize.y >= config::ScreenHeight)
    {
        SetEntityPos({EntityPos.x, config::ScreenHeight - playerSize.y});
    }
}
