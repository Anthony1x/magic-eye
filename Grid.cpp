#include "Grid.h"
#include "Helper.h"
#include <algorithm>

Grid::Grid()
{
}

Grid::Grid(int cellSize) : cellSize(cellSize)
{
    int numCellsX = GetNumCells(cellSize);
    int numCellsY = GetNumCells(cellSize);
    cellColors = std::vector<Color>(numCellsX * numCellsY);

    // Initialize all cell colors to a random color
    for (int i = 0; i < numCellsX * numCellsY; i++)
    {
        cellColors[i] = Helper::RandomColor(false);
    }
}

Color Grid::GetCellColor(int x, int y)
{
    return cellColors[y * GetNumCells(cellSize) + x];
}

void Grid::SetCellColor(int x, int y, Color color)
{
    int numCells = GetNumCells(cellSize);
    if (x >= 0 && x < numCells && y >= 0 && y < numCells)
    {
        cellColors[y * numCells + x] = color;
    }
}

void Grid::DrawGrid()
{
    int numCellsX = GetNumCells(cellSize);
    int numCellsY = GetNumCells(cellSize);

    for (int i = 0; i <= numCellsX; i++)
    {
        // Draw vertical lines
        DrawLine(0, i * cellSize, GetScreenWidth(), i * cellSize, RAYWHITE);
    }

    for (int i = 0; i <= numCellsY; i++)
    {
        // Draw horizontal lines
        DrawLine(i * cellSize, 0, i * cellSize, GetScreenHeight(), RAYWHITE);
    }

    // Draw cell colors
    for (int y = 0; y < numCellsY; y++)
    {
        for (int x = 0; x < numCellsX; x++)
        {
            Color color = cellColors[y * numCellsX + x];

            DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, color);
        }
    }
}

int Grid::GetNumCells(int cellSize) {
  // Get the screen dimensions from Raylib
  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  // Calculate the maximum number of cells that fit horizontally and vertically
  int numCellsX = screenWidth / cellSize;
  int numCellsY = screenHeight / cellSize;

  // Instead of choosing the minimum, calculate the number of cells 
  // that would fill most of the screen area while maintaining a 1:1 aspect ratio
  int idealCellsX = screenHeight / cellSize;  // Assuming height is the limiting factor
  int idealCellsY = screenWidth / cellSize;   // Assuming width is the limiting factor

  // Choose the option that utilizes the most space while maintaining a 1:1 ratio
  int numCells = std::max(idealCellsX, idealCellsY);

  return numCells;
}
