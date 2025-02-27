#include "Block.hpp"
#include "Config.hpp"
#include "Entity.hpp"
#include "raylib.h"
#pragma once

class Player : public Entity
{
  public:
    Player();
    void Move(std::vector<Block> obstacles);
    void Attack(int AttackStage);
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
