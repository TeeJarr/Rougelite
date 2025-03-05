#include "Menubar.hpp"
#include "Config.hpp"
#include "raylib.h"

Menubar::Menubar() /* : barHeight(100), barPosition(Vector2{0, 0}), barWidth(config::ScreenWidth) */ {}

void Menubar::DrawBar() { DrawRectangle(0, 0, 1200, 100, BLUE); }
