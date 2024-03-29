#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include <string>

class Grid
{
public:
  Grid();
  Grid(int cellSize);

  Color GetCellColor(int x, int y);
  void SetCellColor(int x, int y, Color color);
  void DrawGrid();
  // Helper function to get number of cells based on screen size
  static int GetNumCells(int cellSize);

private:
  int cellSize;
  std::vector<Color> cellColors;
};
