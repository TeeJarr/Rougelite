#include "../include/raylibCpp.h"
#include "Vec2.h"
#include <assert.h>
#include <raylib.h>

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color c)
{
    // assert(pos.GetX() >= 0 && pos.GetX() < GetScreenWidth() && pos.GetY() >= 0 && pos.GetY() < GetScreenHeight());
    DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), c);
}
