#pragma once

#include <numeric>
#include <vector>
extern "C"
{
#include "raylib.h"
}

class Helper
{
  public:
    static Color RandomColor(bool noAlpha);
    static std::vector<int> CommonDivisors(int a, int b);
};