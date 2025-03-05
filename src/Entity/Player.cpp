#include "Player.hpp"
#include "Config.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

Player::Player()
{
    SetEntityPos(playerSpawnLocation);
    SetEntitySize(playerSize);
}

// int MaxAttackStage = 24;
//
// void Player::Attack(int AttackStage)
// {
//
//     if (AttackStage <= 7 && AttackStage >= 0)
//     {
//         ++AttackStage;
//         Attack(AttackStage);
//     }
//     else if (AttackStage > 7 && AttackStage <= 18)
//     {
//         // TODO add logiic to create hitbox
//         ++AttackStage;
//         Attack(AttackStage);
//     }
//     else if (AttackStage > 18 && AttackStage < MaxAttackStage)
//     {
//         // TODO impliment end lag frames
//         ++AttackStage;
//     }
//     else if (AttackStage == MaxAttackStage)
//     {
//         AttackStage = 0;
//     }
// }

void Player::Move(const std::vector<Block> obstacles)
{
    Vector2 oldPos = EntityPos;
    Vector2 newPos = EntityPos;

    bool isColliding = false;

    if (IsKeyDown(KEY_LEFT))
        newPos.x -= playerSpeed;
    if (IsKeyDown(KEY_RIGHT))
        newPos.x += playerSpeed;
    if (IsKeyDown(KEY_UP))
        newPos.y -= playerSpeed;
    if (IsKeyDown(KEY_DOWN))
        newPos.y += playerSpeed;

    for (const auto &obstacle : obstacles)
    {
        if (CheckCollisionRecs(Rectangle{newPos.x, newPos.y, playerSize.x, playerSize.y}, obstacle.GetRect()))
        {
            isColliding = true;
            break;
        }
    }

    std::cout << isColliding << std::endl;

    if (!isColliding)
    {
        EntityPos.x = newPos.x;
        EntityPos.y = newPos.y;
    }
    CollisionCheck();
}

void Player::CollisionCheck()
{
    // Screen Bounds
    if (EntityPos.x <= 0)
        SetEntityPos({0, EntityPos.y});
    if (EntityPos.x + playerSize.x >= config::ScreenWidth)
        SetEntityPos({config::ScreenWidth - playerSize.x, EntityPos.y});
    if (EntityPos.y <= 0)
        SetEntityPos({EntityPos.x, 0});
    if (EntityPos.y + playerSize.y >= config::ScreenHeight)
        SetEntityPos({EntityPos.x, config::ScreenHeight - playerSize.y});
}
