#include "Block.hpp"
#include "Config.hpp"
#include "Menubar.hpp"
#include "Player.hpp"
#include "raylib.h"
#include <vector>

void Update();
void Draw();
void GameTick();

Player player;
Block obstacle;
Block obstacle2;
Menubar menubar;

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
    // std::cout << "Game is running" << std::endl;
    Update();
    Draw();
}

void Update() { player.Move(obstacleVector); }

void Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw Entities
    // std::cout << "Drawing entities" << std::endl;
    obstacle.Draw();
    obstacle2.Draw();
    player.Draw();

    // DRAW UI
    // std::cout << "Drawing UI" << std::endl;
    menubar.DrawBar();
    EndDrawing();
}
