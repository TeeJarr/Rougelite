#include "Config.h"
#include "Entity.h"
#include "raylib.h"
#pragma once

class Player : public Entity
{
  public:
    Player();
    void Move();
    void Attack();
    void SetHP();
    void SetMana();

  private:
    // Player Logic Functions
    void CollisionCheck();

    // Player Movement and Size Variables
    int playerSpeed = 5;
    Vector2 playerSize = {30, 30};
    Vector2 playerSpawnLocation = {
        config::ScreenWidth / 2.0f + playerSize.x / 2.0f, config::ScreenHeight / 2.0f + playerSize.y / 2
    };

    // Player Combat
};
