#include "Block.hpp"
#include "Config.hpp"
#include "Player.hpp"
#include "raylib.h"
#include <vector>

void Update();
void Draw();
void GameTick();

Player player;
Block obstacle;
Block obstacle2;

std::vector<Block> obstacleVector;

int main()
{
    InitWindow(config::ScreenWidth, config::ScreenHeight, config::ScreenTitle.c_str());
    SetTargetFPS(60);

    obstacle.SetEntityPos({200, 200});
    obstacle.SetEntitySize({20, 20});
    obstacle2.SetEntitySize({40, 40});
    obstacle2.SetEntityPos({300, 50});

    obstacleVector.push_back(obstacle);
    obstacleVector.push_back(obstacle2);

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

void Update() { player.Move(obstacleVector); }

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    obstacle.Draw();
    obstacle2.Draw();
    player.Draw();
    EndDrawing();
}
