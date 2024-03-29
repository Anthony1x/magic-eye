#pragma once
#include "Grid.h"
#include <cstdint>
extern "C"
{
#include "raylib.h"
}
class Game
{
  public:
    Game();
    void Update();
    void Draw();

  private:
    Grid grid;
    uint8_t cellSize;
};