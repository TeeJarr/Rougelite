#include "Block.hpp"
#include "Config.hpp"
#include "Player.hpp"
#include "raylib.h"
#include <iostream>

void Update();
void Draw();
void GameTick();

Player player;
Block obstacle;

bool isColliding;

int main()
{
    InitWindow(config::ScreenWidth, config::ScreenHeight, config::ScreenTitle.c_str());
    SetTargetFPS(60);

    obstacle.SetEntityPos({200, 200});
    obstacle.SetEntitySize({20, 20});

    while (!WindowShouldClose())
    {
        GameTick();
    }

    CloseWindow();
    return 0;
}

void GameTick()
{
    Update();
    Draw();
}

void Update()
{
    player.Move();
    isColliding = player.Collisions(player.GetRect(), obstacle.GetRect());
    // std::cout << isColliding << std::endl;
}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    obstacle.Draw();
    player.Draw();
    if (isColliding)
    {
        DrawRectangleLinesEx(player.GetRect(), 2, WHITE);
    }
    EndDrawing();
}
