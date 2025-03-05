#include "raylib.h"
#pragma once

class Menubar
{
  public:
    Menubar();
    void DrawBar();

  private:
    int barHeight;
    Vector2 barPosition;
    int barWidth;
};
