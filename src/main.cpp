#include "Config.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "raylib.h"

void Update();
void Draw();
void GameTick();

Player player;

int main()
{
    InitWindow(config::ScreenWidth, config::ScreenHeight, config::ScreenTitle.c_str());
    SetTargetFPS(60);

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

void Update() { player.Move(); }

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    player.Draw();
    EndDrawing();
}
